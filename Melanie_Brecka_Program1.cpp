// Melanie Brecka

#include <iostream>
#include <ctime>
#include <random>
#include <string>
using namespace std;

int main() {
	int youScore = 0, AIscore = 0, pot = 0, roll, count;
	char hold;
	string again = "yes";
	srand(time(0));
	while (again == "yes") {
		count = 1;
		while (youScore < 50 || AIscore < 50) {
			if (youScore >= 50 || AIscore >= 50) {
				if (youScore >= 50) {
					cout << endl << "You win!!" << endl;
				}
				else {
					cout << endl << "AI wins!!" << endl;

				}
				break;
			}
			cout << endl << "SCORE     You: " << youScore << " AI: " << AIscore << endl << endl;
			if (count % 2 != 0) {
				cout << "Players Turn" << endl;
			}
			else {
				cout << "AI Turn" << endl;
			}
			roll = rand() % 6 + 1;
			hold = 'r';
			pot = 0;
			while (hold == 'r' || hold == 'R') {
				if (roll == 1) {
					cout << "Die Roll 1: BUST" << endl;
					pot = 0;
					break;
				}
				while (roll != 1) {
					pot += roll;
					if (count % 2 != 0) {
						cout << "Die Roll: " << roll << "    Pot: " << pot;
						cout << "     (R)oll again or (H)old? ";
						cin >> hold;
						if (hold == 'h' || hold == 'H') {
							youScore += pot;
							break;
						}
					}
					else {
						int num = rand() % 2;
						cout << "Die Roll: " << roll << "    Pot: " << pot << endl;
						if (num == 0) {
							hold = 'r';							}
						else {
							hold = 'h';
							AIscore += pot;
							break;
						}
					}
					roll = rand() % 6 + 1;
				}
				break;
			}
			count++;
		}
		cout << endl << "Do you want to play again? yes/no" << endl;
		cin >> again;
		youScore = 0;
		AIscore = 0;
	}
	return 0;
}