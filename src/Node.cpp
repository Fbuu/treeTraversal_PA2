#include "./include/Node.h"
#include <iostream>
#include <queue>

using namespace std;


Node::Node()
{
    word = "";
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(string wordName)
{
    word = wordName;
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::Node(string wordName, Node* _parent)
{
    word = wordName;
    left = NULL;
    right = NULL;
    parent = _parent;
}

Node::~Node()
{
}

Node* Node::CreateNode(string data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->word = data;
    newNode->left = newNode->right = newNode->parent =  NULL;
    return newNode;
}

Node* Node::createTree(Node* root, string varr)
{
    if (root == NULL) {
        root = CreateNode(varr);
        root->parent = NULL;
        return root;
    }

    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(varr);
            temp->left->parent = temp;
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(varr);
            temp->right->parent = temp;
            return root;
        }
    }
    return NULL;
}

