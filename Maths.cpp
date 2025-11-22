#include <iostream>
using namespace std;

// Prime Numbers
string isPrime(int n) {
    for(int i=2; i*i<=n;i++) {
        if(n % i == 0) {
            return "Non Prime";
        }
    }

    return "Prime";
}


int printDigits(int n) {
    int sum = 0; 

    while(n != 0) {
        int digit = n % 10;
        sum += digit;
    }   

    cout << sum <<endl;
}
int main() {
   int n = 53463; 

   printDigits(n);
    return 0;
} 