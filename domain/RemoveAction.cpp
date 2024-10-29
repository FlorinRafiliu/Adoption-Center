#include "RemoveAction.h"

RemoveAction::RemoveAction(Repository& _repo, Dog _dog) : repo(_repo), dog(_dog) {}

void RemoveAction::undo() {
	repo.addDog(dog);
}

void RemoveAction::redo() {
	repo.removeDog(dog.getName(), dog.getBreed());
}
