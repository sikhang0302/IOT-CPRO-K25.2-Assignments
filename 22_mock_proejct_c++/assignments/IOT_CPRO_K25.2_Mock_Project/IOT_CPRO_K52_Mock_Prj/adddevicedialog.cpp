#include "adddevicedialog.h"
#include "ui_adddevicedialog.h"

addDeviceDialog::addDeviceDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addDeviceDialog)
{
    ui->setupUi(this);
}

addDeviceDialog::~addDeviceDialog()
{
    delete ui;
}

QString addDeviceDialog::getDeviceName() const
{
    return ui->txtDeviceName->toPlainText();
}

QString addDeviceDialog::getDeviceId() const
{
    return ui->txtDeviceId->toPlainText();
}

QString addDeviceDialog::getDeviceLocation() const
{
    return ui->txtDeviceLocation->toPlainText();
}

int addDeviceDialog::getDeviceType() const
{
    return ui->cbDeviceType->currentIndex();
}
