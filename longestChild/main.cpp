#include<stdio.h>
#include<iostream>


#include<stdio.h>
#include <cstring>
using namespace::std;
#define min(x,y) (x<y?x:y)
#define MAX_CHAR 4
#define A 0
#define B 1
#define C 2
#define D 3
//ÿ��node���е���Ϣ
struct node {
	//�ڵ��д洢���ַ�
	char store;
    //�ڵ����ַ�ָ�����һ���ڵ���,Ϊ������Ϊ-1
	int nextstatus=-1;
	//�ж��ַ��Ƿ����
	bool isExited;
};
int main() {

	node transformMatrix[3][4];

		bool isStart = false;
		int transMatrix[3][3];
		char inputChar[50] = "aaababefabddcbbb";
		//���浱ǰ���ַ���
		char longestChar[40] = "";
		//����֮ǰ����ַ���
		char currentLongestChar[40] = "";
		int currenCharIndex = 0;
		//��ʼ״̬Ϊ�ڵ�1
		int currentState = 0;

		int length = 0;

		int i = 0;
		int j = 0;
		//��ʼ��
		//״̬1ʱ
		transformMatrix[0][A].isExited = 1;
		transformMatrix[0][A].store = 'a';
		transformMatrix[0][A].nextstatus = 0;

		transformMatrix[0][B].isExited = 1;
		transformMatrix[0][B].store = 'b';
		transformMatrix[0][B].nextstatus = 1;

		transformMatrix[0][C].isExited = 0;
		transformMatrix[0][C].store = 'c';

		transformMatrix[0][D].isExited = 0;
		transformMatrix[0][D].store = 'd';
	
		//״̬2ʱ
		transformMatrix[1][A].isExited = 1;
		transformMatrix[1][A].store = 'a';
		transformMatrix[1][A].nextstatus = 0;

		transformMatrix[1][B].isExited = 0;
		transformMatrix[1][B].store = 'b';

		transformMatrix[1][C].isExited = 1;
		transformMatrix[1][C].store = 'c';
		transformMatrix[1][C].nextstatus = 2;

		transformMatrix[1][D].isExited = 1;
		transformMatrix[1][D].store = 'd';
		transformMatrix[1][D].nextstatus = 1;

		transMatrix[1][A] = 1;
		transMatrix[1][B] = 1;
		transMatrix[1][C] = 1;
		//״̬3ʱ
		transformMatrix[2][A].isExited = 0;
		transformMatrix[2][A].store = 'a';

		transformMatrix[2][B].isExited = 1;
		transformMatrix[2][B].store = 'b';
		transformMatrix[2][B].nextstatus = 2;

		transformMatrix[2][C].isExited = 0;
		transformMatrix[2][C].store = 'c';

		transformMatrix[2][D].isExited = 0;
		transformMatrix[2][D].store = 'd';

		transMatrix[2][A] = 0;
		transMatrix[2][B] = 1;
		transMatrix[2][C] = 0;
		cout << "�����벻����50��λ���ȵ��ַ�����" << endl;
		cin >> inputChar;
		cout << "�ַ�����lengthΪ " << strlen(inputChar) << endl;
		
		for (int i = 0; i < strlen(inputChar); i++)
		{
			//״̬1ʱ
			if (inputChar[i] == 'a')
			{
				for (j = 0; j < MAX_CHAR; j++)
				{
					if (transformMatrix[currentState][j].store == 'a')
					{
						strcat_s(longestChar, "a");
						currentState = transformMatrix[currentState][j].nextstatus;
						break;
					}
				}
			}
			if (inputChar[i] == 'b')
			{
				for (j = 0; j < MAX_CHAR; j++)
				{
					if (transformMatrix[currentState][j].store == 'b')
					{
						strcat_s(longestChar, "b");
						currentState = transformMatrix[currentState][j].nextstatus;
						break;
					}
				}
			}
			if (inputChar[i] == 'c')
			{
				for (j = 0; j < MAX_CHAR; j++)
				{
					if (transformMatrix[currentState][j].store == 'c')
					{
						strcat_s(longestChar, "c");
						currentState = transformMatrix[currentState][j].nextstatus;
						break;
					}
				}
			}
			if (inputChar[i] == 'd')
			{
				
				for (j = 0; j < MAX_CHAR; j++)
				{
					if (transformMatrix[currentState][j].store == 'd')
					{
						strcat_s(longestChar, "d");
						currentState = transformMatrix[currentState][j].nextstatus;
						continue;
					}
				}
			}
			//��a b c d�����������ַ�
			else if(inputChar[i] !='a'&&inputChar[i] != 'b'&& inputChar[i] != 'c'&& inputChar[i] != 'd')
			{
				if (strlen(currentLongestChar) < strlen(longestChar))
				{
					strcpy_s(currentLongestChar, longestChar);
				}
				strcpy_s(longestChar, "");
			}
			
		}
		//�ڽ���ʱ���֮ǰ����ַ����������µ��ַ���,���ֵ���赽��������
		if (strlen(currentLongestChar) >= strlen(longestChar))
		{
			strcpy_s(longestChar,currentLongestChar);
		}

		cout << "����ת��״̬����Ӵ�Ϊ��" << endl << longestChar << endl;

	system("pause");
	return 0;
}

