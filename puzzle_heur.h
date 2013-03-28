#ifndef PUZZLE_HEUR_H
#define PUZZLE_HEUR_H

//Skeleton Heuristic Class
class PuzzleHeuristic
{
 public:
  virtual int compute(int *tiles, int size) = 0;
};


// Define actual Heuristic Classes here
//Manhattan Heuristic Class
class ManhattanHeuristic : public PuzzleHeuristic
{
	public:
	int compute(int *tiles, int size);

	private:
	
};

//Out of Place Heuristic Class
class OutOfPlaceHeuristic : public PuzzleHeuristic
{
	public:
	int compute(int *tiles, int size);
	
	private:

};
#endif
