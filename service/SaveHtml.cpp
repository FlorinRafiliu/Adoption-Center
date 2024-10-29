#include "SaveHtml.h"

void SaveHtml::save(vector <Dog> data) {
	ofstream fout(filename);

	fout << "<!DOCTYPE html>\n";
	fout << "<html>\n";

	fout << "<head>\n";
	fout << "	<title>Adoption List</title>\n";
	fout << "</head>\n";

	fout << "<body>\n";
	fout << "<table border=\"1\">\n";

	fout << "	<tr>\n";
	fout << "		<td>Dog</td>\n";
	fout << "		<td>Breed</td>\n";
	fout << "		<td>Age</td>\n";
	fout << "		<td>Photo link</td>\n";
	fout << "	</tr>\n";

	for (Dog dog : data) {
		fout << "	<tr>\n";
		fout << "		<td>" + dog.getName() + "</td>\n";
		fout << "		<td>" + dog.getBreed() + "</td>\n";
		fout << "		<td>" + to_string(dog.getAge()) + "</td>\n";
		fout << "		<td><a href=\"" + dog.getPhoto() + "\">Link</a></td>\n";
		fout << "	</tr>\n";
	}

	fout << "</table>\n";
	fout << "</body>\n";
	fout << "</html>\n";
	
	fout.close();
}

void SaveHtml::open() {
	string link = "start " + filename;
	system(link.c_str());
}
