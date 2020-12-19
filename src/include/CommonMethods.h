#ifndef COMMONMETHODS_H 
#define COMMONMETHODS_H

#include "vector"
#include "Node.h"

namespace STRINGPARSER
{
    void parserByWS(std::string line, std::vector<std::string> &varr, std::vector<std::string> &funcNum);
}

namespace COUTFUNC
{
    void coutVector(std::vector<std::string> vectorr);
}

namespace COMMONMETHODS
{
    void readFile(std::vector<std::string> &varr, std::vector<std::string> &funcNum);
}

#endif 