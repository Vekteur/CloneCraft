#pragma once

#include "Structure.h"

class Tree : public Structure {
public:
	Tree();
	virtual bool isValidPos(ivec2 pos) const override;
};