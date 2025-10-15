#include "smartdevicemanager.h"
#include "./ui_smartdevicemanager.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include "devicemanager.h"
#include "adddevicedialog.h"


SmartDeviceManager::SmartDeviceManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmartDeviceManager)
{
    ui->setupUi(this);
    connect(ui->listWidget,&QListWidget::itemSelectionChanged,this,&SmartDeviceManager::on_DeviceSelected);
    ui->btnLightSwitch->hide();
}

void SmartDeviceManager::updateDeviceList(const std::vector<std::unique_ptr<Device>>& list)
{
    ui->listWidget->clear();
    for(auto& device:list)
    {
        ui->listWidget->addItem(QString::fromStdString(device->getDevName()));
    }
}

void SmartDeviceManager::updateLightSwitchValue(QPlainTextEdit* edit, const std::string& deviceValue) {
    QTextDocument *doc = edit->document();
    QTextCursor cursor(doc);

    // Find line that starting with "Trạng Thái Đèn:      "
    QTextCursor found = doc->find("Trạng Thái Đèn:      ", cursor);
    if (!(found.isNull())) {
        // Select entire line
        found.select(QTextCursor::LineUnderCursor);

        // Update new value
        auto updatedLine = "Trạng Thái Đèn:      "  + QString::fromStdString(deviceValue);
        found.removeSelectedText();
        found.insertText(updatedLine);
    } else { // If not found, add new line
       edit->appendPlainText("Trạng Thái Đèn:      "  + QString::fromStdString(deviceValue));
    }
}

SmartDeviceManager::~SmartDeviceManager()
{
    delete ui;
}


void SmartDeviceManager::on_btnAddDevice_clicked()
{

    addDeviceDialog diaglog(this);

    int result = diaglog.exec();

    if(result == QDialog::Accepted)
    {
        auto device  = DeviceFactory::createDevice(diaglog.getDeviceName().toStdString(),
                                                  diaglog.getDeviceId().toStdString(),
                                                  diaglog.getDeviceLocation().toStdString(),
                                                  diaglog.getDeviceType());
        if(device)
        {
            if (deviceManager::getInstance().isDeviceIdExist(device->getDevId())) {
                ui->txtLogging->appendPlainText("");
                ui->txtLogging->appendPlainText("    ID Thiết Bị: " + diaglog.getDeviceId() + " Đã Tồn Tại");
            } else {
                deviceManager::getInstance().addDevice(std::move(device));
                updateDeviceList(deviceManager::getInstance().getDevices());
                ui->txtLogging->appendPlainText("");
                ui->txtLogging->appendPlainText("Thêm thiết bị mới:");
                ui->txtLogging->appendPlainText("    Tên Thiết Bị: " + diaglog.getDeviceName());
                ui->txtLogging->appendPlainText("    ID Thiết Bị: " + diaglog.getDeviceId());
                ui->txtLogging->appendPlainText("    Vị Trí Thiết Bị: " + diaglog.getDeviceLocation());
                ui->txtLogging->appendPlainText("    Kiểu Thiết Bị: " + QString::number(diaglog.getDeviceType()));
                qDebug() << "Diaglog nhan OK";
                qDebug() << diaglog.getDeviceName();
                qDebug() << diaglog.getDeviceId();
                qDebug() << diaglog.getDeviceLocation();
                qDebug() << diaglog.getDeviceType();
            }
        }
    }
    else
    {
        qDebug() << "Dialog bi tu choi/dong.";
    }
}


void SmartDeviceManager::on_btnRemoveDevice_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,
                                  "Remove Device",
                                  "Are you sure you want to remove this device?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (deviceManager::getInstance().getDevices().empty())
        {
            qDebug() << "List of devices is empty";
        }
        else
        {
            int itemIdx = ui->listWidget->row(ui->listWidget->currentItem());
            auto deviceId = deviceManager::getInstance().getDevices().at(itemIdx)->getDevId();

            // Gọi hàm xóa thiết bị ở đây
            deviceManager::getInstance().removeDevice(deviceId);
            updateDeviceList(deviceManager::getInstance().getDevices());

            ui->txtLogging->appendPlainText("");
            ui->txtLogging->appendPlainText("Xóa Thiết Bị Có ID: "+ QString::fromStdString(deviceId));
            qDebug() << "Remove Device ID: " << QString::fromStdString(deviceId);
        }
    } else {
        qDebug() << "User clicked No";
    }
}

void SmartDeviceManager::on_btnLightSwitch_clicked() {
    int itemIdx = ui->listWidget->row(ui->listWidget->currentItem());

    deviceManager::getInstance().getDevices().at(itemIdx)->toggleDev();

    auto deviceValue = deviceManager::getInstance().getDevices().at(itemIdx)->getValue();
    updateLightSwitchValue(ui->txtDevInfo, deviceValue);
}

void SmartDeviceManager::on_DeviceSelected()
{
    ui->btnLightSwitch->hide();

    if (deviceManager::getInstance().getDevices().empty())
    {
        // CLear Text Infor
        ui->txtDevInfo->clear();
    }
    else
    {
        int itemIdx = ui->listWidget->row(ui->listWidget->currentItem());
        if (itemIdx == deviceManager::getInstance().getDevices().size()) {
            itemIdx -= 1;
        }
        auto deviceName = deviceManager::getInstance().getDevices().at(itemIdx)->getDevName();
        auto deviceId = deviceManager::getInstance().getDevices().at(itemIdx)->getDevId();
        auto deviceLocation = deviceManager::getInstance().getDevices().at(itemIdx)->getDevLocation();
        auto deviceType = deviceManager::getInstance().getDevices().at(itemIdx)->getDevType();

        auto deviceValue = deviceManager::getInstance().getDevices().at(itemIdx)->getValue();

        // CLear Text Infor
        ui->txtDevInfo->clear();

        ui->txtDevInfo->appendPlainText("Tên Thiết Bị:      " + QString::fromStdString(deviceName));
        ui->txtDevInfo->appendPlainText("ID Thiết Bị:      " + QString::fromStdString(deviceId));
        ui->txtDevInfo->appendPlainText("Vị Trí Thiết Bị:      " + QString::fromStdString(deviceLocation));

        if(Device::TEMPERATURE_SENSOR == deviceType)
        {
            float val = std::stof(deviceValue);
            ui->txtDevInfo->appendPlainText("Nhiệt Độ:      " + QString::number(val,'f',2) + " °C");
        }
        else if(Device::PRESSURE_SENSOR == deviceType)
        {
            float val = std::stof(deviceValue);
            ui->txtDevInfo->appendPlainText("Áp Suất:      " + QString::number(val,'f',2) + " Bar");
        }
        else if(Device::HUMIDITY_SENSOR == deviceType)
        {
            float val = std::stof(deviceValue);
            ui->txtDevInfo->appendPlainText("Độ Ẩm:      " + QString::number(val,'f',2) + " %");
        }
        else if(Device::LIGHT_SWITCH == deviceType)
        {
            ui->btnLightSwitch->show();
            ui->txtDevInfo->appendPlainText("Trạng Thái Đèn:      "  + QString::fromStdString(deviceValue));
        }
        else
        {
            ui->txtDevInfo->appendPlainText("================= Invalid Device Selected ================= ");
        }

        qDebug() << "Selected Item " << itemIdx << " --- " << deviceName;
    }
}
