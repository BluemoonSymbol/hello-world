  #include<stdio.h>
 #include<math.h>
  int main()
  {
      int a,b;
      while(scanf("%d%d",&a,&b)==2)
      {
          if(a==0)
         {
             printf("0\n");
             continue;
         }
         if(b==0)
         {
             printf("1\n");
             continue;
         }
         a=a%10;
        b=b%4+4;
         printf("%d\n",(int)pow(a,b)%10);
     }
     return 0;
 }
