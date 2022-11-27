#include<iostream>
#include<string>
using namespace std;

class Student{

private:
    string name, std_ID, program;
    int semester, age;
    int marks[5] = {};
    double gpa;

public:
    Student(){};

    Student(string name, string std_ID, string program, int semester, int age, double gpa )
    {
        this->name = name;
        this->std_ID = std_ID;
        this->program = program;
        this->semester = semester;
        this->age = age;
        cout << "Enter marks of 5 subjects: " << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
        this->gpa = gpa;
    }

    Student(Student &obj)
    {
        name = obj.name;
        std_ID = obj.std_ID;
        program = obj.program;
        semester = obj.semester;
        age = obj.age;
        for (int i = 0; i < 5; i++)
        {
            marks[i] = obj.marks[i];
        }
        gpa = obj.gpa;
    }

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getStd_ID()
    {
        return std_ID;
    }

    void setStd_ID(string std_ID)
    {
        this->std_ID = std_ID;
    }

    int getSemester()
    {
        return semester;
    }

    void setSemester(int semester)
    {
        this->semester = semester;
    }

    string getProgram()
    {
        return program;
    }

    void setProgram(string program)
    {
        this->program = program;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    double getGPA()
    {
        return gpa;
    }

    void setGPA(double gpa)
    {
        this->gpa = gpa;
    }

    double calCGPA()
    {
        double sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum = sum + marks[i];
        }
        
        return sum/50;
    }

    double calAverage()
    {
        double total = 0;
        for (int i = 0; i < 5; i++)
        {
            total = total + marks[i];
        }
        
        return ((total/250) * 100);
    }
};

int main(){
    cout << "--------Student 1--------" << endl;
    Student s1("Usama","F2021266066","BSCS",3,19,3.57);
    cout << "Name: " << s1.getName() << endl;
    cout << "Std ID: " << s1.getStd_ID() << endl;
    cout << "Program: " << s1.getProgram() << endl;
    cout << "Semester: " << s1.getSemester() << endl;
    cout << "Age: " << s1.getAge() << endl;
    cout << "GPA: " << s1.getGPA() << endl;
    cout << "CPGA: " << s1.calCGPA() << endl;
    cout << "Average: " << s1.calAverage() << endl;


    cout << "--------Student 2--------" << endl;
    Student s2;
    //Copy Constructor called
    s2 = s1;
    cout << "Name: " << s2.getName() << endl;
    cout << "Std ID: " << s2.getStd_ID() << endl;
    cout << "Program: " << s2.getProgram() << endl;
    cout << "Semester: " << s2.getSemester() << endl;
    cout << "Age: " << s2.getAge() << endl;
    cout << "GPA: " << s2.getGPA() << endl;
    cout << "CPGA: " << s2.calCGPA() << endl;
    cout << "Average: " << s2.calAverage() << endl;
    return 0;
}