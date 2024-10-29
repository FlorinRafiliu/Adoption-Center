#include "AdminGUI.h"

AdminGUI::AdminGUI(Service& _service) : service(_service) {
	this->setFixedSize(QSize(500, 500));

	//Data table
	dataTable = new QTableWidget;
	updateDataTable();

	add = new AddGUI(_service, dataTable);
	remove = new RemoveGUI(_service, dataTable);
	update = new UpdateGUI(_service, dataTable);

	//Buttons
	addDogButton = new QPushButton("Add Dog");
	removeDogButton = new QPushButton("Remove Dog");
	updateDogButton = new QPushButton("Update Dog");
	undoButton = new QPushButton("Undo");
	redoButton = new QPushButton("Redo");
	exitButton = new QPushButton("Exit");

	connect(exitButton, &QPushButton::released, this, &AdminGUI::handleExitButton);
	connect(addDogButton, &QPushButton::released, this, &AdminGUI::handleAddButton);
	connect(removeDogButton, &QPushButton::released, this, &AdminGUI::handleRemoveButton);
	connect(updateDogButton, &QPushButton::released, this, &AdminGUI::handleUpdateButton);
	connect(undoButton, &QPushButton::released, this, &AdminGUI::handleUndoButton);
	connect(redoButton, &QPushButton::released, this, &AdminGUI::handleRedoButton);

	QShortcut* shortcut1 = new QShortcut(QKeySequence("Ctrl+Z"), this);
	connect(shortcut1, &QShortcut::activated, this, &AdminGUI::handleUndoButton);

	QShortcut* shortcut2 = new QShortcut(QKeySequence("Ctrl+Y"), this);
	connect(shortcut2, &QShortcut::activated, this, &AdminGUI::handleRedoButton);

	//Layout
	layoutButtons = new QVBoxLayout(this);
	layoutButtons->addWidget(dataTable);
	layoutButtons->addWidget(addDogButton);
	layoutButtons->addWidget(removeDogButton);
	layoutButtons->addWidget(updateDogButton);
	layoutButtons->addWidget(undoButton);
	layoutButtons->addWidget(redoButton);
	layoutButtons->addWidget(exitButton);
}

void AdminGUI::handleExitButton() {
	this->close();
}

void AdminGUI::handleAddButton() {
	add->run();
}

void AdminGUI::handleRemoveButton() {
	remove->run();
}

void AdminGUI::handleUpdateButton() {
	update->run();
}

void AdminGUI::handleUndoButton() {
	try {
		service.undo();
	}
	catch (exception& e) {
		QMessageBox msgBox;
		msgBox.warning(this, "Eroare!", e.what(), QMessageBox::StandardButton::Close);
	};

	updateDataTable();
}

void AdminGUI::handleRedoButton() {
	try {
		service.redo();
	}
	catch (exception& e) {
		QMessageBox msgBox;
		msgBox.warning(this, "Eroare!", e.what(), QMessageBox::StandardButton::Close);
	};

	updateDataTable();
}

void AdminGUI::updateDataTable() {
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

AdminGUI::~AdminGUI() {
	delete addDogButton;
	delete removeDogButton;
	delete updateDogButton;
	delete exitButton;
	delete layoutButtons;
}
