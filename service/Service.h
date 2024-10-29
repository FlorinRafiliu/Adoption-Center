#pragma once

#include "../domain/Dog.h"
#include "../repository/Repo.h"
#include "Validator.h"
#include "../domain/Action.h"
#include "AddAction.h"
#include "../domain/RemoveAction.h"
#include "../domain/UpdateAction.h"

class Service {
private:
	Repository& repo;
	Validator& val;
	vector <Action*> actions;
	int currentAction;

public:
	/// <summary>
	/// Service constructor
	/// </summary>
	/// <param name="_repo">Repository</param>
	Service(Repository& _repo, Validator& _val);

	void undo();
	void redo();

	/// <summary>
	/// Add a dog to repo
	/// </summary>
	/// <param name="age">- int</param>
	/// <param name="name">- const string</param>
	/// <param name="breed">- const string</param>
	/// <param name="link">- const string</param>
	void addDog(int, const string&, const string&, const string&);

	/// <summary>
	/// Remove a dog from repo
	/// </summary>
	/// <param name="name">- const string</param>
	/// <param name="breed">- const string</param>
	void removeDog(const string&, const string&);

	/// <summary>
	/// Update a dog
	/// </summary>
	/// <param name="name">const string</param>
	/// <param name="breed">const string</param>
	/// <param name="newAge">int</param>
	/// <param name="newLink">const string</param>
	void updateDog(const string&, const string&, int, const string&);

	/// <summary>
	/// Getter for the list of dogs
	/// </summary>
	/// <returns> vector(Dog) </returns>
	vector <Dog> getData();
};

class ServiceException : public exception {
private:
	const char* message;

public:
	ServiceException(const char* _message) {
		message = _message;
	}
	const char* what() const override {
		return message;
	}
};