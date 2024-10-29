#pragma once
#include <string>
#include "../domain/Dog.h"
#include <vector>
using namespace std;

class SaveToFile {
public:
	SaveToFile() = default;
	virtual void save(vector <Dog> data) = 0;
	virtual void open() = 0;
};

