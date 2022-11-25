#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//青蛙跳台阶+高精度加法 
//void QWTTJ(int num)
//{
//	int a = 1, b = 2, c;
//	if (num == 1)
//	{
//		b = 1;
//
//	}
//	else if (num == 2)
//	{
//		b = 2;
//
//	}
//	else
//		while (num >= 3)
//		{
//			c = b;
//			b = a + b;
//			a = c;
//			num--;
//		}
//
//	printf("%d\n", b);
//}
char ans[100000] = { 0 };
char a[100000] = { 0 };
char b[100000] = { 0 };
char aans[100000] = { 0 };

char* my_reverse(char bns[])
{
	int n = strlen(bns) - 1;
	int i;

	for (i = 0; i < n + 1; i++)
	{
		ans[i] = bns[i];
	}
	int lef = 0;
	int rit = n;
	char tmp;
	while (lef <= rit)
	{
		tmp = ans[lef];
		ans[lef] = ans[rit];
		ans[rit] = tmp;
		lef++;
		rit--;
	}
	return ans;
}
void QWTTJ(int num)
{

	if (num == 1)
	{
		printf("1\n");
	}
	else if (num == 2)
	{
		printf("2\n");
	}
	else
	{
		a[0] = '1';
		b[0] = '2';
		while (num >= 3)
		{
			int alen = strlen(a);
			int blen = strlen(b);
			int i;
			int A = 0, B = 0;
			int sum = 0;
			char mid;
			for (i = 0; i < 100000; i++)
			{

				if (alen == 0)
				{
					A = 0;
					alen--;
				}
				else if (alen > 0)
				{
					A = (int)a[alen - 1] - 48;
					alen--;
				}
				if (blen == 0)
				{
					B = 0;
					blen--;
				}
				else if (blen > 0)
				{
					B = (int)b[blen - 1] - 48;
					blen--;
				}
				sum += A + B;
				if (sum > 9)
				{
					mid = (char)((sum % 10) + 48);
					aans[i] = mid;
					sum = 1;
				}
				else
				{
					mid = (char)(sum + 48);
					if (mid == '0' && alen == -1 && blen == -1)
						break;
					else
					{
						aans[i] = mid;
						sum = 0;
					}
				}
			}
			strcpy(aans, my_reverse(aans));
			strcpy(a, b);
			strcpy(b, aans);
			num--;
		}
		//printf("%s", aans);
		int i;
		for (i = 0; i < strlen(aans); i++)
		{
			printf("%c", aans[i]);
		}
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	QWTTJ(num);
	return 0;
}