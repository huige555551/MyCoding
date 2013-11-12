#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int bean[26];
int share[26];

void main()
{
	int i,j,first=1,g,testcase,totalshare,guess;
	char b,s[1000],t[50],c,current;
	double k;

	//freopen("in.txt","r",stdin);

	gets(s);
	testcase=atoi(s);

	while(testcase)
	{
		//for blank line after testcase
		if(first)
		{
			gets(s);
			first=0;
		}
		//initialize with 0
		for(i=0; i<26; i++)
		{
			bean[i]=share[i]=0;
		}
		//read the bean no
		while((c=getchar())!='\n')
		{
			bean[c-'a']++;
		}
		//guess=TotNum total no of guesses by all contestants
		guess=0;
		//while s!=NULL
		while(gets(s))
		{
			//if blank line stop its for: between 2 consequitive input there
			//is a blank line
			if(strcmp(s,"")==0) break;

			//current is the alphabet: A B C D....
			current=s[0];
			//read the rest of the string
			for(i=2; i<strlen(s); i++)
			{
				if(s[i]>='a' && s[i]<='z')
				{
					//b is letter:: a b c...x y z
					b=s[i];
					//to get rid of :
					i++;i++;

					j=0;
					//read the num as string in t
					while(s[i]!=','&& s[i]!=0)
					{
						t[j++]=s[i++];
						t[j]=0;
					}
					//convert the num_string t to integer g(=guess made by contestant)
					g=atoi(t);
					//increase the total no of guesses
					guess++;
					//if it off-one increase by 1
					if(abs(g-bean[b-'a'])==1) share[current-'A']++;
					//if it is right increase by 2
					else if(g-bean[b-'a']==0) share[current-'A']+=2;
				}
			}
		}
		//calculate total no of share from all contestants
		totalshare=0;
		for(i=0; i<26; i++)
		{
			totalshare+=share[i];
		}
		//print the share of diff alphabet A B C...
		for(i=0; i<26; i++)
		{
			//if shrare>0
			if(share[i])
			{
				k=(guess*2.00*share[i])/totalshare;
				printf("%c %.2lf\n",i+65,k);
			}
		}

		printf("\n");

		testcase--;
	}
}