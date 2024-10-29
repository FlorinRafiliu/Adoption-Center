#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qtablewidget.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qlineedit.h>
#include "../service/Service.h"
#include <qdialog.h>
#include <qmessagebox.h>

class AddGUI : public QWidget {
private:
	Service& service;

	QTableWidget* dataTable;

	QLabel* ageLabel;	
	QLineEdit* ageLineEdit;
	QLabel* nameLabel;
	QLineEdit* nameLineEdit;
	QLabel* breedLabel;
	QLineEdit* breedLineEdit;
	QLabel* photoLabel;
	QLineEdit* photoLineEdit;

	QVBoxLayout* layout;
	QHBoxLayout* layout1;
	QHBoxLayout* layout2;
	QHBoxLayout* layout3;
	QHBoxLayout* layout4;

	QPushButton* saveButton;
	
	void handleSaveButton();
	void updateDataTable();
public:
	AddGUI(Service& _service, QTableWidget* _dataTable);

	void run();

	~AddGUI();
};

