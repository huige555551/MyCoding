#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define MAX 201

vector<int> solution;
vector<int> chestUse;
set<int> keysToChest[MAX];

void printResult()
{
	for(int i=0; i<solution.size(); i++)
		cout << solution[i]+1 << " ";
}

bool existsInSolution(int c)
{
	if(chestUse[c]) return true;
	return false;
}

int canOpenWithMyKeys(int chest, map<int, int>& myKeys)
{
	for(auto it=myKeys.begin(); it!=myKeys.end(); it++)
	{
		if(it->second){
			if(keysToChest[it->first].find(chest) != keysToChest[it->first].end())
				return it->first;
		}
	}
	return -1;
}

bool keyFinished(map<int,int>& myKeys)
{
	for(auto it=myKeys.begin(); it!=myKeys.end(); it++)
	{
		if(it->second) return false;
	}

	return true;
}

bool findResult(vector<int>& chestSecKey, vector<vector<int>>& chestKeyCol, map<int,int>& myKeys)
{
	
	if(solution.size()==chestSecKey.size()){
		printResult();
		return true;
	}

	if(keyFinished(myKeys)) return false;
		
	for(int c=0; c<chestSecKey.size(); c++)
	{
		if(existsInSolution(c)) continue;

		int kk = canOpenWithMyKeys(c, myKeys);
		if(kk >= 0)
		{			
			myKeys[kk]--;

			solution.push_back(c);
			chestUse[c] = 1;
							
			for(int k=0; k<chestKeyCol[c].size(); k++)
				myKeys[chestKeyCol[c][k]]++; //push_back(chestKeyCol[c][k]);

			bool t = findResult(chestSecKey, chestKeyCol, myKeys);
			if(t) return true;

			for(int k=0; k<chestKeyCol[c].size(); k++)
				myKeys[chestKeyCol[c][k]]--; //myKeys.pop_back();
				
			chestUse[c] = 0;
			solution.pop_back();
			myKeys[kk]++;
		}
	}
	
	return false;
}

int main()
{
	freopen("D-small-practice.in", "r", stdin);
	//freopen("D-small-practice.out", "w", stdout);

	int input_count;
	cin >> input_count;

	int counter = 1;
	while(input_count)
	{
		int nKey, nChest;

		cin >> nKey;
		cin >> nChest;

		//vector<int> myKeys;
		map<int, int> myKeys;

		for(int i=0; i<nKey; i++){
			int temp; cin >> temp;
			myKeys[temp]++;//.push_back(temp);
		}

		vector<vector<int>> chestKeyCol(nChest, vector<int>());
		vector<int> chestSecKey;
		for(int j=0; j<MAX; j++){
			keysToChest[j].clear();
		}

		for(int i=0; i<nChest; i++)
		{
			int keyType, nK;			

			cin >> keyType;
			cin >> nK;					

			chestSecKey.push_back(keyType);
			keysToChest[keyType].insert(i);

			for(int j=0; j<nK; j++){
				int temp; cin >> temp;
				chestKeyCol[i].push_back(temp);
			}
		}		

		chestUse.clear(); chestUse.resize(nChest, 0);
		solution.clear();		

		cout << "Case #" << counter++ << ": ";
		bool result = findResult(chestSecKey, chestKeyCol, myKeys);
		if(!result) cout << "IMPOSSIBLE";
		cout << "\n";		

		//finish work
		input_count--;
	}

	return 0;
}