#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;

    Student() {
        cout << "non-paramitrized\n" << endl;
    }

    Student(string name) {
        this->name = name;
        cout << "paramitrized\n" << endl;
    }
};

//compile time polymorphism 
class Print {
public: 
    void show(int x) {
        cout << "int : " << x << endl;
    }

    void show(char ch) {
        cout << "char : " << ch << endl;
    }
};

//runtime polymorphism
class Parent {
public:
    void getInfo() {
        cout << "parent class\n";
    }

    virtual void hello() {
        cout << "hello from parent\n";
    }
};
class Child : public Parent {
public:
    void getInfo() {
        cout << "child class\n";
    }

    void hello() {
        cout << "hello from child\n";
    }
};

int main() {
    // Student s1("tony stark");
    // Print p1;
    // p1.show('&');

    // Parent p;
    // p.getInfo();

    Child c1;
    c1.hello();
    return 0;
}