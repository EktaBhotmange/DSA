// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node (int val) {
//         data = val;
//         left = right = NULL;
//     }
// };

// Node* insert(Node* root, int val) {
//     if(root = NULL) {
//         return new Node(val);
//     }

//     if(val < root->data) {
//         root->left = insert(root->left, val);
//     }  else {
//         root->right = insert(root->right, val);
//     }

//     return root;
// }

// Node* buildBST(vector<int> arr) {
//     Node* root = NULL;

//     for(int val : arr) {
//         root = insert(root, val);
//     }

//     return root;
// }

// void inorder(Node* root) {
//     if(root == NULL) {
//         return;
//     }

//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }


// int main() {
//     vector<int> arr = {3, 2, 1, 5, 6, 4};

//     Node* root = buildBST(arr);
//     inorder(root);
//     cout << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int>& arr) {
    Node* root = NULL;
    for (int val : arr) {
        root = insertBST(root, val);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool search(Node* root, int key) {  //O(height)
    if(root == NULL) {
        return false;
    }

    if(root->data == key) {
        return true;
    }

    if(key < root->data) {
       return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node* getInorderSuccessor(Node* root) {  //left most Node in right subTree
    while(root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else { 
        //key == root
        if(root->left == NULL) { 
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {  //2 children
            Node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
        }  
     
    }

    return root;
}

class Info {
public:    
    int min, max, sz;

    Info(int mi, int ma, int size) {
        min = mi;
        max = ma;
        sz = size;
    }
};

Info helper(Node* root) {
    if(root == NULL) {
        return Info (INT_MAX, INT_MIN, 0);
    }

    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->data > left.max && root->data , right.min) {
       int currMin = min(root->data, left.min);
       int currMax = max(root->data, left.min);
       int currSz = left.sz + right.sz + 1;

       return Info(currMin, currMax, currSz);
    }

    return Info(INT_MIN, INT_MAX, max(left.sz, right.sz));
}

int largestBSTinBT(Node* root) {
    Info info = helper(root);
    return info.sz;  //max BST size
}

Node* rightMostInLeftSubtree(Node* root) {
    Node* ans;

    while(root != NULL) {
        ans = root;
        root = root->right;
    }

    return ans;
}

Node* leftMostInRightSubtree(Node* root) {
    Node* ans;

    while(root != NULL) {
        ans = root;
        root = root->left;
    }

    return ans;
}

vector<int> getPredSucc(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL) {
        if(key < curr->data) {
            succ = curr;
            curr = curr->left;
        } else if(key > curr->data) {
            pred = curr;
            curr = curr->right;
        } else {
            if(curr->left != NULL) {
                //inorder pred

                pred = rightMostInLeftSubtree(curr->left);
            }

            if(curr->right != NULL) {
                //inorder succ

                succ = leftMostInRightSubtree(curr->right);
            }

            break;
        }
    }

    return {pred->data, succ->data};
}
  
int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    int key = 7;
    vector<int> ans = getPredSucc(root, key);
    cout << "predecessor: " << ans[0] << endl;
    cout << "successor: " << ans[1] << endl;
    return 0;
}