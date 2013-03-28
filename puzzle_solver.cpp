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
	PMMinList Open_List;
	BoardSet Closed_Set;
	vector<PuzzleMove*> Garbage_List;
	MyList<int> Solutions;

	PuzzleMove *StartState = new PuzzleMove(b_);

	//Adding to open list and closed set
	Open_List.push(StartState);
	Closed_Set.insert(StartState->b_);
	Garbage_List.push_back(StartState);

	while(!Open_List.empty())
	{
		PuzzleMove move = Open_List.top();
		Open_List.pop();
		Closed_Set.insert(move->b_);
		
		if(move->b_->solved())
		{
		
		}
		
	
	
	}


//return int
	return;
}

//returns number of expansions
int PuzzleSolver::getNumExpansions()
{
  return expansions_;
}
