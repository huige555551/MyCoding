#include<stdio.h>
#include<iostream.h>
#include<string.h>

#define MAX 20

char s[MAX][MAX];

void main()
{
	int test,m,n,c,r,i;

	//freopen("in.txt","r",stdin);

	cin>>test;

	while(test)
	{
		cin>>m>>n;
		
		for(i=0; i<m; i++)
			cin>>s[i];

		for(i=0; i<n; i++) 
			if(s[m-1][i]=='@') break;

		c=i;r=m-1;
		if(s[r][c+1]=='I') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='I') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='E') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='E') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='H') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='H') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='O') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='O') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='V') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='V') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='A') { printf("right "); c=c+1;}
		else if(s[r][c-1]=='A') { printf("left "); c=c-1;}
		else{ printf("forth "); r=r-1;}

		if(s[r][c+1]=='#') { printf("right"); c=c+1;}
		else if(s[r][c-1]=='#') { printf("left"); c=c-1;}
		else{ printf("forth"); r=r-1;}

		printf("\n");

		test--;
	}
}