#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vector_of_integers{};

	vector_of_integers.push_back(1); // O(1)
	vector_of_integers.push_back(3); // O(1)
	vector_of_integers.push_back(5); // O(1)
	vector_of_integers.push_back(7); // O(1)

	for (int i = 8; i <= 10; i++)
		vector_of_integers.push_back(i);

	// Printing out all the elements of vector of integers - Method 1
	copy(vector_of_integers.begin(), vector_of_integers.end(), ostream_iterator<int>(cout, " ")); // 1 3 5 7 8 9 10
	cout << endl << endl;

	// Inserting '2' at index 1
	vector<int>::iterator it{ vector_of_integers.begin() };
	advance(it, 1);
	vector_of_integers.insert(it, 2); // O(N+M) => M is size of elements to be inserted

	// Printing out all the elements of vector of integers - Method 2
	for (auto const& element : vector_of_integers)
		std::cout << element << " "; // 1 2 3 5 7 8 9 10
	cout << endl << endl;

	// "it" no longer valid, get a new one
	it = vector_of_integers.begin();
	vector_of_integers.insert(it + 4, 6); // O(N+M) => M is size of elements to be inserted

	// Printing out all the elements of vector of integers - Method 3
	for (it = vector_of_integers.begin(); it != vector_of_integers.end(); it++)
		std::cout << *it << ' '; // 1 2 3 5 6 7 8 9 10
	cout << endl << endl;

	// insert '4' 7 times at index 3
	vector<int> new_vector_to_be_inserted(7, 4);
	vector_of_integers.insert(vector_of_integers.begin() + 3, new_vector_to_be_inserted.begin(), new_vector_to_be_inserted.end()); // O(N+M) => M is size of elements to be inserted

	// Printing out all the elements of vector of integers - Method 4
	for (int i = 0; i < vector_of_integers.size(); i++) // vector_of_integers.size() O(1)
		cout << vector_of_integers.at(i) << ' '; // 1 2 3 4 4 4 4 4 4 4 5 6 7 8 9 10 // vector_of_integers.at(i) O(1)
	cout << endl << endl;

	return 0;
}
