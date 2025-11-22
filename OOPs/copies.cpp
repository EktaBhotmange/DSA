#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaPtr = new double; //allocating new mwmory to the poinetr 
        *cgpaPtr = cgpa;
    }
    
    //constructor
    Student(Student &obj) {
        this->name = obj.name;
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    //destructor 
    ~Student() {
        cout << "hii, i delete everything";
        delete cgpaPtr; //imp step to free up the space in memory
    }

    void getInfo() {
        cout << "name : " << name << endl;
        cout << "cgpa : " << *cgpaPtr << endl;
    }
};

int main() {
    // Student s1("Rahul Kumar", 8.9);
    // Student s2(s1);

    // s1.getInfo();
    // *(s2.cgpaPtr) = 9.2;
    // s1.getInfo();

    // s2.getInfo();

    Student s1("rahul kumar", 8.9);
    s1.getInfo();
    return 0;
}