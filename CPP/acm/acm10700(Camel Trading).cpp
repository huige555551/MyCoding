#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[100];
long long a[100],index;

void main()
{
	int i,j,test,length,num;
	long long max,min;
	char t[100];

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	while(test)
	{
		for(i=0; i<=50; i++) a[i]=0;

		gets(s);
		length=strlen(s);

		//maximum
		index=0;
		for(i=0; i<length; i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while(s[i]>='0' && s[i]<='9')
				{
					t[j++]=s[i++];
				}
				t[j]=0;
				i--;

				num=atoi(t);
				a[index]+=num;
			}
			else if(s[i]=='*')
				index++;
			else ;
		}

		max=1;
		for(i=0; i<=index; i++)
			max*=a[i];

		//printf("%ld ",max);

		for(i=0; i<=50; i++) a[i]=1;

		//minimum.........................................
		index=0;
		for(i=0; i<length; i++)
		{
			if(s[i]>='0' && s[i]<='9')
			{
				j=0;
				while(s[i]>='0' && s[i]<='9')
				{
					t[j++]=s[i++];
				}
				t[j]=0;
				i--;

				num=atoi(t);
				a[index]*=num;
			}
			else if(s[i]=='+')
				index++;
			else ;
		}

		min=0;
		for(i=0; i<=index; i++)
			min+=a[i];

		//printf("%ld\n",min);
		printf("The maximum and minimum are %lld and %lld.\n",max,min);

		test--;
	}
}