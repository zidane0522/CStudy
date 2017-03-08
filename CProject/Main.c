#include <stdio.h>


int count_bits()
{
	unsigned num = ~0U;
	int count = 0;
	while (num)
	{
		
		if (num & 1U)
		{
			num >>= 1;
			count++;
		}
	}
	return count;
}

void print_bits(unsigned num)
{
	int bitcount = count_bits();
	for (int i = bitcount-1; i >= 0; i--)
	{
		putchar((num >> i) & 1U ? '1' : '0');
	}
}



unsigned rrotate(unsigned x,int n)
{
	return x >> n;
}

unsigned lrotate(unsigned x, int n)
{
	return x << n;
}

//��
unsigned set(unsigned x, int pos)
{
	if (pos<1)
	{
		puts("wrong");
		scanf_s("%d",pos);
	}
	unsigned p = 1U;
	return x|(pos==1?p: p <<(pos-1));
}

//��
unsigned reset(unsigned x, int pos)
{
	unsigned p = 1U;
	return x&(~p << (pos - 1));
}

//���
unsigned inverse(unsigned x, int pos) 
{
	if (pos<1)
	{
		puts("wrong");
		scanf_s("%d", pos);
	}
	unsigned p = 1U;
	return x ^ (pos == 1 ? p : p << (pos - 1));
};

//��
unsigned set_n(unsigned x,int pos,int n) 
{
	unsigned p = 1U;
	for (int i = 1; i < n; i++)
	{
		p <<= 1;
		p= p | 1U;		
	}
	return x|(p <<(pos - 1));
};

//��
unsigned reset_n(unsigned x, int pos, int n)
{
	unsigned p = 1U;
	for (int i = 1; i < n; i++)
	{
		p <<= 1;
		p = p & 1U;
	}
	return  x&(~p << (pos - 1));
};

unsigned inverse_n(unsigned x, int pos, int n)
{
	unsigned p = 1U;
	for (int i = 1; i < n; i++)
	{
		p <<= 1;
		p = p | 1U;
	}
	return x ^ (p << (pos - 1));
}

int main(void)
{
	unsigned num;
	puts("������һ���Ǹ�����");
	scanf_s("%u",&num);
	printf("�����Ʊ�ʾΪ\n");
	print_bits(num);

	int n;
	printf("\n���������ƶ���λ��");
	scanf_s("%d",&n);

	printf("�ƶ����Ϊ%u\n",rrotate(num,n));
	print_bits(rrotate(num, n));

	printf("\n���������ƶ���λ��");
	scanf_s("%d", &n);
	printf("�ƶ����Ϊ%u", lrotate(num, n));
	print_bits(lrotate(num, n));

	printf("\n�����λ��λ��");
	scanf_s("%d", &n);
	printf("\n��λΪ1��Ϊ%u", set(num, n));
	printf("\n��λΪ0��Ϊ%u", reset(num, n));
	printf("\n��λΪ����Ϊ%u", inverse(num, n));

	int pos;
	printf("\n���뿪ʼλ");
	scanf_s("%d",&pos);
	printf("\n�����λ����");
	scanf_s("%d", &n);

	printf("\n��λΪ1��Ϊ%u", set_n(num, pos, n));
	printf("\n��λΪ0��Ϊ%u", reset_n(num, pos, n));
	printf("\n��λȡ����Ϊ%u", inverse_n(num, pos, n));
	return(0);
}