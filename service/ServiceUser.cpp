#include "ServiceUser.h"

ServiceUser::ServiceUser(Repository& repo1, Repository& repo2) : dogsList(repo1), userList(repo2) {}

vector <Dog> ServiceUser::getDogsList() {
	return dogsList.getData();
}
vector <Dog> ServiceUser::getUserList() {
	return userList.getData();
}

vector <Dog> ServiceUser::filterBreedAge(const char breed[], int age) {

	vector <Dog> data = dogsList.getData();
	vector <Dog> newList(data.size());
	auto it = copy_if(data.begin(), data.end(), newList.begin(),
		[breed, age](Dog dog) -> bool {
			return ((dog.getBreed() == breed || breed[0] == '\0') && dog.getAge() < age);
		});
	newList.resize(distance(newList.begin(), it));

	return newList;
}

void ServiceUser::addDog(Dog dog) {
	userList.addDog(dog);
}
