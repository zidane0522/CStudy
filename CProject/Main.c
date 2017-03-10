#include <stdio.h>

enum animal
{
	Dog,
	Cat,
	Monkey,
	Invalid
};

void DogYell(void)
{
	puts("ÍôÍô");
}

void CatYell(void)
{
	puts("ß÷ß÷");
}

void MonkeyYell(void)
{
	puts("àÞàÞ");
}


enum animal select(void)
{
	int t;
	do
	{
		scanf_s("%d",&t);
	} while (t>Invalid||t<Dog);
	return t;
};


//½×³ËµÝ¹é
int digui_func(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n*digui_func(n - 1);
	}
}

//½×³ËÎÞµÝ¹é
int func(int n)
{
	int temp = 1;
	for (int i = 1; i <= n; i++)
	{
		temp *= i;
	}
	return temp;
}

void getcharfunc(void)
{
	int num[10] = { 0 };
	int charr;
	float f;
	scanf_s("%f", &f);
	while (1)
	{
		charr = getchar();
	
		if (charr==EOF)
		{
			break;
		}
		switch (charr)
		{
		case '0':num[0]++;
			break;
		case '1':num[1]++;
			break;
		case '2':num[2]++;
			break;
		case '3':num[3]++;
			break;
		case '4':num[4]++;
			break;
		case '5':num[5]++;
			break;
		case '6':num[6]++;
			break;

		case '7':num[7]++;
			break;
		default:
			break;
		}
	}
	puts("Êý×Ö×Ö·û³öÏÖµÄ´ÎÊý");
	for (int i = 0; i < 10; i++)
	{
		printf("'%d':%d\n",i,num[i]);
	}
}

int main(void)
{
	getcharfunc();
	return(0);
}