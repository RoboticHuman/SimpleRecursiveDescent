#pragma once
#include "OperatorNode.h"

class IdentifierNode : public TreeNode
{
public: 
		IdentifierNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};