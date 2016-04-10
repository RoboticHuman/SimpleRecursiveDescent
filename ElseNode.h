#pragma once
#include "OperatorNode.h"

class ElseNode : public TreeNode
{
public: 
		ElseNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};