#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <qboxlayout.h>
#include "../service/Service.h"
#include <iostream>
#include <vector>
#include "AddGUI.h"
#include "RemoveGUI.h"
#include "UpdateGUI.h"
#include <qshortcut.h>

using namespace std;

class AdminGUI : public QWidget {
private:
	Service& service;
	
	QTableWidget* dataTable;

	QVBoxLayout* layoutButtons;
	QPushButton* addDogButton;
	QPushButton* removeDogButton;
	QPushButton* updateDogButton;
	QPushButton* exitButton;
	QPushButton* chartButton;
	QPushButton* undoButton;
	QPushButton* redoButton;

	AddGUI* add;
	RemoveGUI* remove;
	UpdateGUI* update;

	void handleExitButton();
	void handleAddButton();
	void handleRemoveButton();
	void handleUpdateButton();
	void handleUndoButton();
	void handleRedoButton();

public:
	AdminGUI(Service& _service);
	void updateDataTable();
	~AdminGUI();
};