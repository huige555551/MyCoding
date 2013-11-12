#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

#define MAX 100

int board[MAX][MAX];

bool checkRow(int r, int c, int N, int M)
{
	for(int i=0; i<N; i++)
	{
		if(board[i][c] > board[r][c]) 
			return false;
	}

	return true;
}

bool checkCol(int r, int c, int N, int M)
{
	for(int i=0; i<M; i++)
	{
		if(board[r][i] > board[r][c]) 
			return false;
	}

	return true;
}


bool findResult(int N, int M)
{
	for(int r=0; r<N; r++){
		for(int c=0; c<M; c++){
			bool rowPos = checkRow(r, c, N, M);
			bool colPos = checkCol(r, c, N, M);
			
			if(!rowPos && !colPos) 
				return false;				
		}
	}

	return true;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		int N, M;

		cin >> N;
		cin >> M;

		//do work
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> board[i][j];
				//cout << board[i][j];
			}
			//cout << endl;
		}
		//cout << endl;
		
		bool result = findResult(N, M);
		cout << "Case #" << counter++ << ": ";
		if(result) cout << "YES" << "\n";
		else cout << "NO" << "\n";

		//finish work
		input_count--;
	}

	return 0;
}