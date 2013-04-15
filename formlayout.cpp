#include "formlayout.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QFormLayout>
#include <QLineEdit>

using namespace std;

/** Default Constructor */
formlayout::formlayout()
{
	layout = new QFormLayout();
	setLayout(layout);
	 
	sizeEdit = new QLineEdit();
	startMovesEdit = new QLineEdit();
	randomSeedEdit = new QLineEdit();
	
	layout->addRow("Board Size: ", sizeEdit);
	layout->addRow("Starting Moves: ", startMovesEdit);
	layout->addRow("Random Seed Value: ", randomSeedEdit);

}

/** getLayout
	* @return layout The layout being returned */
QFormLayout *formlayout::getLayout()
{
	return layout;
}

/** getSizeEdit
	* @return sizeEdit The input of the size line */
QLineEdit *formlayout::getSizeEdit()
{
	return sizeEdit;
}

/** getStartMovesedit
	* @return startMovesEdit The input of the startmoves line */
QLineEdit *formlayout::getStartMovesEdit()
{
	return startMovesEdit;
}

/** getRandomSeededit
	* @return randomSeedEdit The input of the RandomSeed line */
QLineEdit *formlayout::getRandomSeedEdit()
{
	return randomSeedEdit;
}


/** Default Destructor */
formlayout::~formlayout()
{


}
