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


#include <QMessageBox>
#include "exitpass.h"
#include "additionaly.h"
#include "ui_additionaly.h"
#include "settings.h"
#include "card.h"

additionaly::additionaly(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additionaly)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

additionaly::~additionaly()
{
    delete ui;
}

void additionaly::on_pushButton_clicked()
{
    exitPass exi;
    exi.setModal(true);
    exi.exec();
}

void additionaly::on_pushButton_2_clicked()
{
    settings sety;
    sety.setModal(true);
    sety.exec();
}

void additionaly::on_pushButton_3_clicked()
{
    Card card;
    card.setModal(true);
    card.exec();

}

void additionaly::on_pushButton_4_clicked()
{
    QMessageBox::about(this, "О программе", "RFID LOCKER V1.1\n(C)2020 Lubsanov Dmitry aka dimasik79 aka dimasit\nСделано на Qt\n\nСмотрите https://github.com/dimasik79/RFIDLOCKER\nдДля подробностей");

}

void additionaly::on_pushButton_5_clicked()
{
    QMessageBox::aboutQt(this, "О Qt");
}
