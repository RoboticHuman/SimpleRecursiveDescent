#pragma once
#include "OperatorNode.h"

class NumNode : public TreeNode
{
public: 
		NumNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};