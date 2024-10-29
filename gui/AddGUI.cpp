#include "AddGUI.h"

AddGUI::AddGUI(Service& _service, QTableWidget* _dataTable) : service(_service) , dataTable(_dataTable) {

	saveButton = new QPushButton("Save");
	connect(saveButton, &QPushButton::released, this, &AddGUI::handleSaveButton);

	ageLabel = new QLabel("Age: ");
	nameLabel = new QLabel("Name: ");
	breedLabel = new QLabel("Breed: ");
	photoLabel = new QLabel("Photo link: ");

	ageLineEdit = new QLineEdit;
	nameLineEdit = new QLineEdit;
	breedLineEdit = new QLineEdit;
	photoLineEdit = new QLineEdit;

	layout1 = new QHBoxLayout;
	layout1->addWidget(ageLabel);
	layout1->addWidget(ageLineEdit);

	layout2 = new QHBoxLayout;
	layout2->addWidget(nameLabel);
	layout2->addWidget(nameLineEdit);

	layout3 = new QHBoxLayout;
	layout3->addWidget(breedLabel);
	layout3->addWidget(breedLineEdit);

	layout4 = new QHBoxLayout;
	layout4->addWidget(photoLabel);
	layout4->addWidget(photoLineEdit);

	layout = new QVBoxLayout(this);
	layout->addLayout(layout1);
	layout->addLayout(layout2);
	layout->addLayout(layout3);
	layout->addLayout(layout4);
	layout->addWidget(saveButton);
}

void AddGUI::run() {
	ageLineEdit->setText("");
	nameLineEdit->setText("");
	breedLineEdit->setText("");
	photoLineEdit->setText("");

	this->show();
}

void AddGUI::handleSaveButton() {
	
	int age = ageLineEdit->text().toInt();
	string name = nameLineEdit->text().toStdString();
	string breed = breedLineEdit->text().toStdString();
	string photo = photoLineEdit->text().toStdString();
	try {
		service.addDog(age, name, breed, photo);
	}
	catch (exception& e) {
		QMessageBox msgBox;
		msgBox.warning(this, "Eroare!", e.what(), QMessageBox::StandardButton::Close);
	};

	updateDataTable();

	this->close();
}

void AddGUI::updateDataTable() {
	dataTable->clear();
	dataTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

	dataTable->setRowCount(0);
	dataTable->setColumnCount(4);

	QStringList header;
	header << "Age" << "Name" << "Breed" << "Photo link";
	dataTable->setHorizontalHeaderLabels(header);

	vector<Dog> data = service.getData();
	for (Dog dog : data) {
		dataTable->insertRow(dataTable->rowCount());

		dataTable->setItem(dataTable->rowCount() - 1, 0, new QTableWidgetItem(to_string(dog.getAge()).c_str()));
		dataTable->setItem(dataTable->rowCount() - 1, 1, new QTableWidgetItem(dog.getName().c_str()));
		dataTable->setItem(dataTable->rowCount() - 1, 2, new QTableWidgetItem(dog.getBreed().c_str()));
		dataTable->setItem(dataTable->rowCount() - 1, 3, new QTableWidgetItem(dog.getPhoto().c_str()));
	}
}

AddGUI::~AddGUI() {
	delete saveButton;
	delete ageLineEdit;
	delete nameLineEdit;
	delete breedLineEdit;
	delete photoLineEdit;
	delete ageLabel;
	delete nameLabel;
	delete breedLabel;
	delete photoLabel;
	delete layout1;
	delete layout2;
	delete layout3;
	delete layout4;
	delete layout;
}
