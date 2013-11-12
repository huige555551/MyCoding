#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX 102
//#define a 2.0*acos(0.0)/180.0
#define INF 2147483647

char city[MAX][50];
long double latitude[MAX],longitude[MAX];
long double path[MAX][MAX];

long n,m,q;

long double find_distance(long i,long j)
{
	long double t,u,r;

	double a =2.0*acos(0.0)/180.0;
	
	t=sin(latitude[i]*a)*sin(latitude[j]*a);
	u=cos(latitude[i]*a)*cos(latitude[j]*a)*cos(longitude[i]*a-longitude[j]*a);

	r=(acos(t+u))*6378.0;

	return r;
}

long min(long double i,long double j)
{
	if(i<j) return i;
	return j;
}

void floyd_warshall()
{
	int i,j,k;

	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				path[i][j]=min( path[i][j]+0.5, path[i][k]+path[k][j]+0.5 );//round here
			}
		}
	}
}

void main()
{
	long test=1,i,j,index1,index2,first=1;
	char s1[50],s2[50];

	freopen("in.txt","r",stdin);

	while(scanf("%ld %ld %ld",&n,&m,&q)==3)
	{
		if(n==0 && m==0 && q==0) break;

		if(first==0) printf("\n");first=0;

		for(i=1; i<=n; i++)
		{
			scanf("%s %Lf %Lf",city[i],&latitude[i],&longitude[i]);
		}

		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				path[i][j]=INF;
			}
		}

		for(i=1; i<=m; i++)
		{
			scanf("%s %s",s1,s2);

			index1=index2=0;

			for(j=1; j<=n; j++)
			{
				if(index1==0 || index2==0)
				{
					if(strcmp(s1,city[j])==0)	index1=j;
					else if(strcmp(s2,city[j])==0)  index2=j;
				}
			}

			if(index1!=index2 && index1!=0 && index2!=0)
			{
				path[index1][index2]=find_distance(index1,index2);
			}

		}
		floyd_warshall();

		printf("Case #%ld\n",test++);

		for(i=1; i<=q; i++)
		{
			scanf("%s %s",s1,s2);

			index1=index2=0;

			for(j=1; j<=n; j++)
			{
				if(index1==0 || index2==0)
				{
					if(strcmp(s1,city[j])==0)	index1=j;
					else if(strcmp(s2,city[j])==0)  index2=j;
				}
			}

			if(index1!=index2 && index1!=0 && index2!=0)
			{
				if(path[index1][index2]!=INF)
					printf("%ld km\n",long(path[index1][index2]+0.5));
				else printf("no route exists\n");
			}
			else printf("no route exists\n");
		}
	}
}