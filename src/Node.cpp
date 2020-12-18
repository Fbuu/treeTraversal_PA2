#include "./include/Node.h"

Node::Node()
{
    word = "";
    left = NULL;
    right = NULL;
    parent = NULL;
}

Node::~Node()
{
    /* varList.clear();
    funcNumberList.clear();
    delete left;
    delete right;
    delete parent; */
}

