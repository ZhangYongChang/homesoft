#include "querybydatedialog.h"
#include "ui_querybydatedialog.h"
#include "querybydatetransaction.h"
#include "menudatabase.h"

using namespace transactions;
using namespace database;

QueryByDateDialog::QueryByDateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QueryByDateDialog)
{
    ui->setupUi(this);
}

QueryByDateDialog::~QueryByDateDialog()
{
    delete ui;
}

void QueryByDateDialog::on_pushButtonQuery_clicked()
{
	ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(10);
    QStringList header;
    header << tr("ID") << tr("Name") << tr("Buyer") 
		<< tr("Price") << tr("Number") << tr("Buy Date") << tr("Input Date");

    ui->tableWidget->setHorizontalHeaderLabels(header);
    QueryTransaction *t = new QueryByDateTransaction(ui->dateEditMonth->date());
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
		ui->tableWidget->setItem(nCount, 
			0, 
			new QTableWidgetItem(QString::number((*it)->OrderID(),10)));
		ui->tableWidget->setItem(nCount, 
			1, 
			new QTableWidgetItem(g_mDatabase.GetItemName((*it)->ItemID()).c_str()));

		ui->tableWidget->setItem(nCount,
			2,
			new QTableWidgetItem(g_mDatabase.GetUserName((*it)->UserID()).c_str()));

		ui->tableWidget->setItem(nCount,
			3,
			new QTableWidgetItem(QString::number(dfPrice)));

		ui->tableWidget->setItem(nCount,
			4,
			new QTableWidgetItem(QString::number(dfNumber)));

		ui->tableWidget->setItem(nCount,
			5,
			new QTableWidgetItem(orderdate.toString()));

		ui->tableWidget->setItem(nCount,
			6,
			new QTableWidgetItem(inputdate.toString()));
		++nCount;
    }
}
