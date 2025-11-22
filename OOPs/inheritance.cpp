#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    // Person() {
    //     cout << "parent constructor\n";
    // }
    ~Person() {       
        cout << "i am the parent destructor\n";
    }
};

class Student : public Person {
public:    
    int rollno;
    
    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }
    void getInfo() {
        cout << "name : " << name << endl;
        cout << "age : " << age << endl;
        cout << "rollno : " << rollno << endl;
    }

    ~Student() {
        cout << "i am the child destructor\n";
    }
};

int main() {
    Student s1("Rahul", 30, 1234);
    
    s1.getInfo();
    return 0;
}