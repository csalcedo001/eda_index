#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int main() {
	string dictionary;

	cin >> dictionary;

	string dict_path = "data/data/" + dictionary + ".dat";

	ifstream file(dict_path, ios::binary | ios::in);

	if (!file.is_open()) {
		cerr << "No dictionary " << dictionary << endl;
		return 1;
	}

	vector<string> queries;
	string query;

	while (file) {
		getline(file, query, '\t');

		queries.push_back(query);

		getline(file, query);
	}

	int n;

	cin >> n;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> point_distribution(0, queries.size() - 1);

	cout << dictionary << ' ' << n << endl;

	for (int i = 0; i < n; i++) {
		int index = point_distribution(generator);
		cout << queries[index] << endl;
	}

	return 0;
}
