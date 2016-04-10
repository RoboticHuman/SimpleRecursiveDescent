#pragma once
#include "OperatorNode.h"

class NeNode : public TreeNode
{
public: 
		NeNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};