#include "./repository/Repo.h"
#include "./service/Service.h"
#include "./service/ServiceUser.h"
#include "./tests/Tests.h"
#include "./repository/FileRepository.h"
#include <iostream>
#include "./service/SaveCsv.h"
#include "./service/SaveHtml.h"

#include <qapplication.h>
#include "./gui/ModeGUI1.h"

using namespace std;

int main(int argc, char* argv[]) {
	QApplication application(argc, argv);

	allTests();

	FileRepository repo("input.txt");
	Validator val;
	Service service(repo, val);

	Repository adoptionList;
	ServiceUser serviceUser(repo, adoptionList);

	ModeGUI1 modeGui(service, serviceUser);
	modeGui.show();
	
	return application.exec();
}