/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include"Classic.h"

Classic::Classic() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ClassicBoard[i][j] = '0';
		}
	}
}


void Classic::printClassic(int i, int j) {
	cout << ClassicBoard[i][j] << "  ";
}

void Classic::insertClassic(int Player, int Row, int Column) {
	if (Player == 1) {
		ClassicBoard[Row][Column] = 'X';
	}

	else if (Player == 2) {
		ClassicBoard[Row][Column] = 'Y';
	}
}

char Classic::blockCheckC() {
	if ((ClassicBoard[0][0] == 'X' && ClassicBoard[0][1] == 'X' && ClassicBoard[0][2] == 'X') || (ClassicBoard[1][0] == 'X' && ClassicBoard[1][1] == 'X' && ClassicBoard[1][2] == 'X') || (ClassicBoard[2][0] == 'X' && ClassicBoard[2][1] == 'X' && ClassicBoard[2][2] == 'X')) {
		return 'X';
	}
	else if ((ClassicBoard[0][0] == 'Y' && ClassicBoard[0][1] == 'Y' && ClassicBoard[0][2] == 'Y') || (ClassicBoard[1][0] == 'Y' && ClassicBoard[1][1] == 'Y' && ClassicBoard[1][2] == 'Y') || (ClassicBoard[2][0] == 'Y' && ClassicBoard[2][1] == 'Y' && ClassicBoard[2][2] == 'Y')) {
		return 'Y';
	}

	else if ((ClassicBoard[0][0] == 'X' && ClassicBoard[1][0] == 'X' && ClassicBoard[2][0] == 'X') || (ClassicBoard[0][1] == 'X' && ClassicBoard[1][1] == 'X' && ClassicBoard[2][1] == 'X') || (ClassicBoard[0][2] == 'X' && ClassicBoard[1][2] == 'X' && ClassicBoard[2][2] == 'X')) {
		return 'X';
	}
	else if ((ClassicBoard[0][0] == 'Y' && ClassicBoard[1][0] == 'Y' && ClassicBoard[2][0] == 'Y') || (ClassicBoard[0][1] == 'Y' && ClassicBoard[1][1] == 'Y' && ClassicBoard[2][1] == 'Y') || (ClassicBoard[0][2] == 'Y' && ClassicBoard[1][2] == 'Y' && ClassicBoard[2][2] == 'Y')) {
		return 'Y';
	}

	else if ((ClassicBoard[0][0] == 'X' && ClassicBoard[1][1] == 'X' && ClassicBoard[2][2] == 'X') || (ClassicBoard[0][2] == 'X' && ClassicBoard[1][1] == 'X' && ClassicBoard[2][0] == 'X')) {
		return 'X';
	}
	else if ((ClassicBoard[0][0] == 'Y' && ClassicBoard[1][1] == 'Y' && ClassicBoard[2][2] == 'Y') || (ClassicBoard[0][2] == 'Y' && ClassicBoard[1][1] == 'Y' && ClassicBoard[2][0] == 'Y')) {
		return 'Y';
	}

	else {
		return '0';
	}
}

char Classic::blockTieC() {
	int Zero = 0;
	int Winner;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (ClassicBoard[i][j] == '0') {
				Zero++;
			}
		}
	}

	if (Zero == 0) {
		Winner = !ClassicBoard;

		if (Winner == 1) {
			return 'X';
		}
		else if (Winner == 0) {
			return 'Y';
		}
	}
	else {
		return '0';
	}
}

int Classic::operator!() {
	int TotalX = 0;
	int TotalY = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int Score = 0;

			if (i == 0 && j == 0) {
				Score = 1;
			}
			else if (i == 0 && j == 1) {
				Score = 2;
			}
			else if (i == 0 && j == 2) {
				Score = 3;
			}
			else if (i == 1 && j == 0) {
				Score = 4;
			}
			else if (i == 1 && j == 1) {
				Score = 5;
			}
			else if (i == 1 && j == 2) {
				Score = 6;
			}
			else if (i == 2 && j == 0) {
				Score = 7;
			}
			else if (i == 2 && j == 1) {
				Score = 8;
			}
			else if (i == 2 && j == 2) {
				Score = 9;
			}

			if (ClassicBoard[i][j] == 'X') {
				TotalX = TotalX + Score;
			}
			else if (ClassicBoard[i][j] == 'Y') {
				TotalY = TotalY + Score;
			}
		}
	}

	if (TotalX > TotalY) {
		return 1;
	}
	else if (TotalY > TotalX) {
		return 0;
	}
}