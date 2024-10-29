#pragma once
#include "../domain/Dog.h"


class Validator {
public:
	Validator() = default;
	bool validateDog(Dog&);
	bool validatePhoto(const string&);
};

