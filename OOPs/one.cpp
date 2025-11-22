#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Teacher {
private: 
    double salary;
public:
    //non-paramitrized constructor
    Teacher() {
        cout << "hii, i am constructor" << endl;
    }

    //properties //atributes
    string name;
    string dept;
    string subject;
    
    //methods //member function
    void changeDept(string newDept) {
        dept = newDept;
    }
    
    //setter
    void setSalary(double s) {
        salary = s;
    }
    //getter 
    double getSalary() {
        return salary;
    }
};


class Account {
private:
    double balance;
    string password; 

public:
    string accountId;
    string uername;
    
};

int main() {
    Teacher t1;
    Teacher t2;

    t1.name = "merry";
    t1.subject = "c++";
    t1.dept = "computer science";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    return 0;
}