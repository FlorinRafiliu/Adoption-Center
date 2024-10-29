#pragma once
#include "Action.h"

class UpdateAction : public Action {
private:
	Repository& repo;
	Dog dog1, dog2;

public:

	UpdateAction(Repository& _repo, Dog _dog1, Dog _dog2);
	void undo() override;
	void redo() override;
};

