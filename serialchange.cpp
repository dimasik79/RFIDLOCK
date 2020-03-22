
#include "serialchange.h"
#include "ui_serialchange.h"

QFile Filea("settings");

QTextStream fa(&Filea);

QString passa;

SerialChange::SerialChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialChange)
{
    ui->setupUi(this);
}

SerialChange::~SerialChange()
{
    delete ui;
}

void SerialChange::on_pushButton_clicked()
{




            Filea.open(QFile::ReadWrite | QFile::Text);
            if(!Filea.isOpen()){
                QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
            }
            else{
                fa >> passa;
                fa << "";
                Filea.close();
                Filea.open(QFile::ReadWrite | QFile::Text);

                fa << passa << " " << ui->lineEdit->text() + "";
                Filea.close();
                QMessageBox::information(this, "Успешно", "Успешно");

            }



}
