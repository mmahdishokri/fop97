#include <stdio.h>

#define MAXN 100

int s[MAXN];
int p[MAXN];

void bt(int i, int n)
{
	if(i == n)
	{
		printf("{");
		for(int j = 0; j < n; j++)
		{
			if(j != 0)
				printf(", ");
			printf("%d", p[j]);
		}
		printf("}\n");
		return;
	}

	for(int x = 1; x <= n; x++)
	{
		int ok = 1;
		for(int j = 0; j < i; j++)
			if(p[j] == x)
				ok = 0;
		if(ok == 1)
		{
			p[i] = x;
			bt(i + 1, n);
		}
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	bt(0, n);
}

