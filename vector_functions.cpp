#include <iostream>
#include <vector>
#include <array>

using namespace std;

void print_list(const vector <int>& vector_of_integers)
{
	copy(vector_of_integers.begin(), vector_of_integers.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main()
{
	vector<int> vector_of_integers{ 1,2,3,4,5,6,7 };
	print_list(vector_of_integers); // 1 2 3 4 5 6 7

	cout << vector_of_integers.front() << endl; // 1 // O(1)
	cout << vector_of_integers.back() << endl; // 7 // O(1)

	cout << vector_of_integers[2] << endl; // 3 // O(1)
	cout << vector_of_integers[3] << endl; // 4 // O(1)

	vector<int> new_vector_of_integers{ 7,16 };
	new_vector_of_integers[0] = -1; // O(1)
	new_vector_of_integers[1] = -3; // O(1)
	print_list(new_vector_of_integers); // -1 -3

	new_vector_of_integers = vector_of_integers; // O(N)
	print_list(new_vector_of_integers); // 1 2 3 4 5 6 7

	cout << vector_of_integers.empty() << endl; // 0 // O(1)
	vector_of_integers.clear(); // O(1) if elements need NOT be destroyed (trivially-destructible types, such as scalar or PODs) otherwise, O(N)
	cout << vector_of_integers.empty() << endl; // 1 // O(1)
	print_list(new_vector_of_integers); // 1 2 3 4 5 6 7


	vector_of_integers.push_back(5); // O(1)
	print_list(vector_of_integers); // 5

	vector_of_integers.insert(vector_of_integers.begin(), 1); // O(N+M) => M is size of elements to be inserted
	print_list(vector_of_integers); // 1 5

	vector_of_integers.insert(vector_of_integers.begin() + 1, 3); // O(N+M) => M is size of elements to be inserted
	print_list(vector_of_integers); // 1 3 5

	array<int, 3> new_array{ 7,9,11 };
	vector_of_integers.insert(vector_of_integers.end(), new_array.begin(), new_array.end()); // O(N+M) => M is size of elements to be inserted
	print_list(vector_of_integers); // 1 3 5 7 9 11

	int* p = vector_of_integers.data();
	*p = -1;
	++p;
	*p = -3;
	p[1] = -5;
	p[2] = -7;
	p[3] = -9;
	++p;
	p[3] = -11;
	print_list(vector_of_integers); // -1 -3 -5 -7 -9 -11

	vector_of_integers.erase(vector_of_integers.begin() + 4); // O(N+M) => M is the number of elements erased (destructions)
	print_list(vector_of_integers); // -1 -3 -5 -7 -11

	vector_of_integers.erase(vector_of_integers.begin() + 1, vector_of_integers.end() - 1);  // O(N+M) => M is the number of elements erased (destructions)
	print_list(vector_of_integers); // -1 -11

	vector_of_integers.swap(new_vector_of_integers); // O(1)
	print_list(vector_of_integers); // 1 2 3 4 5 6 7
	print_list(new_vector_of_integers); // -1

	vector_of_integers.pop_back();  // O(1)
	print_list(vector_of_integers); // 1 2 3 4 5 6

	cout << "size: " << vector_of_integers.size() << '\n'; // 7 // O(1) // Returns the number of elements in the vector.
	cout << "capacity: " << vector_of_integers.capacity() << '\n'; // 7 // O(1) // Returns the size of the storage space CURRENTLY allocated for the vector, expressed in terms of elements.
	cout << "max_size: " << vector_of_integers.max_size() << '\n'; // 4611686018427387903 // O(1) // Returns the maximum number of elements that the vector can hold.

	return 0;
}
