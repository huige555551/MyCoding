#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 4

int backtrack=0;
vector<int> a(MAX+1,0);

void printSolution()
{
	for(int r=1; r<=MAX; r++) 
	{
		for(int c=1; c<=MAX; c++){
			if(a[c]==r) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
	cout << endl;
}


bool isConsistent(int n)
{
	for(int c=1; c<n; c++){
		if(a[c]==a[n]) return false;
		if(abs(c-n)==abs(a[c]-a[n])) return false;
	}
	return true;
}

bool eightQueen(int n){
	
	if(n>MAX) {
		printSolution();
		return true;
	}

	for(int i=1; i<=MAX; i++){
		//a.push_back(i);
		a[n]=i;
		if(isConsistent(n)){
			bool t = eightQueen(n+1);
			if(t) return true;			
			else backtrack++;
		}
		//a.pop_back();
	}
	return false;
}

struct state{
	int x;
	int pos;
	int color;
};


bool isConsistent(int n, int pos)
{
	for(int c=1; c<n; c++)
	{
		if(a[c]==pos) return false;
		if(abs(c-n)==abs(a[c]-pos)) return false;
	}
	return true;
}

void iterative_eightQueen(int n)
{
	for(int r=1; r<=MAX; r++) a[r] = 0;	

	stack<state> st;
	for(int i=1; i<=MAX; i++){
		state s0 = {1, i, 0};
		st.push(s0);
		//cout << s0.x << s0.pos << s0.color << endl;
	}

	while(!st.empty())
	{
		//pop one state from stack
		state t = st.top(); st.pop();
		
		//if state is not visited yet
		if(t.color==0)
		{ 
			//mark the state as visited
			//push it in stack as visited
			state temp = t;
			temp.color=1;
			st.push(temp);
			a[t.x] = t.pos;

			if(t.x < MAX)
			{
				for(int i=1; i<=MAX; i++)
				{	
					state s1 = {t.x + 1, i, 0};
					if(isConsistent(s1.x, s1.pos))
						st.push(s1);
				}
			}
		}

		else if(t.color==1)
		{
			if(t.x==MAX)
			{
				printSolution();
				//break;
			}			
			a[t.x] = 0;			
		}		
	}

}

void main()
{
	//a.push_back(0);	
	eightQueen(1);
	cout << backtrack << endl;

	iterative_eightQueen(MAX);
}