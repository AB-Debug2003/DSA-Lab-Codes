#include<iostream>
#include<string>
using namespace std;

class Stack {
public:
	int stacksize = 5;
	int top;
	int arr[];
	Stack() 
	{
		top = -1;
		int arr[stacksize];
		for (int i = 0; i < stacksize; i++) 
		{
			arr[i] = 0;
		}
	}

	void setSize()
	{
		cout << "Enter Stack size: ";
		cin >> stacksize;
		arr[stacksize-1];
		for (int i = 0; i < stacksize; i++) 
		{
			arr[i] = 0;
		}
	}

	bool isEmpty() {
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull() 
	{
		if (top == stacksize-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void push(int val) 
	{
		if (isFull()) 
		{
			cout << "Error! Stack overflow" << endl;
		}
		else 
		{
			top++;
			arr[top] = val;
		}
	}

	int pop() 
	{
		if (isEmpty()) 
		{
			cout << "stack underflow" << endl;
			return 0;
		}
		else 
		{
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}
	}

	int count() 
	{
		return (top + 1);
	}

	void display() 
	{
		cout << endl;
		for (int i = stacksize-1; i >= 0; i--) {
			cout << "[" << arr[i] << "]" << endl;
		}
	}
};

class ArrayList{
public:
    int* arr;
    int total;
    int size;

    ArrayList()
    {
        size = 5;
        arr = new int[size];
        total = 0;
    }

	void bubbleSort()
	{
		for (int i = 0; i < total; i++)
		{
			for (int j = 0; j < (total - i - 1); j++)
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
		for (int j = 0; j < ((size) - i - 1); j++)
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

void merge(int arr[], int l, int m, int r, int size)
{
	int i = l;
	int j = m + 1;
	int k = l;

	int temp[size];

	while (i <= m && j <= r) 
	{
		if (arr[i] <= arr[j]) 
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
		else 
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (i <= m) 
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	while (j <= r) 
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	for (int p = l; p <= r; p++) 
	{
		arr[p] = temp[p];
	}
}

void mergeSort(int arr[], int l, int r, int size)
{
	if (l < r) 
	{
		int m = (l + r) / 2;
		mergeSort(arr, l, m, size);
		mergeSort(arr, m + 1, r, size);
		merge(arr, l, m, r, size);
	}
}

void linearSearch(int a[], int n, int size) {
  int temp = -1;

  for (int i = 0; i < size; i++) {
    if (a[i] == n) {
      cout << "Element found at position: " << i + 1 << endl;
      temp = 0;
      break;
    }
  }

  if (temp == -1) {
    cout << "No Element Found" << endl;
  }

}

int binarySearch(int arr[], int left, int right, int x) 
{
	while (left <= right) 
	{
    	int mid = left + (right - left) / 2;

		if (arr[mid] == x) 
		{
			return mid;
		} 
		else if (arr[mid] < x) 
		{
			left = mid + 1;
		} 
		else 
		{
			right = mid - 1;
		}
  	}

  	return -1;
}

int main(){
	int option = 1;
	do
	{
		int data_struct;
		

		cout << "\nSelect a data structure of your choice. Enter 0 to go Sorting Menu." << endl;
		cout << "1. Stack" << endl;
		cout << "2. List" << endl << endl;
		cin >> data_struct;
		Stack* s1 = new Stack();
		ArrayList* a = new ArrayList;
		switch (data_struct)
		{
			case 0:
				break;
				
			case 1:	
				int stackInput, stackValue;
				cout << "---------------------------" << endl;
				cout << "Stack Selected successfully" << endl;
				cout << "---------------------------" << endl;
				s1->setSize();
				do
				{
					cout << "\nSelect Option number. Enter 0 to go to Sorting menu." << endl;
					cout << "1. Push()" << endl;
					cout << "2. Pop()" << endl;
					cout << "3. isEmpty()" << endl;
					cout << "4. isFull()" << endl;
					cout << "5. count()" << endl;
					cout << "6. display()" << endl;
					cout << "7. Clear Screen" << endl << endl;
					cin >> stackInput;
					cout << endl;
					switch (stackInput)
					{
						case 0:
							break;

						case 1:
							cout << "--Push Function--" << endl;
							cout << "Enter a value to push: ";
							cin >> stackValue;
							s1->push(stackValue);
							break;

						case 2:
							cout << "--Pop Function--" << endl;
							cout << "Enter a value to pop: ";
							cout << "Poped Value:" << s1->pop();
							break;

						case 3:
							if (s1->isEmpty())
							{
								cout << "Stack is Empty!" << endl;
							}
							else
							{
								cout << "Stack is not Empty!" << endl;
							}
							break;

						case 4:
							if (s1->isFull())
							{
								cout << "Stack is full!" << endl;
							}
							else
							{
								cout << "Stack is not Full!" << endl;
							}
							break;

						case 5:
							cout << "Count = " << s1->count();
							break;

						case 6:
							cout << "--Stack Display--" << endl;
							s1->display();
							break;

						case 7:
							system("cls");
							break;

						default:
							cout << "Error! Enter correct option number" << endl;
							break;
					}
				}while(stackInput != 0);
				break;

			case 2:
				int listInput, listValue, newValue;
				cout << "--------------------------" << endl;
				cout << "List Selected successfully" << endl;
				cout << "--------------------------" << endl;
				do
				{
					cout << "\nSelect Option number. Enter 0 to go to searching menu." << endl;
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
							cout << "--Insert Function--" << endl;
							cout << "Enter a value to insert:";
							cin >> listValue;
							a->insert(listValue);
							break;

						case 2:
							cout << "--Delete Function--" << endl;
							cout << "Enter a value to delete:";
							cin >> listValue;
							a->remove(listValue);
							break;

						case 3:
							cout << "--Find Function--" << endl;
							cout << "Enter a value to find:";
							cin >> listValue;
							if (a->find(listValue) != -1)
							{
								cout << "Value Found at position " << a->find(listValue) + 1 << endl;
							}
							else
							{
								cout << "Value Not Found!" << endl;
							}
							break;

						case 4:
							cout << "--Update Function--" << endl;
							cout << "Enter a value to update:";
							cin >> listValue;
							cout << "Enter new Value: ";
							cin >> newValue;
							a->update(listValue, newValue);
							break;

						case 5:
							cout << "--Clear List Function--" << endl;
							a->clear();
							break;

						case 6:
							cout << "--Display Function--" << endl;
							a->display();
							break;

						case 7:
							system("cls");

						default:
							break;
					}
				}while(listInput != 0);
			break;

			default:
				cout << "Enter a valid Option Number" << endl;
				break;
		}

		int sortOption;
		do
		{
			cout << "\nEnter an option. Enter 0 to go to Searching Menu" << endl;
			cout << "1. Bubble Sort" << endl;
			cout << "2. Merge Sort" << endl << endl;
			cin >> sortOption;
			switch (sortOption)
			{
			case 0:
				break;
			
			case 1:
				cout << "------------------------" << endl;
				cout << "Bubble Sorting Your Data" << endl;
				cout << "------------------------" << endl;
				if (data_struct == 1)
				{
					bubbleSort(s1->arr, s1->top);
					cout << "Data Sorted!" << endl;
					s1->display();
				}
				else
				{
					bubbleSort(a->arr, a->total);
					cout << "Data Sorted" << endl;
					a->display();
				}
				break;

			case 2:
				cout << "-----------------------" << endl;
				cout << "Merge Sorting Your Data" << endl;
				cout << "-----------------------" << endl;
				if (data_struct == 1)
				{
					mergeSort(s1->arr,0, s1->top, s1->top);
					cout << "Data Sorted!" << endl;
					s1->display();
				}
				else
				{
					mergeSort(a->arr, 0, a->total-1, a->total);
					cout << "Data Sorted" << endl;
					a->display();
				}
				break;

			default:
				break;
			}			
		} while (sortOption != 0);

		int searchOption;
		int num;
		do
		{
			cout << "\nEnter an option. Enter 0 to go to main menu" << endl;
			cout << "1. Linear Search" << endl;
			cout << "2. Binary Search" << endl;
			cin >> searchOption;
			switch (searchOption)
			{
			case 0:
				break;
			
			case 1:
				cout << "----------------" << endl;
				cout << "Linear Searching" << endl;
				cout << "----------------" << endl;
				cout << "Enter a Value to search:";
				cin >> num;
				if (data_struct == 1)
				{
					linearSearch(s1->arr, num, s1->top+1);
				}
				else
				{
					linearSearch(a->arr, num, a->total);
				}
				break;

			case 2:
				cout << "----------------" << endl;
				cout << "Binary Searching" << endl;
				cout << "----------------" << endl;
				cout << "Enter a Value to search:";
				cin >> num;
				if (data_struct == 1)
				{
					int output = binarySearch(s1->arr, 0, s1->top+1, num);
					if (output == -1) 
					{
						cout << "No Match Found" << endl;
					} 
					else 
					{
						cout << "Match found at position: " << output << endl;
					}
				}
				else
				{
					int output = binarySearch(a->arr, 0, a->total, num);
					if (output == -1) 
					{
						cout << "No Match Found" << endl;
					} 
					else 
					{
						cout << "Match found at position: " << output+1 << endl;
					}
					
				}
				break;

			default:
				cout << "Error! Enter a valid option number" << endl;
				break;
			}
		} while (searchOption != 0);
		
		

	cout << "\nDo you Want to run the program again?" << endl;
	cout << "0. No" << endl;
	cout << "1. Yes" << endl;
	cin >> option;

	}while (option != 0);

	cout << "------------" << endl;
	cout << "Program Exit" << endl;
	cout << "------------" << endl;
	return 0;
}