#pragma once
#include "Treenode.h"

class IdentifierNode : public Treenode
{
public: 
		IdentifierNode (Token token) : Treenode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};