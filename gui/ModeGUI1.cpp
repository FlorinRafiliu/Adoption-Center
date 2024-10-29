#include "ModeGUI1.h"

ModeGUI1::ModeGUI1(Service& _service, ServiceUser& _serviceUser, QWidget* parent) 
	: service(_service), serviceUser(_serviceUser), QWidget(parent) {
	ui.setupUi(this);
	
	ui.label_2->hide();
	ui.label_3->hide();
	ui.extensionLineEdit->hide();
	ui.filenameLineEdit->hide();

	connections();
}

ModeGUI1::~ModeGUI1()
{}

void ModeGUI1::connections() {
	connect(ui.startButton, &QPushButton::clicked, 
		this, &ModeGUI1::handleStartButton);
	connect(ui.cancelButton, &QPushButton::clicked, 
		this, &ModeGUI1::handleCancelButton);
	connect(ui.adminRadioButton, &QRadioButton::clicked,
		this, &ModeGUI1::adminRadioButtonHandler);
	connect(ui.userRadioButton, &QRadioButton::clicked,
		this, &ModeGUI1::userRadioButtonHandler);
}

void ModeGUI1::adminRadioButtonHandler() {
	ui.label_2->hide();
	ui.label_3->hide();
	ui.extensionLineEdit->hide();
	ui.extensionLineEdit->setText("");
	ui.filenameLineEdit->hide();
	ui.filenameLineEdit->setText("");
}

void ModeGUI1::userRadioButtonHandler() {
	ui.label_2->show();
	ui.label_3->show();
	ui.extensionLineEdit->show();
	ui.filenameLineEdit->show();
}

void ModeGUI1::handleStartButton() {
	if (ui.adminRadioButton->isChecked()) {
		this->hide();
		AdminGUI* admin = new AdminGUI(service);
		admin->show();
	}
	else if(ui.userRadioButton->isChecked()) {
		string extension = ui.extensionLineEdit->text().toStdString();
		string filename = ui.filenameLineEdit->text().toStdString();

		filename = filename + "." + extension;
		if (extension == "html") {
			SaveHtml* save = new SaveHtml(filename);
			UserGUI* user = new UserGUI(serviceUser, *save);
			this->hide();
			user->show();
		}
		else if (extension == "csv") {
			SaveCsv* save = new SaveCsv(filename);
			UserGUI* user = new UserGUI(serviceUser, *save);
			this->hide();
			user->show();
		}
	}
}

void ModeGUI1::handleCancelButton() {
	this->close();
}
