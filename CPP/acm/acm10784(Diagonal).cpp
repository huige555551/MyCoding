#include<stdio.h> 
#include<math.h> 

void main() 
{ 
   int Case=1;
   long long N; 
    
   while(scanf("%lld",&N)==1) 
   { 
      if(N==0) break; 

      printf ("Case %d: %d\n", Case,(int)ceil((3.0+sqrt(9.0+8.0*N))/2.0)); 
       
      Case++; 
   } 
}