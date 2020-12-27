#include <iostream>
#include "./include/CommonMethods.h"
#include "./include/Enums.h"
#include "vector"
#include "string"
#include <fstream>
#include <dirent.h>
#include <cstring>
#include <windows.h>

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

    void readFile(vector<string> &varr, vector<string> &funcNum)
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
            file.close();
        }
    }
}

namespace COUTFUNC
{
    void coutVector(vector<string> vectorr)
    {
        for(int i = 0 ; i < vectorr.size(); i++)
            cout << vectorr[i] << endl;
    }
    void coutTreeTraverse(vector<string> vec, Node* tree)
    {
        for(int i = 0 ; i < vec.size(); i++)
        {
            cout << "*****" << endl;
            int num = stoi(vec[i]);
            switch (num)
            {
            case 1:
                tree->preOrderTraverse(tree);
                break;
            case 2:
                tree->postOrderTraverse(tree);
                break;
            case 3:
                tree->inOrderTraverse(tree);
                break;
            case 4:
                tree->findLeafNode(tree);
                break;
            default:
                break;
            }
        }
        cout << "Done!" << endl;
    }
}

namespace COMMONFILEMETHODS
{
    void filesInDirectory(vector<string> &files)
    {
        DIR *dir; 
        struct dirent *diread;
        //vector<string> files;
        if((dir = opendir(INPUTFILEPATH)) != NULL){
            while(diread = readdir(dir)){
                if( strcmp(diread->d_name, ".") != 0 && strcmp(diread->d_name, "..") != 0 )
                {
                    const string name = diread->d_name;
                    files.push_back(name);
                }
            }
            closedir(dir);
        }
        else{
            cout << "Directory is not found! " << endl;
        }
    }

    void createDirectory(string dirPath)
    {
        const char* dirP = dirPath.c_str();
        if (CreateDirectory(dirP, NULL))
        {
            cout << "Created succesfully directory!" << endl;
        }
        else if (ERROR_ALREADY_EXISTS == GetLastError())
        {
            cout << "Directory already exists" << endl;
        }
        else
        {
            cout << "Failed for some other reason" << endl;
        }
    }

    void writeFile(string fileName, vector<string> text)
    {
        if( remove(fileName.c_str()) == 0){
            ofstream outfile;
            outfile.open(fileName, std::ios_base::app); // append instead of overwrite
            for(int i = 0; i < text.size(); ++i)
                outfile << text[i]; 
        }
        else
            cout<<"\nErorr Occurred!";
        
    }
}