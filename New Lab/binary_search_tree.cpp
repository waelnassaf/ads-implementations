#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node() {
        left = right = 0;
        data = -1;
    }
    Node(int data){
        left = right = 0;
        this->data = data;
    }
};

class BST
{
private:
    Node* root;
public:
    BST()   {   root = 0;  }

    void InsertNode(int data)
    {

        Node* newNode = new Node(data);
        if(root == 0){
            root= newNode;
            return;
        }
        Node* prev = 0;
        Node*  temp = root;
        while (temp != 0)
        {
            prev =  temp;
            if (data < temp->data)
                temp = temp->left;
            else
                temp= temp->right;
        }
        if(data > prev->data) prev->right = newNode;
        else prev->left = newNode;
    }
    int Search (int data,int &count)
    {
        int lvl = 0;
        count   = 1;
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
                temp= temp->right;
                lvl++;
            }
            else{
                return lvl;
            }
            count++;
        }
    }

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


};

int main()
{
    BST t;
    t.InsertNode(20);
    t.InsertNode(30);
    t.InsertNode(10);
    t.InsertNode(13);
    t.bfs();
    return 0;
}
