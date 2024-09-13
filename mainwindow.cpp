#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("GameGame!");
    widget = new QWidget(this);
    this -> setCentralWidget(widget);
    layout = new QVBoxLayout(widget);
    enter = new QPushButton("Войти", widget);
    play = new QPushButton("Играть", widget);
    play->setEnabled(false);
    layout->addWidget(enter);
    layout->addWidget(play);
    QObject::connect(enter, &QPushButton::clicked, this, &MainWindow::onEnterClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onEnterClicked(){
    play->setEnabled(true);
    enter->setText("Выйти");
    QObject::disconnect(enter, &QPushButton::clicked, this, &MainWindow::onEnterClicked);
    QObject::connect(enter, &QPushButton::clicked, this, &MainWindow::onLeaveClicked);
}

void MainWindow::onLeaveClicked(){
    play->setEnabled(false);
    enter->setText("Войти");
    QObject::disconnect(enter, &QPushButton::clicked, this, &MainWindow::onLeaveClicked);
    QObject::connect(enter, &QPushButton::clicked, this, &MainWindow::onEnterClicked);
}
