#pragma once
#include "../domain/Dog.h"
#include "../repository/Repo.h"
#include <cstring>

using namespace std;

class ServiceUser {
private:
	Repository& dogsList;
	Repository& userList;
public:

	/// <summary>
	/// Constructor for ServiceUser
	/// </summary>
	/// <param name="repo1">Repository& - shelter dogs</param>
	/// <param name="repo2">Repository& - adopted dogs</param>
	ServiceUser(Repository& repo1, Repository& repo2);

	/// <summary>
	/// Get the array of shelter's dogs
	/// </summary>
	/// <returns> vector(Dog) </returns>
	vector <Dog> getDogsList();

	/// <summary>
	/// Get the array of adopted dogs
	/// </summary>
	/// <returns> vector(Dog) </returns>
	vector <Dog> getUserList();
	
	/// <summary>
	/// Get an array of Dogs filtered by breed and age
	/// </summary>
	/// <param name="">const char[]</param>
	/// <param name="">int - age</param>
	/// <returns>DynamicArray(Dog)</returns>
	vector <Dog> filterBreedAge(const char[], int);

	/// <summary>
	/// Add a dog to adoption
	/// </summary>
	/// <param name="newDog">Dog</param>
	void addDog(Dog);
};