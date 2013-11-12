#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct problem
{
	int solved;
	int incorrect_sub;
};

struct contest
{
	int name;
	int submission;
	int solved_prob;
	int time;
	problem p[10];

}contestant[101];

int compare_func(const void *x,const void *y)
{
	contest *a=(contest*)x;
	contest *b=(contest*)y;

	if(a->solved_prob < b->solved_prob) return 1;
	if(a->solved_prob > b->solved_prob) return -1;

	if(a->time < b->time) return -1;
	if(a->time > b->time) return 1;

	if(a->name < b->name) return -1;
	else return 1;
}

void main()
{
	char s[300],ch;
	int i,j,test,n,prob,t;

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	gets(s);

	while(test)
	{
		//clear all input
		for(i=0; i<=100; i++)
		{
			contestant[i].name=contestant[i].submission=contestant[i].solved_prob=contestant[i].time=0;
			for(j=0; j<10; j++)
			{
				contestant[i].p[j].incorrect_sub=0;
				contestant[i].p[j].solved=0;
			}
		}

		while(gets(s))
		{
			if(strcmp(s,"")==0) break;

			sscanf(s,"%d %d %d %c",&n,&prob,&t,&ch);

			contestant[n].name=n;
			contestant[n].submission=1;
			if(ch=='C' && contestant[n].p[prob].solved==0)
			{ 
				contestant[n].solved_prob++;
				contestant[n].time+=(t+contestant[n].p[prob].incorrect_sub * 20);
				contestant[n].p[prob].solved=1;
				contestant[n].p[prob].incorrect_sub=0;
			}
			else if(ch=='I')
			{
				contestant[n].p[prob].incorrect_sub++;
			}
		}

		qsort(contestant,101,sizeof(contest),compare_func);

		for(i=0; i<101; i++)
		{
			if(contestant[i].submission)
			{
				printf("%d %d %d\n",contestant[i].name,contestant[i].solved_prob,contestant[i].time);
			}
		}
		test--;
		if(test) printf("\n");
	}
}