#include < iostream >
using namespace std;

void bubbleSort(int a[]) {
	for (int i = 0; i < 10; i++) 
	{
		for (int j = 0; j < (10 - i - 1); j++) 
		{
			if (a[j] > a[j + 1]) 
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int binarySearch(int arr[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == x) {
			return mid;
		}
		else if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}

int main() {
	int arr[10];

	cout << "Enter 10 integers in any order: " << endl;
	for (int i = 0; i < 10; i++) 
	{
		cin >> arr[i];
	}

	cout << "Before Sorting" << endl;
	cout << "[";
	for (int i = 0; i < 10; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

	bubbleSort(arr);

	cout << endl << "After Sorting" << endl;
	cout << "[";
	for (int i = 0; i < 10; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;

	int num;
	cout << endl << "Please enter an element to search" << endl;
	cin >> num;

	int left = 0;
	int right = 9;

	int output = binarySearch(arr, left, right, num);

	if (output == -1) {
		cout << "No Match Found" << endl;
	}

	else {
		cout << "Match found at position: " << output << endl;
	}


	cout << endl;
	return 0;
}