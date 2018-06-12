#include <stdio.h>
#include <string.h>

#define N 10000001

char b[N];
int a[1000000]={0};

int main()
 {
	


		
		memset(b, 1, sizeof(b));
		
		long long sum = 0;
		for (int i = 2; i < 10000; i++)
		 {
			if (b[i] == 0) continue;
			
			for (int j = 2 * i; j < 10000; j += i)
			 {
				b[j] = 0;
			}
			
			//sum += i;
		}
	int k=1;
		for (int i = 2; i < 10000; i++)
		 {
			if (b[i])
			{
				a[k]=i;
				k++;
				
			 } 
			
		}
		
//		for(int i=1;i<1000000;i++)
//		{
//			printf("%d  ",a[i]);
//		}
		
		
		
		
		FILE *fp;	
	fp=fopen("D:\\b.txt","wt");
	for (int i = 0; i < k-1; i++)
	 	{  
 		 fprintf(fp,"%d,",a[i]);
 		}
 fclose(fp);      
	
	
		printf("%lld\n", sum);
	
	
	return 0;
}


