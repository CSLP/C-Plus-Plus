#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
protected:
    void dragEnterEvent(QDragEnterEvent*event);
    void dropEvent(QDropEvent*event);
};

#endif // MAINWINDOW_H
