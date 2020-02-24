#include <QtCore>
#include <QFile>
#include <QMessageBox>

#include "exitpass.h"
#include "ui_exitpass.h"



QFile sgFile("settings");
QTextStream in(&sgFile);

exitPass::exitPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::exitPass)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

exitPass::~exitPass()
{
    delete ui;
}

void exitPass::on_pushButton_clicked()
{

    sgFile.open(QFile::ReadWrite | QFile::Text);
    //if(!sgFile.isOpen()){
            //QMessageBox::critical(this, "Error", "Error");
    //}
    //else{
        QString pass = ui->lineEdit->text();
        QString inp;

        in >> inp;

        if(inp == pass){
            sgFile.close();
            QCoreApplication::exit();

        }
        else {
            sgFile.close();
            QMessageBox::warning(this, "Не удалось выйти", "Не совпадает пароль");
        }
    //}
}
