#include <cstdlib>
#include <iostream>
#include <queue>
#include "tree.h"
#include "DLinkedList.h"
#include <iostream>

using namespace std;

const char PROGRAM_NAME[] = "Rock Pile Game Demo";
const int WIDTH = 640;
const int HEIGHT = 480;
const int ITEMS = 64;
const int ARIAL = 0;
const int PILES = 1;
 int ROCKS = 8;
 int MAXTAKE = 1;
class RockState
{
public:

	// constructor, clear everything
	RockState()
	{
		int x;

		// clear each pile
		for (x = 0; x < PILES; x++)
			m_rocks[x] = 0;

		// make the minimax value 0
		m_minimaxValue = -1;

		// there is no next state yet.
		m_nextState = 0;
	}


	// equivalence operator, return true if all the piles match.
	bool operator== (RockState& p_rock)
	{
		int x;
		for (x = 0; x < PILES; x++)
		{
			// if any of the piles don't match, return false
			if (m_rocks[x] != p_rock.m_rocks[x])
				return false;
		}
		return true;
	}

	// determines if the pile is empty.
	bool Empty()
	{
		int x;
		for (x = 0; x < PILES; x++)
		{
			// if any of the piles aren't empty, return false
			if (m_rocks[x] != 0)
				return false;
		}
		return true;
	}

	// the rock data
	int m_rocks[PILES];

	// the minimax value of the state
	int m_minimaxValue;

	// the next state of the game using the minimax algorithm
	Tree<RockState>* m_nextState;
};



Tree<RockState>* g_tree;

// the initial state of the game
RockState g_startingState;

// the current state of the game
Tree<RockState>* g_current = 0;
//比较最大能拿多少个与石块剩余个数,返回其中的最小值
int MaxTakeStone(int maxTake, int stoneCount)
{
	if (maxTake <= stoneCount)
	{
		return maxTake;
	}
	else
	{
		return stoneCount;
	}
}
Tree<RockState>* CalculateTree(RockState p_state)
{
	int i;
	int rocks;

	// create a new tree node, 
	Tree<RockState>* tree = new Tree<RockState>;
	Tree<RockState>* child = 0;
	RockState state;
	TreeIterator<RockState> itr = tree;

	// set the tree nodes state to the parameter state
	tree->m_data = p_state;


	// loop through each pile
	for (i = 0; i < PILES; i++)
	{
		// loop through each rock in each pile
		for (rocks = 1; rocks <= MaxTakeStone(MAXTAKE,p_state.m_rocks[i]); rocks++)
		{
			// create a new state by subtracting rocks from
			// the current pile
			state = p_state;
			state.m_rocks[i] -= rocks;

			// calculate the game tree for the new state.
			child = CalculateTree(state);

			// add the child tree to the current tree.
			itr.AppendChild(child);
		}
	}
	return tree;
}

// return the heuristic value of the end-game state using
// the current players turn as a value.
int Heuristic(RockState p_state, bool p_max)
{
	return p_max;
}

void CalculateMiniMaxValue(Tree<RockState>* p_tree, bool p_max)
{
	// if the node is a leaf node, calculate its heuristic value.
	if (p_tree->m_children.m_count == 0)
	{
		p_tree->m_data.m_minimaxValue = Heuristic(p_tree->m_data, p_max);
		cout << p_max << " " << endl;
		return;
	}

	// else the node is not a leaf, so you need to calculate the min or the max
	// of its children.
	int minmax;
	TreeIterator<RockState> itr = p_tree;

	itr.ChildStart();
	minmax = itr.ChildItem().m_minimaxValue;
	p_tree->m_data.m_nextState = itr.m_childitr.m_node->m_data;
	itr.ChildForth();

	if (p_max == true)
	{
		// max's turn
		// loop through finding the highest child
		while (itr.ChildValid())
		{
			if (itr.ChildItem().m_minimaxValue > minmax)
			{
				minmax = itr.ChildItem().m_minimaxValue;
				p_tree->m_data.m_nextState = itr.m_childitr.m_node->m_data;
			}
			itr.ChildForth();
		}
	}
	else
	{
		// min's turn
		// loop through finding the lowest child
		while (itr.ChildValid())
		{
			if (itr.ChildItem().m_minimaxValue < minmax)
			{
				minmax = itr.ChildItem().m_minimaxValue;
				p_tree->m_data.m_nextState = itr.m_childitr.m_node->m_data;
			}
			itr.ChildForth();
		}
	}

	p_tree->m_data.m_minimaxValue = minmax;
	cout << p_max << " " << endl;
}

// recursively calculate the entire minimax tree.
void MiniMax(Tree<RockState>* p_tree, bool p_max)
{
	TreeIterator<RockState> itr = p_tree;
	
	// do a postorder traversal.
	for (itr.ChildStart(); itr.ChildValid(); itr.ChildForth())
	{
		MiniMax(itr.m_childitr.Item(), !p_max);
	}

	// process the current node.
	CalculateMiniMaxValue(p_tree, p_max);
}

void GameTree()
{
	if (g_tree != 0)
		delete g_tree;

	// calculate the new game tree
	g_tree = CalculateTree(g_startingState);
}

int main()
{

	cout << "请输入石头个数 和 每次最多能拿几个石头 " << endl;

	cin >> ROCKS >> MAXTAKE;

	cout <<"石头个数: "<<ROCKS <<"最多能拿: "<< MAXTAKE<<"个"<<endl;
	
	cout << "遍历minMaxTree的结果为" << endl;
	g_startingState.m_rocks[PILES-1] = ROCKS;

	GameTree();

	MiniMax(g_tree, true);

	
	cin >> ROCKS >> MAXTAKE;

	return 0;
}