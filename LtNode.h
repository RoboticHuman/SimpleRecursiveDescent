#pragma once
#include "OperatorNode.h"

class LtNode : public TreeNode
{
public: 
		LtNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};