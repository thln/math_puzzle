#include "formlayout.h"
#include <QTimer>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <QFormLayout>
#include <QLineEdit>

using namespace std;

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

QFormLayout *formlayout::getLayout()
{
	return layout;
}
	
QLineEdit *formlayout::getSizeEdit()
{
	return sizeEdit;
}

QLineEdit *formlayout::getStartMovesEdit()
{
	return startMovesEdit;
}

QLineEdit *formlayout::getRandomSeedEdit()
{
	return randomSeedEdit;
}

formlayout::~formlayout()
{


}