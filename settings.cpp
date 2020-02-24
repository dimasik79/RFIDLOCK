//  This file is part of RFID Locker.

//   RFID Locker is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.

//   Foobar is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.

//   You should have received a copy of the GNU General Public License
//   along with Foobar.  If not, see <https://www.gnu.org/licenses/>.


#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>

#include "settings.h"
#include "ui_settings.h"


QString pass;

//const QString path = ".\\conf\\";
//QDir setting(path);
QFile File("settings");

QTextStream f(&File);

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    File.open(QFile::NewOnly);
    f << "0";
    File.close();


}


settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{



        File.open(QFile::ReadWrite | QFile::Text);
        if(!File.isOpen()){
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
        }
        else{
            f >> pass;
            File.close();
            if(ui->lineEdit->text() == pass){

            File.open(QFile::WriteOnly);
            f << ui->lineEdit_2->text() + "";
            File.close();
            QMessageBox::information(this, "Успешно", "Успешно");
            }
        }


}
