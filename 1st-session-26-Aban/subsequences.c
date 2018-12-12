#include <stdio.h>

#define MAXN 100

int s[MAXN];
int state[MAXN];

void bt(int i, int n)
{
	if(i == n)
	{
		printf("{");
		for(int j = 0; j < n; j++)
			if(state[j] == 1)
				printf("%d ", s[j]);
		printf("}\n");
		return;
	}

	state[i] = 0;
	bt(i + 1, n);
	state[i] = 1;
	bt(i + 1, n);
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	bt(0, n);
}

