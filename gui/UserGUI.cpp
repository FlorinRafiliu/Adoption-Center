#include "UserGUI.h"

UserGUI::UserGUI(ServiceUser& _service, SaveToFile& _save, QWidget *parent) :
	service(_service), save(_save), QWidget(parent) {

	ui.setupUi(this);
	ui.dataTableView->hide();
	connections();
}

UserGUI::~UserGUI() {}

void UserGUI::populateTable() {
	return ;
}

void UserGUI::connections() {
	connect(ui.exitButton, &QPushButton::clicked,
		this, &UserGUI::exitButtonHandler);
	connect(ui.adoptButton, &QPushButton::clicked,
		this, &UserGUI::adoptButtonHandler);
	connect(ui.adoptionButton, &QPushButton::clicked,
		this, &UserGUI::adoptionButtonHandler);
	connect(ui.filterButton, &QPushButton::clicked,
		this, &UserGUI::filterButtonHandler);
	connect(ui.exportButton, &QPushButton::clicked,
		this, &UserGUI::exportButtonHandler);
}

void UserGUI::exitButtonHandler() {
	save.save(service.getUserList());
	this->close();
}

void UserGUI::adoptButtonHandler() {
	ui.dataTableView->hide();
	AdoptGUI* adopt = new AdoptGUI(service, service.getDogsList());
	adopt->show();
}

void UserGUI::adoptionButtonHandler() {
	populateTable();
	model = new ModelGUI(service);
	ui.dataTableView->setModel(model);
	ui.dataTableView->show();
}

void UserGUI::filterButtonHandler() {
	bool ok;
	QString breed = QInputDialog::getText(this, tr("Breed"),
		tr("Breed:"), QLineEdit::Normal, "", &ok);

	if (ok == false) return;

	QString age = QInputDialog::getText(this, tr("Age"),
		tr("Age:"), QLineEdit::Normal, "", &ok);

	if (ok == false || age.isEmpty() || age.startsWith('-') || age.toInt() == 0) return;

	vector <Dog> dogs = service.filterBreedAge(breed.toStdString().c_str(), age.toInt());
	ui.dataTableView->hide();
	AdoptGUI* adopt = new AdoptGUI(service, dogs);
	adopt->show();
}

void UserGUI::exportButtonHandler() {
	save.save(service.getUserList());
	save.open();
}
