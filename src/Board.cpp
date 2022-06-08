#include"Board.h"

Board::Board()
{
	srand(time(NULL));
	initBoard();

	initLevel();
}



void Board::initBoard()
{
	for (size_t row = 0; row < BS; row++)
	{
		auto newRow = vector<shared_ptr<Tile>>();
		for (size_t col = 0; col < BS; col++)
			newRow.push_back(make_shared <Tile>(setTilePosition({ row, col }), FreeColor));
		m_board.push_back(newRow);
	}
}

void Board::initLevel(int level)
{
	m_BussyStack = stack<LocIndx>();//clear stack

	for (size_t row = 0; row < BS; row++)
		for (size_t col = 0; col < BS; col++)
			m_board[row][col]->setFree();

	auto numOfBussy = ((rand() % 3) + 12) / level;
	
	set<LocIndx> bussyTiles;
	while (bussyTiles.size() < numOfBussy)
		bussyTiles.insert(randCell());


	for (auto& tile : bussyTiles)
		m_board[tile.first][tile.second]->setBussy();

}

void Board::resetLevel()
{
	while (!m_BussyStack.empty())
	{
		auto cell = m_BussyStack.top();
		m_board[cell.first][cell.second]->setFree();
		m_BussyStack.pop();
	}
}


LocIndx Board::randCell() const
{
	int row, col;
	do
	{
		row = rand() % 11;
		col = rand() % 11;
	} while (make_pair(row, col) == dragonStart);

	return { row , col };
}

bool Board::isTileClicked(const Vector2f clickLoc) 
{
	for (auto i = 0; i < m_board.size(); i++)
		for (auto j = 0; j < m_board[i].size(); j++)
			if (m_board[i][j]->getGlobalBounds().contains(clickLoc) && !m_board[i][j]->isBussy())
			{
				m_board[i][j]->setBussy();
				m_BussyStack.push({ i , j });
				return true;
			}
	return false;
}

void Board::undo()
{
	if (!m_BussyStack.empty())
	{
		auto& undoTile = m_BussyStack.top();
		m_BussyStack.pop();
		m_board[undoTile.first][undoTile.second]->setFree();
	}
}

bool Board::isValid(const vector<vector<bool>>& vis, int row, int col) const
{
	// If cell lies out of bounds
	if (row < firstRow || col < firstCol || row > lastRow || col > lastCol || vis[row][col])
		return false;
	return true;
}

vector<vector<bool>> Board::visMap() const
{
	vector<vector<bool>> vis;
	for (auto i = 0; i < m_board.size(); i++)
	{
		vector<bool> temp;
		for (auto j = 0; j < m_board[i].size(); j++)
			temp.push_back(((m_board[i][j]->isBussy() ? true : false)));
		vis.push_back(temp);
	}
	return vis;
}

optional<LocIndx> Board::BFS(const LocIndx& src) const 
{
	//initial visited verticies
	auto vis = visMap();
	LocIndx parents[BS][BS];
	queue<LocIndx> q;
	q.push(src);
	vis[src.first][src.second] = true;
	while (!q.empty())
	{
		auto& cell = q.front();
		int x = cell.first;
		int y = cell.second;
		if (x == firstCol || y == firstRow || x == lastCol || y == lastRow)//if cell is end of board
			return findStep(parents, src, cell);

		q.pop();
		auto neighbours = randSet();

		for (auto& i : neighbours)
		{
			auto adjCell = getNeighbour(i, x, y, oddOrEven(x));
			int adjx = adjCell.first;
			int adjy = adjCell.second;

			if (isValid(vis, adjx, adjy))
			{
				q.push({ adjx, adjy });
				vis[adjx][adjy] = true;
				parents[adjx][adjy] = { x, y };
			}
		}
	}
	//the cat was trapped, return free neighbour tile
	return findStep(src.first, src.second);

}

unordered_set<int> Board::randSet() const
{
	unordered_set<int> s ;
 
	while (s.size() < maxNumOfNeighbours)
	{
		int num = rand() % 6;
		s.insert(num);
	}
	return s;
}


optional<LocIndx> Board::findStep(LocIndx parents[][BS], const LocIndx& src, const LocIndx& dest) const
{
	auto x = dest.first;
	auto y = dest.second;
	while (parents[x][y] != src)
	{
		auto temp = parents[x][y];
		x = temp.first;
		y = temp.second;
	}
	return make_pair(x, y);
}

optional<LocIndx> Board::findStep(const int row, const int col) const 
{
	for (int i = 0; i < 6; i++)
	{
		auto neig = getNeighbour(i, row, col, oddOrEven(row));
		if (!m_board[neig.first][neig.second]->isBussy())
			return neig;

	}
	return {};
}

LocIndx Board::getNeighbour(const int index, const int row, const int col, const int OddOrEven) const
{
	switch (index)
	{
	case 0: return { row - 1, col + OddOrEven };
	case 1: return { row - 1, col };
	case 2: return { row , col - 1 };
	case 3: return { row , col + 1 };
	case 4: return { row + 1, col + OddOrEven };
	case 5: return { row + 1, col };
	default: return { row, col };
	}
}

void Board::draw(RenderWindow* window)
{
	for (auto& row : m_board)
		for (auto& tile : row)
			tile->draw(window);
}