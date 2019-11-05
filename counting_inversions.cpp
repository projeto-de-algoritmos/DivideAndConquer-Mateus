#include <iostream>
#include <vector>
#include <algorithm>

#define INT_MAX 2147483647

int merge_sort(std::vector<int> &arr)
{
	int size = arr.size();

	if (size == 1)
		return 0; // no inversions here

	int no_inversions = 0;

	std::vector<int> first_half, second_half;

	// after creating the segments, assign
	
	for (int i = 0; i < size/2; i++)
		first_half.push_back(arr[i]);

	for (int i = size/2; i < size; i++)
		second_half.push_back(arr[i]);


	// recursive calls
	no_inversions += merge_sort(first_half);
	no_inversions += merge_sort(second_half);


	// adding a sentinel to avoid aditional checks 
	first_half.push_back(INT_MAX);
	second_half.push_back(INT_MAX);


	// declare two pointers to iterate through each half
	
	int p = 0;
	int q = 0;

	for (int i = 0; i < size; i++)
	{
		/* if the element (a not checked one) in the first half is bigger 
		 * than another unchecked one in the second half
		 */
		if (first_half[p] > second_half[q])
		{
			arr[i] = second_half[q++];
			no_inversions += first_half.size() - p - 1;
		}
		else
			arr[i] = first_half[p++]; // just add to the array and increase the first pointer
	}

	return no_inversions;
}

int main()
{
	int no_elements;

	std::cout << "Digite o numero de elementos: ";
	std::cin >> no_elements;
	
	std::cout << "Digite os " << no_elements << " numeros desejados:\n";
	std::vector<int> v(no_elements);

	for (int i = 0; i < no_elements; i++)
	{
		std::cin >> v[i];
	}

	int no_inversions = merge_sort(v);
	
	std::cout << "\nO numero total de inversoes eh: " << no_inversions << "\n\n";

	std::cout << "Array ordenada: \n";
	std::cout << v[0];
	for (int i = 1; i < no_elements; i++)
		std::cout << " " << v[i];

	std::cout << "\n";
}
