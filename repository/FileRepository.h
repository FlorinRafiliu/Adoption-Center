#pragma once
#include "../repository/Repo.h"
#include <string>
#include <fstream>

using namespace std;

class FileRepository : public Repository {
private:
	string filename;
	void read_all();
	void write_all();
public:

	/// <summary>
	/// FileRepository constructor
	/// </summary>
	/// <param name="filename">string </param>
	FileRepository(string);

	/// <summary>
	/// Add a dog
	/// </summary>
	/// <param name="newDog">Dog</param>
	void addDog(Dog);

	/// <summary>
	/// Remove an existing dog
	/// </summary>
	/// <param name="name">const string</param>
	/// <param name="breed">const string</param>
	Dog removeDog(const string&, const string&);

	/// <summary>
	/// Update a dog
	/// </summary>
	/// <param name="name">const string</param>
	/// <param name="breed">const string</param>
	/// <param name="newDog">Dog </param>
	Dog updateDog(const string&, const string&, Dog);

	/// <summary>
	/// Getter for the list of dogs
	/// </summary>
	/// <returns> vector(Dog)</returns>
	vector <Dog> getData();

	/// <summary>
	/// Clear the repository
	/// </summary>
	void clearRepo();
};

