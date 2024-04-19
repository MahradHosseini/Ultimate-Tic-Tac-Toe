/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include"Ultimate.h"

Ultimate::Ultimate() {
	Classic::Classic();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			WinRecord[i][j] = '0';
		}
	}
}

void Ultimate::printLine(int B, int L) {
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			UltimateBoard[B][k].printClassic(L, i);
		}
		cout << "\t";
	}
	cout << endl;
}

void Ultimate::printUltimate() {
	for (int B = 0; B < 3; B++) {
		for (int L = 0; L < 3; L++) {
			Ultimate::printLine(B, L);
		}
		cout << "\n";
	}
}

void Ultimate::insertUltimate(int Player, int Block, int Row, int Column) {
	int BoardRow;
	int BoardColumn;

	switch (Block) {
	case 0: {
		BoardRow = 0;
		BoardColumn = 0;
	}
		  break;

	case 1: {
		BoardRow = 0;
		BoardColumn = 1;
	}
		  break;

	case 2: {
		BoardRow = 0;
		BoardColumn = 2;
	}
		  break;

	case 3: {
		BoardRow = 1;
		BoardColumn = 0;
	}
		  break;

	case 4: {
		BoardRow = 1;
		BoardColumn = 1;
	}
		  break;

	case 5: {
		BoardRow = 1;
		BoardColumn = 2;
	}
		  break;

	case 6: {
		BoardRow = 2;
		BoardColumn = 0;
	}
		  break;

	case 7: {
		BoardRow = 2;
		BoardColumn = 1;
	}
		  break;

	case 8: {
		BoardRow = 2;
		BoardColumn = 2;
	}
		  break;
	default:
		cout << "Please Enter Correct Block Number!" << endl;
	}

	UltimateBoard[BoardRow][BoardColumn].insertClassic(Player, Row, Column);
}

void Ultimate::blockCheckU(int Block) {
	int BoardRow, BoardColumn;

	switch (Block) {
	case 0: {
		BoardRow = 0;
		BoardColumn = 0;
	}
		  break;

	case 1: {
		BoardRow = 0;
		BoardColumn = 1;
	}
		  break;

	case 2: {
		BoardRow = 0;
		BoardColumn = 2;
	}
		  break;

	case 3: {
		BoardRow = 1;
		BoardColumn = 0;
	}
		  break;

	case 4: {
		BoardRow = 1;
		BoardColumn = 1;
	}
		  break;

	case 5: {
		BoardRow = 1;
		BoardColumn = 2;
	}
		  break;

	case 6: {
		BoardRow = 2;
		BoardColumn = 0;
	}
		  break;

	case 7: {
		BoardRow = 2;
		BoardColumn = 1;
	}
		  break;

	case 8: {
		BoardRow = 2;
		BoardColumn = 2;
	}
		  break;
	}

	WinRecord[BoardRow][BoardColumn] = UltimateBoard[BoardRow][BoardColumn].blockCheckC();

	if (WinRecord[BoardRow][BoardColumn] != 0) {
		if (WinRecord[BoardRow][BoardColumn] == 'X') {
			cout << "Player 1 won block" << Block << endl;
		}
		else {
			cout << "Player 2 won block" << Block << endl;
		}
	}
}

char Ultimate::roundCheckU() {
	if ((WinRecord[0][0] == 'X' && WinRecord[0][1] == 'X' && WinRecord[0][2] == 'X') || (WinRecord[1][0] == 'X' && WinRecord[1][1] == 'X' && WinRecord[1][2] == 'X') || (WinRecord[2][0] == 'X' && WinRecord[2][1] == 'X' && WinRecord[2][2] == 'X')) {
		cout << "Player 1 won this round" << endl;
		return 'X';
	}
	else if ((WinRecord[0][0] == 'Y' && WinRecord[0][1] == 'Y' && WinRecord[0][2] == 'Y') || (WinRecord[1][0] == 'Y' && WinRecord[1][1] == 'Y' && WinRecord[1][2] == 'Y') || (WinRecord[2][0] == 'Y' && WinRecord[2][1] == 'Y' && WinRecord[2][2] == 'Y')) {
		cout << "Player 2 won this round" << endl;
		return 'Y';
	}

	else if ((WinRecord[0][0] == 'X' && WinRecord[1][0] == 'X' && WinRecord[2][0] == 'X') || (WinRecord[0][1] == 'X' && WinRecord[1][1] == 'X' && WinRecord[2][1] == 'X') || (WinRecord[0][2] == 'X' && WinRecord[1][2] == 'X' && WinRecord[2][2] == 'X')) {
		cout << "Player 1 won this round" << endl;
		return 'X';
	}
	else if ((WinRecord[0][0] == 'Y' && WinRecord[1][0] == 'Y' && WinRecord[2][0] == 'Y') || (WinRecord[0][1] == 'Y' && WinRecord[1][1] == 'Y' && WinRecord[2][1] == 'Y') || (WinRecord[0][2] == 'Y' && WinRecord[1][2] == 'Y' && WinRecord[2][2] == 'Y')) {
		cout << "Player 2 won this round" << endl;
		return 'Y';
	}

	else if ((WinRecord[0][0] == 'X' && WinRecord[1][1] == 'X' && WinRecord[2][2] == 'X') || (WinRecord[0][2] == 'X' && WinRecord[1][1] == 'X' && WinRecord[2][0] == 'X')) {
		cout << "Player 1 won this round" << endl;
		return 'X';
	}
	else if ((WinRecord[0][0] == 'Y' && WinRecord[1][1] == 'Y' && WinRecord[2][2] == 'Y') || (WinRecord[0][2] == 'Y' && WinRecord[1][1] == 'Y' && WinRecord[2][0] == 'Y')) {
		cout << "Player 2 won this round" << endl;
		return 'Y';
	}

	else {
		int Zero = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (WinRecord[i][j] == '0') {
					Zero++;
				}
			}
		}

		if (Zero == 0) {
			cout << "This round ended in a draw" << endl;
			return 'D';
		}
		else {
			return '0';
		}
	}
}

void Ultimate::blockTieU(int Block) {
	int BoardRow, BoardColumn;

	switch (Block) {
	case 0: {
		BoardRow = 0;
		BoardColumn = 0;
	}
		  break;

	case 1: {
		BoardRow = 0;
		BoardColumn = 1;
	}
		  break;

	case 2: {
		BoardRow = 0;
		BoardColumn = 2;
	}
		  break;

	case 3: {
		BoardRow = 1;
		BoardColumn = 0;
	}
		  break;

	case 4: {
		BoardRow = 1;
		BoardColumn = 1;
	}
		  break;

	case 5: {
		BoardRow = 1;
		BoardColumn = 2;
	}
		  break;

	case 6: {
		BoardRow = 2;
		BoardColumn = 0;
	}
		  break;

	case 7: {
		BoardRow = 2;
		BoardColumn = 1;
	}
		  break;

	case 8: {
		BoardRow = 2;
		BoardColumn = 2;
	}
		  break;
	}

	if (WinRecord[BoardRow][BoardColumn] == 0) {
		WinRecord[BoardRow][BoardColumn] = UltimateBoard[BoardRow][BoardColumn].blockTieC();
	}
}

char Ultimate::getWinRecord(int Row, int Column) {
	return WinRecord[Row][Column];
}

void Ultimate::setWinRecord(char Winner, int Row, int Column) {
	WinRecord[Row][Column] = Winner;
}