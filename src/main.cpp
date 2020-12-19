#include <iostream>
#include <string>
#include <vector>

#include "include/CommonMethods.h"
#include "include/Node.h"
using namespace std;

/* struct node{

    string word;
    node* left;
    node* right;
    node* father;
}; */

int main () {

    cout << "Hello, main!" << endl;

    vector<string> varList;
    vector<string> funcNumberList;

    COMMONMETHODS::readFile(varList,funcNumberList);

    cout << "varr " << endl;
    COUTFUNC::coutVector(varList);
    cout << "funcNum " << endl;
    COUTFUNC::coutVector(funcNumberList);

    Node* tree = NULL;
    for(int i = 0; i < varList.size(); ++i)
    {
        tree = tree->createTree(tree,varList[i]);
    }
    
    return 0;
}
