#include <iostream>
#include <cstdlib>
#include <math.h>
#include "puzzle_heur.h"
using namespace std;

//Out Of Place Heuristic Computation
int OutOfPlaceHeuristic::compute(int *tiles, int size)
{
	int heuristic=0;
	for(int i=0; i<size; i++)
	{
		//if there is a tile out of place, add one to heuristic
		if(tiles[i] != i)
		{
			heuristic++;
		}
	}

	return heuristic;
}

//Manhattan Heuristic Computation
int ManhattanHeuristic::compute(int *tiles, int size)
{
	int iRow;
	int iColumn;
	int jRow;
	int jColumn;
	int dim = sqrt(size);
	int heuristic=0;
	
//Searching through array looking for any number out of place
	for(int i=0; i<size; i++)
	{
		if(tiles[i] != i)
		{
			//Calculate current row and column of incorrect place
			iRow = i/dim;
			iColumn = i%dim;
			//Find correct row and column
			for(int j=0; j<size; j++)
			{
				if(j == tiles[i])
				{
					jRow = j/dim;
					jColumn = j%dim;
					//adding heuristic up
					heuristic+= abs(iRow-jRow) + abs(iColumn-jColumn);
				}
			}
		}
	}

	return heuristic;
}
