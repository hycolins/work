#include<stdio.h>
#include<math.h>
#include<time.h>
#include <stdlib.h>
void operation(void);
float plus(float a,float b);
float minus(float a,float b);
float multiply(float a,float b);
float divide(float a,float b);
float caculate(int i,float a,float b);
char Operator(int i);
void main()
{
	int i=0,n;
	printf("你想要输入的运算题目数为：");
	scanf("%d",&n);
	do{
		operation();
		i++;
	}while(i<n);
	system("pause");
}
void operation()
{
	float answer;
	float x,y,z;
	int a,b,c;
	int j,k;
	char op1,op2;
	srand((unsigned)time(NULL));
	do{
		a=rand()%100;
		b=rand()%100;
		c=rand()%100;
		//0，1为加减 2，3为乘除
		j=rand()%4;
		k=rand()%4;
		if(j>1){
			y=(float)a;
			z=(float)b;
			x=caculate(j,y,z);
			y=x;
			z=(float)c;
			x=caculate(k,y,z);
		}
		else
		{
			if(k<2)
			{
				y=(float)a;
			    z=(float)b;
			    x=caculate(j,y,z);
			    y=x;
			    z=(float)c;
			    x=caculate(k,y,z);
			}
			else
			{
				y=(float)b;
			    z=(float)c;
		    	x=caculate(k,y,z);
			    y=(float)a;
			    z=x;
		    	x=caculate(j,y,z);
			}
		}
	}while(x<0.0);
	op1=Operator(j);
	op2=Operator(k);
	printf("%d %c %d %c %d = ",a,op1,b,op2,c);
	scanf("%f",&answer);
	if(j==3&&k==3)
	{
		if((answer-x)<0.01)
		{
			printf("恭喜你，答对啦！\n");
		}
		else
		{
			printf("很遗憾，你答错了！正确答案是：%.1f\n",x);
		}
	}
	else
	{
		if((x-answer)<0.01)
		{
			printf("恭喜你，答对啦！\n");
		}
		else
		{
			printf("很遗憾，你答错了！正确答案是：%.1f\n",x);
		}
	}
}
float caculate(int i,float a,float b)      //当它是哪种符号就进行哪个计算
{
	float x;
	switch(i)
	{
	case 0:
		x=plus(a,b);
		break;
	case 1:
		x=minus(a,b);
		break;
	case 2:
		x=multiply(a,b);
		break;
	case 3:
		x=divide(a,b);
		break;
	default:
		break;
	}
	return x;
}
float plus(float a,float b)
{
	float x;
	x=a+b;
	return x;
}
float minus(float a,float b)
{
	float x;
	x=a-b;
	return x;
}
float multiply(float a,float b)
{
	float x;
	x=a*b;
	return x;
}
float divide(float a,float b)
{
	float x;
	x=a/b;
	return x;
}
char Operator(int i)   //运算符
{
	char fh;
	switch(i)
	{
	case 0:
		fh='+';
		break;
	case 1:
		fh='-';
		break;
	case 2:
		fh='*';
		break;
	default:
		fh='/';
		break;
	}
	return fh;
}