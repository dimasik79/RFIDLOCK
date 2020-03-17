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


#ifndef ADDITIONALY_H
#define ADDITIONALY_H

#include <QDialog>
#include <QMessageBox>
#include "exitpass.h"

#include "ui_additionaly.h"
#include "settings.h"
#include "card.h"

namespace Ui {
class additionaly;
}

class additionaly : public QDialog
{
    Q_OBJECT

public:
    explicit additionaly(QWidget *parent = nullptr);
    ~additionaly();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::additionaly *ui;
};

#endif // ADDITIONALY_H
