#include "Repo.h"

void Repository::addDog(Dog newDog) {

	vector <Dog>::iterator it = find(data.begin(), data.end(), newDog);

	if(it != data.end())
		throw RepoException("The dog is already in the database!\n");
	
	data.push_back(newDog);
}

Dog Repository::removeDog(const string& name, const string& breed) {

	vector <Dog>::iterator it = find_if(data.begin(), data.end(),
		[name, breed](const Dog& dog) -> bool {
			return dog.getName() == name && dog.getBreed() == breed;
		});

	if (it != data.end()) {
		Dog dog = (*it);
		data.erase(it);
		return dog;
	}
	else {
		throw RepoException("This dog does not exist in the list!\n");
	}
}

Dog Repository::updateDog(const string& name, const string& breed, Dog newDog) {

	vector <Dog>::iterator it = find_if(data.begin(), data.end(),
		[name, breed](const Dog& dog) -> bool {
			return dog.getName() == name && dog.getBreed() == breed;
		});

	if (it != data.end()) {
		Dog oldDog = (*it);
		(*it) = newDog;
		return oldDog;
	}
}

vector <Dog> Repository::getData() {
	return data;
}
