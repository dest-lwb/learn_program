/*
	PAT Maximum Subsequence Sum (25)
	Given a sequence of K integers { N1, N2, ..., NK }.
	A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } 
	where 1 <= i <= j <= K. The Maximum Subsequence is the continuous 
	subsequence which has the largest sum of its elements. For example, 
	given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence 
	is { 11, -4, 13 } with the largest sum being 20.

	Now you are supposed to find the largest sum, 
	together with the first and the last numbers of the maximum subsequence.
	input: 10
		   -10 1 2 3 4 -5 -23 3 7 -21
	output: 10 1 4
*/

#include<stdio.h>
int main(){
	int k = 0;
	int max = 0;
	int last = 0;
	int first = 0;
	scanf("%d",&k);
	int a[k];
	int i = 0;
	for (i=0; i<k; i++)
	{
		scanf("%d",&a[i]);
	}
	int nag = 0;
	int tmp = 0;
	int sum = 0;
	for (i=0; i<k; i++)
	{
		if(a[i] < 0){
			nag ++;
		}
		sum += a[i];
		if (sum > max)
		{
			max = sum;
			last = i;
			first = tmp;
		}else if(sum < 0){
			sum = 0;
			tmp = i+1;
		}
	}

	if (nag == k){
		printf("0 %d %d",a[0],a[k-1]);
		return 0;
	}

	if (max == 0)
	{
		printf("0 0 0");
	}else{
		printf("%d %d %d", max,a[first],a[last]);
	}

}
