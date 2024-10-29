#include "FileRepository.h"

FileRepository::FileRepository(string _filename) {
	filename = _filename; 
	read_all();
}

void FileRepository::addDog(Dog dog) {
	read_all();
	Repository::addDog(dog);
	write_all();
}

Dog FileRepository::removeDog(const string& name, const string& breed) {
	read_all();
	Dog dog = Repository::removeDog(name, breed);
	write_all();
	return dog;
}

Dog FileRepository::updateDog(const string& name, const string& breed, Dog dog) {
	read_all();
	Dog oldDog = Repository::updateDog(name, breed, dog);
	write_all();
	return oldDog;
}

vector<Dog> FileRepository::getData() {
	return Repository::getData();
}

void FileRepository::clearRepo() {
	data.clear();
	write_all();
}

void FileRepository::read_all() {
	data.clear();

	ifstream fin;
	fin.open(filename);
	
	Dog dog;
	while (fin >> dog) {
		data.push_back(dog);
	}

	fin.close();
}

void FileRepository::write_all() {

	ofstream fout;

	fout.open(filename);

	for (Dog dog : data)
		fout << dog;

	fout.close();
}
