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


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comport.h"
#include "additionaly.h"


COM com;

QFile cardId("cardid.txt");
QTextStream card(&cardId);





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //setWindowState(Qt::WindowMaximized);

    ui->setupUi(this);
    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
#ifndef QT_DEBUG
    setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint | Qt::WindowStaysOnTopHint );
#endif
    //setWindowModality(Qt::WindowModal);
    setWindowState(Qt::WindowFullScreen);

    cardId.open(QFile::ReadOnly);
    QString dummy, l;
    card >> dummy >> l;
     QString qcomstat = com.InitSerial(l);
    statusBar()->showMessage(qcomstat);




}
#ifndef QT_DEBUG
void MainWindow::closeEvent (QCloseEvent *event)
{
    event->ignore();
}
#endif
MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{
    additionaly add;
    add.setModal(true);
    add.exec();
}





void MainWindow::on_pushButton_2_clicked()
{
    cardId.open(QFile::ReadOnly);
    QString l;
    QString quid = com.ReadUID();
    quid.chop(1);




    card >> l;

    if(quid == l){
        QCoreApplication::exit();
    }
    else statusBar()->showMessage("Неверный код");

}
