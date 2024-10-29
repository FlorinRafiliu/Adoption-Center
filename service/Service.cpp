#include "Service.h"

Service::Service(Repository& _repo, Validator& _val) : repo(_repo), val(_val) {
	currentAction = -1;
}

void Service::undo() {
	if (currentAction == -1) {
		throw exception("No more undoes!");
	}

	actions[currentAction]->undo();
	currentAction -= 1;
}

void Service::redo() {
	if (currentAction + 1 == actions.size()) {
		throw exception("No more redos!");
	}

	currentAction += 1;
	actions[currentAction]->redo();
}

void Service::addDog(int age, const string& name, const string& breed, const string& photo_link) {
	Dog newDog {age, name, breed, photo_link};
	if (!val.validateDog(newDog)) {
		throw ServiceException("Invalid dog!\n");
	}

	AddAction* addAction = new AddAction(repo, newDog);

	while (actions.size() != currentAction + 1) {
		actions.pop_back();
	}

	actions.push_back(addAction);
	currentAction = actions.size() - 1;

	repo.addDog(newDog);
}

void Service::removeDog(const string& name, const string& breed) {
	Dog oldDog = repo.removeDog(name, breed);

	RemoveAction* removeAction = new RemoveAction(repo, oldDog);

	while (actions.size() != currentAction + 1) {
		actions.pop_back();
	}

	actions.push_back(removeAction);
	currentAction = actions.size() - 1;
}

void Service::updateDog(const string& name, const string& breed, int newAge, const string& newPhoto) {

	Dog newDog(newAge, name, breed, newPhoto);

	if (!val.validateDog(newDog)) {
		throw ServiceException("Invalid Dog\n");
	}

	Dog oldDog = repo.updateDog(name, breed, newDog);

	UpdateAction* updateAction = new UpdateAction(repo, oldDog, newDog);

	while (actions.size() != currentAction + 1) {
		actions.pop_back();
	}

	actions.push_back(updateAction);
	currentAction = actions.size() - 1;
}

vector <Dog> Service::getData()
{
	return repo.getData();
}
