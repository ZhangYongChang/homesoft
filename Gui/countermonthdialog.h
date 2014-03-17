#ifndef COUNTERMONTHDIALOG_H
#define COUNTERMONTHDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QDateEdit;
class QLabel;
class QPushButton;
class QLineEdit;

class CounterMonthDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CounterMonthDialog(QWidget *parent = 0);
	~CounterMonthDialog();

	private slots:
		void on_pushButtonCount();

private:
	QDialogButtonBox *buttonBox;
	QDateEdit *dateEditMonth;
	QLabel *labelMonth;
	QPushButton *pushButtonQuery;
	QLineEdit *counterResult;

public:
	void setupUi(QDialog *QueryByDateDialog);
	void retranslateUi(QDialog *QueryByDateDialog);
};

#endif