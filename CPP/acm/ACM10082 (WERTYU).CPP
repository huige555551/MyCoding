#include<stdio.h>

void main()
{
	char c;

	while((c=getchar())!=EOF )
	{
		if(c=='=')
			putchar('-');

		else if(c=='-')
			putchar('0');

		else if(c=='0')
			putchar('9');

		else if(c=='9')
			putchar('8');

		else if(c=='8')
			putchar('7');

		else if(c=='7')
			putchar('6');

		else if(c=='6')
			putchar('5');

		else if(c=='5')
			putchar('4');

		else if(c=='4')
			putchar('3');

		else if(c=='3')
			putchar('2');

		else if(c=='2')
			putchar('1');

		else if(c=='1')
			putchar('`');
/*********************************************/
		else if(c==92)
			putchar(']');

		else if(c==']')
			putchar('[');

		else if(c=='[')
			putchar('P');

		else if(c=='P')
			putchar('O');

		else if(c=='O')
			putchar('I');

		else if(c=='I')
			putchar('U');

		else if(c=='U')
			putchar('Y');

		else if(c=='Y')
			putchar('T');

		else if(c=='T')
			putchar('R');

		else if(c=='R')
			putchar('E');

		else if(c=='E')
			putchar('W');

		else if(c=='W')
			putchar('Q');
/********************************************/
		else if(c==39)
			putchar(';');

		else if(c==';')
			putchar('L');

		else if(c=='L')
			putchar('K');

		else if(c=='K')
			putchar('J');

		else if(c=='J')
			putchar('H');

		else if(c=='H')
			putchar('G');

		else if(c=='G')
			putchar('F');

		else if(c=='F')
			putchar('D');

		else if(c=='D')
			putchar('S');

		else if(c=='S')
			putchar('A');
/*******************************************/
		else if(c=='/')
			putchar('.');

		else if(c=='.')
			putchar(',');

		else if(c==',')
			putchar('M');

		else if(c=='M')
			putchar('N');

		else if(c=='N')
			putchar('B');

		else if(c=='B')
			putchar('V');

		else if(c=='V')
			putchar('C');

		else if(c=='C')
			putchar('X');

		else if(c=='X')
			putchar('Z');
/*********************************************/
		else
			putchar(c);
	}
}