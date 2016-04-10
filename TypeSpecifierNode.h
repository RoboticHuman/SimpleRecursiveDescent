#pragma once
#include "OperatorNode.h"

class TypeSpecifierNode : public TreeNode
{
public: 
		TypeSpecifierNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};