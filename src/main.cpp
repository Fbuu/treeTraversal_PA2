#include <iostream>
#include <string>
#include <vector>

#include "include/CommonMethods.h"
#include "include/Node.h"
#include "include/Enums.h"
using namespace std;

int main () {

    cout << "Hello, main!" << endl;

    vector<string> varList;
    vector<string> funcNumberList;

    STRINGPARSER::readFile(varList,funcNumberList);

    cout << "varr " << endl;
    COUTFUNC::coutVector(varList);
    cout << "funcNum " << endl;
    COUTFUNC::coutVector(funcNumberList);

    Node* tree = NULL;
    for(int i = 0; i < varList.size(); ++i)
        tree = tree->createTree(tree,varList[i]);

    COUTFUNC::coutTreeTraverse(funcNumberList,tree);

    vector<string> files;
    COMMONFILEMETHODS::filesInDirectory(files);
    COMMONFILEMETHODS::createDirectory(OUTPUTFILEPATH);

    string outputFileName = OUTPUTFILEPATH + files[1] ;
    COMMONFILEMETHODS::writeFile(outputFileName, tree->getVector());

    return 0;
}
