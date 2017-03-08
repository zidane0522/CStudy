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

//或
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

//与
unsigned reset(unsigned x, int pos)
{
	unsigned p = 1U;
	return x&(~p << (pos - 1));
}

//异或
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

//或
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

//与
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
	puts("请输入一个非负整数");
	scanf_s("%u",&num);
	printf("二进制表示为\n");
	print_bits(num);

	int n;
	printf("\n输入向右移动的位数");
	scanf_s("%d",&n);

	printf("移动后变为%u\n",rrotate(num,n));
	print_bits(rrotate(num, n));

	printf("\n输入向左移动的位数");
	scanf_s("%d", &n);
	printf("移动后变为%u", lrotate(num, n));
	print_bits(lrotate(num, n));

	printf("\n输入变位的位数");
	scanf_s("%d", &n);
	printf("\n变位为1后为%u", set(num, n));
	printf("\n变位为0后为%u", reset(num, n));
	printf("\n变位为反后为%u", inverse(num, n));

	int pos;
	printf("\n输入开始位");
	scanf_s("%d",&pos);
	printf("\n输入变位长度");
	scanf_s("%d", &n);

	printf("\n变位为1后为%u", set_n(num, pos, n));
	printf("\n变位为0后为%u", reset_n(num, pos, n));
	printf("\n变位取反后为%u", inverse_n(num, pos, n));
	return(0);
}