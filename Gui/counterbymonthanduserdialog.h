#ifndef COUNTRTBYMONTHANDUSERDIALOG_H
#define COUNTRTBYMONTHANDUSERDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QDateEdit;
class QLabel;
class QPushButton;
class QLineEdit;
class QComboBox;

class CounterByMonthAndUserDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CounterByMonthAndUserDialog(QWidget *parent = 0);
	~CounterByMonthAndUserDialog();

	private slots:
		void on_pushButtonCount();

private:
	QDialogButtonBox *buttonBox;
	QDateEdit *dateEditMonth;
	QLabel *labelMonth;
	QPushButton *pushButtonQuery;
	QLineEdit *counterResult;
	QComboBox *comboBox;
	QLabel *labelName;

public:
	void setupUi(QDialog *QueryByDateDialog);
	void retranslateUi(QDialog *QueryByDateDialog);
	void SetUsers( const std::vector<std::string> &users );
};

#endif