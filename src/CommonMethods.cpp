#include <iostream>
#include "./include/CommonMethods.h"
#include "./include/Enums.h"
#include "vector"
#include "string"
#include <fstream>

using namespace std;

namespace STRINGPARSER{
    void parserByWS(string line, vector<string> &varr, vector<string> &funcNum)
    {
        string delimiter = " ";        
        size_t pos = 0;
        string token;
        bool isEnd = false;
        cout << line << endl;
        while ((pos = line.find(delimiter)) != string::npos) 
        {
            token = line.substr(0, pos);
            cout << "---" << token << endl;
            
            if(token.compare("end") == 0){
                isEnd = true;
            }  

            if(!isEnd)
                varr.push_back(token);
            else
                funcNum.push_back(token);
            
            line.erase(0, pos + delimiter.length());
        }
    }
}

namespace COUTFUNC
{
    void coutVector(std::vector<string> vectorr)
    {
        for(int i = 0 ; i < vectorr.size(); i++)
            cout << vectorr[i] << endl;
    }
}

namespace COMMONMETHODS
{
    void readFile( vector<string> &varr, vector<string> &funcNum)
    {
        string line;
        string fileName = INPUTFILEPATH + string("names_short2.txt");
        ifstream file(fileName);

        bool isVarName = true;

        if (file.is_open())
        {
            while (getline(file,line))
            {
                if(line.compare("end") == 0){
                isVarName = false;
                continue;
                }

                if(isVarName)
                varr.push_back(line);
                else
                {
                if(line.compare("-1") != 0)
                funcNum.push_back(line);
                }

            }
            cout << "varr " << endl;
            COUTFUNC::coutVector(varr);  
            cout << "funcNum " << endl;
            COUTFUNC::coutVector(funcNum);
            file.close();
        }

        
    }
}