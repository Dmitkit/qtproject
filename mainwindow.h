#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QVBoxLayout *layout;
    QPushButton *enter;
    QPushButton *play;
    QWidget *widget;

private:
    Ui::MainWindow *ui;

public:
    void onEnterClicked();
    void onLeaveClicked();
public slots:
    void acceptUserLogin();
};
#endif // MAINWINDOW_H
