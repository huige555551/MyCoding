#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char maze[80][80];
char s[80];

void main()
{
	int i,j,k,d,testcase,row,column,in_row,in_col,r,c,quit;
	char t[2][5];

	freopen("in.txt","r",stdin);

	//no of testcase
	gets(s);
	testcase=atoi(s);

	while(testcase)
	{
		//for reading blank line
		gets(s);
		//read row column line
		gets(s);
		//get the num from string
		k=0;
		for(i=0; i<strlen(s); i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while((s[i]>='0' && s[i]<='9'))
				{
					t[k][j]=s[i];
					j++; i++;
				}
				t[k][j]=0;
				k++;
			}
		}

		row=atoi(t[0]);
		column=atoi(t[1]);
		//read the maze
		for(i=0; i<row; i++)
		{
			gets(maze[i]);
		}
		//read initial row column line
		gets(s);
		//get the num from string
		k=0;
		for(i=0; i<strlen(s); i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while((s[i]>='0' && s[i]<='9'))
				{
					t[k][j]=s[i];
					j++; i++;
				}
				t[k][j]=0;
				k++;
			}
		}

		r=in_row=atoi(t[0])-1;
		c=in_col=atoi(t[1])-1;
		//d=direction 0=North,1=East,2=South,3=West
		d=quit=0;
		while(gets(s))
		{
			for(i=0; i<strlen(s); i++)
			{
				//rotate clockwise 90 degree
				if(s[i]=='R')
				{
					d=(d+1)%4;
				}
				//rotate counter-clockwise 90 degree
				else if(s[i]=='L')
				{
					d=(d+3)%4;
				}
				//move forward if possible
				else if(s[i]=='F')
				{
					if(d==0)
					{
						if(maze[r-1][c]!='*' && r-1>=0)
						{
							r--;
						}
					}
					else if(d==1)
					{
						if(maze[r][c+1]!='*' && c+1<column)
						{
							c++;
						}
					}
					else if(d==2)
					{
						if(maze[r+1][c]!='*' && r+1<row)
						{
							r++;
						}
					}
					else
					{
						if(maze[r][c-1]!='*' && c-1>=0)
						{
							c--;
						}
					}
				}
				//if Q quit
				else if(s[i]=='Q')
				{
					quit=1;
					break;
				}
				//if spaces then do nothing
				else
				{

				}
			}
			if(quit==1) break;
		}
		//print final row column
		printf("%d %d ",r+1,c+1);
		//print direction
		if(d==0) printf("N");
		else if(d==1) printf("E");
		else if(d==2) printf("S");
		else printf("W");

		printf("\n\n");

		testcase--;
	}

}