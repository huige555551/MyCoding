#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define XWON "X won"
#define OWON "O won"
#define DRAW "Draw"
#define NOTC "Game has not completed"

char board[4][4];

string findResult()
{
	int xn = 0;
	int on = 0;
	int dn = 0;
	int tn = 0;

	bool dotExist = false;

	//check rows
	for(int i=0; i<4; i++)
	{
		xn = on = dn = tn = 0;
		for(int j=0; j<4; j++)
		{
			if(board[i][j] == 'X') xn++;
			else if(board[i][j] == 'O') on++;
			else if(board[i][j] == '.') dn++;
			else tn++;
		}

		if((xn==4) || (xn ==3 && tn==1)) return XWON;
		if((on==4) || (on ==3 && tn==1)) return OWON;
		if(dn) dotExist = true;
	}

	//check columns
	for(int j=0; j<4; j++)
	{
		xn = on = dn = tn = 0;
		for(int i=0; i<4; i++)
		{
			if(board[i][j] == 'X') xn++;
			else if(board[i][j] == 'O') on++;
			else if(board[i][j] == '.') dn++;
			else tn++;
		}

		if((xn==4) || (xn ==3 && tn==1)) return XWON;
		if((on==4) || (on ==3 && tn==1)) return OWON;
	}

	//check diagonal	
	xn = on = dn = tn = 0;
	for(int i=0; i<4; i++)
	{
		if(board[i][i] == 'X') xn++;
		else if(board[i][i] == 'O') on++;
		else if(board[i][i] == '.') dn++;
		else tn++;
	}
	if((xn==4) || (xn ==3 && tn==1)) return XWON;
	if((on==4) || (on ==3 && tn==1)) return OWON;
	
	//check reverse diagonal	
	xn = on = dn = tn = 0;
	for(int i=0; i<4; i++)
	{
		int j = 3-i;
		if(board[i][j] == 'X') xn++;
		else if(board[i][j] == 'O') on++;
		else if(board[i][j] == '.') dn++;
		else tn++;
	}
	if((xn==4) || (xn ==3 && tn==1)) return XWON;
	if((on==4) || (on ==3 && tn==1)) return OWON;
	

	if(dotExist) return NOTC;
	if(!dotExist) return DRAW;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int input_count;

	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		//do work
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				cin >> board[i][j];
			}
		}
		
		string result = findResult();
		cout << "Case #" << counter++ << ": " << result << "\n";

		//finish work
		input_count--;
	}

	return 0;
}