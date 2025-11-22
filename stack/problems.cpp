#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Problem: Find the next greater element for each element in the array.
/*  int main() {
    vector<int> arr = {3, 6, 8, 0, 1};

    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=arr.size()-1; i>=0; i--) {
        while(s.size() > 0 && s.top() <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] =  -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}  */



// Problem: Find the previous smaller element for each element in the array.
/*  int main() {
    vector<int> arr = {3, 6, 8, 0, 1};

    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=0; i<=arr.size(); i++) {
        while(s.size() > 0 && s.top() >= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] =  -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    for(int val : ans) {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}  */