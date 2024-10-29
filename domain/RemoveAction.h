#pragma once
#include "Action.h"

class RemoveAction : public Action {
private:
	Repository& repo;
	Dog dog;

public:

	RemoveAction(Repository& _repo, Dog _dog);
	void undo() override;
	void redo() override;
};

