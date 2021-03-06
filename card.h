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


#ifndef CARD_H
#define CARD_H

#include <QDialog>


namespace Ui {
class Card;
}

class Card : public QDialog
{
    Q_OBJECT

public:
    explicit Card(QWidget *parent = nullptr);
    ~Card();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Card *ui;
};

#endif // CARD_H
