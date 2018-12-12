	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>

	/**
	 * Auto-generated code below aims at helping you parse
	 * the standard input according to the problem statement.
	 **/


	#define X 33


	int grid[X][X];

	int main()
	{

		// game loop
		while (1) {
			int N; // total number of players (2 to 4).
			int P; // your player number (0 to 3).
			int myX = -1, myY = -1;
			scanf("%d%d", &N, &P);
			for (int i = 0; i < N; i++) {
				int X0; // starting X coordinate of lightcycle (or -1)
				int Y0; // starting Y coordinate of lightcycle (or -1)
				int X1; // starting X coordinate of lightcycle (can be the same as X0 if you play before this player)
				int Y1; // starting Y coordinate of lightcycle (can be the same as Y0 if you play before this player)
				scanf("%d%d%d%d", &X0, &Y0, &X1, &Y1);
				if(i == P)
					myX = X1, myY = Y1;
				grid[X1][Y1] = i + 1;
			}

			// Write an action using printf(). DON'T FORGET THE TRAILING \n
			// To debug: fprintf(stderr, "Debug messages...\n");

			if(myY > 2 && grid[myX][myY - 1] == 0)
				printf("UP\n");
			else if(myX > 2 && grid[myX - 1][myY] == 0)
				printf("LEFT\n");
			else if(myY < 18 && grid[myX][myY + 1] == 0)
				printf("DOWN\n");
			else
				printf("RIGHT\n");
		}

		return 0;
	}
