#include "loginwindow.h"

LoginDialog::LoginDialog(QWidget *parent):
    QDialog(parent)
{
    setUpGUI();//отдельная функция, задающая gui
    setWindowTitle(tr("User Login"));//ясно
    setModal(true);//чтобы заблокировать остальные окна
}

void LoginDialog::setUpGUI(){
 // set up the layout
    QGridLayout *formGridLayout = new QGridLayout(this);

// initialize the username combo box so that it is editable
    editUsername = new QLineEdit(this);
// initialize the password field so that it does not echo
// characters
    editPassword = new QLineEdit(this);
    editPassword->setEchoMode(QLineEdit::Password);

// initialize the labels
    labelUsername = new QLabel(this);
    labelPassword = new QLabel(this);
    labelUsername->setText(tr("Username"));
    labelUsername->setBuddy(editUsername);
    labelPassword->setText(tr("Password"));
    labelPassword->setBuddy(editPassword);

// initialize buttons
    buttons = new QDialogButtonBox(this);
    buttons->addButton(QDialogButtonBox::Ok);
    buttons->addButton(QDialogButtonBox::Cancel);
    buttons->button(QDialogButtonBox::Ok)->setText(tr("Login"));
    buttons->button(QDialogButtonBox::Cancel)->setText(tr("Cancel"));

 // connects slots
    connect(buttons->button(QDialogButtonBox::Cancel),
    SIGNAL (clicked()),
    this,
    SLOT (close())
);

    connect(buttons->button(QDialogButtonBox::Ok),
    SIGNAL (clicked()),
    this,
    SLOT (handleLogin()));

// place components into the dialog
    formGridLayout->addWidget(labelUsername, 0, 0);
    formGridLayout->addWidget(editUsername, 0, 1);
    formGridLayout->addWidget(labelPassword, 1, 0);
    formGridLayout->addWidget(editPassword, 1, 1);
    formGridLayout->addWidget(buttons, 2, 0, 1, 2);

    setLayout(formGridLayout);

}

void LoginDialog::setUsername(QString &username){
    editUsername->setText(username);
}

void LoginDialog::setPassword(QString &password){
    editPassword->setText(password);
}

void LoginDialog::handleLogin(){
    QString username = editUsername->text();
    QString password = editPassword->text();

    if (username == "Dima" && password == "1"){
        emit accepted();
        close();
    }
}

