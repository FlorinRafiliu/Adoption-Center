#pragma once
#include <fstream>
using namespace std;

class Dog {
	friend ifstream& operator>>(ifstream& is, Dog& dog);
	friend ofstream& operator<<(ofstream& os, Dog& dog);
	friend istream& operator>>(istream& is, Dog& dog);
	friend ostream& operator<<(ostream & os, Dog & dog);

private:
	int age;
	string name, breed, link;
public:

	/// <summary>
	/// Constructor for class Dog
	/// </summary>
	/// <param name="_age">int</param>
	/// <param name="_name">const string</param>
	/// <param name="_breed">const string</param>
	/// <param name="_link">const string</param>
	Dog(int _age, const string& _name, const string& _breed, const string& _link);

	/// <summary>
	/// Constructor for uninitialized Dog
	/// </summary>
	Dog();

	/// <summary>
	/// == Operator override
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>
	bool operator==(Dog other);

	/// <summary>
	/// Getter for age property
	/// </summary>
	/// <returns>int - the age</returns>
	int getAge();

	/// <summary>
	/// Getter for name property
	/// </summary>
	/// <returns>const string </returns>
	string getName() const;

	/// <summary>
	/// Getter for breed property
	/// </summary>
	/// <returns>const string </returns>
	string getBreed() const;

	/// <summary>
	/// Getter for photo-link property
	/// </summary>
	/// <returns>const string </returns>
	string getPhoto() const;
};