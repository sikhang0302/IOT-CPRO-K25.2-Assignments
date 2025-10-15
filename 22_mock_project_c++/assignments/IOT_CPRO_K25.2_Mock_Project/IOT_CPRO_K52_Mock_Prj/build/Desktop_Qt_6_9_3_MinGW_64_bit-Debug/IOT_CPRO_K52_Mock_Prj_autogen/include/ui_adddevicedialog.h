/********************************************************************************
** Form generated from reading UI file 'adddevicedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDEVICEDIALOG_H
#define UI_ADDDEVICEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_addDeviceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *txtDeviceName;
    QTextEdit *txtDeviceId;
    QTextEdit *txtDeviceLocation;
    QComboBox *cbDeviceType;

    void setupUi(QDialog *addDeviceDialog)
    {
        if (addDeviceDialog->objectName().isEmpty())
            addDeviceDialog->setObjectName("addDeviceDialog");
        addDeviceDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addDeviceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(addDeviceDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 141, 20));
        label_2 = new QLabel(addDeviceDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 91, 20));
        label_3 = new QLabel(addDeviceDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 101, 20));
        label_4 = new QLabel(addDeviceDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 91, 20));
        txtDeviceName = new QTextEdit(addDeviceDialog);
        txtDeviceName->setObjectName("txtDeviceName");
        txtDeviceName->setGeometry(QRect(120, 10, 271, 31));
        txtDeviceId = new QTextEdit(addDeviceDialog);
        txtDeviceId->setObjectName("txtDeviceId");
        txtDeviceId->setGeometry(QRect(120, 50, 271, 31));
        txtDeviceLocation = new QTextEdit(addDeviceDialog);
        txtDeviceLocation->setObjectName("txtDeviceLocation");
        txtDeviceLocation->setGeometry(QRect(120, 150, 271, 31));
        cbDeviceType = new QComboBox(addDeviceDialog);
        cbDeviceType->addItem(QString());
        cbDeviceType->addItem(QString());
        cbDeviceType->addItem(QString());
        cbDeviceType->addItem(QString());
        cbDeviceType->setObjectName("cbDeviceType");
        cbDeviceType->setGeometry(QRect(120, 110, 271, 26));

        retranslateUi(addDeviceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addDeviceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addDeviceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addDeviceDialog);
    } // setupUi

    void retranslateUi(QDialog *addDeviceDialog)
    {
        addDeviceDialog->setWindowTitle(QCoreApplication::translate("addDeviceDialog", "Add New Device", nullptr));
        label->setText(QCoreApplication::translate("addDeviceDialog", "Device Name", nullptr));
        label_2->setText(QCoreApplication::translate("addDeviceDialog", "Device ID", nullptr));
        label_3->setText(QCoreApplication::translate("addDeviceDialog", "Device Type", nullptr));
        label_4->setText(QCoreApplication::translate("addDeviceDialog", "Location", nullptr));
        cbDeviceType->setItemText(0, QCoreApplication::translate("addDeviceDialog", "Temperature Sensor", nullptr));
        cbDeviceType->setItemText(1, QCoreApplication::translate("addDeviceDialog", "Pressure Sensor", nullptr));
        cbDeviceType->setItemText(2, QCoreApplication::translate("addDeviceDialog", "Humidity Sensor", nullptr));
        cbDeviceType->setItemText(3, QCoreApplication::translate("addDeviceDialog", "Light Switch", nullptr));

    } // retranslateUi

};

namespace Ui {
    class addDeviceDialog: public Ui_addDeviceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDEVICEDIALOG_H
