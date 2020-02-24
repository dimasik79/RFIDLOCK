#include <QDir>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>

#include "settings.h"
#include "ui_settings.h"


QString pass;

//const QString path = ".\\conf\\";
//QDir setting(path);
QFile File("settings");

QTextStream f(&File);

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{

    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    File.open(QFile::NewOnly);
    f << "0";
    File.close();


}


settings::~settings()
{
    delete ui;
}

void settings::on_pushButton_clicked()
{



        File.open(QFile::ReadWrite | QFile::Text);
        if(!File.isOpen()){
            QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл настроек");
        }
        else{
            f >> pass;
            File.close();
            if(ui->lineEdit->text() == pass){

            File.open(QFile::WriteOnly);
            f << ui->lineEdit_2->text() + "";
            File.close();
            }
        }


}
