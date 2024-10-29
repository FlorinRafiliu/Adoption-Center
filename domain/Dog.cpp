#include "Dog.h"
#include <cstring>

Dog::Dog() {
	age = -1;
	name = "";
	breed = "";
	link = "";
}

bool Dog::operator==(Dog other)
{
	if (other.name == name && other.breed == breed)
		return true;
	return false;
}

Dog::Dog(int _age, const string& _name, const string& _breed, const string& _link) {
	age = _age;
	name = _name;
	breed = _breed;
	link = _link;
}

int Dog::getAge() { return age; }

string Dog::getName() const {
	return name;
}

string Dog::getBreed() const {
	return breed;
}

string Dog::getPhoto() const {
	return link;
}

ifstream& operator>>(ifstream& is, Dog& dog) {
	is >> dog.age >> dog.name >> dog.breed >> dog.link;
	return is;
}

ofstream& operator<<(ofstream& os, Dog& dog) {
	os << dog.age << " " << dog.name << " " << dog.breed << " " << dog.link << "\n";
	return os;
}

istream& operator>>(istream& is, Dog& dog) {
	is >> dog.age >> dog.name >> dog.breed >> dog.link;
	return is;
}

ostream& operator<<(ostream& os, Dog& dog) {
	os << dog.age << " " << dog.name << " " << dog.breed << " " << dog.link << "\n";
	return os;
}