#include<stdio.h>
#include<string.h>

char word[83684][7];

void main()
{
	long long i,j,k,l,m,check,n;
	char s[7];

	n=0;

	for(i=0; i<26; i++)
	{
		word[n++][0]='a'+i;
	}

	for(i=0; i<25; i++)
	{
		for(j=i+1; j<26; j++)
		{
			word[n][0]='a'+i;
			word[n][1]='a'+j;
			n++;
		}
	}

	for(i=0; i<24; i++)
	{
		for(j=i+1; j<25; j++)
		{
			for(k=j+1; k<26; k++)
			{
				word[n][0]='a'+i;
				word[n][1]='a'+j;
				word[n][2]='a'+k;
				n++;
			}
		}
	}

	for(i=0; i<23; i++)
	{
		for(j=i+1; j<24; j++)
		{
			for(k=j+1; k<25; k++)
			{
				for(l=k+1; l<26; l++)
				{
					word[n][0]='a'+i;
					word[n][1]='a'+j;
					word[n][2]='a'+k;
                                        word[n][3]='a'+l;
					n++;
				}
			}
		}
	}

	for(i=0; i<22; i++)
	{
		for(j=i+1; j<23; j++)
		{
			for(k=j+1; k<24; k++)
			{
				for(l=k+1; l<25; l++)
				{
					for(m=l+1; m<26; m++)
					{
						word[n][0]='a'+i;
						word[n][1]='a'+j;
						word[n][2]='a'+k;
                                                word[n][3]='a'+l;
                                                word[n][4]='a'+m;    
						n++;
					}
				}
			}
		}
	}

	while(scanf("%s",s)!=EOF)
	{
		check=0;

		for(i=0; i<=n-1; i++)
		{
			if(!strcmp(s,word[i]))
			{
				printf("%lld\n",i+1);
				check=1;
				break;
			}
		}
		if(!check)
			printf("0\n");
	}
}