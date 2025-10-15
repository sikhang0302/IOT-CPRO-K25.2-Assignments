#ifndef ADDDEVICEDIALOG_H
#define ADDDEVICEDIALOG_H

#include <QDialog>

namespace Ui {
class addDeviceDialog;
}

class addDeviceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDeviceDialog(QWidget *parent = nullptr);
    ~addDeviceDialog();

    QString getDeviceName() const;
    QString getDeviceId() const;
    QString getDeviceLocation() const;
    int getDeviceType() const;


private:
    Ui::addDeviceDialog *ui;
};

#endif // ADDDEVICEDIALOG_H
