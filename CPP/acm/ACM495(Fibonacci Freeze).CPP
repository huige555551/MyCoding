#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5000

char store[MAX][MAX];

void str_rev(char p[MAX])
{
	char s[MAX]={0};
	long i,j;

	i=strlen(p)-1;
	for(j=0; i>=0; j++,i--)s[j]=p[i];
	s[j]=0;

	for(i=0; p[i]; i++)p[i]=s[i];
}

char* sum(char l[MAX],char f[MAX])
{
	int l1,l2,a,b,c,i,sum;
	char answer[MAX]={0},s1[MAX]={0},s2[MAX]={0};

	strcpy(s1,l);
	strcpy(s2,f);

	str_rev(s1);
	str_rev(s2);

	l1=strlen(s1);
	l2=strlen(s2);

	if(l1 > l2){
		a=l1-l2;
		for(b=1; b<=a; b++,l2++)s2[l2]='0';
	}
	if(l1 < l2){
		a=l2-l1;
		for(b=1; b<=a; b++,l1++)s1[l1]='0';
	}

	c=0;
	for(i=0; s1[i]; i++){
		sum=s1[i]+s2[i]-96+c;
		if(sum>9){
			sum=sum-10;
			c=1;
		}
		else c=0;
		answer[i]=sum+48;
	}
	if(c==0)answer[i]=0;
	else{
		answer[i]=c+48;
		answer[i+1]=0;
	}

	str_rev(answer);

	return answer;
}

void fibo()
{
	char l[MAX]="1",f[MAX]="1",ans[MAX];
	int i;
	for(i=0; i<=MAX; i++)
	{
		if(i==0)strcpy(ans,"0");
		else if(i==1||i==2)strcpy(ans,"1");
		else
		{
			strcpy(ans,sum(l,f));
			strcpy(f,l);
			strcpy(l,ans);
		}
		strcpy(store[i],ans);
	}
}

void main()
{
	int n;

	fibo();

	while(scanf("%d",&n)!=EOF)
	{
		printf("The Fibonacci number for %d is %s\n",n,store[n]);
	}
}




