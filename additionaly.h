#ifndef ADDITIONALY_H
#define ADDITIONALY_H

#include <QDialog>

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

private:
    Ui::additionaly *ui;
};

#endif // ADDITIONALY_H
