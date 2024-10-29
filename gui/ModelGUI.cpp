#include "ModelGUI.h"

ModelGUI::ModelGUI(ServiceUser& _service, QObject* parent) : service(_service), QAbstractTableModel(parent) {}

int ModelGUI::rowCount(const QModelIndex& parent) const {
	return (service.getUserList()).size();
}

int ModelGUI::columnCount(const QModelIndex& parent) const {
	return 4;
}

QVariant ModelGUI::data(const QModelIndex& index, int role) const {
	
	if (role == Qt::DisplayRole) {
		int row = index.row();
		int column = index.column();
		vector <Dog> dogs = service.getUserList();

		//return QString(to_string(row).c_str()) + QString(to_string(column).c_str());

		if (column == 0) {
			return QString(to_string(dogs[row].getAge()).c_str());
		}
		else if (column == 1) {
			return QString(dogs[row].getName().c_str());
		}
		else if (column == 2) {
			return QString(dogs[row].getBreed().c_str());
		}
		else if (column == 3) {
			return QString(dogs[row].getPhoto().c_str());
		}
	}
	return QVariant();
}

QVariant ModelGUI::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("Age");
		case 1:
			return QString("Name");
		case 2:
			return QString("Breed");
		case 3:
			return QString("Photo Link");
		}
	}
	return QVariant();
}
