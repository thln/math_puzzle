#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 3){
    cerr << "Usage: ./puzzle size initMoves seed" << endl;
    return 1;
  }

  int size, initMoves, seed;

  size = atoi(argv[1]);
  initMoves = atoi(argv[2]);
  seed = atoi(argv[3]);

  Board b(size,initMoves,seed);


//Testing pmminlist
/*
PMMinList test;
Board Board1;
Board Board2;
PuzzleMove *PM1= new PuzzleMove(Board1);
PuzzleMove *PM2= new PuzzleMove(Board2);
test.push(PM1);
test.push(PM2);
cout << test.top() << endl;
test.pop();
cout << test.top() << endl;
*/

  //**** Implement the gameplay here

	cout << "Welcome to the Game!" << endl;

	ManhattanHeuristic *MH = new ManhattanHeuristic;
//	OutOfPlaceHeuristic *OOPH = new OutOfPlaceHeuristic;
	
	while(!b.solved())
	{
		cout<<b<<endl;
	
		int answer;
		cout << "Enter tile number to move or -1 for a cheat: " << endl;
		cin>>answer;

//****MAJOR PROBLEMS
//* last problem - Is adding 0's to the solutions vector
//!!* 1 Goes straight into the "solved" if statement and then breaks
//!!* 2 Does not push back the tiles into the Solutions linked list
//!!* 3 Switches the number 1 with a random number (modifies original gameboard)
//!!* 4 Apparently, if it skips the if statement, there is a floating point exception (core dumped)
	
		if(answer == -1)
		{
			PuzzleSolver *Answer = new PuzzleSolver(b);
			cout<< "LALA1" << endl;
			Answer->run(MH);
			cout<< "LALA1" << endl;
			Answer->printSolutions();
			cout<< "LALA1" << endl;
		}
		else
		{
			b.move(answer);
		}
	}

	cout << "YOU WIN!" << endl;



  return 0;
}
