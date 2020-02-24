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
#include <iostream>

using namespace std;

string COM::InitCOM(LPCTSTR sPort){
    Port = CreateFile(sPort, GENERIC_READ | GENERIC_WRITE, NULL,0, OPEN_EXISTING, 0, NULL);

    if (Port == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            return "Порт не найден ";
        }
        return "Не удалось открыть порт";
}

    DCB dcbSerialParalams = { 0 };
    dcbSerialParalams.DCBlength = sizeof(dcbSerialParalams);
    if (!GetCommState(Port, &dcbSerialParalams)){
    return "Не удалось получить состояние порта";
}

    dcbSerialParalams.BaudRate = CBR_9600;
    dcbSerialParalams.ByteSize = 8;
    dcbSerialParalams.StopBits = ONESTOPBIT;
    dcbSerialParalams.Parity = NOPARITY;

    if (!SetCommState(Port, &dcbSerialParalams)){
        return "Не удалось установить состояние порта";
    }
    return "OK";

}
string COM::ReadUid(){

    DWORD iSize;
    char sReceivedChar;
    string uid;
    while (true){

        ReadFile(Port, &sReceivedChar, 1, &iSize, 0);/// получаем 1 байт
        if (iSize > 0 && sReceivedChar == '\n') {
            do{
                ReadFile(Port, &sReceivedChar, 1, &iSize, 0);
                if(iSize > 0 && sReceivedChar != '\n') uid+=sReceivedChar;
            }
            while(sReceivedChar != '\n');
            return uid;
        }


    }
}