//int main()
//{
//	//a b c 
//	bool isStart = false;
//	char transMatrix[3][3];
//	char longestChar[50] = "NULL";
//	char currentChar[40] = "NULL";
//	int currenCharIndex = 0;
//	char inputChar[50] = "NULL";
//	int length = 0;
//	transMatrix[0][0] = 'a';
//	transMatrix[0][1] = 'b';
//	transMatrix[0][2] = '0';
//	transMatrix[1][0] = 'a';
//	transMatrix[1][1] = 'd';
//	transMatrix[1][2] = 'c';
//	transMatrix[2][0] = '0';
//	transMatrix[2][1] = '0';
//	transMatrix[2][2] = 'b';
//	cout << transMatrix[0][0] << endl;
//	cin >> inputChar;
//	cout << inputChar[0];
//	length = strlen(inputChar);
//	cout << length;
//	system("pause");
//	for (int i = 0; i < length; i++)
//	{
//		if (inputChar[i] == 'a'&&isStart==false)
//		{
//			isStart = true;
//			currentChar[currenCharIndex] = 'a';
//			currenCharIndex++;
//		}
//
//	}
//	return 0;
//}
//#include<iostream>  
//#include<vector>  
//#include<map>  
//#include<string.h>   
//#include<math.h>
//using namespace std;
//#define min(x,y) (x<y?x:y)
//
//bool Matching_Prefix(const char *P, int k, int q, char a) {
//	if (k == 0)
//		return true;
//	if (k == 1) {
//		return P[0] == a;
//	}
//	return P[k - 1] == a && (strncmp(P, P + q - k + 1, k - 1) == 0);
//}
//
//vector<map<char, int>> Compute_Transition_Function(const char *P, const char*input_character) {
//	int m = strlen(P);
//	int j = 0, k;
//	cout << m << endl;
//	vector<map<char, int> >transition_map(m + 1);
//	for (int i = 0; i<m; i++) {
//		j = 0;
//		cout << "p:" << i << endl;                        //״̬i   
//		while (input_character[j] != '\0') {
//			k = min(m + 1, i + 2);
//			do {
//				k = k - 1;
//			} while (!Matching_Prefix(P, k, i, input_character[j]));
//			transition_map[i][input_character[j]] = k;
//			cout << "״̬p:" << i << ",    �����ַ�" << input_character[j] << ",    k:" << k << endl;   //���״̬ת�ƺ���   
//			j++;
//		}
//	}
//	return  transition_map;
//}
//
//
//void Finite_Automaton_Matcher(char *T, char*P, vector<map<char, int>>transition_map) {
//	int n = strlen(T);
//	int m = strlen(P);
//	int q = 0;   //��ʼ״̬Ϊ0      
//	for (int i = 0; i<n; i++) {
//		q = transition_map[q][T[i]];
//		if (q == m)
//			cout << "Pattern occurs whit shift" << i - m << endl;
//	}
//
//}
//
//
//int main() {
//	const char *input_character = "abcdefghijklmnopqrstuvwxyz";  //����������ĸ��   
//	char T[] = "abdfdfsdklfdjgkjgdkjerdfgfdg";
//	char P[11] = "dklfdjgkj";
//	vector<map<char, int>>transition_map = Compute_Transition_Function(P, input_character);
//	Finite_Automaton_Matcher(T, P, transition_map);
//	system("pause");
//	return 0;
//}