#pragma once

#include <QAbstractTableModel>
#include "../service/ServiceUser.h"

class ModelGUI : public QAbstractTableModel {

    Q_OBJECT

public:
    explicit ModelGUI(ServiceUser& _service, QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    ServiceUser& service;
};