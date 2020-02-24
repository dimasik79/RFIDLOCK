#include <QtCore>
#include <QFile>
#include <QMessageBox>

#include "exitpass.h"
#include "ui_exitpass.h"

exitPass::exitPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exitPass)
{
    ui->setupUi(this);
}

exitPass::~exitPass()
{
    delete ui;
}

void exitPass::on_pushButton_clicked()
{
    const QString path = "%USERPROFILE%\\Documents\\RFIDLOCK\\";
    QFile sgFile(path + "settings");
    QTextStream in(&sgFile);
    sgFile.open(QFile::ReadWrite | QFile::Text);
    if(!sgFile.isOpen()){
            QMessageBox::critical(this, "", "");
    }
    else{
        QString pass = ui->lineEdit->text();
        QString f;

        in >> f;

        if(f == pass){
            sgFile.close();
            QCoreApplication::exit();
            QMessageBox::information(this, "Выход", "ВЫход");
        }
        else {
            sgFile.close();
            QMessageBox::warning(this, "Не удалось выйти", "Не совпадает пароль");
        }
    }
}
