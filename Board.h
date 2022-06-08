#pragma once
#include "macros.h"
#include "Utilities.h"
#include "Tile.h"


class Board
{
public:
	/* Constructor/ Distructor */
	Board();

	/* algorithm */
	optional<LocIndx> BFS(const LocIndx& src) const ;

	/* Mutators */
	void initLevel(int level = 1);
	void resetLevel();
	void undo();
	

	bool isTileClicked(const Vector2f clickLoc);

	/* Draw*/
	void draw(RenderWindow* window);

private:
	/* Private Members */
	vector<vector<shared_ptr<Tile>>> m_board;
	stack<LocIndx> m_BussyStack;//stack of bussy cell for undo
	/* Private Functions */
	LocIndx randCell() const;
	void initBoard();
	bool isValid(const vector<vector<bool>>& vis, int row, int col) const ;
	vector<vector<bool>> visMap() const ;
	LocIndx getNeighbour(const int index, const int row, const int col, const int OddOrEven) const ;
	optional<LocIndx> findStep(LocIndx parents[][BS], const LocIndx& src, const LocIndx& dest) const;
	optional<LocIndx> findStep(const int row, const int col) const;
	unordered_set<int> randSet() const ;
};