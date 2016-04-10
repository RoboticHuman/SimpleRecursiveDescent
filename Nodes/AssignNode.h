#pragma once
#include "OperatorNode.h"

class AssignNode : public TreeNode
{
public: 
		AssignNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};