#include <iostream>
#include <cstdlib>
#include <deque>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

/** @mainpage CSCI 102 Programming Project #3
	@section purpose Purpose/Overview
	I am to create Number Puzzle Slider. It is to be same as the 
	childhood game where the player slides the number around. In order 
	to solve the puzzle, the blank space must be in the top left corner
	while the rest of the numbers are in order left to right, top to bottom.
	I must also include a "cheat", where once used, it will give you the 
	necessary tiles to move in order to solver the current board in the most
	efficient manner.
	@section requirements Requirements 
	* Implement a Board Class
	* Implement the Puzzle Play in puzzle.cpp
	* Implement a PuzzleMove Class
	* Implement a PMMinList Class
	* Implement classes to use the Manhattan Heuristic or the OutOfPlace Heuristic
	* Implement a PuzzleSolver Class
	* Implement the cheat
	* Make sure there are no memory leaks
	* Document using Doxygen*/

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

	
		if(answer == -1)
		{
			PuzzleSolver *Answer = new PuzzleSolver(b);
			//cout<< "LALA1" << endl;
			Answer->run(MH);
			//Answer->run(OOPH);
			//cout<< "LALA1" << endl;
			Answer->printSolutions();
			//cout<< "LALA1" << endl;
		} 
		else
		{
			b.move(answer);
		}
	}

	cout << "YOU WIN!" << endl;



  return 0;
}
