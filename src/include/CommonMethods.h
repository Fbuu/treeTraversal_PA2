#ifndef COMMONMETHODS_H 
#define COMMONMETHODS_H

#include "vector"
#include "Node.h"

using namespace std;

namespace STRINGPARSER
{
    void parserByWS(string line, vector<string> &varr, vector<string> &funcNum);
    void readFile(vector<string> &varr, vector<string> &funcNum);

}

namespace COUTFUNC
{
    void coutVector(vector<string> vectorr);
    void coutTreeTraverse(vector<string> vec, Node* tree);
}

namespace COMMONFILEMETHODS
{
    void filesInDirectory(vector<string> &files);
    void createDirectory(string dirPath);
    void writeFile(string fileName, vector<string> text);
}

#endif 