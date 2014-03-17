#ifndef QUERYBYNAMEANDDATEDIALOG_H
#define QUERYBYNAMEANDDATEDIALOG_H

#include <QDialog>

class QDialogButtonBox;
class QDateEdit;
class QLabel;
class QPushButton;
class QTableWidget;
class QComboBox;

class QueryByNameAndDateDialog : public QDialog
{
	Q_OBJECT

public:
	explicit QueryByNameAndDateDialog(QWidget *parent = 0);
	~QueryByNameAndDateDialog();

private slots:
	void on_pushButtonQuery();

private:
	QDialogButtonBox *buttonBox;
	QDateEdit *dateEditMonth;
	QLabel *labelMonth;
	QPushButton *pushButtonQuery;
	QTableWidget *tableWidget;
	QComboBox *comboBox;
	QLabel *labelName;

public:
	void setupUi(QDialog *QueryByDateDialog); // setupUi
	void retranslateUi(QDialog *QueryByDateDialog); // retranslateUi
	void SetUsers( const std::vector<std::string> &users );
};

#endif