#include<stdio.h>
#include<string.h>

#define MAX 200
#define NO_CHANGE 0
#define CHANGE 1
#define DELET 2
#define INSERT 3

int m[MAX][MAX];
int x[MAX][MAX];
char s1[MAX],s2[MAX];

void edit_distance(char *s1,char *s2)
{
	int i,j,val,change,insert,delet;
	int	length_s1=strlen(s1),length_s2=strlen(s2);
	
	m[0][0]=0;
	x[0][0]=0;

	for(i=1; i<=length_s1; i++)
	{
		m[i][0]=i;
		x[i][0]=DELET;
	}
	for(j=1; j<=length_s2; j++)
	{
		m[0][j]=j;
		x[0][j]=INSERT;
	}

	for(i=1; i<=length_s1; i++)
	{
		for(j=1; j<=length_s2; j++)
		{
			val = ( s1[i-1] == s2[j-1] ) ? 0 : 1;

			change = m[i-1][j-1]+val;
			delet = m[i-1][j]+1;
			insert = m[i][j-1]+1;
		
					
			if(insert<=delet && insert<=change)
			{
				m[i][j]=insert;
				x[i][j]=INSERT;
			}
			else if(delet<=insert && delet<=change)
			{
				m[i][j]=delet;
				x[i][j]=DELET;
			}		
			else
			{
				m[i][j]=change;
				if(val==1) x[i][j]=CHANGE;
				else x[i][j]=NO_CHANGE;				
			}
		}
	}

	//cout<<m[length_s1][length_s2]<<endl;
}

void print_edit(int i,int j)
{
	if(i==0 && j==0) return;

	if(x[i][j]==NO_CHANGE)
	{
		print_edit(i-1,j-1);
		//printf("no change\n");
	}
	else if(x[i][j]==CHANGE)
	{
		print_edit(i-1,j-1);
		//printf("change\n");
		printf("C%c",s2[j-1]);
		if(j<10) printf("0%d",j);
		else printf("%d",j);
	}
	else if(x[i][j]==DELET)
	{
		print_edit(i-1,j);
		//printf("delete\n");
		printf("D%c",s1[i-1]);
		if(j+1<10) printf("0%d",j+1);
		else printf("%d",j+1);
	}
	else//INSERT
	{
		print_edit(i,j-1);
		//printf("insert\n");
		printf("I%c",s2[j-1]);
		if(j<10) printf("0%d",j);
		else printf("%d",j);
	}	
}

void main()
{
	char s[400];
	
	//freopen("in.txt","r",stdin);

	while(gets(s))
	{
		if(strcmp(s,"#")==0)
		{ 
			break;
		}
		
		strcpy(s1,"");
		strcpy(s2,"");

		sscanf(s,"%s %s",s1,s2);

		edit_distance(s1,s2);

		print_edit(strlen(s1),strlen(s2));
		printf("E\n");
	}
}