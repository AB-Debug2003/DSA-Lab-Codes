#include<iostream>
#include<string>
using namespace std;

class ItemInfo{
	string productName, RFIDTagNumber;
	double price;
	string originalLocation;
	string currentLocation;

	bool checkRFID(string RFID){
		bool flag;
		if (RFID.length() == 9)
		{
			for (int i = 0; i < RFID.length(); i++)
			{
				if ((RFID[i] >= 0 || RFID[i] <= 9) || (RFID[i] == 'A' || RFID[i] == 'B' || RFID[i] == 'C' || RFID[i] == 'D' || RFID[i] == 'E' || RFID[i] == 'F'))
				{
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
		}
		else
		{
			flag = false;
		}
		return flag;
	}

	bool checkOriginalLocation(string originalLocation)
	{
		bool flag;
		if (originalLocation.length() == 6)
		{
			if (originalLocation[0] == 's')
			{
				for (int i = 1; i < originalLocation.length(); i++)
				{
					if (originalLocation[i] >=0 || originalLocation[i] <=9)
					{
						flag = true;
					}
					else
					{
						flag = false;
					}
				}
			}
			else
			{
				flag = false;
			}
		}

		else
		{
			flag = false;
		}
		return flag;
	}


	bool checkCurrentLocation(string currentLocation)
	{
		bool flag;
		if ((currentLocation == originalLocation) || (currentLocation == "out"))
		{
			flag = true;
		}
		else if(currentLocation[0] == 'c' && currentLocation.length() == 4)
		{
			for (int i = 1; i < originalLocation.length(); i++)
			{
				if (currentLocation[i] >=0 || currentLocation[i] <=9)
				{
					flag = true;
				}
				else
				{
					flag = false;
				}
			}
		}
		
		else
		{
			flag = false;
		}

		return flag;
	}

public:
	ItemInfo(){
		productName = "";
		RFIDTagNumber = "";
		price = 0.00;
		originalLocation = "";
		currentLocation = "";
	}

	ItemInfo(string productName, string RFIDTagNumber, double price, string originalLocation, string currentLocation){
		this->productName = productName;
		this->price = price;

		// Validate RFID Format
		if(checkRFID(RFIDTagNumber))
		{
			this->RFIDTagNumber = RFIDTagNumber;
		}
		else
		{
			cout << "Error! Enter a valid 9 character hexadecimal format RFID Tag Number" << endl;
		}

		//Validate Original Location Format
		if (checkOriginalLocation(originalLocation))
		{
			this->originalLocation = originalLocation;
		}
		else
		{
			cout << "Error! Enter a valid 6 character Original Location followed by 's'(sXXXXX)" << endl;
		}

		this->currentLocation = originalLocation;
		if (checkCurrentLocation(currentLocation))
		{
			this->currentLocation = currentLocation;
		}
		else
		{
			cout << "Error! Enter a valid Current Location (cXXX)" << endl;
		}
		
	}

	string getProdName()
	{
		return productName;
	}

	string getRFID()
	{
		return RFIDTagNumber;
	}

	double getPrice()
	{
		return price;
	}

	string getOriginalLocation()
	{
		return originalLocation;
	}

	string getCurrentLocation()
	{
		return currentLocation;
	}

	void setProductName(string productName)
	{
		this->productName = productName;
	}

	void setRFID(string RFID)
	{
		if (checkRFID(RFID))
		{
			this->RFIDTagNumber = RFID;
		}
		else
		{
			cout << "Error! Enter a valid 9 character hexadecimal format RFID Tag Number." << endl;
		}
	}

	void setPrice(double price)
	{
		this->price = price;
	}

	void setOriginalLocation(string originalLocation)
	{
		if (checkOriginalLocation(originalLocation))
		{
			this->originalLocation = originalLocation;
			this->currentLocation = currentLocation;
		}
		else
		{
			cout << "Error! Enter a valid 6 character Original Location followed by 's'(sXXXXX)" << endl;
		}
	}

	void setCurrentLocation(string currentLocation)
	{
		if (checkCurrentLocation(currentLocation))
		{
			this->currentLocation = currentLocation;
		}
		else
		{
			cout << "Error! Enter a valid Current Location (cXXX)" << endl;
		}
	}
};

class ItemInfoNode{
	ItemInfo* obj;
	ItemInfo* prevObj;
	ItemInfo* nextObj;

public:
	ItemInfoNode()
	{
		this->obj = NULL;
		this->prevObj = NULL;
		this->nextObj = NULL;
	}
	ItemInfoNode(ItemInfo* obj, ItemInfo* prevObj, ItemInfo* nextObj){
		this->obj = obj;
		this->prevObj = prevObj;
		this->nextObj = nextObj;
	}

	void setObj(ItemInfo* obj)
	{
		this->obj = obj;
	}

	void setprevObj(ItemInfo* prevObj)
	{
		this->prevObj = prevObj;
	}

	void setnextObj(ItemInfo* nextObj)
	{
		this->nextObj = nextObj;
	}

	ItemInfo* getObj()
	{
		return obj;
	}

	ItemInfo* getprevObj()
	{
		return prevObj;
	}

	ItemInfo* getnextObj()
	{
		return nextObj;
	}
};

class ItemList{
	ItemInfoNode* head;
	ItemInfoNode* tail;

public:
	ItemList()
	{
		head = NULL;
		tail = NULL;
	}

	ItemList(ItemInfoNode* n)
	{
		head = n;
	}
	void insertInfo(string name, string RFID, double price, string originalPosition)
	{
		head->setObj(new ItemInfo(name, RFID, price, originalPosition, originalPosition));
	}
};

class DepartmentalStore{
	char option;
	public:
	DepartmentalStore()
	{
		cout << "Welcome!" << endl;
		cout << "C - Clean Store" << endl;
		cout << "I - Insert an item into list" << endl;
		cout << "L - List by Location" << endl;
		cout << "M - Move an item in the store" << endl;
		cout << "O - Checkout" << endl;
		cout << "P - Print all items in store" << endl;
		cout << "R - Print by RFID tag number" << endl;
		cout << "U - Update Inventory system" << endl;
		cout << "Q - Exit Program" << endl;

		cout << "Please Select an option: ";
		cin >>option;
		switch (option)
		{
		case 'C':
			/* code */
			break;
		
		default:
			break;
		}
	}
};

int main(){
	string name, RFID, Location;
	double price;
	cout << "Enter a Product Name: ";
	cin >> name;
	cout << "\nEnter RFID Tag Number: ";
	cin >> RFID;
	cout << "\nEnter Price: ";
	cin >> price;
	cout << "\nEnter Location: ";
	cin >> Location;
	ItemList* i1 = new ItemList;
	i1->insertInfo(name, RFID, price, Location);
	

	return 0;
}