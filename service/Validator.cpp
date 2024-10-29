#include "Validator.h"

bool Validator::validateDog(Dog& dog) {
	if (dog.getAge() < 0)
		return false;

	if (dog.getBreed().size() < 4)
		return false;

	for (int i = 0; i < dog.getBreed().size(); i++)
		if ('0' <= dog.getBreed()[i] && dog.getBreed()[i] <= '9')
			return false;

	if (dog.getName().size() < 3)
		return false;

	for (int i = 0; i < dog.getName().size(); i++)
		if ('0' <= dog.getName()[i] && dog.getName()[i] <= '9')
			return false;

	if (!validatePhoto(dog.getPhoto()))
		return false;

	return true;
}

bool Validator::validatePhoto(const string& photo) {
	if (photo.size() < 5)
		return false;
	if (photo.find("https") == -1)
		return false;
	return true;
}