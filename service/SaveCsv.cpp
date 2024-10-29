#include "SaveCsv.h"

void SaveCsv::save(vector<Dog> data) {
	ofstream fout(filename);

	fout << "Adoption List\n";

	fout << "Dog,Breed,Age,Photo link\n";

	for (Dog dog : data) {
		fout << dog.getName() + "," + dog.getBreed() + "," + to_string(dog.getAge()) + "," + dog.getPhoto() + "\n";
	}
}

void SaveCsv::open() {
	string link = "start " + filename;
	system(link.c_str());
}
