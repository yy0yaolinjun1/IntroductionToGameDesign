#include<iostream>
#include<cmath>
#include<deque>
using namespace std;

const int ROW = 30;
const int COLUMN = 20;
enum status { open, closed, obstacle, unsorted };
struct node {
	int row;
	int col;
	node* father;
	int gvalue;
	int hvalue;
	int fvalue;
	status st;
};
node map[ROW][COLUMN];

deque<node*> openTable;
deque<node*> closeTable;

int init(node source, node dest)
{
	for (int i = 0; i<ROW; i++)
	{
		for (int j = 0; j<COLUMN; j++)
		{
			map[i][j].row = i;
			map[i][j].col = j;
			map[i][j].father = NULL;
			map[i][j].hvalue = (abs(i - dest.row) + abs(j - dest.col)) * 10;
			map[i][j].st = unsorted;
		}
	}
	//设置障碍物
	for (int i = 2; i < 13; i++)
	{
		map[i][20].st = obstacle;
	}
	for (int i = 15; i < 20; i++)
	{
		map[7][i].st = obstacle;
	}
	for (int i = 10; i < 20; i++)
	{
		map[13][i].st = obstacle;
	}


	map[source.row][source.col].st = open;
	map[source.row][source.col].gvalue = 0;
	openTable.push_back(&map[source.row][source.col]);
	return 0;
}

