#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool consonant(string sub, long num){
	long count = 0;

	for(long i=0; i<sub.length(); i++)
	{
		if(sub[i]=='a' || sub[i]=='e' || sub[i]=='i' || sub[i]=='o' || sub[i]=='u')
		{
			count=0;
			continue;
		}
		count++;
		if(count >= num) return true;
	}

	return false;
}

long countCons(string sub, long size)
{
	long count = 0;
	long maxi = 0;

	for(long i=0; i<size; i++)
	{
		if(sub[i]=='a' || sub[i]=='e' || sub[i]=='i' || sub[i]=='o' || sub[i]=='u')
		{
			count=0;
			continue;
		}
		count++;		
		if(maxi < count) maxi = count;
	}

	return maxi;
}

vector<long> precompute(string str)
{
	long count = 0;
	vector<long> v(str.size()+1);

	for(long size=1; size<=str.length(); size++)
	{
		v[size] 
	}
}

long findResult(string str, long num)
{
	long len = str.length();
	long count = 0;

	vector<long> v = precompute(str);

	for(long st=0; st<=len-num; st++){
		bool possible = false;
		for(long size=num; size<=len-st; size++){
			string sub = str.substr(st, size);

			if(consonant(sub, num)){
				count += (len-st - size + 1);
				possible = true;
				break;
			}
		}
		if(!possible) break;
	}

	return count;
}


int main()
{
	freopen("A-large.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	long input_count;
	cin >> input_count;

	long counter = 1;
	while(input_count)
	{
		string str;
		long num;

		cin >> str;
		cin >> num;
		long result = findResult(str, num);
		cout << "Case #" << counter++ << ": " << result << "\n";

		//finish work
		input_count--;
	}

	return 0;
}