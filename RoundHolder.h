/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include "Ultimate.h"

class RoundHolder {
private:
	Ultimate Round[3];
	char RoundWinner[3];

public:
	RoundHolder();
	void printRound(int);
	void insertRound(int, int, int, int, int);
	void blockCheckR(int, int);
	int roundCheckR(int);
	void blockTieR(int, int);
	int winnerCheck();
	void randomnessR();
	int thirdRoundCheck();
	friend Ultimate operator + (Ultimate, Ultimate);
	friend Ultimate operator - (Ultimate, Ultimate);
};