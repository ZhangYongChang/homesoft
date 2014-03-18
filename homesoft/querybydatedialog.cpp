#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include "querybydatedialog.h"
#include "querybydatetransaction.h"
#include "menudatabase.h"

using namespace transactions;
using namespace database;

QueryByDateDialog::QueryByDateDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
}

QueryByDateDialog::~QueryByDateDialog()
{
}

void QueryByDateDialog::on_pushButtonQuery_clicked()
{
	tableWidget->clear();
    tableWidget->setColumnCount(7);
    tableWidget->setRowCount(10);
    QStringList header;
    header << tr("ID") << tr("Name") << tr("Buyer") 
		<< tr("Price") << tr("Number") << tr("Buy Date") << tr("Input Date");

    tableWidget->setHorizontalHeaderLabels(header);
    QueryTransaction *t = new QueryByDateTransaction(dateEditMonth->date());
    t->Execute();
    std::vector<Order *> orders = t->GetRecord();
	delete t;

	int nCount = 0;
    for (std::vector<Order *>::iterator it = orders.begin();
        it != orders.end();
        ++it)
    {
		double dfPrice = (*it)->PriceOfEach();
		double dfNumber = (*it)->Numbers();
		QDate orderdate = (*it)->OrderDate();
		QDate inputdate = (*it)->InputDate();
		tableWidget->setItem(nCount, 
			0, 
			new QTableWidgetItem(QString::number((*it)->OrderID(),10)));
		tableWidget->setItem(nCount, 
			1, 
			new QTableWidgetItem(g_mDatabase.GetItemName((*it)->ItemID()).c_str()));

		tableWidget->setItem(nCount,
			2,
			new QTableWidgetItem(g_mDatabase.GetUserName((*it)->UserID()).c_str()));

		tableWidget->setItem(nCount,
			3,
			new QTableWidgetItem(QString::number(dfPrice)));

		tableWidget->setItem(nCount,
			4,
			new QTableWidgetItem(QString::number(dfNumber)));

		tableWidget->setItem(nCount,
			5,
			new QTableWidgetItem(orderdate.toString()));

		tableWidget->setItem(nCount,
			6,
			new QTableWidgetItem(inputdate.toString()));
		++nCount;
    }
}

void QueryByDateDialog::setupUi( QDialog *QueryByDateDialog )
{
	if (QueryByDateDialog->objectName().isEmpty())
		QueryByDateDialog->setObjectName(QString::fromUtf8("QueryByDateDialog"));
	QueryByDateDialog->resize(800, 600);
	buttonBox = new QDialogButtonBox(QueryByDateDialog);
	buttonBox->setGeometry(QRect(330, 550, 341, 32));
	buttonBox->setOrientation(Qt::Horizontal);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
	dateEditMonth = new QDateEdit(QueryByDateDialog);
	dateEditMonth->setGeometry(QRect(50, 10, 110, 22));
	labelMonth = new QLabel(QueryByDateDialog);
	labelMonth->setGeometry(QRect(10, 10, 54, 12));
	pushButtonQuery = new QPushButton(QueryByDateDialog);
	pushButtonQuery->setGeometry(QRect(40, 560, 75, 23));
	tableWidget = new QTableWidget(QueryByDateDialog);
	tableWidget->setGeometry(QRect(10, 40, 771, 471));

	retranslateUi(QueryByDateDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), QueryByDateDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), QueryByDateDialog, SLOT(reject()));
	QObject::connect(pushButtonQuery, SIGNAL(clicked()), QueryByDateDialog, SLOT(on_pushButtonQuery_clicked()));
	this->dateEditMonth->setDate(QDate::currentDate());
}

void QueryByDateDialog::retranslateUi( QDialog *QueryByDateDialog )
{
	QueryByDateDialog->setWindowTitle(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242\346\234\210\344\273\275\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
	dateEditMonth->setDisplayFormat(QApplication::translate("QueryByDateDialog", "yyyy/M", 0, QApplication::UnicodeUTF8));
	labelMonth->setText(QApplication::translate("QueryByDateDialog", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
	pushButtonQuery->setText(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
}
