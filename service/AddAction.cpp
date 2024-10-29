#include "AddAction.h"

AddAction::AddAction(Repository& _repo, Dog _dog) : repo(_repo), dog(_dog) {}
void AddAction::undo() {
	repo.removeDog(dog.getName(), dog.getBreed());
}

void AddAction::redo() {
	repo.addDog(dog);
}

