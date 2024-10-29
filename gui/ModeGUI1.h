#pragma once

#include <QWidget>
#include "ui_ModeGUI1.h"
#include "../service/Service.h"
#include "../service/ServiceUser.h"
#include "../service/SaveHtml.h"
#include "../service/SaveCsv.h"
#include "AdminGUI.h"
#include "UserGUI.h"

class ModeGUI1 : public QWidget {
	Q_OBJECT

public:
	ModeGUI1(Service& _service, ServiceUser& _serviceUser, QWidget* parent = nullptr);
	~ModeGUI1();

private:
	Ui::ModeGUI1Class ui;
	Service& service;
	ServiceUser& serviceUser;

	void connections();
	void adminRadioButtonHandler();
	void userRadioButtonHandler();
	void handleStartButton();
	void handleCancelButton();
};
