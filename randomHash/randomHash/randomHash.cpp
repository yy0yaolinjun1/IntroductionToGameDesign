#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <array>choseNum
#include"HashTable.h"
#include"DLinkedList.h"
using namespace std;

int CHOSENUM = 10000;
int TOTALNUM = 40000;
int student[10000];
int HASHLENGTH = 2000;
struct StuInfo
{
	int studentID;
	long long int cardID;
};
StuInfo stu[10000];
int ChoseStudentId(struct StuInfo *stu)
{
	int i, j;
	long long int initCardId = 1000000000000000000;
	srand(time(NULL));
	for (i = 0; i < CHOSENUM; )
	{

		stu[i].studentID = rand() % TOTALNUM;
		for (j = 0; j < i; j++)
			if (stu[j].studentID == stu[i].studentID)break;
		if (j == i)
		{
			initCardId++;
			stu[i].cardID = initCardId;
			i++;
		}
	}
	cout << "10000��������ѧ�������е�5������������" << endl;
	for (i = 0; i < 5; i++)
	{   
		cout <<"ѧ��ѧ�� "<<stu[i].studentID << "���п��� "<< stu[i].cardID <<endl;
	}

	return 0;
}
unsigned long int Hash(int i)
{
	return i;
}
int main()
{
	long long int ranNum[2000];
	HashTable<int, int> g_table(2000, Hash);
	int searchID = 0;
	bool isFind = false;
	ChoseStudentId(stu);
	for (int i = 0; i < CHOSENUM; i++)
	{
		g_table.Insert(stu[i].studentID, stu[i].studentID);
	}

	while (true)
	{
		cout << "��������Ҫ���ҵ�ѧ��id 0-39999" << endl;
		cin >> searchID;

		if (g_table.Find(searchID))
		{
			for (int i = 0; i < 10000; i++)
			{
				if (stu[i].studentID == searchID)
				{
					cout << "ѧ�������п�����" << stu[i].cardID << endl;
				}
			}
		}
		else
		{
			cout << "��ѧ��δ����ȡ��,���δ���ҵ�" << endl;
		}
	}

	system("pause");
	return 0;
}

