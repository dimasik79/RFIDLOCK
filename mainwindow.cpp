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
#include <windows.h>
#include <QMessageBox>
#include <QProcess>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comport.h"
#include "additionaly.h"

LPCTSTR sPort = L"COM3";
COM com;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //setWindowState(Qt::WindowMaximized);

    ui->setupUi(this);
    setWindowState(Qt::WindowFullScreen);
     string comstat = com.InitCOM(sPort);
     QString qcomstat = QString::fromStdString(comstat);
    statusBar()->showMessage(qcomstat);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::ComInit()
//{

//}


void MainWindow::on_pushButton_clicked()
{
    /*QMessageBox::StandardButton shutdwn = QMessageBox::question(this, "Выключение?", "Действительно выключить?");
    if(shutdwn == QMessageBox::Yes) QProcess::startDetached("shutdown -s -f -t 0");*/
    additionaly add;
    add.setModal(true);
    add.exec();
}
