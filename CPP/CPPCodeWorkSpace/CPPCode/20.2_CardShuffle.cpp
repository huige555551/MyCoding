#include<iostream>
#include<vector>
#include<cstdlib>
#include<map>
#include<ctime>
#include<algorithm>
using namespace std;

vector<int> card(52);
map<int, int> rnum;

//[m,n)
int rand_num(int m, int n){ 
	//return m+rand()%(n-m); //uses only lower bits
	return m + rand() / ((RAND_MAX/(n-m)) + 1);	//it uses a range for a particular random number //uses upper bits
	//return (rand()/(RAND_MAX+1.0)) * (n-m) + m;
}

void card_shuffle()
{
	for(int i=0; i<card.size(); i++) card[i]=i;
	random_shuffle(card.begin(), card.end());
	for(int i=0; i<card.size(); i++) cout << card[i] << " ";
	cout << endl;

	for(int i=0; i<52; i++){
		int random = rand_num(i,52);
		int t=card[random];
		card[random]=card[i];
		card[i]=t;
	}
	for(int i=0; i<card.size(); i++) cout << card[i] << " ";
	cout << endl;
}

void main()
{
	srand(time(NULL));	
	
	for(int i=0; i<=20; i++) {
		int a = rand_num(1,20);
		cout << a << endl;
		rnum[a] += 1;
	}

	for(auto i=rnum.begin(); i!=rnum.end(); i++){
		cout << i->first << "->" <<  i->second << endl;
	}
	cout<< endl << endl;
	for(int i=0; i<=20; i++){
		cout << i << "->" << rnum[i] << endl;
	}

	card_shuffle();
}