void openNeighbor(int row, int col)

	{
		deque<node*>::iterator it;
for (it = openTable.begin(); it<openTable.end(); it++)
{
	if ((*it) == (&map[row][col]))
	{
		map[row][col].st = closed;
		openTable.erase(it);
		closeTable.push_back(&map[row][col]);
		break;
	}
}
//上
if (row - 1 >= 0)
{
	if (map[row - 1][col].st == open)//检查该节点是否有更优的G值

	{
		if (map[row - 1][col].gvalue>map[row][col].gvalue + 10)
		{
			map[row - 1][col].gvalue = map[row][col].gvalue + 10;
			map[row - 1][col].father = &map[row][col];
		}
	}
	else if (map[row - 1][col].st == unsorted)
	{
		map[row - 1][col].st = open;
		map[row - 1][col].father = &map[row][col];
		map[row - 1][col].gvalue = 10 + map[row][col].gvalue;
		openTable.push_back(&map[row - 1][col]);
	}
}
//右
if (col + 1<COLUMN)
{
	if (map[row][col + 1].st == open)
	{
		if (map[row][col + 1].gvalue>map[row][col].gvalue + 10)
		{
			map[row][col + 1].gvalue = map[row][col].gvalue + 10;
			map[row][col + 1].father = &map[row][col];
		}
	}
	else if (map[row][col + 1].st == unsorted)
	{
		map[row][col + 1].st = open;
		map[row][col + 1].father = &map[row][col];
		map[row][col + 1].gvalue = 10 + map[row][col].gvalue;
		openTable.push_back(&map[row][col + 1]);
	}
}
//下
if (row + 1<ROW)
{
	if (map[row + 1][col].st == open)
	{
		if (map[row + 1][col].gvalue>map[row][col].gvalue + 10)
		{
			map[row + 1][col].gvalue = map[row][col].gvalue + 10;
			map[row + 1][col].father = &map[row][col];
		}
	}
	else if (map[row + 1][col].st == unsorted)
	{
		map[row + 1][col].st = open;
		map[row + 1][col].father = &map[row][col];
		map[row + 1][col].gvalue = 10 + map[row][col].gvalue;
		openTable.push_back(&map[row + 1][col]);
	}
}
//左
if (col - 1 >= 0)
{
	if (map[row][col - 1].st == open)
	{
		if (map[row][col - 1].gvalue>map[row][col].gvalue + 10)
		{
			map[row][col - 1].gvalue = map[row][col].gvalue + 10;
			map[row][col - 1].father = &map[row][col];
		}
	}
	else if (map[row][col - 1].st == unsorted)
	{
		map[row][col - 1].st = open;
		map[row][col - 1].father = &map[row][col];
		map[row][col - 1].gvalue = 10 + map[row][col].gvalue;
		openTable.push_back(&map[row][col - 1]);
	}
}
//左上
if (row - 1 >= 0 && col - 1 >= 0 && map[row - 1][col].st != obstacle && map[row][col - 1].st != obstacle)
{
	if (map[row - 1][col - 1].st == open)
	{
		if (map[row - 1][col - 1].gvalue>map[row][col].gvalue + 14)
		{
			map[row - 1][col - 1].gvalue = map[row][col].gvalue + 14;
			map[row - 1][col - 1].father = &map[row][col];
		}
	}
	else if (map[row - 1][col - 1].st == unsorted)
	{
		map[row - 1][col - 1].st = open;
		map[row - 1][col - 1].father = &map[row][col];
		map[row - 1][col - 1].gvalue = 14 + map[row][col].gvalue;
		openTable.push_back(&map[row - 1][col - 1]);
	}
}
//右上
if (row - 1 >= 0 && col + 1<COLUMN && map[row - 1][col].st != obstacle && map[row][col + 1].st != obstacle)
{
	if (map[row - 1][col + 1].st == open)
	{
		if (map[row - 1][col + 1].gvalue>map[row][col].gvalue + 14)
		{
			map[row - 1][col + 1].gvalue = map[row][col].gvalue + 14;
			map[row - 1][col + 1].father = &map[row][col];
		}
	}
	else if (map[row - 1][col + 1].st == unsorted)
	{
		map[row - 1][col + 1].st = open;
		map[row - 1][col + 1].father = &map[row][col];
		map[row - 1][col + 1].gvalue = 14 + map[row][col].gvalue;
		openTable.push_back(&map[row - 1][col + 1]);
	}
}
//右下
if (row + 1<ROW && col + 1<COLUMN && map[row + 1][col].st != obstacle && map[row][col + 1].st != obstacle)
{
	if (map[row + 1][col + 1].st == open)
	{
		if (map[row + 1][col + 1].gvalue>map[row][col].gvalue + 14)
		{
			map[row + 1][col + 1].gvalue = map[row][col].gvalue + 14;
			map[row + 1][col + 1].father = &map[row][col];
		}
	}
	else if (map[row + 1][col + 1].st == unsorted)
	{
		map[row + 1][col + 1].st = open;
		map[row + 1][col + 1].father = &map[row][col];
		map[row + 1][col + 1].gvalue = 14 + map[row][col].gvalue;
		openTable.push_back(&map[row + 1][col + 1]);
	}
}
//左下
if (row + 1<ROW && col - 1 >= 0 && map[row + 1][col].st != obstacle && map[row][col - 1].st != obstacle)
{
	if (row + 1<ROW && col - 1 >= 0 && map[row + 1][col - 1].st == open && map[row + 1][col].st != obstacle && map[row][col - 1].st != obstacle)
	{
		if (map[row + 1][col - 1].gvalue>map[row][col].gvalue + 14)
		{
			map[row + 1][col - 1].gvalue = map[row][col].gvalue + 14;
			map[row + 1][col - 1].father = &map[row][col];
		}
	}
	else if (row + 1<ROW && col - 1 >= 0 && map[row + 1][col - 1].st)
	{
		map[row + 1][col - 1].st = open;
		map[row + 1][col - 1].father = &map[row][col];
		map[row + 1][col - 1].gvalue = 14 + map[row][col].gvalue;
		openTable.push_back(&map[row + 1][col - 1]);
	}
}
	}

	bool findPath(node source, node dest)
	{
		int minDistence;
		int pos;
		int rowNum, colNum;
		deque<node*>::iterator i;
		while (openTable.size()>0)
		{

			minDistence = numeric_limits<int> ::max();
			for (i = openTable.begin(); i<openTable.end(); i++)
			{
				if ((((node*)*i)->gvalue + ((node*)*i)->hvalue)<minDistence)
				{
					minDistence = ((node*)*i)->gvalue + ((node*)*i)->hvalue;
					rowNum = ((node*)*i)->row;
					colNum = ((node*)*i)->col;
				}
			}
			if (rowNum == dest.row && colNum == dest.col)
			{
				openNeighbor(rowNum, colNum);
				return true;
			}
			else
			{
				openNeighbor(rowNum, colNum);
			}
		}
		return false;
	}

	void printPath(node source, node dest)
	{
		deque<node*> dq;
		dq.clear();
		node* p = &map[dest.row][dest.col];
		while (!(p->row == source.row&&p->col == source.col))
		{
			dq.push_back(p);
			p = p->father;
		}
		dq.push_back(p);
		for (int i = dq.size() - 1; i >= 0; i--)
		{
			cout << "(" << dq[i]->row << "," << dq[i]->col << ")" << endl;
		}
	}

	int main()
	{
		node source, dest;
		source.row = 11;
		source.col = 11;
		dest.row = 22;
		dest.col = 2;
		init(source, dest);
		cout << "(11,11)->(22,2)的结果" << endl;
		if (findPath(source, dest))
		{
			printPath(source, dest);
		}
		else
		{
			cout << "无法找到最短路径" << endl;
		}
		system("pause");
		return 0;
	}