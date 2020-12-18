#ifndef NODE_H 
#define NODE_H

#include <vector>
#include <string>

using namespace std;

class Node
{
    public:

        Node();
        ~Node();
        void setWord(string _word) { word = _word;}

        void setLeftNode( Node* _left) { left = _left;}
        void setRightNode( Node* _right) { right = _right;}
        void setParentNode( Node* _parent) { parent = _parent;}

        void setVarList(vector<string> _varList){ varList = _varList;}
        void setFuncNumberList(vector<string> _funcNumberList){ funcNumberList = _funcNumberList;}

        string getWord(){ return word;}
        Node* getLeftNode(){ return left;}
        Node* getRightNode(){ return right;}
        Node* getParentNode(){ return parent;}

        vector<string>& getVarList() { return varList;}
        vector<string>& getFuncNumberList() { return funcNumberList;}

    private:

        string word;
        Node* left;
        Node* right;
        Node* parent;      
        
        vector<string> varList;
        vector<string> funcNumberList;

};

#endif 

