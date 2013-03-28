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
	
	while(!b.solved())
	{
		cout<<b<<endl;
	
		int answer;
		cout << "Enter tile number to move or -1 for a cheat: " << endl;
		cin>>answer;
	
		if(answer == -1)
		{
			cout << "No cheating!" << endl;
		}
		else
		{
			b.move(answer);
		}
	}

	cout << "YOU WIN!" << endl;



  return 0;
}
