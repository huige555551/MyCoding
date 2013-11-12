#include<stdio.h>
#include<string.h>

typedef long long big;

big factorial(big n)
{
	big m=1;

	while(n)
	{
		m*=n;
		n--;
	}

	return m;
}

void main()
{
	char s[25];
	big i,j,l,n,n1,Case=1,r,t,n2;

	//freopen("i.txt","r",stdin);

	scanf("%lld",&n);

	while(n)
	{
		scanf("%s",s);
		
		l=strlen(s);
		n1=factorial(l);

		t=1;
		for(i=0; i<l; i++)
		{
			n2=1;
			if(s[i]!='#')
			{
				for(j=i+1; j<l; j++)
				{
					if(s[i]==s[j])
					{
						s[j]='#';
						n2++;
					}
				}
			}
			if(n2>1)
			{
				t=t*factorial(n2);
			}
		}

		r=n1/t;

		printf("Data set %lld: %lld\n",Case++,r);

		n--;
	}
}