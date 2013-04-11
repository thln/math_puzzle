#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graphicswindow.h"
#include <QToolBar>
#include <QAction>
#include "formlayout.h"
#include <QDockWidget>
#include <QWidget>
//#include "guitile.h"
#include <QRadioButton>
#include <QHBoxLayout>

using namespace std;

class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
	MainWindow();
	GraphicsWindow *gw;
	~MainWindow();
	
private:
	QDockWidget *qdw;
	formlayout *textfields;
	QToolBar *tool;
	QRadioButton *mhChoice;
	QRadioButton *ooohChoice;
	QHBoxLayout *horlayout;

public slots:
	void startGame();
	void cheatGame();
	void quitGame();
	bool clickedstate();

};

#endif // MAINWINDOW_H
