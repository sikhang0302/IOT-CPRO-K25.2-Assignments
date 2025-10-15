/********************************************************************************
** Form generated from reading UI file 'smartdevicemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTDEVICEMANAGER_H
#define UI_SMARTDEVICEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartDeviceManager
{
public:
    QWidget *centralwidget;
    QWidget *bodyContainer;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QPlainTextEdit *txtDevInfo;
    QWidget *controlContainer;
    QPushButton *btnAddDevice;
    QPushButton *btnRemoveDevice;
    QPushButton *btnLightSwitch;
    QWidget *logWidget;
    QPlainTextEdit *txtLogging;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SmartDeviceManager)
    {
        if (SmartDeviceManager->objectName().isEmpty())
            SmartDeviceManager->setObjectName("SmartDeviceManager");
        SmartDeviceManager->resize(800, 656);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SmartDeviceManager->sizePolicy().hasHeightForWidth());
        SmartDeviceManager->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(SmartDeviceManager);
        centralwidget->setObjectName("centralwidget");
        bodyContainer = new QWidget(centralwidget);
        bodyContainer->setObjectName("bodyContainer");
        bodyContainer->setGeometry(QRect(11, 11, 771, 331));
        label_2 = new QLabel(bodyContainer);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 10, 120, 20));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        layoutWidget = new QWidget(bodyContainer);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(13, 13, 172, 311));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setMaximumSize(QSize(170, 500));

        verticalLayout->addWidget(listWidget);

        txtDevInfo = new QPlainTextEdit(bodyContainer);
        txtDevInfo->setObjectName("txtDevInfo");
        txtDevInfo->setGeometry(QRect(237, 39, 521, 281));
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txtDevInfo->sizePolicy().hasHeightForWidth());
        txtDevInfo->setSizePolicy(sizePolicy4);
        controlContainer = new QWidget(centralwidget);
        controlContainer->setObjectName("controlContainer");
        controlContainer->setGeometry(QRect(10, 350, 781, 61));
        btnAddDevice = new QPushButton(controlContainer);
        btnAddDevice->setObjectName("btnAddDevice");
        btnAddDevice->setGeometry(QRect(10, 10, 271, 41));
        btnRemoveDevice = new QPushButton(controlContainer);
        btnRemoveDevice->setObjectName("btnRemoveDevice");
        btnRemoveDevice->setGeometry(QRect(510, 10, 271, 41));
        btnLightSwitch = new QPushButton(controlContainer);
        btnLightSwitch->setObjectName("btnLightSwitch");
        btnLightSwitch->setGeometry(QRect(370, 10, 131, 41));
        logWidget = new QWidget(centralwidget);
        logWidget->setObjectName("logWidget");
        logWidget->setGeometry(QRect(11, 417, 778, 181));
        txtLogging = new QPlainTextEdit(logWidget);
        txtLogging->setObjectName("txtLogging");
        txtLogging->setGeometry(QRect(10, 40, 761, 131));
        label_3 = new QLabel(logWidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 121, 20));
        SmartDeviceManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SmartDeviceManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        SmartDeviceManager->setMenuBar(menubar);
        statusbar = new QStatusBar(SmartDeviceManager);
        statusbar->setObjectName("statusbar");
        SmartDeviceManager->setStatusBar(statusbar);

        retranslateUi(SmartDeviceManager);

        QMetaObject::connectSlotsByName(SmartDeviceManager);
    } // setupUi

    void retranslateUi(QMainWindow *SmartDeviceManager)
    {
        SmartDeviceManager->setWindowTitle(QCoreApplication::translate("SmartDeviceManager", "SmartDeviceManager", nullptr));
        label_2->setText(QCoreApplication::translate("SmartDeviceManager", "Th\303\264ng Tin Thi\341\272\277t B\341\273\213", nullptr));
        label->setText(QCoreApplication::translate("SmartDeviceManager", "Danh S\303\241ch Thi\341\272\277t B\341\273\213", nullptr));
        btnAddDevice->setText(QCoreApplication::translate("SmartDeviceManager", "Th\303\252m Thi\341\272\277t B\341\273\213", nullptr));
        btnRemoveDevice->setText(QCoreApplication::translate("SmartDeviceManager", "X\303\263a Thi\341\272\277t B\341\273\213", nullptr));
        btnLightSwitch->setText(QCoreApplication::translate("SmartDeviceManager", "B\341\272\255t/T\341\272\257t", nullptr));
        label_3->setText(QCoreApplication::translate("SmartDeviceManager", "Logging", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartDeviceManager: public Ui_SmartDeviceManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTDEVICEMANAGER_H
