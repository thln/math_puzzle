#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "puzzle_solver.h"
#include "pmminlist.h"

using namespace std;

//Constructor
PuzzleSolver::PuzzleSolver(const Board &b)
{
	b_ = b;
	expansions_ = 0;

}

//Destructor
PuzzleSolver::~PuzzleSolver()
{

}

//Runs the A Star Algorithm
int PuzzleSolver::run(PuzzleHeuristic *ph)
{
	PMMinList Open_List;              //stores new, unexplored moves
	BoardSet Closed_Set;              //stores old boards
	vector<PuzzleMove*> Garbage_List; //stores old moves
	MyList<int> Solutions;            //stores solution set

	PuzzleMove *StartState = new PuzzleMove(b_);

	//Adding to open list and closed set
	Open_List.push(StartState);
	Closed_Set.insert(StartState->b_);
	Garbage_List.push_back(StartState);

	while(!Open_List.empty())
	{
		PuzzleMove *move = Open_List.top();
		Open_List.pop();
		Closed_Set.insert(move->b_);
		Garbage_List.push_back(move);
		
		if(move->b_->solved())
		{
		//PuzzleMove *temp = new PuzzleMove(mov
		//trace path backwards
		//** make a temp puzzle with current move.getTile, move, move->prev
		//** add current move.getTile to solutions linked list
		//** temp = temp->prev?
		//** for loop until temp = StartState?
		
		PuzzleMove *temp = new PuzzleMove(move->tileMove_, move->b_, move->prev_);
		//std::list<PuzzleMove*>::iterator it = temp;
		//std::list<PuzzleMove*>::iterator it = ;
		//for(it = move; it != StartState; ++it)
		while(temp != StartState)
		{
			Solutions.push_back(temp->tileMove_);
			temp = temp->prev_;
		}
		
		Solutions.push_back(StartState->tileMove_);
		break;
		}
		move->b_->potentialMoves();
		/* Generates potentialMoves (in a map, see what you can do next) 
		For every potential move 's'
		 - if 's' does not exist in Closed_Set(i.e. is a new move)
		   - compute f value ( # of moves + heuristic)
		   - add 's' board to Closed_Set (no longer new move)
		   - add 's' to Open_List (will be continued later on)
		   - increment number of expansions (expansions_++ so you know)
		- forloop ends, because there is still a move (not solved) while continues
		
	finishes return solutionSet(??) */
	
		//**Possible algorithm
		//**
	
	}


//return int
//	return;
}

//returns number of expansions
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
