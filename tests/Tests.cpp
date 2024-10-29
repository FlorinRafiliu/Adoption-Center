#include "Tests.h"
#include "../domain/Dog.h"
#include "../repository/Repo.h"
#include "../repository/FileRepository.h"
#include "../service/Service.h"
#include "../service/ServiceUser.h"
#include <assert.h>
#include <cstring>

#include <iostream>

void testDog() {
	Dog dog1{ 1, "dog", "dog1", "dog2" };
	assert(dog1.getAge() == 1);
	assert(dog1.getBreed() == "dog1");
	assert(dog1.getName() == "dog");
	assert(dog1.getPhoto() == "dog2");

	Dog dog2;
	assert(dog2.getAge() == -1);
}

void testRepo() {
	Repository repo;

	Dog dog1{ 1, "dog1", "dog1", "www.dog1.ro" };
	Dog dog2{ 2, "dog2", "dog2", "www.dog2.ro" };

	repo.addDog(dog1);
	repo.addDog(dog2);

	try {
		repo.addDog(dog1);
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "The dog is already in the database!\n") == 0);
	}

	vector <Dog> data = repo.getData();
	assert(data.size() == 2);
	assert(data[0].getAge() == 1);
	assert(data[0].getName() == "dog1");
	assert(data[0].getBreed() == "dog1");
	assert(data[0].getPhoto() == "www.dog1.ro");

	repo.removeDog("dog1", "dog1");
	
	data = repo.getData();
	assert(data.size() == 1);
	assert(data[0].getAge() == 2);
	assert(data[0].getName() == "dog2");
	assert(data[0].getBreed() == "dog2");
	assert(data[0].getPhoto() == "www.dog2.ro");
	
	try {
		repo.removeDog("dog1", "dog1");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "This dog does not exist in the list!\n") == 0);
	}

	repo.updateDog("dog2", "dog2", dog1);
	data = repo.getData();
	assert(data[0].getAge() == 1);
	assert(data[0].getName() == "dog1");
	assert(data[0].getBreed() == "dog1");
	assert(data[0].getPhoto() == "www.dog1.ro");
}

void testService() {
	Repository repo;
	Validator val;
	Service service(repo, val);

	service.addDog(1, "dogunu", "dogunu", "https1");
	service.addDog(2, "dogdoi", "dogdoi", "https2");
	try {
		service.addDog(1, "dogunu", "dogunu", "https");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "The dog is already in the database!\n") == 0);
	}

	try {
		service.addDog(1, "dog1", "dog1", "www.dog1");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}

	vector <Dog> data = service.getData();

	assert(data.size() == 2);
	assert(data[0].getAge() == 1);
	assert(data[0].getName() == "dogunu");
	assert(data[0].getBreed() == "dogunu");
	assert(data[0].getPhoto() == "https1");

	service.removeDog("dogunu", "dogunu");

	data = service.getData();
	assert(data.size() == 1);
	assert(data[0].getAge() == 2);
	assert(data[0].getName() == "dogdoi");
	assert(data[0].getBreed() == "dogdoi");
	assert(data[0].getPhoto() == "https2");

	try {
		service.removeDog("dogunu", "dogunu");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "This dog does not exist in the list!\n") == 0);
	}

	service.updateDog("dogdoi", "dogdoi", 1, "https1");
	data = service.getData();
	assert(data[0].getAge() == 1);
	assert(data[0].getPhoto() == "https1");

	
	try {
		service.updateDog("dogtrei", "dogtrei", 1, "http");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid Dog\n") == 0);
	}

	try {
		service.addDog(1, "dogtrei", "dogtrei", "httpp");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}

	try {
		service.addDog(-1, "dogtrei", "dogtrei", "https");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}
	
	try {
		service.addDog(1, "dogtrei", "dog", "https");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}

	try {
		service.addDog(1, "do", "dogtrei", "https");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}

	try {
		service.addDog(1, "dog3", "dogtrei", "https");
	}
	catch (exception& e) {
		assert(strcmp(e.what(), "Invalid dog!\n") == 0);
	}

}

void testServiceUser() {
	
	Repository dogs;

	Dog dog1{ 1, "caine", "maidanez", "https1" };
	dogs.addDog(dog1);

	Repository adoptions;
	ServiceUser service(dogs, adoptions);

	Dog dog{ 1, "caine", "caine", "https1" };
	service.addDog(dog);

	vector <Dog> data = service.filterBreedAge("maidanez", 2);

	for (int i = 0; i < data.size(); i++) {
		assert(data[i].getAge() == 1);
		assert(data[i].getBreed() == "maidanez");
		assert(data[i].getName() == "caine");
		assert(data[i].getPhoto() == "https1");
	}

	data = service.getDogsList();
	assert(data[0].getAge() == 1);
	assert(data[0].getBreed() == "maidanez");
	assert(data[0].getName() == "caine");
	assert(data[0].getPhoto() == "https1");
	
	data = service.getUserList();
	assert(data[0].getAge() == 1);
	assert(data[0].getBreed() == "caine");
	assert(data[0].getName() == "caine");
	assert(data[0].getPhoto() == "https1");
}

void testFileRepository() {
	FileRepository repo("test1.txt");
	repo.clearRepo();

	Dog v[5];
	repo.addDog(v[0] = Dog(10, "boboita1", "caine1", "https1"));
	repo.addDog(v[1] = Dog(10, "boboita2", "caine2", "https2"));
	repo.addDog(v[2] = Dog(10, "boboita3", "caine3", "https3"));
	repo.addDog(v[3] = Dog(10, "boboita4", "caine4", "https4"));
	repo.addDog(v[4] = Dog(10, "boboita5", "caine5", "https5"));

	repo.updateDog("boboita5", "caine5", v[0]);

	assert(repo.getData().size() == 5);

	FileRepository repo2("test1.txt");
	vector <Dog> data = repo2.getData();
	int i = 0;
	for (Dog dog : data) {
		if (i != 4)
			assert(v[i++] == dog);
		else
			assert(!(v[i] == dog));
	}

	repo.removeDog("boboita2", "caine2");

	assert(repo.getData().size() == 4);
}

void allTests() {
	testDog();
	testRepo();
	testService();
	testServiceUser();
	testFileRepository();
}