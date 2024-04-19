/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include "RoundHolder.h"

RoundHolder::RoundHolder() {
	Ultimate::Ultimate();
	for (int i = 0; i < 3; i++) {
		RoundWinner[i] = '0';
	}
}

void RoundHolder::printRound(int R) {
	Round[R].printUltimate();
}

void RoundHolder::insertRound(int R, int Player, int Block, int Row, int Column) {
	Round[R].insertUltimate(Player, Block, Row, Column);
}

void RoundHolder::blockCheckR(int R, int Block) {
	Round[R].blockCheckU(Block);
}

int RoundHolder::roundCheckR(int R) {
	RoundWinner[R] = Round[R].roundCheckU();

	if (RoundWinner[R] != '0') {
		return 1;
	}

	else {
		return 0;
	}
}

void RoundHolder::blockTieR(int R, int Block) {
	Round[R].blockTieU(Block);
}

int RoundHolder::winnerCheck() {
	if (RoundWinner[0] == RoundWinner[1]) {
		if (RoundWinner[0] == 'X') {
			cout << "PLAYER 1 WON THE GAME !!!!" << endl;
			return 1;
		}
		else if (RoundWinner[0] == 'Y') {
			cout << "PLAYER 2 WON THE GAME !!!!" << endl;
			return 1;
		}
	}
	else {
		return 0;
	}
}

void RoundHolder::randomnessR() {
	int Selector = 0;  // An integer between 1 and 2 with probability of 50% for each
	srand(time(0));
	
	Selector = rand() % 2 + 1;

	if (Selector == 1) {
		Round[2] = operator + (Round[0], Round[1]);
	}
	
	else if (Selector == 2) {
		Round[2] = operator - (Round[0], Round[1]);
	}
}

Ultimate operator+(Ultimate Operand1, Ultimate Operand2) {
	Ultimate Result;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char Op1, Op2, Rslt;

			Op1 = Operand1.getWinRecord(i, j);
			Op2 = Operand2.getWinRecord(i, j);

			if (Op1 == 'X' || Op2 == 'X') {
				Rslt = 'X';
			}
			else if ((Op1 == 'Y' && Op2 == '0') || (Op1 == '0' && Op2 == 'Y') || (Op1 == 'Y' && Op2 == 'Y')) {
				Rslt = 'Y';
			}
			else if (Op1 == '0' && Op2 == '0') {
				Rslt = '0';
			}

			Result.setWinRecord(Rslt, i, j);
		}
	}

	return Result;
}

Ultimate operator-(Ultimate Operand1, Ultimate Operand2) {
	Ultimate Result;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char Op1, Op2, Rslt;

			Op1 = Operand1.getWinRecord(i, j);
			Op2 = Operand2.getWinRecord(i, j);

			if (Op1 == 'Y' || Op2 == 'Y') {
				Rslt = 'Y';
			}
			else if ((Op1 == 'X' && Op2 == '0') || (Op1 == '0' && Op2 == 'X') || (Op1 == 'X' && Op2 == 'X')) {
				Rslt = 'X';
			}
			else if (Op1 == '0' && Op2 == '0') {
				Rslt = '0';
			}

			Result.setWinRecord(Rslt, i, j);
		}
	}

	return Result;
}

int RoundHolder::thirdRoundCheck() {
	RoundWinner[2] = Round[2].roundCheckU();
	if (RoundWinner[2] == 'X') {
		return 1;
	}
	else if (RoundWinner[2] == 'Y') {
		return 2;
	}
	else if (RoundWinner[2] == 'D') {
		int WinnerSelector = 0;
		srand(time(0));
		WinnerSelector = rand() % 2 + 1;

		if (WinnerSelector == 1) {
			RoundWinner[2] = 'X';
			cout << "Player 1 Won this round" << endl;
			return 1;
		}
		else if (WinnerSelector == 2) {
			RoundWinner[2] = 'Y';
			cout << "Player 2 Won this round" << endl;
			return 2;
		}
	}

}