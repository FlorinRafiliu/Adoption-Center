#pragma once
#include "../domain/Action.h"

class AddAction : public Action {
private:
	Repository& repo;
	Dog dog;

public:

	AddAction(Repository& _repo, Dog _dog);
	void undo() override;
	void redo() override;
};

