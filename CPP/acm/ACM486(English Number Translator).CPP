#include<stdio.h>
#include<string.h>

char word[100][100];
int j;

char m[31][10]={"zero","one","two","three","four","five",
				"six","seven","eight","nine","ten",
				"eleven","twelve","thirteen","fourteen","fifteen",
				"sixteen","seventeen","eighteen","nineteen","twenty",
				"thirty","forty","fifty","sixty","seventy","eighty",
				"ninety","hundred","thousand","million"};
long n[31]={0, 1, 2, 3, 4, 5,
		   6, 7, 8, 9, 10,
		   11, 12, 13, 14, 15,
		   16, 17, 18, 19, 20,
		   30, 40, 50, 60, 70, 80,
		   90, 100, 1000, 1000000};

void get_word(char *s)
{
	int i,k;

	for(i=0,j=0; i<strlen(s); i++)
	{
		if( (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') )
		{
			for(k=0; (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'); i++,k++)
			{
				word[j][k]=s[i];
			}
			word[j][k]=0;
			i--;
			j++;
		}
	}
}


void main()
{
	int i,k,million,thousand;
	char s[100];
	long num,num1,num2,num3;

	/*freopen("in.txt","r",stdin);*/

	while(gets(s)!=NULL)
	{
		get_word(s);

		i=0;
		if(strcmp(word[0],"negative")==0)
		{
			printf("-");
			i=1;
		}

		num=num1=num2=num3=million=thousand=0;

		for(k=0; k<j; k++)
		{
			if(strcmp(word[k],"million")==0) million=1;
			else if(strcmp(word[k],"thousand")==0) thousand=1;
		}

		if(million)
		{
			for(i; i<j; i++)
			{
				for(k=0; k<31; k++)
				{
					if(strcmp(word[i],m[k])==0) break;
				}

				if(k>=0&&k<=27) num1+=n[k];
				else if(k>=28&&k<=30)
				{
					num1*=n[k];
					if(k==30){i++;break;}
				}
			}
		}

		if(thousand)
		{
			for(i; i<j; i++)
			{
				for(k=0; k<31; k++)
				{
					if(strcmp(word[i],m[k])==0) break;
				}

				if(k>=0&&k<=27) num2+=n[k];
				else if(k>=28&&k<=30)
				{
					num2*=n[k];
					if(k==29){i++;break;}
				}
			}
		}

		for(i; i<j; i++)
		{
			for(k=0; k<31; k++)
			{
				if(strcmp(word[i],m[k])==0) break;
			}

			if(k>=0&&k<=27) num3+=n[k];
			else if(k>=28&&k<=30)
			{
				num3*=n[k];
			}
		}

		num=num1+num2+num3;

		printf("%ld\n",num);
	}
}
