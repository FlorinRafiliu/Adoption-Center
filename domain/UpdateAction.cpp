#include "UpdateAction.h"

UpdateAction::UpdateAction(Repository& _repo, Dog _dog1, Dog _dog2)
	: repo(_repo), dog1(_dog1), dog2(_dog2) { }

void UpdateAction::undo() {
	repo.removeDog(dog2.getName(), dog2.getBreed());
	repo.addDog(dog1);
}

void UpdateAction::redo() {
	repo.removeDog(dog1.getName(), dog1.getBreed());
	repo.addDog(dog2);
}
