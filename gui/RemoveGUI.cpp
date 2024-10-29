#include "RemoveGUI.h"

void RemoveGUI::handleRemoveButton() {
	string name = nameLineEdit->text().toStdString();
	string breed = breedLineEdit->text().toStdString();

	try {
		service.removeDog(name, breed);
	}
	catch (exception& e) {
		QMessageBox msgBox;
		msgBox.warning(this, "Eroare!", e.what(), QMessageBox::StandardButton::Close);
	};	updateDataTable();

	this->close();
}

void RemoveGUI::updateDataTable() {
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

RemoveGUI::RemoveGUI(Service& _service, QTableWidget* _dataTable) : service(_service), dataTable(_dataTable) {
	removeButton = new QPushButton("Remove");
	connect(removeButton, &QPushButton::released, this, &RemoveGUI::handleRemoveButton);

	nameLabel = new QLabel("Name: ");
	breedLabel = new QLabel("Breed: ");

	nameLineEdit = new QLineEdit;
	breedLineEdit = new QLineEdit;

	layout1 = new QHBoxLayout;
	layout1->addWidget(nameLabel);
	layout1->addWidget(nameLineEdit);

	layout2 = new QHBoxLayout;
	layout2->addWidget(breedLabel);
	layout2->addWidget(breedLineEdit);

	layout = new QVBoxLayout(this);
	layout->addLayout(layout1);
	layout->addLayout(layout2);
	layout->addWidget(removeButton);
}

void RemoveGUI::run()
{
	nameLineEdit->setText("");
	breedLineEdit->setText("");
	this->show();
}

RemoveGUI::~RemoveGUI() {
	delete removeButton;
	delete nameLineEdit;
	delete breedLineEdit;
	delete nameLabel;
	delete breedLabel;
	delete layout1;
	delete layout2;
	delete layout;
}
