#ifndef INDEX_B_TREE_HPP_
#define INDEX_B_TREE_HPP_

#include <vector>

#include "record.hpp"

template <typename T, int ORDER>
class BTree {
private:
    long rootPos = 0;

    enum state_t { OF, UF, B_OK };

    struct Page {
        long posOfIndex = -1;
        std::pair <T, long> indexdata[ORDER+1];
        long children[ORDER+2];
        size_t count{0};

        Page() {
            std::fill(children, children + ORDER + 2, -1);
        }

        void insert_into(size_t index, std::pair<T, long> value, std::fstream& file) {
            size_t j = this->count;

            while (j > index) {
                children[j+1] = children[j];
                indexdata[j] = indexdata[j-1];
                j--;
            }

            children[j+1] = children[j];
            indexdata[j] = value;
            this->count++;
            file.seekg(this->posOfIndex, std::ios::beg);
            Page pos = *this;
            file.write((char*) &pos, sizeof(Page));
        }

        state_t insert(std::pair<T, long> value, std::fstream& file) {
            size_t index = 0;
            while (this->indexdata[index].first < value.first && index < this->count) {
                index++;
            }
            if (this->children[index] == -1) {
                this->insert_into(index, value, file);
            }
            else {
                file.seekg(this->children[index], std::ios::beg);
                Page nextnode;
                file.read((char*) &nextnode, sizeof(Page));
                auto state = nextnode.insert(value, file);
                if (state == state_t::OF) {
                    this->split(index, file);
                }
            }
            return this->count > ORDER ? OF : B_OK;
        }

        void split(size_t position, std::fstream& file) {
            Page tosplitNode;
            file.seekg(this->children[position], std::ios::beg);
            file.read((char*) &tosplitNode, sizeof(Page));

            Page child1;
            Page child2;
            size_t i = 0;
            for(; i < tosplitNode.count / 2; i++) {
                child1.children[i] = tosplitNode.children[i];
                child1.indexdata[i] = tosplitNode.indexdata[i];
                child1.count++;
            }
            child1.children[i] = tosplitNode.children[i];
            auto mid = i;
            i++;
            size_t j = 0;
            for (; i < tosplitNode.count; i++) {
                child2.children[j] = tosplitNode.children[i];
                child2.indexdata[j] = tosplitNode.indexdata[i];
                child2.count++;
                j++;
            }
            child2.children[j] = tosplitNode.children[i];

            this->insert_into(position, tosplitNode.indexdata[mid], file);
            file.seekg(0, std::ios::end);
            long poschild1 = file.tellg();
            child1.posOfIndex = poschild1;
            file.write((char*) &child1, sizeof(Page));

            file.seekg(tosplitNode.posOfIndex, std::ios::beg);
            long poschild2 = tosplitNode.posOfIndex;
            child2.posOfIndex = poschild2;
            file.write((char*) &child2, sizeof(Page));

            this->children[position] = poschild1;
            this->children[position + 1] = poschild2;
            file.seekg(this->posOfIndex, std::ios::beg);
            file.write((char*) this, sizeof(Page));
        }

        long search(T key, std::fstream& file) {
            if (this->count == 0) { return -1; }
            size_t index = 0;
            while (this->indexdata[index].first < key  && index < this->count) {
                index += 1;
            }
            if (this->indexdata[index].first == key) {
                return this->indexdata[index].second;
            } else {
                file.seekg(this->children[index], std::ios::beg);
                Page nextnode;
                file.read((char*) &nextnode, sizeof(Page));
                return nextnode.search(key, file);
            }
        }

    };

public:
    BTree() {}

    void insert(T key, long datapos) {
        std::fstream file("data/index/index.dat", std::ios::in | std::ios::out | std::ios::binary);
        if(!file.is_open()){
            std::cout << "Could not open file" << std::endl;
        }
        file.seekg(0, std::ios::end);
        if (file.tellg() == 0) {
            Page newroot;
            std::pair<T, long> value = std::make_pair(key, datapos);
            long pos = 0;
            newroot.posOfIndex = pos;
            newroot.insert(value, file);
        }
        else {
            file.seekg(rootPos, std::ios::beg);
            Page root;
            file.read((char*) &root, sizeof(Page));
            std::pair<T, long> value = std::make_pair(key, datapos);
            auto state = root.insert(value, file);
            if (state == state_t::OF) {
                split_root(file);
            }
        }
        file.close();
    }

    void split_root(std::fstream& file) {
        file.seekg(rootPos, std::ios::beg);
        Page root;
        file.read((char*) &root, sizeof(Page));

        Page child1;
        Page child2;
        size_t i = 0;
        for(; i < root.count / 2; i++) {
            child1.children[i] = root.children[i];
            child1.indexdata[i] = root.indexdata[i];
            child1.count++;
        }
        child1.children[i] = root.children[i];
        auto mid = i;
        i++;
        size_t j = 0;
        for (; i < root.count; i++) {
            child2.children[j] = root.children[i];
            child2.indexdata[j] = root.indexdata[i];
            child2.count++;
            j++;
        }
        child2.children[j] = root.children[i];

        root.indexdata[0] = root.indexdata[mid];
        file.seekg(0, std::ios::end);
        long poschild1 = file.tellg();
        child1.posOfIndex = poschild1;
        file.write((char*) &child1, sizeof(Page));

        long poschild2 = file.tellg();
        child2.posOfIndex = poschild2;
        file.write((char*) &child2, sizeof(Page));

        root.children[0] = poschild1;
        root.children[1] = poschild2;
        root.count = 1;

        file.seekg(rootPos, std::ios::beg);
        file.write((char*) &root, sizeof(Page));
    }

    Record search(T key) {
        std::fstream file("data/index/index.dat", std::ios::in | std::ios::out | std::ios::binary);

        if (!file.is_open()){
            std::cout << "Could not open file" << std::endl;

			return Record();
        }

        file.seekg(rootPos, std::ios::beg);
        Page root;
        file.read((char*) &root, sizeof(Page));

        long pos = root.search(key, file);

        file.close();

        if (pos == -1) {
			std::cout << "Not found" << std::endl;
			return Record();
		}

		return Record(pos);
    }

};

#endif // INDEX_B_TREE_HPP_
