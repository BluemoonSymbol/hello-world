#include<stdio.h>
#include<string.h>
#include<math.h>

int sum_bit(int num)
{
	int sum=0;
	while(1)
	{
		sum+=num%10;
		num/=10;
		if(!num)
		{
			break;
		}
	}
	
  return sum;
}

int multi_bit(int num) 
{
  int muti=1;
	while(1)
	{
		muti*=num%10;
		num/=10;
		if(!num)
		{
			break;
		}
	}
	
  return muti;
}

int square_sum_bit(int num) 
{
  int sum=0;
	while(1)
	{
		sum+=(num%10)*(num%10);
		num/=10;
		if(!num)
		{
			break;
		}
	}
	
  return sum;
}

int isprime(int num) 
{
	int i;
	for(i=2;i<=sqrt(num);i++)
	{
		if(!(num%i))
		{
			
			return 0;
		}
		
	}
	return 1;
  
}


int main() 
{
	int i,j=0,sum=0,flag=0,count=0;;
	for(i=9999;i>=100;i--)
	{
		if(isprime(i)&&isprime(sum_bit(i))&&isprime(multi_bit(i))&&isprime(square_sum_bit(i)))
		  {
		  	if(!flag)
		  	{
		  		printf("%d\n",i);
		  		flag=1;
			}
		  	sum+=i;
		  	count++;
		  	
		  }
	}
	printf("%d\n%d\n",sum,count);
  
    return 0;
}
