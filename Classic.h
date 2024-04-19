/* Mahrad Hosseini – 2528388
I read and accept the submission rules and the notes specified in each question. This is
my own work that is done by myself only */

#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<time.h>
using namespace std;

class Classic {
private:
	char ClassicBoard[3][3];

public:
	Classic();
	void printClassic(int,int);
	void insertClassic(int, int, int);
	char blockCheckC();
	char blockTieC();
	int operator!();
};