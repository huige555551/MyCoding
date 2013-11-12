#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char E[100],P[100];

int PREC(char ch)
{
	if(ch=='+' || ch=='-') return 3;
	else if(ch=='*' || ch=='/') return 4;
	else if(ch=='(') return 2;
	else if(ch=='$') return 1;
	else return 0;
}

void main()
{
	int i,j,top,test,x;
	char s[30],stack[50];

	//freopen("in.txt","r",stdin);

	gets(s);
	test=atoi(s);

	gets(s);
	while(test)
	{
		strcpy(stack,"");	strcpy(E,""); strcpy(P,"");

		while(gets(s))
		{
			if(strcmp(s,"")==0) break;
			strncat(E,s,1);
		}
		strcat(E,"$");

		i=j=-1;
		stack[0]='#';
		top=0;
		while(stack[top]!='$')
		{
			i++;
			//if E[i] operand:
			if(E[i]>='0' && E[i]<='9')
			{
				j++;
				P[j]=E[i];
			}
			//if E[i]=='(':
			else if(E[i]=='(')
			{
				stack[++top]=E[i];
			}
			//if E[i]==')':
			else if(E[i]==')')
			{
				x=stack[top];
				top--;
				while(x!='(')
				{
					j++;
					P[j]=x;
					x=stack[top];
					top--;

				}
			}
			//if E[i] operand
			else
			{
				while(PREC(E[i])<=PREC(stack[top]) && top>0)
				{
					j++;
					P[j]=stack[top];
					top--;
				}
				stack[++top]=E[i];
			}
		}
		P[j+1]=0;
		printf("%s\n\n",P);
		test--;
	}
}