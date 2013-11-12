#include <stdio.h>
#include <string.h>

char s[2000002];
//char s[2000];

void main()
{
	int i,j,k,m,n;

	//freopen("in.txt","r",stdin);

	while (gets(s) && strcmp(s,"."))
	{
		m = n = strlen(s);

		for (i=2;i<=n;i++)
		{
			while (n%i == 0)
			{
				n /= i;

				//for (j=0; j<m-m/i && s[j] == s[j+m/i]; j++);

				for (j=0; j<m-m/i; j++)
				{
					if(s[j]!=s[j+m/i])	break;
				}

				if (j == m-m/i) m /= i;
			}
		}
		printf("%d\n",strlen(s)/m);
	}
}