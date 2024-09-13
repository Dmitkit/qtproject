#ifndef LOGINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>

//Makes class LoginDialog a child to its parent, QDialog

class LoginDialog : public QDialog
{

//Turns Login Dialog into a QObject
    Q_OBJECT

private:
//A label for the username component.
    QLabel* labelUsername;
//A label for the password.
    QLabel* labelPassword;
//Login field
    QLineEdit* editUsername;
//A field to let the user enters his password.
    QLineEdit* editPassword;
//The standard dialog button box.
    QDialogButtonBox* buttons;
//A method to set up all dialog components and
//initialize them.
    void setUpGUI();

public:
    explicit LoginDialog(QWidget *parent = 0);
//Sets the proposed username
    void setUsername(QString& username);
//Sets the current password
    void setPassword(QString& password);
signals:
//A signal is emitted when password is 1 and login is Dima
    void accepted();
public slots:
//Slot for OK button to check if the login and password are correct.
    void handleLogin();
};

#endif LOGINWINDOW_H
