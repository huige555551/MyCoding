#include <iostream>
#include <vector>
using namespace std;

//using vectors
vector<char> v;
void parentheses(int x, int y, int n){

	if(x==n && y==n){
		for(int i=0; i<v.size(); i++)	cout << v[i]; cout << endl;
		return;
	}
	if(x<n){
		v.push_back('(');
		parentheses(x+1,y,n);
		v.pop_back();
	}
	if(y<n && y<x){
		v.push_back(')');
		parentheses(x,y+1,n);
		v.pop_back();
	}

}

//using arrays
void printParentheses(int x, int y, int count, char str[])
{
	if(x==0 && y==0){		
		for(int i=0; i<count; i++) cout << str[i]; cout << endl;
	}
	if(x > 0){
		str[count] = '(';
		printParentheses(x-1, y, count+1, str);
	}
	if(y > 0 && y > x){
		str[count] = ')';
		printParentheses(x, y-1, count+1, str);
	}
}

void main(){
	
	parentheses(0,0,3);

	cout << endl;
	char str[3*2];
	printParentheses(3, 3, 0, str);
}