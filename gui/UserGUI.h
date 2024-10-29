#pragma once

#include <QWidget>
#include "ui_UserGUI.h"
#include <vector>
#include "../service/ServiceUser.h"
#include "AdoptGUI.h"
#include <qinputdialog.h>
#include <qdir.h>
#include "../service/SaveToFile.h"
#include "ModelGUI.h"

using std::vector;

class UserGUI : public QWidget
{
	Q_OBJECT

public:
	UserGUI(ServiceUser& _service, SaveToFile& _save, QWidget* parent = nullptr);
	~UserGUI();

private:
	Ui::UserGUIClass ui;
	ServiceUser& service;
	SaveToFile& save;
	ModelGUI* model;

	void populateTable();
	void connections();
	void exitButtonHandler();
	void adoptButtonHandler();
	void adoptionButtonHandler();
	void filterButtonHandler();
	void exportButtonHandler();
};
