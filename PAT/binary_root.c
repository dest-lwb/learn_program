/*
	PAT 二分法求多项式单根(20)
	本题目要求编写程序，计算给定3阶多项式f(x)=a3x3+a2x2+a1x+a0在给定区间[a, b]内的根。
	输入格式：输入在第1行中顺序给出多项式的4个系数a3、a2、a1、a0，在第2行中顺序给出
	区间端点a和b。题目保证多项式在给定区间内存在唯一单根。
	输出格式：在一行中输出该多项式在该区间内的根，精确到小数点后2位。
	input: 3 -1 -3 1
	       -0.5 0.5
	output: 0.33
*/

#include<stdio.h>

float a3,a2,a1,a0;
float func(float x);

int main(){

	float left = 0.0;
	float right = 0.0;
	float mid = 0.0;

	float va = 0.001;

	scanf("%f %f %f %f", &a3, &a2, &a1, &a0);
	scanf("%f %f", &left, &right);

	float root = 1.0;

	while (1){
		mid = (left + right) / 2.0;
		if ((right - left) < va){
			root = mid;
			break;
		}

		float fa = func(left);
		float fb = func(right);
		float fv = func(mid);
		if ((fv*fa) > 0)
		{
			left = mid;
			continue;
		}
		if((fv*fb) > 0){
			right = mid;
			continue;
		}
		if(fv < va && fv > -va){
			root = mid;
			break;
		}
	}
	printf("%.2f", root);
}

float func(float x){
	float funl = 0.0;
	return funl = ((a3*x + a2)*x + a1)*x + a0;
}
