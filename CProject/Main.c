#include <stdio.h>
int main(void)
{ 
	puts("�ҳ�1000���ڵ���������");

	//�ҳ�1000��ƽ����������Χ

	//������������

	//�ܽ�������

	//���ַ�ȷ��1000��ƽ����������Χ
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
	//�����������飬����500,���ֵlimit
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
	printf("�������%d\n",counter);
	puts("�����б�");
	for (int i = 0; i < zhishuCount; i++)
	{
		printf("%d\n", zhishu[i]);
	}
}