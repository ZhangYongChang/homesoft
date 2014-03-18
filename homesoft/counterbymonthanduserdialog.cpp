#include <QDialogButtonBox>
#include <QDateEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QComboBox>

#include "counterbymonthanduserdialog.h"
#include "counterbymonthandusertransaction.h"
#include "menudatabase.h"

void CounterByMonthAndUserDialog::on_pushButtonCount()
{
	using namespace transactions;
	using namespace database;

	CounterTransaction *t = new CounterByMonthAndUserTransaction(this->dateEditMonth->date(),
		this->comboBox->currentText().toStdString());
	t->Execute();
	double result = t->GetCount();
	counterResult->setText(QString::number(result));
	delete t;	
}

CounterByMonthAndUserDialog::CounterByMonthAndUserDialog( QWidget *parent /*= 0*/ )
{
	setupUi(this);
}

CounterByMonthAndUserDialog::~CounterByMonthAndUserDialog()
{

}

void CounterByMonthAndUserDialog::setupUi( QDialog *QueryByNameAndDateDialog )
{
	using namespace database;

	if (QueryByNameAndDateDialog->objectName().isEmpty())
		QueryByNameAndDateDialog->setObjectName(QString::fromUtf8("QueryByDateDialog"));
	QueryByNameAndDateDialog->resize(800, 600);
	buttonBox = new QDialogButtonBox(QueryByNameAndDateDialog);
	buttonBox->setGeometry(QRect(330, 550, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	dateEditMonth = new QDateEdit(QueryByNameAndDateDialog);
	dateEditMonth->setGeometry(QRect(50, 10, 110, 22));
	labelMonth = new QLabel(QueryByNameAndDateDialog);
	labelMonth->setGeometry(QRect(10, 10, 54, 12));
	pushButtonQuery = new QPushButton(QueryByNameAndDateDialog);
	pushButtonQuery->setGeometry(QRect(40, 560, 75, 23));
	counterResult = new QLineEdit(QueryByNameAndDateDialog);
	counterResult->setGeometry(QRect(40, 500, 50, 20));

	comboBox = new QComboBox(QueryByNameAndDateDialog);
	comboBox->setGeometry(QRect(300, 10, 110, 22));
	labelName = new QLabel(QueryByNameAndDateDialog);
	labelName->setGeometry(QRect(200, 10, 54, 12));
	SetUsers(g_mDatabase.GetUsers());

	retranslateUi(QueryByNameAndDateDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), QueryByNameAndDateDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), QueryByNameAndDateDialog, SLOT(reject()));
	QObject::connect(pushButtonQuery, SIGNAL(clicked()), QueryByNameAndDateDialog, SLOT(on_pushButtonCount()));
}

void CounterByMonthAndUserDialog::retranslateUi( QDialog *QueryByNameAndDateDialog )
{
	QueryByNameAndDateDialog->setWindowTitle(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242\346\234\210\344\273\275\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
	dateEditMonth->setDisplayFormat(QApplication::translate("QueryByDateDialog", "yyyy/M", 0, QApplication::UnicodeUTF8));
	labelMonth->setText(QApplication::translate("QueryByDateDialog", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
	pushButtonQuery->setText(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
}

void CounterByMonthAndUserDialog::SetUsers( const std::vector<std::string> &users )
{
	comboBox->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = users.begin();
		it != users.end();
		++it)
	{
		comboBox->addItem(it->c_str());
	}

}