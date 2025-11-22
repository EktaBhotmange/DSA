#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int partition(vector<int> &arr, int st, int end) {
    int idx = st-1, pivot = arr[end];

    for(int j=st; j<end; j++) {
        if(arr[j] <= pivot) {        //condition for ascending or descending
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quikSort(vector<int> &arr, int st, int end) {
    if(st < end) {
        int pivIdx = partition(arr, st, end);

        quikSort(arr, st, pivIdx-1); // left half
        quikSort(arr, pivIdx+1, end); // left half
    }
}

int main() {
    vector<int> arr = {8, 1, 6, 4, 2, 5, 7};
    quikSort(arr, 0, arr.size()-1);
    
    for(int val : arr) {
        cout << val << " ";
    }

    cout << endl;
    return 0;
}