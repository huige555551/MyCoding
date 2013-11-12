#include <iostream>
#include <string>
#include <vector>
using namespace std;

int M[50][50];
vector<int> list;

int max_(int a, int b)
{ 
	if(a>b) return a; 
	else return b;
}

int LCS(const string& A, const string& B)
{
	int mx = 0;
	
	for(int i=0; i<=A.size(); i++) M[i][0] = 0;
	for(int j=0; j<=B.size(); j++) M[0][j] = 0;

	for(int i=1; i<=A.size(); i++)
	{
		for(int j=1; j<=B.size(); j++)
		{
			if(A[i-1]==B[j-1])
			{
				M[i][j] = M[i-1][j-1] + 1;
				
				if(M[i][j] > mx) {
					mx = M[i][j];

					list.clear();
					list.push_back(i-1); // store the last index of the substring
				}
				else if(M[i][j]==mx){
					list.push_back(i-1); //for more than 2 common substring
				}					
			}
			else {
				M[i][j] = 0;
			}
		}
	
	}

	return mx;
}

int main()
{
	string A = "ABAB";
	string B = "BABA";

	int lcs = LCS(A, B);
	cout << "Length of the longest common substring: " << lcs << endl;
	cout << "How many longest substring possible: " << list.size() << endl;

	for(int i=0; i<list.size(); i++)
	{
		//calculate the start index by subtracting the lenght of lcs
		for(int j=list[i]-lcs+1; j<=list[i]; j++)
		{
			cout << A[j];
		}
		cout << endl;
	}
	return 0;
}

