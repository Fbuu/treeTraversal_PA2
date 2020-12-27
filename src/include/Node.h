#ifndef NODE_H 
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node
{
    public:

        Node();
        Node(string wordName);
        Node(string wordName, Node* _parent);


        ~Node();
        void setWord(string _word) { word = _word;}
        void setLeft( Node* _left) { left = _left;}
        void setRight( Node* _right) { right = _right;}
        void setParent( Node* _parent) { parent = _parent;}

        string getWord(){ return word;}
        Node* getLeft(){ return left;}
        Node* getRight(){ return right;}
        Node* getParent(){ return parent;}

        vector<string> getVector(){ return textVector;}

        Node* createNode(string data);
        Node* createTree(Node* root, std::string varr);
        void vectorClear(){ textVector.clear(); }

        void preOrderTraverse(Node* node);
        void postOrderTraverse(Node* node);
        void inOrderTraverse(Node* node);
        void findLeafNode(Node* node);


    private:

        string word;
        Node* left;
        Node* right;
        Node* parent;  
        vector<string> textVector;    
        
};

#endif 

