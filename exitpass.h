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


#ifndef EXITPASS_H
#define EXITPASS_H

#include <QDialog>
#include <QtCore>
#include <QFile>
#include <QMessageBox>


namespace Ui {
class exitPass;
}

class exitPass : public QDialog
{
    Q_OBJECT

public:
    explicit exitPass(QWidget *parent = nullptr);
    ~exitPass();

private slots:
    void on_pushButton_clicked();

private:
    Ui::exitPass *ui;
};

#endif // EXITPASS_H
