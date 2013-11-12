#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	int i,j,filp,k,f,t,n;
	char s[100],c[10];
	int a[100],b[100];

	freopen("in.txt","r",stdin);

	while(gets(s))
	{
		printf("%s\n",s);
		for(i=n=0; i<strlen(s); i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while((s[i]>='0' && s[i]<='9'))
				{
					c[j]=s[i];
					c[j+1]=0;
					j++;
					i++;
				}
				a[n]=b[n++]=atoi(c);
			}
		}

		for(i=0,j=n-1; i<n/2; j--,i++)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}

		for(i=1; i<n; i++)
		{
			for(j=n-1; j>=i; j--)
			{
				if(b[j]>b[j-1])
				{
					t=b[j];
					b[j]=b[j-1];
					b[j-1]=t;
				}
			}
		}

		for(f=0; f<n; f++)
		{
			if(a[f]!=b[f])
			{
				for(j=f+1; j<n; j++)
				{
					if(a[j]==b[f]) break;
				}

				if(j+1!=n)
					printf("%d ",j+1);

				//m=a[j];

				for(i=n-1,k=j; i>(j+n-1)/2; k++,i--)
				{
					t=a[i];
					a[i]=a[k];
					a[k]=t;
				}

				//a[n-1]=m;

				for(i=n-1,j=f; i>(f+n-1)/2; j++,i--)
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}

				//a[f]=m;

				printf("%d ",f+1);
			}
		}
		printf("0");
		printf("\n");
	}
}