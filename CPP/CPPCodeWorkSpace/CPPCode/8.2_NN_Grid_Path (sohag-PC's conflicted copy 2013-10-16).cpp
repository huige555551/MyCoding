#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> path;

int count=0;
void getPaths(int x, int y, int N){
	
	if(x==N-1 && y==N-1){
		count++;
		cout << count << ": ";
		for(int i=0; i<path.size(); i++) cout << path[i] << "-->";
		cout << endl;			
		return;
	}

	if(x<N-1){
		path.push_back("right");		
		getPaths(x+1, y, N);
		path.pop_back();
	}
	if(y<N-1){
		path.push_back("down");
		getPaths(x, y+1, N);		
		path.pop_back();
	}
	
	return;
}

void main()
{
	getPaths(0,0,2);
	count=0; cout<< endl;
	getPaths(0,0,3);
	count=0;cout<< endl;
	getPaths(0,0,4);
	count=0;cout<< endl;
	getPaths(0,0,5);
}