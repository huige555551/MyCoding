#include<stdio.h>
#include<string.h>

char s[100];
char word[120000][100],pair[120000][100];
int n,m;

int search(char *t)
{
	int i,high,low,mid;

	high=n-1;
	low=0;

	while(low<=high)
	{
		mid=(low+high)/2;

		i=strcmp(t,word[mid]);

		if(i==0)
			break;
		else if(i<0)
			high=mid-1;
		else
			low=mid+1;
	}

	if(low>high)
			return 0;
	return 1;
}

void main()
{
	int i,j,k,p;

	freopen("in.txt","r",stdin);

	while(gets(s))
	{
		strcpy(word[n++],s);
	}

	for(i=0; i<n; i++)
	{
		for(j=i+1; (strncmp(word[i],word[j],strlen(word[i]))==0) && j<n ; j++)
		{
			if( search( word[j]+strlen(word[i]) ) )
			{
				//here i have to insert in a sorted way.i made mistake.took longtime
				for(k=m-1; k>=0 && (strcmp(word[j],pair[k])<0); k--)
				{
					
				}

				if(k<0 || strcmp(word[j],pair[k]))
				{
					for(p=m; p>k; p--)
						strcpy(pair[p+1],pair[p]);

					strcpy(pair[k+1],word[j]);
					m++;
				}
			}
		}
	}

	for(i=0; i<m; i++)
	{
		printf("%s\n",pair[i]);
	}
}