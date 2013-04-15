#ifndef FORMLAYOUT_H
#define FORMLAYOUT_H
 
#include <QMainWindow> 
#include "graphicswindow.h" 
#include <QToolBar>
#include <QAction>
#include <QFormLayout> 
#include <QLineEdit> 
   
using namespace std;

/**
	* This class is used to keep track of the text grabber to init the game.
	* Inherits from QWidget.
	* @author Tam Henry Le Nguyen */

class formlayout : public QWidget {
    Q_OBJECT
    
public:
	formlayout(); /** Default Constructor */
	~formlayout(); /** Default Destructor */
	QFormLayout *getLayout(); /** Layout Accessor */
	QLineEdit *getSizeEdit(); /** Size Edit Accessor */
	QLineEdit *getStartMovesEdit(); /** StartMovesEdit Accessor */
	QLineEdit *getRandomSeedEdit(); /** RandomSeedEdit Accessor*/
	
private:
	QFormLayout *layout; /** Your layout */
	QLineEdit *sizeEdit; /** To store what was written in size edit */
	QLineEdit *startMovesEdit; /** To Store what was written in startMoves Edit */
	QLineEdit *randomSeedEdit; /** To store what was written in randomseed edit */

public slots:

};

#endif // MAINWINDOW_H
