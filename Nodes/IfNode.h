#pragma once
#include "OperatorNode.h"

class IfNode : public TreeNode
{
public: 
		IfNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};