#pragma once
#include "OperatorNode.h"

class MinusNode : public TreeNode
{
public: 
		MinusNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};