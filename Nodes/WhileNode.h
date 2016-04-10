#pragma once
#include "OperatorNode.h"

class WhileNode : public TreeNode
{
public: 
		WhileNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};