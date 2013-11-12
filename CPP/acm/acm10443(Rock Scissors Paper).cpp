#include<stdio.h>
#include<string.h>
#include<iostream.h>

#define MAX 200

char s[MAX][MAX],t[MAX][MAX];

void main()
{
	int i,j,k,test,r,c,d,x,y;

	//freopen("in.txt","r",stdin);

	//scanf("%d",&test);
	cin>>test;

	while(test)
	{
		//scanf("%d %d %d",&r,&c,&d);
		cin>>r>>c>>d;

		for(i=0; i<r; i++)
		{
			cin>>s[i];
			strcpy(t[i],s[i]);
		}

		for(k=1; k<=d; k++)
		{
			for(i=0; i<r; i++)
			{
				for(j=0; j<c; j++)
				{
					if(s[i][j]=='R')
					{
						if(i-1>=0)
						{
							if(s[i-1][j]=='P')
								t[i][j]='P';
						}
						if(i+1<r)
						{
							if(s[i+1][j]=='P')
								t[i][j]='P';
						}
						if(j-1>=0)
						{
							if(s[i][j-1]=='P')
								t[i][j]='P';
						}
						if(j+1<c)
						{
							if(s[i][j+1]=='P')
								t[i][j]='P';
						}
					}	
					else if(s[i][j]=='S')
					{
						if(i-1>=0)
						{
							if(s[i-1][j]=='R')
								t[i][j]='R';
						}
						if(i+1<r)
						{
							if(s[i+1][j]=='R')
								t[i][j]='R';
						}
						if(j-1>=0)
						{
							if(s[i][j-1]=='R')
								t[i][j]='R';
						}
						if(j+1<c)
						{
							if(s[i][j+1]=='R')
								t[i][j]='R';
						}				
					}
					else//if(s[i][j]=='P')
					{
						if(i-1>=0)
						{
							if(s[i-1][j]=='S')
								t[i][j]='S';
						}
						if(i+1<r)
						{
							if(s[i+1][j]=='S')
								t[i][j]='S';
						}
						if(j-1>=0)
						{
							if(s[i][j-1]=='S')
								t[i][j]='S';
						}
						if(j+1<c)
						{
							if(s[i][j+1]=='S')
								t[i][j]='S';
						}				
					}
				}
			}
			//s==t
			for(x=0; x<r; x++)
			{
				for(y=0; y<c; y++)
				{
					s[x][y]=t[x][y];
				}
			}
		}

		for(x=0; x<r; x++)
		{
			cout<<s[x]<<'\n';
		}

		test--;
		if(test)cout<<'\n';
	}
}