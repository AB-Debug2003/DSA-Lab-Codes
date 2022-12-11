    #include<iostream>
    #include<string>
    using namespace std;

    struct Employee{
        string name;
        int id;
        int salary;
    };

    void DisplayData(Employee var){
        cout << var.name << endl;
        cout << var.id << endl;
        cout << var.salary << endl;
    }

    int main(){
        Employee e1;
        e1.name = "Abdullah";
        e1.id = 215;
        e1.salary = 30000;
        //Pointer of structure
        Employee* e2 = &e1;
        e2->name = "Ali";
        cout << e2->name;
        return 0;
    }