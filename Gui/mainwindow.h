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

private slots:
    void on_actionLoad_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionAddUser_triggered();

    void on_actionAddItem_triggered();

    void on_actionAddOrder_triggered();

    void on_actionQueryByDate_triggered();

    void on_actionQueryByNameAndDate_triggered();

    void on_actionCounterByMonth();

    void on_actionCounterByNameAndDate_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
