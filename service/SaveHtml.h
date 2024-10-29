#pragma once
#include "SaveToFile.h"

class SaveHtml : public SaveToFile {
private:
	string filename;
public:
	SaveHtml(string _filename) : filename(_filename) {};
	void save(vector <Dog> data) override;
	void open() override;
};

