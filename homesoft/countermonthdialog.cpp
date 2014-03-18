#include <QDialogButtonBox>
#include <QDateEdit>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>

#include "countermonthdialog.h"
#include "countermonthtransaction.h"
#include "menudatabase.h"

void CounterMonthDialog::on_pushButtonCount()
{
	using namespace transactions;
	using namespace database;

	CounterTransaction *t = new CounterMonthTransaction(this->dateEditMonth->date());
	t->Execute();
	double result = t->GetCount();
	counterResult->setText(QString::number(result));
	delete t;	
}

CounterMonthDialog::CounterMonthDialog( QWidget *parent /*= 0*/ )
{
	setupUi(this);
}

CounterMonthDialog::~CounterMonthDialog()
{

}

void CounterMonthDialog::setupUi( QDialog *QueryByNameAndDateDialog )
{
	using namespace database;

	if (QueryByNameAndDateDialog->objectName().isEmpty())
		QueryByNameAndDateDialog->setObjectName(QString::fromUtf8("QueryByDateDialog"));
	QueryByNameAndDateDialog->resize(800, 600);
	buttonBox = new QDialogButtonBox(QueryByNameAndDateDialog);
	buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
	buttonBox->setGeometry(QRect(330, 550, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	dateEditMonth = new QDateEdit(QueryByNameAndDateDialog);
	dateEditMonth->setObjectName(QString::fromUtf8("dateEditMonth"));
	dateEditMonth->setGeometry(QRect(50, 10, 110, 22));
	labelMonth = new QLabel(QueryByNameAndDateDialog);
	labelMonth->setObjectName(QString::fromUtf8("labelMonth"));
	labelMonth->setGeometry(QRect(10, 10, 54, 12));
	pushButtonQuery = new QPushButton(QueryByNameAndDateDialog);
	pushButtonQuery->setObjectName(QString::fromUtf8("pushButtonQuery"));
	pushButtonQuery->setGeometry(QRect(40, 560, 75, 23));
	counterResult = new QLineEdit(QueryByNameAndDateDialog);
	counterResult->setGeometry(QRect(40, 500, 50, 20));
	counterResult->setObjectName(QString::fromUtf8("counterResult"));

	retranslateUi(QueryByNameAndDateDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), QueryByNameAndDateDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), QueryByNameAndDateDialog, SLOT(reject()));
	QObject::connect(pushButtonQuery, SIGNAL(clicked()), QueryByNameAndDateDialog, SLOT(on_pushButtonCount()));
	this->dateEditMonth->setDate(QDate::currentDate());
}

void CounterMonthDialog::retranslateUi( QDialog *QueryByNameAndDateDialog )
{
	QueryByNameAndDateDialog->setWindowTitle(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242\346\234\210\344\273\275\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
	dateEditMonth->setDisplayFormat(QApplication::translate("QueryByDateDialog", "yyyy/M", 0, QApplication::UnicodeUTF8));
	labelMonth->setText(QApplication::translate("QueryByDateDialog", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
	pushButtonQuery->setText(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
}