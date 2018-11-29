	//    . .. ... .... ..... be name khoda ..... .... ... .. .     \\

#include <stdio.h>

int c[20];

void print(int n)
{
	int st = -1;
	for(int j = 0; j < n; j++)
		if(c[j])
		{
			st = j;
			break;
		}
	printf("{");
	for(int j = 0; j < n; j++)
		if(c[j])
		{
			if(j != st)
				printf(", ");
			printf("%d", j + 1);
		}
	printf("}\n");
}

void go(int i, int nextNumber, int n)
{
	print(n);
	if(i == n || nextNumber == n)
		return;
	for(; nextNumber < n; nextNumber++)
	{
		c[nextNumber] = 1;
		go(i + 1, nextNumber + 1, n);
		c[nextNumber] = 0;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	go(0, 0, n);
}
