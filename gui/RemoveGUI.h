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

class RemoveGUI : public QWidget {
private:
	Service& service;

	QTableWidget* dataTable;

	QLabel* nameLabel;
	QLineEdit* nameLineEdit;
	QLabel* breedLabel;
	QLineEdit* breedLineEdit;

	QVBoxLayout* layout;
	QHBoxLayout* layout1;
	QHBoxLayout* layout2;

	QPushButton* removeButton;

	void handleRemoveButton();
	void updateDataTable();
public:
	RemoveGUI(Service& _service, QTableWidget* _dataTable);

	void run();

	~RemoveGUI();
};

