#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct football
{
	char name[40];
	int game_played;
	int win;
	int tie;
	int loss;
	int goal_scored;
	int goal_against;
	int point;
	int goal_difference;

}team[32];
int n;

int find_team(char *s)
{
	int i;

	for(i=0; i<n; i++)
	{
		if(strcmp(s,team[i].name)==0) return i;
	}

	return 0;
}

int str_cmp(char *s,char *t)
{
	int i,l1,l2;
	char t1[50],t2[50];

	l1=strlen(s);
	l2=strlen(t);

	i=0;
	while(i<l1)
	{
		t1[i]=tolower(s[i]);
		i++;
	}
	t1[i]=0;

	i=0;
	while(i<l2)
	{
		t2[i]=tolower(t[i]);
		i++;
	}
	t2[i]=0;

	return strcmp(t1,t2);
}

int compare_func(const void *a,const void *b)
{
	football *x=(football*)a;
	football *y=(football*)b;

	if(x->point>y->point) return -1;
	if(x->point<y->point) return 1;

	if(x->win>y->win) return -1;
	if(x->win<y->win) return 1;

	if(x->goal_difference>y->goal_difference) return -1;
	if(x->goal_difference<y->goal_difference) return 1;

	if(x->goal_scored>y->goal_scored) return -1;
	if(x->goal_scored<y->goal_scored) return 1;

	if(x->game_played<y->game_played) return -1;
	if(x->game_played>y->game_played) return 1;

	return str_cmp(x->name,y->name);
}

void main()
{
	int test,i,j,k,m,g1,g2,l,p1,p2;
	char s[150],t1[50],t2[50],t[50];

	//freopen("in.txt","r",stdin);

	for(i=0; i<32; i++)
	{
		team[i].game_played=0;
		team[i].goal_against=0;
		team[i].goal_difference=0;
		team[i].goal_scored=0;
		team[i].loss=0;
		team[i].win=0;
		team[i].tie=0;
		team[i].point=0;
		strcpy(team[i].name,"");
	}


	gets(s);
	test=atoi(s);

	while(test)
	{
		gets(s);
		printf("%s\n",s);

		gets(s);		
		n=atoi(s);//no of teams

		for(i=0; i<n; i++)
		{
			gets(s);
			strcpy(team[i].name,s);
		}

		gets(s);
		m=atoi(s);//no of matches

		for(i=0; i<m; i++)
		{
			gets(s);

			//parsing

			//team1
			j=0; k=0;
			while(s[j]!='#')
			{
				t1[k++]=s[j++];
			}
			t1[k]=0;

			//goals scored by team1
			j++;k=0;
			while(s[j]!='@')
			{
				t[k++]=s[j++];
			}
			t[k]=0;
			g1=atoi(t);
			
			//goals socored by team2
			j++;k=0;
			while(s[j]!='#')
			{
				t[k++]=s[j++];
			}
			t[k]=0;
			g2=atoi(t);

			//team2
			j++;k=0;l=strlen(s);
			while(j<l)
			{
				t2[k++]=s[j++];
			}
			t2[k]=0;
			//parsing finished

			p1=find_team(t1);
			p2=find_team(t2);

			team[p1].game_played++; team[p2].game_played++;

			if(g1>g2)
			{
				team[p1].win++;               team[p2].loss++;
				team[p1].goal_scored+=g1;     team[p2].goal_scored+=g2;
				team[p1].goal_against+=g2;    team[p2].goal_against+=g1;
				team[p1].point+=3;
			}
			else if(g1<g2)
			{
				team[p2].win++;               team[p1].loss++;
				team[p2].goal_scored+=g2;     team[p1].goal_scored+=g1;
				team[p2].goal_against+=g1;    team[p1].goal_against+=g2;
				team[p2].point+=3;
			}
			else
			{
				team[p1].tie++;               team[p2].tie++;
				team[p1].goal_scored+=g1;     team[p2].goal_scored+=g2;
				team[p1].goal_against+=g2;    team[p2].goal_against+=g1;
				team[p1].point++;             team[p2].point++; 
			}

		}

		for(i=0; i<n; i++)
		{
			team[i].goal_difference = team[i].goal_scored - team[i].goal_against;
		}

		//sorting

		qsort(team,n,sizeof(football),compare_func);

		for(i=0; i<n; i++)
		{
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,team[i].name,team[i].point,team[i].game_played,team[i].win,team[i].tie,team[i].loss,team[i].goal_difference,team[i].goal_scored,team[i].goal_against);			
		}

		for(i=0; i<n; i++)
		{
			team[i].game_played=0;
			team[i].goal_against=0;
			team[i].goal_difference=0;
			team[i].goal_scored=0;
			team[i].loss=0;
			team[i].win=0;
			team[i].tie=0;
			team[i].point=0;
			strcpy(team[i].name,"");

		}

		test--;

		if(test) printf("\n");
	}
}