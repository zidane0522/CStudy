#include <stdio.h>
int main(void)
{ 
	puts("找出1000以内的所有质数");

	//找出1000开平方的整数范围

	//生成质数数组

	//总结计算次数

	//二分法确定1000开平方的整数范围
	int left=2, right=1000;
	int limit;

	while (right-left>1)
	{
		int temp = (left + right) / 2;
		if (temp*temp>1000)
		{
			right = temp;
		}
		else
		{
			left = temp;
		}
	}
	limit = right;
	int zhishu[500] = { 2 };
	int zhishuCount = 1;
	int zhishuFlag;
	int limitflag = 0;
	int jlimit = zhishuCount;
	int counter = 0;
	//生成质数数组，长度500,最大值limit
	for (int i = 3; i <= 1000; i+=2)
	{
		zhishuFlag = 1;
		for (int j = 0;j < jlimit; j++)
		{
			counter++;
			if (i%zhishu[j]==0)
			{
				zhishuFlag = 0;
				break;
			}
		}
		if (zhishuFlag)
		{
			counter++;
			if (limitflag==0)
			{
				if (i>limit)
				{
					limitflag = 1;
					
				}
				else
				{
					jlimit++;
				}
			}
			zhishu[zhishuCount++] = i;
		}
	}
	printf("运算次数%d\n",counter);
	puts("质数列表");
	for (int i = 0; i < zhishuCount; i++)
	{
		printf("%d\n", zhishu[i]);
	}
}