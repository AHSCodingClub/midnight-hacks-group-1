#include <iostream>
#include <string>
#include <cctype>
#include <regex>

using namespace std;

void ticTacToe() {
		
		string b[9][2];
		for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 2; j++) b[i][j] = "    ";
		}
		
		for (int i = 0; i < 9; i++) {
				string ans;
				do {
						if (i % 2 == 0) {
								cout << sisterName + "'s move: ";
								cin >> ans;
						}
						else ans = promptUser("Your move: ")
				} while (ans.length() <= 1 && 
					ans[0] != '1' &&
					ans[0] != '2' &&
					ans[0] != '3' &&
					ans[0] != '4' &&
					ans[0] != '5' &&
					ans[0] != '6' &&
					ans[0] != '7' &&
					ans[0] != '8' &&
					ans[0] != '9');

					int num = ans[0] - '1';
					if (i % 2 == 0) {
						b[num][0] = " \\/ ";
						b[num][1] = " /\\ ";
					}
					else {
						b[num][0] = " _  ";
						b[num][1] = "|_| ";
					}
				
					cout <<
					" __________________________\n"
					"|1 " + b[0][0] + "  |2 " + b[1][0] + "  |3 " + b[2][0] + "  |\n"
					"|  " + b[0][1] + "  |  " + b[1][1] + "  |  " + b[2][1] + "  |\n"
					" __________________________\n"
					"|4 " + b[3][0] + "  |5 " + b[4][0] + "  |6 " + b[5][0] + "  |\n"
					"|  " + b[3][1] + "  |  " + b[4][1] + "  |  " + b[5][1] + "  |\n"
					" __________________________\n"
					"|7 " + b[6][0] + "  |8 " + b[7][0] + "  |9 " + b[8][0] + "  |\n"
					"|  " + b[6][1] + "  |  " + b[7][1] + "  |  " + b[8][1] + "  |"
					"|________|________|________|";
		}
}

/*
BACKUP:
ans.length() <= 1 && 
					ans[0] != '1' &&
					ans[0] != '2' &&
					ans[0] != '3' &&
					ans[0] != '4' &&
					ans[0] != '5' &&
					ans[0] != '6' &&
					ans[0] != '7' &&
					ans[0] != '8' &&
					ans[0] != '9'
*/