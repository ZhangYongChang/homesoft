#ifndef QUERYBYDATEDIALOG_H
#define QUERYBYDATEDIALOG_H

#include <QDialog>

namespace Ui {
class QueryByDateDialog;
}

class QueryByDateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryByDateDialog(QWidget *parent = 0);
    ~QueryByDateDialog();

private slots:
    void on_pushButtonQuery_clicked();

private:
    Ui::QueryByDateDialog *ui;
};

#endif // QUERYBYDATEDIALOG_H
