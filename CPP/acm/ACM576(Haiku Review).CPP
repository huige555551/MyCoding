#include<stdio.h>
#include<string.h>

#define MAX 200

void main()
{
	char s[MAX],s1[MAX];
	int i,j,w;

	while(1)
	{
		gets(s);

		if(!strcmp(s,"e/o/i"))
			break;
		else
		{    /*get 1st line*/
			for(i=0; s[i]!='/'; i++)
				s1[i]=s[i];
			s1[i]='\0';
			/*count the syllables*/
			w=0;
			for(j=0; s1[j]; j++)
			{
				if((s1[j]=='a')||(s1[j]=='e')||(s1[j]=='i')||(s1[j]=='o')||(s1[j]=='u')||(s1[j]=='y'))
				{
					if((s1[j+1]!='a')&&(s1[j+1]!='e')&&(s1[j+1]!='i')&&(s1[j+1]!='o')&&(s1[j+1]!='u')&&(s1[j+1]!='y'))
						w++;
				}
			}
			/*if right*/
			if(w==5)
			{    /*get the 2nd line*/
				for(j=0,i++; s[i]!='/'; j++,i++)
					s1[j]=s[i];
				s1[j]=0;
				/*count the syllables*/
				w=0;
				for(j=0; s1[j]; j++)
				{
					if((s1[j]=='a')||(s1[j]=='e')||(s1[j]=='i')||(s1[j]=='o')||(s1[j]=='u')||(s1[j]=='y'))
					{
						if((s1[j+1]!='a')&&(s1[j+1]!='e')&&(s1[j+1]!='i')&&(s1[j+1]!='o')&&(s1[j+1]!='u')&&(s1[j+1]!='y'))
						w++;
					}
				}
				/*if right*/
				if(w==7)
				{    /*get the 3rd line*/
					for(j=0,i++; s[i]; j++,i++)
						s1[j]=s[i];
					s1[j]=0;
					/*count the syllables*/
					w=0;
					for(j=0; s1[j]; j++)
					{
						if((s1[j]=='a')||(s1[j]=='e')||(s1[j]=='i')||(s1[j]=='o')||(s1[j]=='u')||(s1[j]=='y'))
						{
							if((s1[j+1]!='a')&&(s1[j+1]!='e')&&(s1[j+1]!='i')&&(s1[j+1]!='o')&&(s1[j+1]!='u')&&(s1[j+1]!='y'))
							w++;
						}
					}
					/*if right*/
					if(w==5)
						printf("Y\n");
					else
						printf("3\n");

				}
				else
					printf("2\n");
			}
			else
				printf("1\n");
		}
	}
}