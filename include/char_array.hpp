#ifndef INDEX_CHAR_ARRAY_HPP_
#define INDEX_CHAR_ARRAY_HPP_

#include <cstring>

template <int T>
struct CharArray {
    char data[T];

    CharArray() = default;
    CharArray(const std::string& temp) { strcpy(data, temp.c_str()); }
    CharArray(char in[T]) { memcpy(data, in, T); }

    char& operator[](unsigned int idx) { return data[idx]; }

    bool operator < (const CharArray<T>& idx) const {
        std::string lhd(data);
        std::string rhd(idx.data);
        return lhd < rhd;
    }
    bool operator == (const CharArray<T>& idx) const {
        std::string lhd(data);
        std::string rhd(idx.data);
        return lhd == rhd;
    }
};

#endif // INDEX_CHAR_ARRAY_HPP_
