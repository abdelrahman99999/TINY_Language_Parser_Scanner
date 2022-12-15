#pragma once

#include <vector>
#include "Scanner/Scan.h"
struct Node
{
    Token key;
    std::vector<Node*>child;
	Node* sibling;
};


Node* newNode(Token key);
