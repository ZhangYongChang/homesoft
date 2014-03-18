#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class QMenuBar;
class QWidget;
class QMenu;
class QToolBar;
class QStatusBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onActionLoad();
	void onActionSave();
    void onActionExit();
    void onActionAddUser();
    void onActionAddItem();
    void onActionAddOrder();
    void onActionQueryByDate();
    void onActionQueryByNameAndDate();
    void onActionCounterByMonth();
    void onActionCounterByNameAndDate();
	void onActionAbout();

private:
	void setupUi(QMainWindow *MainWindow);
	void CreateMenu( QMainWindow * MainWindow );
	void ActionRelation( QMainWindow * MainWindow );
	void retranslateUi(QMainWindow *MainWindow);
	void CreateToolBar(QMainWindow *MainWindow);

private:
	QWidget *centralWidget;
	
	QMenuBar *menuBar;
	QMenu *menuFile;
	QMenu *menuAdd;
	QMenu *menuQuery;
	QMenu *menuCounter;
	QMenu *menuHelp;

	QAction *actionLoad;
	QAction *actionSave;
	QAction *actionExit;
	QAction *actionAddUser;
	QAction *actionAddItem;
	QAction *actionAddOrder;
	QAction *actionQueryByDate;
	QAction *actionQueryByNameAndDate;
	QAction *actionCounterByDate;
	QAction *actionCounterByNameAndDate;
	QAction *actionAbout;

	QToolBar *fileToolBar;
	QToolBar *addInfoToolBar;
	QToolBar *counterToolBar;
	QToolBar *queryToolBar;
	QToolBar *helpToolBar;

	QStatusBar *statusBar;
};

#endif // MAINWINDOW_H
