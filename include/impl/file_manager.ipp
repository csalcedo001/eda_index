#ifndef INDEX_FILE_MANAGER_IPP_
#define INDEX_FILE_MANAGER_IPP_

namespace eda {

namespace index {

template <class Record>
FileManager<Record>::FileManager(std::string filename) :
	file_(filename, std::ios::binary | std::ios::in | std::ios::out)
{
	this->file_.seekg(sizeof(long long), file_.beg);
	this->last_position_ = this->file_.tellg();

	if (this->last_position_ == 0) {
		this->file_.write((char *) &this->last_position_, sizeof(long long));
		this->last_position_ = this->file_.tellg();
	}
}

template <class Record>
void FileManager<Record>::get(Record &record, long long position) {
	this->file_.seekg(0, this->last_position_);
	this->file_.read((char *) &record, sizeof(Record));
}

template <class Record>
long long FileManager<Record>::set(Record &record) {
	this->file_.seekg(0, this->last_position_);
	this->file_.write((char *) &record, sizeof(Record));
	this->last_position_ = this->seekg();
}

} // namespace index

} // namespace eda

#endif // INDEX_FILE_MANAGER_IPP_
