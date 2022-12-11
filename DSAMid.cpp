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
        arr = new int[size];
        total = 0;
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

    bool isEmpty()
    {
        if (total == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int value)
    {
        if (isFull())
        {
            size *= 2;
            int* temp = new int[size];
            for (int i = 0; i < total; i++)
            {
                temp[i] = arr[i];
            }
            delete []arr;
            arr = temp;
            insert(value);
        }
        else
        {
            arr[total] = value;
            total++;
        }
        
    }

    int find(int val)
    {
        for (int i = 0; i < total; i++)
        {
            if (arr[i] == val)
            {
                return i;
                break;
            }
        }
        return -1;
    }

    void update(int value, int newValue)
    {
        if (find(value) != -1)
        {
            arr[find(value)] = newValue;
            cout << "Value Updated!" << endl;
        }
        else
        {
            cout << "Value Not Found" << endl;
        }
        
    }

    void remove(int value)
    {
        if (isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            int index = find(value);
            //last value
            if (arr[index] == arr[total-1])
            {
                total--;
                cout << "Value Deleted" << endl;
            }
            else
            {
                for (int i = index; i < total-1; i++)
                {
                    arr[i] = arr[i+1];
                }
                total--;
                cout << "Value Deleted" << endl;
            }
        }
    }

    void clear()
    {
        total = 0;
        size = 5;
        delete []arr;
        arr = new int[size];
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "List is Empty" << endl;
        }
        else
        {
            cout << "[ ";
            for (int i = 0; i < total; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "]" << endl;
        }
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
		do
		{
			cout << "Select a data structure of your choice or 0 to exit menu" << endl;
			cout << "1. Stack" << endl;
			cout << "2. List" << endl << endl;
			cin >> data_struct;
			switch (data_struct)
			{
				case 0:
					break;
					
				case 1:
					{
						Stack s1;
						int stackInput, stackValue;
						cout << "Stack Selected successfully!" << endl;
						do
						{
							cout << "Select Option number. Enter 0 to exit." << endl;
							cout << "1. Push()" << endl;
							cout << "2. Pop()" << endl;
							cout << "3. isEmpty()" << endl;
							cout << "4. isFull()" << endl;
							cout << "5. count()" << endl;
							cout << "6. display()" << endl;
							cout << "7. Clear Screen" << endl << endl;
							cin >> stackInput;
							switch (stackInput)
							{
								case 0:
									break;

								case 1:
									cout << "------Push Function-----" << endl;
									cout << "Enter a value to push: ";
									cin >> stackValue;
									s1.push(stackValue);
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
						}while(stackInput != 0);
					}
					break;

				case 2:
					{
						ArrayList a;
						int listInput, listValue, newValue;
						cout << "List Selected successfully!" << endl;
						do
						{
							cout << "Select Option number. Enter 0 to exit." << endl;
							cout << "1. Insert()" << endl;
							cout << "2. Delete()" << endl;
							cout << "3. Find()" << endl;
							cout << "4. Update()" << endl;
							cout << "5. Clear List()" << endl;
							cout << "6. Display()" << endl;
							cout << "7. Clear Screen" << endl << endl;
							cin >> listInput;
							switch (listInput)
							{
								case 0:
									break;

								case 1:
									cout << "----Insert Function----" << endl;
									cout << "Enter a value to insert:";
									cin >> listValue;
									a.insert(listValue);
									break;

								case 2:
									cout << "----Delete Function----" << endl;
									cout << "Enter a value to delete:";
									cin >> listValue;
									a.remove(listValue);
									break;

								case 3:
									cout << "----Find Function----" << endl;
									cout << "Enter a value to find:";
									cin >> listValue;
									if (a.find(listValue) != -1)
									{
										cout << "Value Found at position " << a.find(listValue) + 1 << endl;
									}
									else
									{
										cout << "Value Not Found!" << endl;
									}
									break;

								case 4:
									cout << "----Update Function----" << endl;
									cout << "Enter a value to update:";
									cin >> listValue;
									cout << "Enter new Value: ";
									cin >> newValue;
									a.update(listValue, newValue);
									break;

								case 5:
									cout << "----Clear List Function----" << endl;
									a.clear();
									break;

								case 6:
									cout << "----Display Function----" << endl;
									a.display();
									break;

								case 7:
									system("cls");

								default:
									break;
							}
						}while(listInput != 0);
					}
					break;

					default:
						cout << "Enter a valid Option Number" << endl;
						break;
			}
		}while(data_struct != 0);

		cout << "Do you want to run program again?" << endl;
		cout << "'y' = Yes" << endl;
		cout << "'n' = No" << endl << endl;
		cin >> option;
		
	}while (option == 'y');
	return 0;
}