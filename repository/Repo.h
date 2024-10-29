#pragma once
#include "../domain/Dog.h"
#include <vector>
#include <algorithm>
using namespace std;

class Repository {
protected:
	vector <Dog> data;
public:
	/// <summary>
	/// Add a dog
	/// </summary>
	/// <param name="newDog">Dog</param>
	virtual void addDog(Dog);

	/// <summary>
	/// Remove an existing dog
	/// </summary>
	/// <param name="name">const string</param>
	/// <param name="breed">const string</param>
	virtual Dog removeDog(const string&, const string&);
	
	/// <summary>
	/// Update a dog
	/// </summary>
	/// <param name="name">const string</param>
	/// <param name="breed">const string</param>
	/// <param name="newDog">Dog </param>
	virtual Dog updateDog(const string&, const string&, Dog);

	/// <summary>
	/// Getter for the list of dogs
	/// </summary>
	/// <returns> vector(Dog)</returns>
	virtual vector <Dog> getData();
};

class RepoException : public exception {
private:
	const char* message;

public:
	RepoException(const char* _message) {
		message = _message;
	}
	const char* what() const override {
		return message;
	}
};