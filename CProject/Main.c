#include <stdio.h>

int isleapYear(int *y)
{
	if (*y%400==0)
	{
		return 1;
	}
	else if(*y%100==0)
	{
		return 0;
	}
	else if (*y%4==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int getmaxday(int *y, int *m)
{
	int isleapyear = isleapYear(y);
	switch (*m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 2:
		if (isleapyear)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	}
	return 0;
}

void lastDay(int *y,int *m,int *d,int maxday)
{
	int ly, lm, ld;
	if (*d==1)
	{
		lm = *m > 1 ? *m - 1 : 12;
		ly = lm == 12 ? *y - 1 : *y;
		ld = getmaxday(&ly, &lm);
	}
	else
	{
		ly = *y;
		lm = *m;
		ld = *d-1;
	}
	printf("上一天的日期是%d年-%d月-%d日\n",ly,lm,ld);
	return(0);
}

void nextDay(int *y, int *m, int *d,int maxday)
{
	int ly, lm, ld;
	if (*d == maxday)
	{
		lm = *m == 12 ? 1 : *m +1;
		ly = lm == 1 ? *y + 1: *y;
		ld = 1;
	}
	else
	{
		ly = *y;
		lm = *m;
		ld = *d+1;
	}
	printf("下一天的日期是%d年-%d月-%d日\n", ly, lm, ld);
	return(0);
}



void sort3(int *n,int *n2,int *n3)
{
	int s[] = { *n,*n2,*n3 };
	int temp=s[0];
	for (int j = 2; j >=0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (s[i]>s[i + 1])
			{
				temp = s[i];
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}
		}
	}
	*n = s[0];
	*n2 = s[1];
	*n3 = s[2];
	printf("%d\n%d\n%d\n", &s[2], &s[0],&s[2]-&s[0]);
}

char *str_copy(char *d,const char *s)
{
	char *t = d;
	while (*d++ = *s++)
		return (t);
}

int main(void)
{
	char s1[128] = "abcd";
	char s2[128] = "efgh";
	printf("字符串s1:"); scanf_s("%s",s1);
	str_copy(s2,s1);
	puts("s1复制到了s2");
	printf("s1=%s\n",s1);
	printf("s2=%s\n", s2);
	return(0);
}