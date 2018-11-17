#include <stdio.h>

#define MAXN 100

int s[MAXN];
int p[MAXN];
int mark[MAXN + 1];

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
		if(mark[x] == 0)
		{
			p[i] = x;
			mark[x] = 1;
			bt(i + 1, n);
			mark[x] = 0;
		}
	}

}

int main()
{
	int n;
	scanf("%d", &n);
	bt(0, n);
}

