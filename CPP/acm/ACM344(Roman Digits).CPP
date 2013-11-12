#include<stdio.h>

#define MAX 101

int i[MAX],v[MAX],x[MAX],l[MAX],c[MAX];

void main()
{
	int ni,nv,nx,nl,nc;
	int j,n,d,t;

	for(j=1; j<=100; j++)
	{
		d=j%10;
		t=j/10;

		ni=nv=nx=nl=nc=0;

		if(d==0);
		else if(d==1) ni+=1;
		else if(d==2) ni+=2;
		else if(d==3) ni+=3;
		else if(d==4) { ni+=1; nv+=1;}
		else if(d==5) nv+=1;
		else if(d==6) { ni+=1; nv+=1;}
		else if(d==7) { ni+=2; nv+=1;}
		else if(d==8) { ni+=3; nv+=1;}
		else if(d==9) { ni+=1; nx+=1;}

		if(t==0);
		else if(t==1) nx+=1;
		else if(t==2) nx+=2;
		else if(t==3) nx+=3;
		else if(t==4) { nx+=1; nl+=1;}
		else if(t==5) nl+=1;
		else if(t==6) { nx+=1; nl+=1;}
		else if(t==7) { nx+=2; nl+=1;}
		else if(t==8) { nx+=3; nl+=1;}
		else if(t==9) { nx+=1; nc+=1;}
		else if(t==10) nc+=1;

		i[j]=i[j-1]+ni;
		v[j]=v[j-1]+nv;
		x[j]=x[j-1]+nx;
		l[j]=l[j-1]+nl;
		c[j]=c[j-1]+nc;
	}

	while(1)
	{
		scanf("%d",&n);

		if(n==0)break;

		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,i[n],v[n],x[n],l[n],c[n]);
	}
}