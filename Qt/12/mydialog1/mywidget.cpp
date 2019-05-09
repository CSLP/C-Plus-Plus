#include "mywidget.h"
#include "ui_mywidget.h"
#include "mydialog.h"
#include<QDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showChildbutton_clicked()
{
   QDialog*dialog=new QDialog(this);
   dialog->show();
}

void MyWidget::on_pushButton_clicked()
{
   close();
   MyDialog dlg;
   if(dlg.exec()==QDialog::Accepted) show();
}
