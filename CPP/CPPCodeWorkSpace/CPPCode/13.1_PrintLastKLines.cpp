#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void readFile1()
{
	ifstream inFile("input.in");

	if(inFile.is_open())
	{
		while(inFile.good()){
			string line;
			getline(inFile, line);
			cout << line << endl;
		}
		inFile.close();
	}
}
void readFile2()
{
	ifstream inFile("input.in");

	if(inFile.is_open())
	{
		string line;
		while(getline(inFile, line)){
			cout << line << endl;
		}
		inFile.close();
	}
} 

void lastKline(int k)
{
	ifstream inFile("input.in");
	vector<string> lineStr(k);
	
	int i=0;
	if(inFile.is_open())
	{				
		while(inFile.good()){
			getline(inFile, lineStr[i%k]);
			i++;
		}
		inFile.close();
	}

	int start, count;

	if(i<k) {
		start = 0;
		count = i;
	}else{
		start = i%k;
		count = k;
	}
	
	for(int j=0; j<count; j++){
		cout << lineStr[(start+j)%k] << endl;
	}
	cout << endl;
}

int main()
{
	//readFile1();
	//readFile2();
	for(int i=1; i<7; i++){
		cout << "Last " << i << " lines:\n";
		lastKline(i);
		cout << endl;
	}

	lastKline(50);
	return 0;
}