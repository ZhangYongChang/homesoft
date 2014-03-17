#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDateEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include "querybynameanddatetransaction.h"
#include "querybynameanddatedialog.h"
#include "order.h"
#include "menudatabase.h"


void QueryByNameAndDateDialog::on_pushButtonQuery()
{
	using namespace transactions;
	using namespace database;

	tableWidget->clear();
	tableWidget->setColumnCount(7);
	tableWidget->setRowCount(10);
	QStringList header;
	header << tr("ID") << tr("Name") << tr("Buyer") 
		<< tr("Price") << tr("Number") << tr("Buy Date") << tr("Input Date");

	tableWidget->setHorizontalHeaderLabels(header);
	QueryTransaction *t = new QueryByNameAndDateTransaction(dateEditMonth->date(), 
		this->comboBox->currentText().toStdString());
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

QueryByNameAndDateDialog::QueryByNameAndDateDialog( QWidget *parent /*= 0*/ )
{
	setupUi(this);
}

QueryByNameAndDateDialog::~QueryByNameAndDateDialog()
{

}

void QueryByNameAndDateDialog::setupUi( QDialog *QueryByNameAndDateDialog )
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
	comboBox = new QComboBox(QueryByNameAndDateDialog);
	comboBox->setObjectName(QString::fromUtf8("comboBox"));
	comboBox->setGeometry(QRect(300, 10, 110, 22));
	this->SetUsers(g_mDatabase.GetUsers());
	labelMonth = new QLabel(QueryByNameAndDateDialog);
	labelMonth->setObjectName(QString::fromUtf8("labelMonth"));
	labelMonth->setGeometry(QRect(10, 10, 54, 12));
	labelName = new QLabel(QueryByNameAndDateDialog);
	labelName->setObjectName(QString::fromUtf8("labelName"));
	labelName->setGeometry(QRect(200, 10, 54, 12));
	pushButtonQuery = new QPushButton(QueryByNameAndDateDialog);
	pushButtonQuery->setObjectName(QString::fromUtf8("pushButtonQuery"));
	pushButtonQuery->setGeometry(QRect(40, 560, 75, 23));
	tableWidget = new QTableWidget(QueryByNameAndDateDialog);
	tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
	tableWidget->setGeometry(QRect(10, 40, 771, 471));

	retranslateUi(QueryByNameAndDateDialog);
	QObject::connect(buttonBox, SIGNAL(accepted()), QueryByNameAndDateDialog, SLOT(accept()));
	QObject::connect(buttonBox, SIGNAL(rejected()), QueryByNameAndDateDialog, SLOT(reject()));

	QObject::connect(pushButtonQuery, SIGNAL(clicked()), QueryByNameAndDateDialog, SLOT(on_pushButtonQuery()));
}

void QueryByNameAndDateDialog::retranslateUi( QDialog *QueryByNameAndDateDialog )
{
	QueryByNameAndDateDialog->setWindowTitle(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242\346\234\210\344\273\275\350\256\260\345\275\225", 0, QApplication::UnicodeUTF8));
	dateEditMonth->setDisplayFormat(QApplication::translate("QueryByDateDialog", "yyyy/M", 0, QApplication::UnicodeUTF8));
	labelMonth->setText(QApplication::translate("QueryByDateDialog", "\346\227\245\346\234\237", 0, QApplication::UnicodeUTF8));
	pushButtonQuery->setText(QApplication::translate("QueryByDateDialog", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
	labelName->setText(tr("UserName"));
}

void QueryByNameAndDateDialog::SetUsers( const std::vector<std::string> &users )
{
	comboBox->setMaxVisibleItems(10);
	for (std::vector<std::string>::const_iterator it = users.begin();
		it != users.end();
		++it)
	{
		comboBox->addItem(it->c_str());
	}

}

