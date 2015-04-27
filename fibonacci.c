#include <stdio.h>
#include <math.h>

double fibo1(double n)//f(n) = f(n-1)+f(n-2)
{
	int i=0,temp;
	double cur=1,prev=0;
	//double sum=0;
	if(n<=1)
		return n;
	for(i=1;i<n;i++)
	{
		//sum += cur; 
		temp=cur;
		cur=cur+prev;
		prev=temp;
	}
	return cur;
}
double fibo2(double n)//f(n)=(1/sqrt(5))*( (1+sqrt(5))^n - ( (1-sqrt(5))^n )) ^is pow  n>=1
{
	return (pow(0.5+sqrt(5)/2, n) - pow(0.5-sqrt(5)/2, n)) * (1/sqrt(5));
}
int main()
{
	double n;
	printf("input n:");
	scanf("%lf",&n);
	printf("fibonacci1 is:%lf\n",fibo1(n));
	printf("fibonacc2 is:%lf\n",fibo2(n));
	
	return 0;
}
