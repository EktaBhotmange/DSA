#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

int main(){

    string s = "abc";
    next_permutation(s.begin(), s.end());
    cout << s;

    return 0;
}

// bool comparator(pair<int, int> p1, pair<int, int> p2) {
//     if(p1.second < p2.second) return true;
//     if(p1.second > p2.second) return false;

//     if(p1.first < p2.first) return true;
//     else return false;
// }
// int main(){
//     vector<pair<int, int>> vec = {{1, 2}, {2, 1}, {3, 1}, {7, 1}, {5, 2}};

//     sort(vec.begin(), vec.end(), comparator);
//     return 0;
// }


// int main() {
//     set<int> s;

//     s.insert(1);
//     s.insert(2);
//     s.insert(3);
//     s.insert(4);
//     s.insert(5);

//     cout << s.size() << endl;
//     for(auto val : s) {
//         cout << val << " ";
//     }
//     cout << endl;

// }


// int main(){
//     multimap<string, int> a;

    // a["tv"] = 100;
    // a["Laptop"] = 655;
    // a["Headphones"] = 30;
    // // a["Mobile"] = 50;

    // a.emplace("camera", 400);
    // a.emplace("camera", 400);
    // a.emplace("camera", 400);
    // a.emplace("camera", 400);
    // a.emplace("camera", 400);

    // a.erase("camera");
    // for(auto p: a) {
    //     cout << p.first << " " << p.second << endl;
    // }

    // if(a.find("camera") != a.end()) {
    //     cout << "found";
    // } else {
//      cout << "not found";
//     }
//     return 0;
// }


// int main(){
//     priority_queue<int> q;

//     q.push(5);
//     q.push(10);
//     q.push(3);
//     q.push(4);

//     while(!q.empty()) {
//         cout << q.top() << " ";
//         q.pop();
//     }
//     cout << endl;
//     return 0;
// }

// int main(){
//     stack<int> s;

//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.pop();

//     stack<int> s2;
//     s2.swap(s);

//     cout << "s size: "<<s.size() << endl;
//     cout << "s2 size: "<<s2.size() << endl;

//     return 0;
// }

// int main(){
//     vector<pair<int, int>> vec = {{1, 2}, {3, 4}, {2, 3}};

//     vec.push_back({4, 5}); //insert
//     vec.emplace_back(4, 5); //in-place objects create

//     for(auto p : vec) {
//         cout << p.first << " " << p.second << endl;
//     }
// }

// int main(){
//     list<int> l;

//     l.emplace_back(1);
//     l.push_back(2);
//     l.push_front(3);
//     l.push_front(5);

//     for(int val : l) {
//         cout << val << " ";
//     }
//     cout << endl;
//     return 0;

// }


// int main() {
//     vector<int> vec = {1, 2, 3, 4, 5};
   
//     // vector<int>::reverse_iterator it;

//     for(auto it = vec.rbegin(); it != vec.rend(); it++) {
//         cout << *(it) << " ";
//     }
   
//     return 0;
// }