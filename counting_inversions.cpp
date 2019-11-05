#include <iostream>
#include <vector>
#include <algorithm>

int no_inversions = 0;

int ans[10001];

void merge_sort(std::vector<int> &arr, int left, int right)
{
	if (left == right)
		return;

	int mid = (left + right)/2;

	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);

	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (arr[i] > arr[j])
		{
			ans[k++] = arr[j++];	
			no_inversions += (j - k);
		}
		else
			ans[k++] = arr[i++];
	}

	while (i <= mid)
		ans[k++] = arr[i++];

	for (i = left; i < k; i++)
		arr[i] = ans[i];

}

int main()
{
	int no_elements;

	std::cout << "Digite o numero de elementos: ";
	std::cin >> no_elements;
	
	std::cout << "Digite os " << no_elements << " numeros desejados:\n";
	std::vector<int> v(no_elements+1);

	for (int i = 1; i <= no_elements; i++)
	{
		std::cin >> v[i];
	}

	merge_sort(v, 1, no_elements);

	std::cout << "O numero total de inversoes eh: " << no_inversions << "\n";

	std::cout << v[1];
	for (int i = 2; i <= no_elements; i++)
		std::cout << " " << v[i];

	std::cout << "\n";
}
