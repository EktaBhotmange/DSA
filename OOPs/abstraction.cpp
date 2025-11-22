#include <iostream>
#include <string>
using namespace std;

class Shape {  //abstract class
    virtual void draw() = 0;  //pure vitual function
};

class Circle : public Shape {
public:
    void draw() {
        cout <<"drawing a circle\n";
    }
};

void fun() {
    static int x = 0;
    cout << x << endl;
    x++;
}

class A {
public:
    int x;

    void incX() {
        x = x + 1;
    }
};

int main() {
    // Circle c1;
    // c1.draw();

    A obj1;
    A obj2;
    obj1.x = 0;
    cout << obj1.x << endl;
    obj1.incX();
    cout << obj1.x << endl;

    return 0;
}


//any object created with the static keyword will persist for lifetime of the program and whenever the function ends it will stay in the memory.