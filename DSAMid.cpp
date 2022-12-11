#include<iostream>
#include<string>
using namespace std;

class Stack {
private:
	int top;
	int arr[5];
public:
	Stack() {
		top = -1;
		for (int i = 0; i < 5; i++) {
			arr[i] = 0;
		}
	}

	bool isEmpty() {
		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull() {
		if (top == 4)
			return true;
		else
			return false;
	}

	void push(int val) {
		if (isFull()) {
			cout << "stack overflow" << endl;
		}
		else {
			top++;
			arr[top] = val;
		}
	}

	int pop() {
		if (isEmpty()) {
			cout << "stack underflow" << endl;
			return 0;
		}
		else {
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int count() {
		return (top + 1);
	}

	void display() {
		cout << "All values in the Stack are " << endl;
		for (int i = 4; i >= 0; i--) {
			cout << arr[i] << endl;
		}
	}
};

class ArrayList{
    int* arr;
    int total;
    int size;

public:
    ArrayList()
    {
        size = 5;
        arr = new int;
        total = 0;
    }

    void insert(int value)
    {
        if (isFull())
        {
            cout << "Full" << endl;
        }
        else
        {
            arr[total] = value;
            total++;
        }
        
    }

    bool isFull()
    {
        if (total == size)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void display()
    {
        cout << "[";
        for (int i = 0; i < total; i++)
        {
            cout << arr[i] << " " <<;
        }
        cout << "]" << endl;
    }
};

void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < (size - i - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void merge(int arr[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	/* create temp array */
	int temp[5];

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		else {
			temp[k] = arr[j];
			j++;
			k++;
		}

	}

	/* Copy the remaining elements of first half, if there are any */
	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;

	}

	/* Copy the remaining elements of second half, if there are any */
	while (j <= right) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	/* Copy the temp array to original array */
	for (int p = left; p <= right; p++) {
		arr[p] = temp[p];
	}
}

/* left is for left index and right is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		// find midpoint
		int mid = (left + right) / 2;

		// recurcive mergesort first and second halves 
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// merge
		merge(arr, left, mid, right);
	}
}

int main(){
	int option = 'y';
	int data_struct;
	do
	{
		cout << "Select a data structure of your choice or 0 to exit menu" << endl;
		cout << "1. Stack" << endl;
		cout << "2. List" << endl;
		cin >> data_struct;
		switch (data_struct)
		{
			case 0:
				break;
			case 1:
				Stack s1;
				int input, value;
				cout << "Stack Selected successfully!" << endl;
				cout << "What operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
				cout << "1. Push()" << endl;
				cout << "2. Pop()" << endl;
				cout << "3. isEmpty()" << endl;
				cout << "4. isFull()" << endl;
				cout << "5. count()" << endl;
				cout << "6. display()" << endl;
				cout << "7. Clear Screen" << endl << endl;
				cin >> input;
				switch (input)
				{
					case 0:
						break;

					case 1:
						cout << "------Push Function-----" << endl;
						cout << "Enter a value to push: ";
						cin >> value;
						s1.push(value);
						break;

					case 2:
						cout << "-----Pop Function-----" << endl;
						cout << "Enter a value to pop: ";
						cout << "Poped Value:" << s1.pop();
						 break;

					case 3:
						if (s1.isEmpty())
						{
							cout << "Stack is Empty!" << endl;
						}
						else
						{
							cout << "Stack is not Empty!" << endl;
						}
						break;

					case 4:
						if (s1.isFull())
						{
							cout << "Stack is full!" << endl;
						}
						else
						{
							cout << "Stack is not Full!" << endl;
						}
						break;

					case 5:
						cout << "Count = " << s1.count();
						break;

					case 6:
						s1.display();
						break;

					case 7:
						system("cls");
						break;

					default:
						cout << "Error! Enter correct option number" << endl;
						break;
				}
				break;
			case 2:
				int input, value;
				cout << "List Selected successfully!" << endl;

			default:
				cout << "Enter a valid Option Number" << endl;
				break;
		}


		cin >> option;
	} 
	while (option == 'y');
	return 0;
}