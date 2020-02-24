#include "card.h"
#include "ui_card.h"
#include "mainwindow.cpp"

QFile pwd("settings");
QTextStream fs(&pwd);

QString uid;

Card::Card(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    string s = com.ReadUid();
    uid = QString::fromStdString(s);
    ui->label_2->setText(uid);

}

Card::~Card()
{
    delete ui;
}

void Card::on_pushButton_clicked()
{
    cardId.open(QFile::WriteOnly);
    pwd.open(QFile::ReadOnly);
    QString pwwd;
    fs >> pwwd;
    if(pwwd == ui->lineEdit->text()){
        card << "";
        card << uid;
        cardId.close();
    }
    pwd.close();


}
