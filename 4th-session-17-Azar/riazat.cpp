#include <bits/stdc++.h>

#define P 8
#define STP (243*243/9) // = 3 ^ 8

void init() {
}

int winMove(int move) {
	return (move + 2) % 3;
}

int predict[STP][STP][3];

int ourMoves, theirMoves;
int ourLastMove;

int guess() {
	int best = 0;
	for(int i = 0; i < 3; i++)
		if(predict[i] > predict[best])
			best = i;
	return best;
}

int next(int previous_opponent_move) {
	if(previous_opponent_move >= 0 && previous_opponent_move < 3) {
		predict[theirMoves][ourMoves][previous_opponent_move]++;

		ourMoves = ourMoves * 3 % STP + ourLastMove;
		theirMoves = theirMoves * 3 % STP + previous_opponent_move;
	}
	ourLastMove = winMove(guess());
	return ourLastMove;
}
