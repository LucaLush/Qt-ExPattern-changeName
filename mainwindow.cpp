#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"dragwidget.h"
#include<QDir>
#include<QDebug>
#include<QRegularExpression>
#include<QRegularExpressionMatch>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //新建一个拖拽控件，将之绑定到主窗口中
    dragWidget * d = new dragWidget(this);

    //信号绑定
    connect(d,&dragWidget::getURLS,this,&MainWindow::isHasThisAutor);
    //将路径获取控件添加到主窗口中
    ui->verticalLayout->addWidget(d);
}

MainWindow::~MainWindow()
{
    delete ui;
}



QString MainWindow::getUrlRexString(const QUrl& url)//获取[*]中*的内容
{
    QRegularExpression pattern("\\[(?<fileName>.*)\\]");//设定中括号内容匹配模式
    //设定最小匹配模式
    pattern.setPatternOptions(QRegularExpression::InvertedGreedinessOption);
    QRegularExpressionMatch match = pattern.match(url.fileName());
    if(match.hasMatch())
    {
        QString fileAutorName = match.captured("fileName");//指定分组的方法获取匹配字段的特定部分;
        qDebug()<<"Has matched:"<<fileAutorName;
        return fileAutorName;
    }
    else
        return "";

}

bool MainWindow::isHasThisAutor(const QList<QUrl>& urls)//确定数据库中是否有这个作者存在
{
    qDebug()<<"Message:"<<QString::number(urls.length());

    ui->statusBar->showMessage(QString::number(urls.length()));
    foreach(QUrl var,urls)
    {
       QString fileAutorName = getUrlRexString(var);
       QDir d(var.toLocalFile());
       qDebug()<<"file address:"<<var.toLocalFile();
       qDebug()<<"file name:"<<d.dirName();
       if(fileAutorName=="test1")
       {
           //使用换名字的方式剪切文件到指定路径
           QString disticntName = "C:/Users/asus/Desktop/QT-Halcon/[test1]distinction/"+d.dirName();
           d.rename(var.toLocalFile(),disticntName);

       }
       else if(fileAutorName=="test2")
       {
           //使用换名字的方式剪切文件到指定路径
           QString disticntName = "C:/Users/asus/Desktop/QT-Halcon/[test2]distinction/"+d.dirName();
           d.rename(var.toLocalFile(),disticntName);

       }
    }

    return false;
}
