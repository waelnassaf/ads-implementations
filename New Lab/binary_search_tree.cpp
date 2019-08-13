#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node () {   left = right = 0; data = -1;   }
    Node (int data){
        left = right = 0;
        this->data = data;
    }
};

class BST {
public:
    Node* root;
    BST() {   root = 0;  }

    void InsertNode(int data)
    {
        Node* newNode = new Node(data);
        if(root == 0) {
            root = newNode;
        } else {
            Node* prev = 0;
            Node*  temp = root;
            while (temp != 0) {
                prev = temp;
                if (data < temp->data) temp = temp->left;
                else temp = temp->right;
            }
            if (data > prev->data) prev->right = newNode;
            else prev->left = newNode;
        }
    }

    int Search(int data, int &count)
    {
        int lvl = 0;    // Tree Level
        count   = 1;    // # Comparisons
        if (root->data == data) return 0;

        Node* temp = root;
        while (temp != 0)
        {
            if (data < temp->data)
            {
                temp = temp->left;
                lvl++;
            }
            else if (data > temp->data)
            {
                temp = temp->right;
                lvl++;
            }
            else {
                return lvl;
            }
            count++;
        }
        return -1;
    }

    // Traverse the tree with a breadth first algorithm.
    void bfs() {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left != 0) q.push(temp->left);
            if (temp->right != 0) q.push(temp->right);
        }
    }

    // Depth first 1
    void InOrder(Node* temp) {
        if (temp) {
            InOrder(temp->left);
            cout << temp->data << " ";
            InOrder(temp->right);
        }
    }
    // Depth first 2
    void PreOrder(Node* temp) {
        if (temp) {
            cout << temp->data << " ";
            PreOrder(temp->left);
            PreOrder(temp->right);
        }
    }
    // Depth first 3
    void PostOrder(Node* temp) {
        if (temp) {
            PostOrder(temp->left);
            PostOrder(temp->right);
            cout << temp->data << " ";
        }
    }

};

int main()
{
    BST t;
    t.InsertNode(20);
    t.InsertNode(30);
    t.InsertNode(10);
    t.InsertNode(13);
//    t.bfs();
    t.PostOrder(t.root);
    return 0;
}