#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<math.h> 

#define MAX 1000 

typedef long long big; 

char word[MAX][20]; 
big j; 
big c[MAX],x[MAX]; 

void get_word(char *s) 
{ 
   big i,k,l=strlen(s); 

   for(i=0,j=0; i<l; i++) 
   { 
      if( (s[i]>='0'&&s[i]<='9') || (s[i]=='-') ) 
      { 
         for(k=0; (s[i]>='0'&&s[i]<='9') || (s[i]=='-'); i++,k++) 
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
   char s[MAX+100]; 
   big i,k,n,m,t,p; 

   //freopen("in.txt","r",stdin); 

   while(gets(s)!=NULL) 
   { 
      if(strcmp(s,"")==0) continue; 

      get_word(s); 

      for(i=0; i<j; i++) 
      { 
         c[i]=atol(word[i]); 
      } 
      n=i-1; 

      gets(s); 
      get_word(s); 

      for(i=0; i<j; i++) 
      { 
         x[i]=atol(word[i]); 
      } 
      m=i-1; 

      for(k=0; k<=m; k++) 
      { 
         t=0; 
         if(x[k]!=0) 
         { 
            for(i=0,j=n; i<=n; i++,j--) 
            { 
               p=(long)pow(x[k],j); 
               t+=c[i]*p; 
            } 
         } 
         else 
         { 
            for(i=0,j=n; i<=n; i++,j--) 
            { 
               if(j==0) 
               { 
                  t+=c[i]*1; 
               } 
            } 
         } 
         printf("%lld ",t); 
      } 

      printf("\n"); 

   } 
}