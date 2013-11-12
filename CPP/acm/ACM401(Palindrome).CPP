#include<stdio.h>
#include<string.h>

#define MAX 100

int palindrome(char str1[]);
int mirroredstring(char str1[]);
void str_rev(char p[]);

char ch1[21]={'A', 'E', 'H', 'I', 'J', 'L', 'O', 'M', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '5', '8' };
char ch2[21]={'A', '3', 'H', 'I', 'L', 'J', 'O', 'M', '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5', '1', 'S', 'E', 'Z', '8' };

void main()
{
	char str[MAX],s[MAX];
	int pal,mirror;
	while(gets(str)!=NULL)
	{
		strcpy(s,str);
		pal=palindrome(str);
		mirror=mirroredstring(str);

		printf("%s",s);
		if(pal==0 && mirror==0) printf(" -- is not a palindrome.");
		if(pal==1 && mirror==0) printf(" -- is a regular palindrome.");
		if(pal==0 && mirror==1) printf(" -- is a mirrored string.");
		if(pal==1 && mirror==1) printf(" -- is a mirrored palindrome.");
		printf("\n\n");
	}

}

int palindrome(char str1[])
{
	char str2[MAX];
	strcpy(str2,str1);

	str_rev(str2);

	if(strcmp(str1,str2)==0) return 1;
	else return 0;
}

int mirroredstring(char str1[])
{
	int i,j;
	char str2[MAX];

	strcpy(str2,str1);
	str_rev(str2);

	for(i=0; i<strlen(str1); i++)
	{
		for(j=0; j<21; j++)
		{
			if(str1[i]==ch1[j])
			{
				str1[i]=ch2[j];
				break;
			}
		}
		if(j==21) return 0;
	}

	if(strcmp(str1,str2)==0) return 1;
	else return 0;

}

void str_rev(char p[])
{
	char s[MAX]={0};
	long i,j;

	i=strlen(p)-1;
	for(j=0; i>=0; j++,i--)s[j]=p[i];
	s[j]=0;

	for(i=0; p[i]; i++)p[i]=s[i];
}