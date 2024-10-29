#pragma once

#include <QWidget>
#include "ui_AdoptGUI.h"
#include "../domain/Dog.h"
#include <vector>
#include <qpixmap.h>
#include "../service/ServiceUser.h"

class AdoptGUI : public QWidget
{
	Q_OBJECT

public:
	AdoptGUI(ServiceUser& _sercice, vector <Dog> _dogs, QWidget *parent = nullptr);
	~AdoptGUI();

private:
	Ui::AdoptGUIClass ui;
	ServiceUser& service;
	vector <Dog> dogs;
	int current;

	void connections();
	void display();
	void cancelButtonHandler();
	void nextButtonHandler();
	void adoptButtonHandler();
};
