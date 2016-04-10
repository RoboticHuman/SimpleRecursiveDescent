#pragma once
#include "OperatorNode.h"

class GteNode : public TreeNode
{
public: 
		GteNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};