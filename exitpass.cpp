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




#include "exitpass.h"
#include "ui_exitpass.h"



QFile sgFile("settings");
QTextStream in(&sgFile);

exitPass::exitPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exitPass)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

exitPass::~exitPass()
{
    delete ui;
}

void exitPass::on_pushButton_clicked()
{

    sgFile.open(QFile::ReadWrite | QFile::Text);
    //if(!sgFile.isOpen()){
            //QMessageBox::critical(this, "Error", "Error");
    //}
    //else{
        QString pass = ui->lineEdit->text();
        QString inp;

        in >> inp;

        if(inp == pass){
            sgFile.close();
            QCoreApplication::exit();

        }
        else {
            sgFile.close();
            QMessageBox::warning(this, "Не удалось выйти", "Не совпадает пароль");
        }
    //}
}
