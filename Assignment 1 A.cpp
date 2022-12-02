#include <bits/stdc++.h>
using namespace std;
class Sack
{
	public:
		float price, weight, ratio;
};
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}
void mergeSortedArray(Sack arr[], int begin, int mid, int end)
{
	int i = 0, j = 0, k = begin;
	int n1 = mid - begin + 1;
	int n2 = end - mid;
	Sack a[n1], b[n2];
	while (i < n1)
	{
		a[i] = arr[k];
		i++;
		k++;
	}
	while (j < n2)
	{
		b[j] = arr[k];
		j++;
		k++;
	}	
	i = 0, j = 0, k = begin;
	while (i < n1 && j < n2){
		if (a[i].ratio > b[j].ratio)
		{
			arr[k] = a[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = b[j];
			j++;
			k++;
		}
	}
	while (i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}
void mergeSort(Sack arr[], int begin, int end)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		mergeSort(arr, begin, mid);
		mergeSort(arr, mid + 1, end);
		mergeSortedArray(arr, begin, mid, end);
	}
}
int main()
{
	int capacity, n;
	cout << "Enter the Capacity of Sack: ";
	cin >> capacity;
	cout << "Enter the N Item you want in Sack: ";
	cin >> n;
	Sack item[n];
	float arr[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++)
	{
		cout <<"=============================================================" << endl;
		cout << "Enter the Price of Item No. " << i + 1 << ": ";
		cin >> item[i].price;
		cout << "Enter the Weight of Item No. " << i + 1 << ": ";
		cin >> item[i].weight;
	}
	for (int i = 0; i < n; i++)
		item[i].ratio = item[i].price / item[i].weight;	
	cout << "\n\n\nBefore Sorting Sack in Descending Order: " << endl;
	cout << " " << endl;
	cout << "Price\t\t";
	for (int i = 0; i < n; i++)
		cout << item[i].price << "\t";
	cout << "\n=============================================================" << endl;
	cout << "Weight\t\t";
	for (int i = 0; i < n; i++)
		cout << item[i].weight << "\t";
	cout << "\n=============================================================" << endl;
	cout << setprecision(4) << "Ratio\t\t";
	for (int i = 0; i < n; i++)
		cout << item[i].ratio << "\t";
	cout << endl<< endl;
	mergeSort(item, 0, n - 1);
	float totalProfit = 0.0;
	for (int i = 0; i < n; i++)
	{
		if (capacity - item[i].weight >= 0)
		{
			totalProfit = totalProfit + item[i].price;
			capacity = capacity - item[i].weight;
			arr[i] = 1;
		}
		else
		{
			totalProfit = totalProfit + ((capacity) / (item[i].weight) *item[i].price);
			arr[i] = (capacity / item[i].weight);
			break;
		}
	}
	cout << "After Sorting Sack in Descending Order: " << endl;
	cout << " " << endl;
	cout << "Price\t\t";
	for (int i = 0; i < n; i++)
		cout << item[i].price << "\t";
	cout << "\n=============================================================" << endl;
	cout << "Weight\t\t";
	for (int i = 0; i < n; i++)
		cout << item[i].weight << "\t";
	cout << "\n=============================================================" << endl;
	cout << "Ratio\t\t";
	for (int i = 0; i < n; i++)
		cout << setprecision(4) << item[i].ratio << "\t";
	cout << "\n\n=============================================================\n"<< endl;
	cout << "\nSelected\t";
	for (int i = 0; i < n; i++)
		cout << setprecision(4) << arr[i] << "\t";
	cout << "\n\nMaximum profit is: " << totalProfit << endl;
	cout <<"=============================================================" << endl;
return 0;
}
/*
	Enter the Capacity of Sack: 60
	Enter the N Item you want in Sack: 4
	=============================================================
	Enter the Price of Item No. 1: 100
	Enter the Weight of Item No. 1: 10
	=============================================================
	Enter the Price of Item No. 2: 280
	Enter the Weight of Item No. 2: 40
	=============================================================
	Enter the Price of Item No. 3: 120
	Enter the Weight of Item No. 3: 20
	=============================================================
	Enter the Price of Item No. 4: 120
	Enter the Weight of Item No. 4: 24

	Before Sorting Sack in Descending Order:
	Price           100     280     120     120
	=============================================================
	Weight          10      40      20      24
	=============================================================
	Ratio           10      7       6       5

	After Sorting Sack in Descending Order:
	Price           100     280     120     120
	=============================================================
	Weight          10      40      20      24
	=============================================================
	Ratio           10      7       6       5
	=============================================================

	Selected        1       1       0.5     0
	Maximum profit is: 440
*/
