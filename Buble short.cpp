#include <iostream>
using namespace std;

void Swap_two_numbers(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int a[7] = { 15, 6, 83, 19, 9, 02, 12 }, i, j, k;

	k = sizeof(a) / sizeof(a[0]);

	cout << "Before swap ";
	for (i = 0; i < k; i++)
	{
		cout << a[i] << "\t";
	}

	for (i = 0; i < k-1; i++)
	{
		for (j = 0; j < k-i-1; j++)
		{
			if (a[j] < a[j+1])
			{
				Swap_two_numbers(&a[j], &a[j+1]);
			}
		}
	}
	
	cout << "\nAfter swap ";
	for (i = 0; i < k; i++)
	{
		cout << a[i] << "\t";
	}
}