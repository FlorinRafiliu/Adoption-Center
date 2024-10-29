#pragma once
#include "../repository/Repo.h"

class Action {
public:
	Action() = default;
	void virtual undo() = 0;
	void virtual redo() = 0;
};

