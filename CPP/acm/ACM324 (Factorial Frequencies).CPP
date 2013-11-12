#include<stdio.h>
#include<string.h>

#define MAX 1500
#define DGT 367

void str_rev(char p[MAX])
{
	char s[MAX]={0};
	long i,j;

	i=strlen(p)-1;
	for(j=0; i>=0; j++,i--)s[j]=p[i];

	for(i=0; p[i]; i++)p[i]=s[i];
}

char* convert_str(int n)
{
	char str[MAX];
	int i;

	for(i=0; n>0; i++)
	{
		str[i]=(n%10)+'0';
		n=n/10;
	}
	str_rev(str);
	return str;
}

char* mul(char str1[MAX],char str2[MAX])
{
	char ans[MAX]={0};
	int m,n,num1,num2,i,j,k;

	str_rev(str1);
	str_rev(str2);

	i=strlen(str1);
	j=strlen(str2);

	for(m=0;m<j;m++){              /* loop for str2 */
		num2=str2[m]-'0';        /* loop for str1 */
		for(n=0;n<i;n++){
			num1=str1[n]-'0';
			ans[n+m]+=num1*num2;
			if(ans[n+m]>9){
				ans[n+m+1]+=ans[m+n]/10;
				ans[m+n]%=10;
			}
		}
	}
	for(k=0;k<=(i+j);k++) ans[k]+='0';    /* charac conversion */

	str_rev(ans);                          /* rev the ans */

	while(ans[0]=='0'){
		for(k=0; k<MAX; k++) ans[k]=ans[k+1];    /* setting number  in actual order */
	}

	return ans;
}

void main()
{
	int i,j,k,num,digit[DGT][11]={0};
	char store[DGT][MAX]={0};
	char n[DGT][MAX]={0};

	for(i=1; i<=DGT; i++)
	{
		strcpy(store[i],convert_str(i));
	}

	strcpy(n[1],"1");

	for(i=2; i<=DGT; i++)
	{
		strcpy(n[i],mul(store[i],n[i-1]));
	}

	for(i=1; i<DGT; i++)
	{
		for(j=0; j<strlen(n[i]); j++)
		{
			if(n[i][j]=='0') digit[i][0]++;
			else if(n[i][j]=='1') digit[i][1]++;
			else if(n[i][j]=='2') digit[i][2]++;
			else if(n[i][j]=='3') digit[i][3]++;
			else if(n[i][j]=='4') digit[i][4]++;
			else if(n[i][j]=='5') digit[i][5]++;
			else if(n[i][j]=='6') digit[i][6]++;
			else if(n[i][j]=='7') digit[i][7]++;
			else if(n[i][j]=='8') digit[i][8]++;
			else if(n[i][j]=='9') digit[i][9]++;
		}
	}

	while(1)
	{
		scanf("%d",&num);
		if(num==0)break;
		printf("%d! --\n",num);

		for(i=0; i<10; i++)
		{
			if(i==5)printf("\n");
			printf("   (%d)%5d",i,digit[num][i]);
		}
		printf("\n");
	}

}
