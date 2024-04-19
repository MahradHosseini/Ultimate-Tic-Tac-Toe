/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include"Classic.h"

class Ultimate {
private:
	Classic UltimateBoard[3][3];
	char WinRecord[3][3];
	
public:
	Ultimate();
	void printUltimate();
	void printLine(int, int);
	void insertUltimate(int, int, int, int);
	void blockCheckU(int);
	char roundCheckU();
	void blockTieU(int);
	char getWinRecord(int, int);
	void setWinRecord(char, int, int);
};