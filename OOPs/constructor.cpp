#include<iostream>
#include<string>
using namespace std;

class Teacher {
private: 
    double salary;
public:
    //properties //atributes
    string name;
    string dept;
    string subject;
    //non-paramitrized constructor
    Teacher() {
        cout << "hii, i am constructor" << endl;
    }
    
    //paramitrized constructor
    Teacher(string name, string dept, string subject, double salary) {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }

    //copy constructor
    Teacher(Teacher &orgObj) {   //pass by referance
        cout << "i am custom copy constructor" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }

    void getInfo() {
        cout << "name : " << name << endl;
        cout << "sub : " << subject << endl; 
    }
};

int main() {
    Teacher t1("merry", "computer science", "c++", 25000);
    // t1.getInfo();

    Teacher t2(t1); //custom copy constructor
    // Teacher t2(t1); //default copy constructor invoked
    t2.getInfo();
    return 0;
}