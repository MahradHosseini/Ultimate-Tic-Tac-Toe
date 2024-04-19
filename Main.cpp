/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */


/* In this program, the character 'Y' has been utilized instead of 'O' for:
1. Ease of reading the board
2. Not to be mistaken with zero symbol '0'
*/

#include "RoundHolder.h"

int main() {
	RoundHolder TicTac;
	cout << "Welcome to Ultimate Tic Tac Toe!-----------------\n" << endl;
	
	for (int R = 0; R < 3; R++) {
		int EndRound = 0;
		cout << "Round " << R + 1 << endl;
		if (R == 2) {
			int WinWithFirstTwo = 0;
			WinWithFirstTwo = TicTac.winnerCheck();

			if (WinWithFirstTwo == 0) {
				int Winner = 0;
				
				TicTac.randomnessR();

				Winner = TicTac.thirdRoundCheck();
				if (Winner == 1) {
					cout << "PLAYER 1 WON THE GAME !!!!" << endl;
				}
				else if (Winner == 2) {
					cout << "PLAYER 2 WON THE GAME !!!!" << endl;
				}

			}
		}
		else {
			while (EndRound == 0) {
				for (int Player = 1; Player <= 2; Player++) {
					int BlockNumber, Row, Column;
					cout << "Player " << Player << ", Choose your coordinates:" << endl;
					cout << "Block No. (From 0 to 8): ";
					cin >> BlockNumber;

					cout << "Row(From 0 to 2): ";
					cin >> Row;

					cout << "Column(From 0 to 2): ";
					cin >> Column;

					TicTac.insertRound(R, Player, BlockNumber, Row, Column);

					TicTac.printRound(R);

					TicTac.blockCheckR(R, BlockNumber);
					EndRound = TicTac.roundCheckR(R);

					TicTac.blockTieR(R, BlockNumber);
				}
			}
		}
		
	}
	

	return 0;
}