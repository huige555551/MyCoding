
#include <iostream> 
using namespace std; 

int turn (int a,int b,int d) 
{ 
	if (d) 
	{ // clockwise 
		if (b>a) return (b-a); 
		else return (40-a+b); 
	} 
	else 
	{ 
		if (a>b) return (a-b); 
		else return (40-b+a); 
	} 
} 

int main() 
{ 
	int a,b,c,d,s; 

	freopen("in.txt","r",stdin);
	
	while (cin >>a>>b>>c>>d) 
	{ 
		if (!a&&!b&&!c&&!d) break; 
		
		s = 120; 
		s+=turn(a,b,0); // why here is counter-clockwise ?! 
		s+=turn(b,c,1); 
		s+=turn(c,d,0); 
		
		cout << s*9 << endl; 
	} 
	return 0; 
} 

//here clockwise means counter clockwise
//and counter clockwise means clockwise
//why dont know>strange!
