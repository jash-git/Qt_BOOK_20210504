#include <QtGui>
#include "mainwindow.h"
CMainWindow::CMainWindow(QWidget* parent)
 :	QMainWindow(parent)
{
	iniMenu();
	iniToolBar();
	iniCentralWidget();

        setWindowTitle(tr("��r�s�边"));
showMaximized();
}


void CMainWindow::iniMenu()
{
        menu_F	= new QMenu(tr("�ɮ�(&F)"), this);
        actNew 	= menu_F->addAction(QIcon(":/new.png"), tr("�s��(&N)"));
	actNew->setShortcut(QKeySequence(tr("Ctrl+N")));
        actOpen	= menu_F->addAction(QIcon(":/open.png"), tr("���}(&O)"));
	actOpen->setShortcut(QKeySequence(tr("Ctrl+O")));
        actClose = menu_F->addAction(tr("����(&C)"));
	menu_F->addSeparator();
        actSave = menu_F->addAction(QIcon(":/save.png"), tr("�O�s(&S)"));
	actSave->setShortcut(QKeySequence(tr("Ctrl+S")));
        actASave = menu_F->addAction(QIcon(":/asave.png"), tr("�t�s��(&A)"));
	menu_F->addSeparator();
        actQuit = menu_F->addAction(tr("�h�X(&X)"));
	
        menu_E = new QMenu(tr("�s��(&E)"), this);
        actUndo = menu_E->addAction(QIcon(":/undo.png"), tr("�_��(&U)"));
	actUndo->setShortcut(QKeySequence(tr("Ctrl+Z")));
	menu_E->addSeparator();
        actCut = menu_E->addAction(QIcon(":/cut.png"), tr("�ŤU(&C)"));
	actCut->setShortcut(QKeySequence(tr("Ctrl+X")));
        actCopy = menu_E->addAction(QIcon(":/copy.png"), tr("�ƻs(&C)"));
	actCopy->setShortcut(QKeySequence(tr("Ctrl+C")));
        actPast = menu_E->addAction(QIcon(":/paste.png"), tr("�K�W(&P)"));
	actPast->setShortcut(QKeySequence(tr("Ctrl+V")));
	menu_E->addSeparator();
        actAll = menu_E->addAction(tr("����(&A)"));
	actAll->setShortcut(QKeySequence(tr("Ctrl+A")));
	
        menu_T = new QMenu(tr("�u��(&T)"), this);
        actFind = menu_T->addAction(QIcon(":/find.png"), tr("�M����...(&F)"));
	
	QMenuBar* bar = menuBar();
	bar->addMenu(menu_F);
	bar->addMenu(menu_E);
	bar->addMenu(menu_T);
}

void CMainWindow::iniToolBar()
{
	fileToolBar = new QToolBar(this);
	fileToolBar->setAllowedAreas(Qt::NoToolBarArea);
	fileToolBar->setOrientation(Qt::Horizontal);
	fileToolBar->addAction(actNew);
	fileToolBar->addAction(actOpen);
	fileToolBar->addAction(actSave);
	fileToolBar->addAction(actASave);
	editToolBar = new QToolBar(this);
	editToolBar->setAllowedAreas(Qt::AllToolBarAreas);
	editToolBar->setOrientation(Qt::Horizontal);
	editToolBar->addAction(actUndo);
	editToolBar->addAction(actCut);
	editToolBar->addAction(actCopy);
	editToolBar->addAction(actPast);

	addToolBar(Qt::TopToolBarArea, fileToolBar);
	addToolBar(Qt::TopToolBarArea, editToolBar);
}


void CMainWindow::iniCentralWidget()
{
	textEdit = new QTextEdit(this);
	setCentralWidget(textEdit);	
}
