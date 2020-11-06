#ifndef INDEX_FILE_MANAGER_HPP_
#define INDEX_FILE_MANAGER_HPP_

namespace eda {

namespace index {

template <class Record>
class FileManager {
private:
	std::string file_;
	long long last_position_;

public:
	IndexManager(std::string);

	void get(Record &, long long);
	long long set(Record &);
};

} // namespace index

} // namespace eda

#endif // INDEX_FILE_MANAGER_HPP_
