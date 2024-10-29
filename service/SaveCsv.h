#pragma once
#include "SaveToFile.h"

class SaveCsv : public SaveToFile {
private:
	string filename;
public:
	SaveCsv(string _filename) : filename(_filename) {};
	void save(vector <Dog> data) override;
	void open() override;
};
