#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int sum(int n){
    if(n == 1){
        return 1;
    }

    return n + sum(n-1);
}

int factorial(int n) {
    if(n == 0){
        return 1;
    }

    return n * factorial(n-1);
}

void printNums(int n) {
    if(n == 1){
        cout << "1\n";
        return;
    }

    cout << n << " ";
    printNums(n-1);
}


//check if the array is sorted
bool isSorted(vector<int> arr, int n){
     if(n == 0 || n == 1){
        return true;
     }

    return arr[n-1] >= arr[n-2] && isSorted(arr, n-1);
}


//printing subset of a given array using recursion
void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if(i == arr.size()){
        for(int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    ans.push_back(arr[i]);
    printSubsets(arr, ans, i+1);

    ans.pop_back();
    printSubsets(arr, ans, i+1);
}
 
int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;

    printSubsets(arr, ans, 0);
    
    return 0;
} 