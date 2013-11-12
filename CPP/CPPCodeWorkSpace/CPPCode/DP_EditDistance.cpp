#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min_(int a, int b, int c)
{
	int m = c;

	if(a<b) {
		if(a<c) m = a;
	}
	else {
		if(b<c) m = b;
	}

	return m;
}

int editDistRecur(char* s1, char* s2, int m, int n)
{
	if(m==0 && n==0) return 0;
	if(m==0) return n;
	if(n==0) return m;

	if(s1[m]==s2[n]){ 
		return editDistRecur(s1, s2, m-1, n-1);
	}
	else{
		int t_replace = 1 + editDistRecur(s1, s2, m-1, n-1); // corner
		int t_delete = 1 + editDistRecur(s1, s2, m-1, n);    // up
		int t_insert = 1 + editDistRecur(s1, s2, m, n-1);	 // left
		int t_final = min_(t_replace, t_delete, t_insert);

		return t_final;
	}
}

void printResult(vector<vector<int>> R, char* s1, char* s2, int m, int n)
{
	if(m==0 && n==0) return;

	if(R[m][n] == 0){
		printResult(R, s1, s2, m-1, n-1);
	}
	else if(R[m][n] == 1){
		printResult(R, s1, s2, m-1, n-1);
		cout << s1[m-1] << " at position " << m-1 << " is replaced with " << s2[n-1] << endl;
	}
	else if(R[m][n] == 2){
		printResult(R, s1, s2, m-1, n);
		cout << s1[m-1] << " at position " << m-1 << " is deleted." << endl;
	}
	else {
		printResult(R, s1, s2, m, n-1);
		cout << s2[n-1] << " is inserted after position " << m-1 << endl;
	}	
}

int editDistDyn(char* s1, char* s2, int m, int n)
{
	vector<vector<int>> M(m+1, vector<int>(n+1, 0));
	vector<vector<int>> R(m+1, vector<int>(n+1, -1));

	for(int i=0; i<=m; i++) { M[i][0] = i; R[i][0]=2;}
	for(int j=0; j<=n; j++) { M[0][j] = j; R[0][j]=3;}

	cout << "  ";
	for(int j=0; j<n; j++) cout << s2[j] << " "; cout << endl;

	for(int i=1; i<=m; i++)
	{
		cout << s1[i-1] << " ";
		for(int j=1; j<=n; j++)
		{
			if(s1[i-1]==s2[j-1]) 
			{
				M[i][j] = M[i-1][j-1];
				R[i][j] = 0;
			}
			else
			{
				int t_replace = 1 + M[i-1][j-1];
				int t_delete  = 1 + M[i-1][j];
				int t_insert  = 1 + M[i][j-1];

				M[i][j] = t_replace;
				R[i][j] = 1;

				if(t_delete < t_insert)
				{
					if(t_delete < t_replace)
					{
						M[i][j] = t_delete;
						R[i][j] = 2;
					}
				}
				else
				{
					if(t_insert < t_replace)
					{
						M[i][j] = t_insert;
						R[i][j] = 3;
					}
				}
			}

			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	printResult(R, s1, s2, strlen(s1), strlen(s2));
	return M[m][n];
}



int main()
{
	char s1[] = "CTGATC";
	char s2[] = "CCTAC";

	cout << editDistRecur(s1, s2, strlen(s1), strlen(s2)) << endl;
	cout << editDistDyn(s1, s2, strlen(s1), strlen(s2)) << endl;

	return 0;
}