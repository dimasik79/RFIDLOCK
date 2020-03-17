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


#ifndef COMPORT_H
#define COMPORT_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include<string>

using std::string;

    class COM{
    public:

    //HANDLE Port;*
    QSerialPort port;


    QString InitCOM(QString portName);

    QString ReadUid();

};

#endif // COMPORT_H
