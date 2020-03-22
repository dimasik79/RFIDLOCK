#pragma once

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>


namespace Ui {
class SerialChange;
}

class SerialChange : public QDialog
{
    Q_OBJECT

public:
    explicit SerialChange(QWidget *parent = nullptr);
    ~SerialChange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SerialChange *ui;
};

