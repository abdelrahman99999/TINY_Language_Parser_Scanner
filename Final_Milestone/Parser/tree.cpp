#include"Tree.h"

Node *newNode(Token key)
{
	Node *temp = new Node;
	temp->key.type = key.type;
	temp->key.value = key.value;
	temp->sibling = nullptr;
	return temp;
}

