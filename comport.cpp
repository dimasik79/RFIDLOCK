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

#include "comport.h"






using namespace std;




QString COM::InitSerial(QString portName){
    port.setPortName(portName);
    port.setBaudRate(QSerialPort::Baud9600);
    port.setDataBits(QSerialPort::Data8);
    port.setParity(QSerialPort::NoParity);
    port.setFlowControl(QSerialPort::NoFlowControl);
    port.open(QIODevice::ReadOnly);
    if(port.error())return "err";
    else return "OK";
}

QString COM::ReadUID(){
    QString uid;
    if(!port.error()){
    for(int i = 0; i < 70000000; i++){


        char *n;


        port.read(n, 1);/// получаем 1 байт
        if (*n == '\n') {
            do{
                port.read(n, 1);
                if(*n != '\n') uid+=*n;
            }
            while(*n != '\n');
            return uid;
        }

}

}
    return "00000000\n";
}
