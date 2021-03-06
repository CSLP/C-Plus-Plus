#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

private slots:
    void on_goToLoginPushButton_clicked();

    void on_signupPushButton_clicked();
signals:
    void sclose();
private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
