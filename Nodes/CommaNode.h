#pragma once
#include "OperatorNode.h"

class CommaNode : public TreeNode
{
public: 
		CommaNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};