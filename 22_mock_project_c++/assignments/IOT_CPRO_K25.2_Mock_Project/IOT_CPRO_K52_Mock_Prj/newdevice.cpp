#include "newdevice.h"
#include "ui_newdevice.h"

NewDevice::NewDevice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewDevice)
{
    ui->setupUi(this);
    setWindowTitle("Add New Device");

    // ví dụ: thêm lựa chọn cho comboBox
    ui->comboBoxType->addItem("Light Switch");
    ui->comboBoxType->addItem("Sensor");
    ui->comboBoxType->addItem("Camera");
}

NewDevice::~NewDevice()
{
    delete ui;
}

QString NewDevice::deviceName() const {
    return ui->lineEditName->text();
}

QString NewDevice::deviceId() const {
    return ui->lineEditId->text();
}

QString NewDevice::deviceType() const {
    return ui->comboBoxType->currentText();
}
