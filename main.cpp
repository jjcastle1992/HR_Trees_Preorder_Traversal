#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

/* you only have to complete the function given below.
Node is defined as

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    /* Pre-Order Traversal "visits":
     * 1. ROOT
     * 2. LEFT
     * 3. RIGHT
     *
     * Time Complexity O(n)
     * Space Complexity O(n)
     */
    void preOrder(Node *root) {
        //Prints our tree in the Pre-Order methodology
        if (root) {
            //1. Visit and Print payload at Root
            std::cout << root->data << std::endl;
            //2. Visit and Print payload at left subtree until leaves are hit (root == null)
            preOrder (root->left);
            //3. Visit and Print payload at right subtree until leaves are hit (root == null)
            preOrder (root->right);
        }
        else {
            return;
        }
    }
}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);
    return 0;
}
