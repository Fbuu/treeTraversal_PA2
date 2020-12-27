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

Node* Node::createNode(string data)
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
        root = createNode(varr);
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
            temp->left = createNode(varr);
            temp->left->parent = temp;
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = createNode(varr);
            temp->right->parent = temp;
            return root;
        }
    }
    return NULL;
}

void Node::preOrderTraverse(Node* node)
{
    if(node != NULL){
        //cout << node->word << endl;
        textVector.push_back(node->word);
        textVector.push_back("\n");
        preOrderTraverse(node->left);
        preOrderTraverse(node->right);
    }
    else
        return;
}

void Node::postOrderTraverse(Node* node)
{
    if(node != NULL){
        postOrderTraverse(node->left);
        postOrderTraverse(node->right);
        //cout << node->word << endl;
        textVector.push_back(node->word);
        textVector.push_back("\n");
    }
    else
        return;
}

void Node::inOrderTraverse(Node* node)
{
    if(node != NULL){
        inOrderTraverse(node->left);
        //cout << node->word << endl;
        textVector.push_back(node->word);
        textVector.push_back("\n");
        inOrderTraverse(node->right);
    }
    return;
}

void Node::findLeafNode(Node* node)
{
    if(node != NULL){
        if(!(node->left) && !(node->right))
        {
            //cout << node->word << endl;
            textVector.push_back(node->word);
            textVector.push_back("\n");
            return;
        }
        else
        { 
            findLeafNode(node->left);
            findLeafNode(node->right);
        }
    }
    return;
}