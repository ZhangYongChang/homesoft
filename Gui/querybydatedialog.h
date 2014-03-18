#ifndef QUERYBYDATEDIALOG_H
#define QUERYBYDATEDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QDateEdit;
class QLabel;
class QPushButton;
class QTableWidget;

class QueryByDateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QueryByDateDialog(QWidget *parent = 0);
    ~QueryByDateDialog();

private slots:
    void on_pushButtonQuery_clicked();

private:
	QDialogButtonBox *buttonBox;
	QDateEdit *dateEditMonth;
	QLabel *labelMonth;
	QPushButton *pushButtonQuery;
	QTableWidget *tableWidget;

	void setupUi(QDialog *QueryByDateDialog);
	void retranslateUi(QDialog *QueryByDateDialog);
};

#endif // QUERYBYDATEDIALOG_H
