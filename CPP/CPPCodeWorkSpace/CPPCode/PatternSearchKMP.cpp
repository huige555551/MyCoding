#include <iostream>
#include <string>
#include <vector>
using namespace std;

void KMPSearch(const string& txt, const string& pat, const vector<int>& LPS)
{
	int i = 0;
	int j = 0;

	while (i < txt.size())
	{
		if(txt[i] == pat[j])
		{
			i++;
			j++;
		}

		if(j == pat.size())
		{
			cout << "Pattern found at position: " << i - j + 1 << endl;
			j = LPS[j-1];
		}
		else if ( txt[i] != pat[j])
		{
			if(j > 0)
			{
				j = LPS[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

//compute Longest Prefix of the pattern 
//which is equal to the Suffix of pattern
vector<int> generateLPS(string pat)
{
	// for each subpattern of the pattern
	// computer and store longest prefix length
	vector<int> LPS(pat.length());

	int i = 1; // start from index 1
	int j = 0; // check matching prefix from index 0
	LPS[0] = 0;// fro the first index longest prefix is 0

	//for each index of the pattern
	while(i < pat.size())
	{
		// if suffix of pattern = prefix of pattern
		// pat[i-j..i] = pat [0..j]
		if(pat[i] == pat[j])
		{
			LPS[i] = j + 1;
			i++;
			j++;
		}
		else //if pat[i] != pat[j]
		{
			// if current prefix length is not zero
			if(j > 0) {
				j = LPS[j-1]; // try with previous prefix length
				// but dont increase the index i
			} else {
				//there is no prefix matched
				//start from 0 again for perfix matching j=0
				LPS[i] = 0;
				i++;
			}
		}
	}

	return LPS;
}

void printLPS(const vector<int>& LPS, string pat)
{
	for(int i = 0; i < LPS.size(); i++)	{
		cout.width(i+1);
		cout << i; 		
	}
	cout << endl;

	for(int i = 0; i < LPS.size(); i++)	{
		cout << pat.substr(0, i+1); 
		cout << " ";
	}
	cout << endl;

	for(int i = 0; i < LPS.size(); i++)	{
		cout.width(i+1);
		cout << LPS[i]; 		
	}
	cout << endl;
}

int main()
{
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABCABAB";

	vector<int> LPS = generateLPS(pat);
	// print LPS array
	printLPS(LPS, pat);

	KMPSearch(txt, pat, LPS);

	return 0;
}


//http://computing.dcu.ie/~humphrys/Notes/String/kmp.html
//http://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm/