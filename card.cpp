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


#include "card.h"
#include "ui_card.h"
#include "mainwindow.cpp"

QFile pwd("settings");
QTextStream fs(&pwd);

QString uid;

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    QString s = com.ReadUID();
    uid = s;
    ui->label_2->setText(uid);

}

Card::~Card()
{
    delete ui;
}

void Card::on_pushButton_clicked()
{
    cardId.open(QFile::WriteOnly);
    pwd.open(QFile::ReadOnly);
    QString pwwd;
    fs >> pwwd;
    if(pwwd == ui->lineEdit->text()){
        card << "";
        card << uid;
        cardId.close();
        QMessageBox::information(this, "Успешно", "Успешно");
    }

    pwd.close();


}
