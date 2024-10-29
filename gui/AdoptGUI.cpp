#include "AdoptGUI.h"

AdoptGUI::AdoptGUI(ServiceUser& _service, vector <Dog> _dogs, QWidget *parent) 
	: service(_service), dogs(_dogs), QWidget(parent) {
	ui.setupUi(this);
	connections();

	current = 0;
	display();
}

AdoptGUI::~AdoptGUI()
{}

void AdoptGUI::connections() {
	connect(ui.cancelButton, &QPushButton::clicked,
		this, &AdoptGUI::cancelButtonHandler);
	connect(ui.adoptButton, &QPushButton::clicked,
		this, &AdoptGUI::adoptButtonHandler);
	connect(ui.nextButton, &QPushButton::clicked,
		this, &AdoptGUI::nextButtonHandler);
}

void AdoptGUI::display() {
	Dog dog = dogs[current];

	string link = "start " + dog.getPhoto();
	system(link.c_str());

	string age = "Age: " + to_string(dog.getAge());
	ui.ageLabel->setText(age.c_str());
	ui.nameLabel->setText(("Name: " + dog.getName()).c_str());
	ui.breedLabel->setText(("Breed: " + dog.getBreed()).c_str());
}

void AdoptGUI::cancelButtonHandler() {
	this->close();
}

void AdoptGUI::nextButtonHandler() {
	current += 1;
	if (current == dogs.size())
		current = 0;
	display();
}

void AdoptGUI::adoptButtonHandler() {
	try {
		service.addDog(dogs[current]);
	}
	catch (exception& e) {}
	nextButtonHandler();
}
