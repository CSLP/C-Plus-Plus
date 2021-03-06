#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QtNetwork>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
 /*   manager=new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::replyFinished);
    manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
    */
    manager=new QNetworkAccessManager(this);
    ui->progressBar->hide();

}

void MainWindow::startRequest(QUrl url)
{
    reply=manager->get(QNetworkRequest(url));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::httpReadyRead);
    connect(reply,&QNetworkReply::downloadProgress,this,&MainWindow::updateDataReadProgress);
    connect(reply,&QNetworkReply::finished,this,&MainWindow::httpFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::httpFinished()
{
    ui->progressBar->hide();
    if(file)
    {
        file->close();
        delete file;
        file=0;
    }
    reply->deleteLater();
    reply=0;
}

void MainWindow::httpReadyRead()
{
    if(file)  file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
        ui->progressBar->setMaximum(totalBytes);
        ui->progressBar->setValue(bytesRead);
}

/*void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString all=reply->readAll();
    ui->textBrowser->setText(all);
    reply->deleteLater();
}
*/
void MainWindow::on_pushButton_clicked()
{
   // url=ui->lineEdit->text();
    QUrl url;
    url.setScheme("ftp");
    url.setHost("v0.ftp.upyun.com");
    url.setPath("readme.txt");
    url.setUserName("qtertest/qtftptest");
    url.setPassword("pwd123456");
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    if(fileName.isEmpty()) fileName="index.html";
    file=new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly))
    {
        delete file;
        file=0;
        return ;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
