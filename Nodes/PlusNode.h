#pragma once
#include "OperatorNode.h"

class PlusNode : public TreeNode
{
public: 
		PlusNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};