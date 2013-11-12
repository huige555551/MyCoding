#include<stdio.h>

void main()
{
	char c;

	while((c=getchar())!=EOF )
	{
		if(c==92)
			putchar('-');

		else if(c=='=')
			putchar('0');

		else if(c=='-')
			putchar('9');

		else if(c=='0')
			putchar('8');

		else if(c=='9')
			putchar('7');

		else if(c=='8')
			putchar('6');

		else if(c=='7')
			putchar('5');

		else if(c=='6')
			putchar('4');

		else if(c=='5')
			putchar('3');

		else if(c=='4')
			putchar('2');

		else if(c=='3')
			putchar('1');
	  /*
		else if(c=='2')
			putchar('1');

		else if(c=='1')
			putchar('`');
/*********************************************/
		else if((c==']')||(c=='}'))
			putchar('p');

		else if((c=='[')||(c=='{'))
			putchar('o');

		else if((c=='p')||(c=='P'))
			putchar('i');

		else if((c=='o')||(c=='O'))
			putchar('u');

		else if((c=='i')||(c=='I'))
			putchar('y');

		else if((c=='u')||(c=='U'))
			putchar('t');

		else if((c=='y')||(c=='Y'))
			putchar('r');

		else if((c=='t')||(c=='T'))
			putchar('e');

		else if((c=='r')||(c=='R'))
			putchar('w');

		else if((c=='e')||(c=='E'))
			putchar('q');
	  /*
		else if(c=='W')
			putchar('Q');
/********************************************/
		else if((c==39)||(c=='"'))
			putchar('l');

		else if((c==';')||(c==':'))
			putchar('k');

		else if((c=='l')||(c=='L'))
			putchar('j');

		else if((c=='k')||(c=='K'))
			putchar('h');

		else if((c=='j')||(c=='J'))
			putchar('g');

		else if((c=='h')||(c=='H'))
			putchar('f');

		else if((c=='g')||(c=='G'))
			putchar('d');

		else if((c=='f')||(c=='F'))
			putchar('s');

		else if((c=='d')||(c=='D'))
			putchar('a');
	 /*
		else if(c=='s')
			putchar('A');
/*******************************************/
		else if((c=='/')||(c=='?'))
			putchar(',');

		else if((c=='.')||(c=='>'))
			putchar('m');

		else if((c==',')||(c=='<'))
			putchar('n');

		else if((c=='m')||(c=='M'))
			putchar('b');

		else if((c=='n')||(c=='N'))
			putchar('v');

		else if((c=='b')||(c=='B'))
			putchar('c');

		else if((c=='v')||(c=='V'))
			putchar('x');

		else if((c=='c')||(c=='C'))
			putchar('z');
	    /*
		else if(c=='X')
			putchar('Z');
/*********************************************/
		else
			putchar(c);
	}
}