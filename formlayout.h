#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H
 
#include <QMainWindow> 
#include "graphicswindow.h" 
#include <QToolBar>
#include <QAction>
#include <QFormLayout> 
#include <QLineEdit> 
   
using namespace std;

class formlayout : public QWidget {
    Q_OBJECT
    
public:
	formlayout();
	~formlayout();
	
private:
	QFormLayout* layout;
	QLineEdit* sizeEdit;
	QLineEdit* startMovesEdit;
	QLineEdit* randomSeedEdit;

public slots:

};

#endif // MAINWINDOW_H
