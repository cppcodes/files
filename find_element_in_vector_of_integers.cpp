#include <iostream>
#include <vector>

using namespace std;

int64_t find_element_in_vector_of_integers(const int &element, vector <int>& vector_of_integers)
{
	// Define an iterator pointing to the element in vector of integers
	vector<int>::iterator it = find(vector_of_integers.begin(), vector_of_integers.end(), element); // O(N)

	// Check if element was found in vector of integers
	if (it == vector_of_integers.end())
	{
		// Element not found
		return -1;
	}

	// Get element index inside vector of integers
	int64_t index{ distance(vector_of_integers.begin(), it) }; // O(1)

	return index;
}

int main()
{
	vector<int> vector_of_integers{ 7, 10, 75, 16, 4, 2, 29, 5, 73 };
	int element{ 16 };
	int64_t index = find_element_in_vector_of_integers(element, vector_of_integers);

	cout << "The index of '" << element << "' is " << index << endl;

	return 0;
}
