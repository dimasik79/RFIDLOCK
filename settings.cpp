#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>

#include "settings.h"
#include "ui_settings.h"

QString pass;

const QString path = "%USERPROFILE%\\Documents\\RFIDLOCK\\";
QDir setting(path);
QFile sgFile(path + "settings");

QTextStream f(&sgFile);

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);

    if(!setting.exists()){

        if(QMessageBox::question(this, "Ошибка", "Не удалось найти папку настроек. Создать?") == QMessageBox::Yes){
            setting.mkpath(path);
            sgFile.open(QFile::ReadWrite | QFile::Text | QFile::NewOnly);
            if(!sgFile.isOpen()){
                QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
            }
            else{
                f << "defaultpassword" << "\n";
                sgFile.close();
            }
        }
    }

    sgFile.open(QFile::ReadWrite | QFile::Text);
    if(!sgFile.isOpen()){
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
    }
    else{
        f >> pass;
        sgFile.close();
    }
}


settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == pass){
        sgFile.open(QFile::ReadWrite | QFile::Text);
        if(!sgFile.isOpen()){
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
        }
        else{
            f << ui->lineEdit_2->text();
            sgFile.close();
        }
    }
}
