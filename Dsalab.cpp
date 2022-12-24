#include<iostream>
#include<string>
using namespace std;

class Queue{
public:
	int front, rear;
	int arr[8];


	Queue()
	{
		front = -1;
		rear = -1;
		for (int i = 0; i < 8; i++)
		{
			arr[i] = 0;
		}
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
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
		if (rear == 8)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	void enQueue(int value)
	{
		if (isFull())
		{
			cout << "Queue is Full" << endl;
		}

		else
		{
			front = 0;
			rear++;
			arr[rear] = value;
			cout << "Value Enqueued!" << endl;
		}
	}

	int deQueue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
		}

		else if (front == rear)
		{
			arr[front] = 0;
			front--;
			rear--;
		}

		else
		{
			int deqVal = arr[front];
			arr[front] = 0;
			front++;
			return deqVal;
		}
	}

	int count()
	{
		return(rear - front + 1);
	}

	void display()
	{
		cout << "All values in Queue are" << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << arr[i] << "  ";
		}
	}
};
class Array{
public:
	int arr[8];
	int total;

	Array()
	{
		total = 0;
	}

	bool isFull()
	{
		if (total == 8)
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
			cout << "Error! Array is Full!" << endl;
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
			if (arr[index] == arr[total - 1])
			{
				total--;
				cout << "Value Deleted" << endl;
			}
			else
			{
				for (int i = index; i < total - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				total--;
				cout << "Value Deleted" << endl;
			}
		}
	}

	void display()
	{
		if (isEmpty())
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

int Partition(int arr[], int s, int e)
{
	int pivot = arr[e];
	int pIndex = s;

	for (int i = s; i<e; i++)
	{
		if (arr[i]<pivot)
		{
			int temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex++;
		}
	}

	int temp = arr[e];
	arr[e] = arr[pIndex];
	arr[pIndex] = temp;

	return pIndex;
}

void QuickSort(int arr[], int s, int e)
{
	if (s<=e)
	{
		int p = Partition(arr, s, e);
		QuickSort(arr, s, (p - 1));
		QuickSort(arr, (p + 1), e);
	}
}

int binarySearch(int arr[], int left, int right, int n)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == n)
		{
			return mid;
		}

		else if (arr[mid] < n)
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
	char option = 'y';
	do
	{
		Array a1;
		Queue q1;
		int dataStruct;
		cout << "\nSelect a data structure of your choice" << endl;
		cout << "1: Array" << endl;
		cout << "2: Queue" << endl;
		cin >> dataStruct;
		switch (dataStruct)
		{
		case 0:
			break;
		case 1:
			cout << "--------------" << endl;
			cout << "Array Selected" << endl;
			cout << "--------------" << endl;
			int arrayInput, value, newValue;
			do
			{
				cout << "\nSelect Option number. Enter 0 to go searching menu" << endl;
				cout << "1. Insert()" << endl;
				cout << "2. Delete()" << endl;
				cout << "3. Update()" << endl;
				cout << "4. Display()" << endl;
				cout << "5. isFull()" << endl;
				cout << "6. isEmpty()" << endl;
				cout << "7. Clear Screen" << endl << endl;
				cin >> arrayInput;
				switch (arrayInput)
				{
				case 0:
					break;
				case 1:
					cout << "--Insert Function--" << endl;
					cout << "Enter a value to insert:";
					cin >> value;
					a1.insert(value);
					break;

				case 2:
					cout << "--Delete Function--" << endl;
					cout << "Enter a value to delete:";
					cin >> value;
					a1.remove(value);
					break;
				
				case 3:
					cout << "--Update Function--" << endl;
					cout << "Enter a value to update:";
					cin >> value;
					cout << "Enter new Value: ";
					cin >> newValue;
					a1.update(value, newValue);
					break;

				case 4:
					cout << "--Display Function--" << endl;
					a1.display();
					break;

				case 5:
					if (a1.isFull())
					{
						cout << "Array is Full" << endl;
					}
					else
					{
						cout << "Array is not full" << endl;
					}
					break;

				case 6:
					if (a1.isEmpty())
					{
						cout << "Array is Empty" << endl;
					}
					else
					{
						cout << "Array is not Empty" << endl;
					}
					break;
				case 7:
					system("cls");
					break;
				default:
					cout << "Enter a valid option number" << endl;
					break;
				}
			} while (arrayInput != 0);
			break;

		case 2:
			int queueInput, queueValue;
			cout << "--------------" << endl;
			cout << "Queue Selected" << endl;
			cout << "--------------" << endl;
			do
			{
				cout << "\nSelect Option number. Enter 0 to go to searching menu." << endl;
				cout << "1. Enqueue()" << endl;
				cout << "2. Dequeue()" << endl;
				cout << "3. isEmpty()" << endl;
				cout << "4. isFull()" << endl;
				cout << "5. count()" << endl;
				cout << "6. display()" << endl;
				cout << "7. Clear Screen" << endl << endl;
				cin >> queueInput;
				cout << endl;
				switch (queueInput)
				{
				case 0:
					break;
				case 1:
					cout << "--Enqueue Function--" << endl;
					cout << "Enter a value to enqueue: ";
					cin >> queueValue;
					q1.enQueue(queueValue);
					break;

				case 2:
					cout << "--Dequeue Function--" << endl;
					cout << "Enter a value to Dequeue: ";
					cout << "Dequeued Value:" << q1.deQueue();
					break;

				case 3:
					if (q1.isEmpty())
					{
						cout << "Queue is Empty" << endl << endl;
					}

					else
					{
						cout << "Queue is Not Empty" << endl << endl;
					}
					break;

				case 4:
					if (q1.isFull())
					{
						cout << "Queue is Full" << endl << endl;
					}

					else
					{
						cout << "Queue is Not Full" << endl << endl;
					}
					break;

				case 5:
					cout << "Count: " << q1.count() << endl << endl;
					break;

				case 6:
					q1.display();
					cout << endl << endl;
					break;
				
				case 7:
					system("cls");
					break;

				default:
					cout << "Enter a valid option number" << endl;
					break;
				}
			} while (queueInput != 0);
			break;

		default:
			cout << "Enter a valid option number" << endl;
			break;
		}

		if (dataStruct == 1)
		{
			QuickSort(a1.arr, 0, a1.total-1);
			cout << "Data Structure Sorted!" << endl;
			a1.display();

		}

		else
		{
			cout << "Queue cannot be sorted" << endl;
			/*QuickSort(q1.arr, 0, q1.rear);
			cout << "Data Structure Sorted!" << endl;
			q1.display();*/
		}

		char searchOption = 'y';
		int num;
		do
		{
			if (dataStruct == 1)
			{
				cout << "Enter a value to search"<< endl;
				cin >> num;
				cout << "Element Present at position " << binarySearch(a1.arr, 0, a1.total, num) +1 << endl;
			}
			else
			{
				break;
			}
			cout << "\nDo you want run search again?" << endl;
			cout << "y: Yes" << endl;
			cout << "n: No" << endl;
			cin >> searchOption;
		} while (searchOption != 'n');


		cout << "Do you want run program again?" << endl;
		cout << "y: Yes" << endl;
		cout << "n: No" << endl;
		cin >> option;
	} while (option != 'n');

	return 0;
}
