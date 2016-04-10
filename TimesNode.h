#pragma once
#include "OperatorNode.h"

class TimesNode : public TreeNode
{
public: 
		TimesNode (Token token) : TreeNode(nullptr,nullptr){ 
			this->token = token;
		}

		Token getToken() {
			return this->token;
		}
private: 
		Token token;

};