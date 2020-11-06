#ifndef INDEX_INDEX_MANAGER_HPP_
#define INDEX_INDEX_MANAGER_HPP_

namespace eda {

namespace index {

template <class Record>
class IndexManager {
private:
	std::string filename_;

public:
	IndexManager(std::string);

	Record get(long long);
	long long set(Record);
};

} // namespace index

} // namespace eda

#endif // INDEX_INDEX_MANAGER_HPP_
