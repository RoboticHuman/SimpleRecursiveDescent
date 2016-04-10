#pragma once
#include "OperatorNode.h"

class LteNode : public TreeNode
{
public: 
		LteNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};