#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QUrl>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:

    bool isHasThisAutor(const QList<QUrl>&);//确定数据库中是否有这个作者存在


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QString getUrlRexString(const QUrl&);//获取[*]中*的内容,并输出作者名字
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
