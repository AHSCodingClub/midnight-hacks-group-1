#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

string garbage;

const string artDoor = "   ┌─────┐\n   |     |\n   |    x|\n   |     |\n───└─────┘───";
const string artClock = "  _______\n /  12   \\\n|    |    |\n|9   |/  3|\n|    *    |\n|         |\n \\___6___/";
const string artWall = 
"┌─────────────────────────────┐\n"
"|   ┌──┐       🕐   ┌─────┐   |\n"
"|   └──┘            |     |   |\n"
"|       _____       |    x|   |\n"
"|      |__o__|      |     |   |\n"
"└──────└─────┘──────└─────┘───┘";

const string artFloor = 
"┌─────────────────────────────────────────────────┐\n"
"|      __             ________________            |\n"
"|   .''..''.         |  | #####  | ####           |\n"
"|  :._.''._.:        |  |_#####  |_#####___       |\n"
"|  :  \\__/  :        |_   ___     ___    |_\\      |\n"
"|   './  \\.'         |_|__/   \\___/   \\____|      |\n"
"|      ''                 \\___/   \\___/           |\n"
"|                                                 |\n"
"|                                                 |\n"
"|    ┌───────────┐                _               |\n"
"|    | _ | _ | _ |               /_\\              |\n"
"|    | _ | _ | _ |              |___|             |\n"
"|    | _ | _ | _ |               | |              |\n"
"|    └───────────┘               |_|              |\n"
"|    ┌───────────┐              /   \\             |\n"
"|    | O | _ | O |              |   |             |\n"
"|    | X | _ | X |              |   |             |\n"
"|    | X | X | X |              |___|             |\n"
"|    └───────────┘                                |\n"
"└─────────────────────────────────────────────────┘\n";
/*
const string artFloor = "______________________________________\n___________|_____________|_____________|\n______|____________|____________|_______\n___________|_____________|_____________|\n______|____________|____________|_______\n________|________----------__|_____________|\n______|____________|____________|_______\n___________|_____________|_____________|\n______|____________|____________|_______";
*/
const string artDresser = " _______\n|_o_|_o_|\n|___o___|\n|___o___|\n|___o___|\n||   ||";
const string artOldRoomFloor = "┌─────────────────────────────────────────────────┐\n|     ________        _______________             |\n|    |__|__|__|      | | #####  | ####            |\n|    |__|__|__|      | |_#####  |_#####___        |    \n|    |__|__|__|      | _  ___     ___    |_       |\n|                    | _|/   \\___/   \\____|       |\n|                        \\___/   \\___/            |\n|                                                 |\n|                                                 |\n|    ┌───────────┐                                |\n|    | _ | _ | _ |                                |\n|    | _ | _ | _ |                                |\n|    | _ | _ | _ |                                |\n|    └───────────┘                                |\n|    ┌───────────┐                                |\n|    | _ | _ | X |                                |\n|    | O | _ | _ |                                |\n|    | _ | _ | _ |                                |\n|    └───────────┘                                |\n└─────────────────────────────────────────────────┘";
const string artThreeDoors = "   ┌─────┐   ┌─────┐   ┌─────┐  \n   |  1  |   |  2  |   |  3  |\n   |    x|   |    x|   |    x|\n   |     |   |     |   |     |\n───└─────┘───└─────┘───└─────┘───";

const string artPainting = "╬════════════════╬\n║──────────░░░░░░║\n║──────────░░░░░░║\n║─▐▀▀█─────░░░░░░║\n║─▐▄─▄▌──▄─▄─────║\n║──▐▐────│─┼─────║\n║████████████████║\n╬════════════════╬";

const string artPaintingCompleted = "╬════════════════╬\n║──────────░xxxx░\n║\n║──────────░x░░x░║\n║─▐▀▀█─────░xxxx░║\n║─▐▄─▄▌──▄─▄─────║\n║──▐▐────│─┼─────║\n║████████████████║\n╬════════════════╬";

const string artFuneral = "        _.---,._,'\n       /' _.--.<\n         /'     `'\n       /' _.---._____\n       \\.'   ___, .-'`\n\n           /'    \\\\             .\n         /'       `-.          -|-\n        |                       |\n        |                   .-'~~~`-.\n        |                 .'         `.\n        |                 |           |\n        |                 |           |\n        |                 |           |\n         \\              \\\\|           |//\n   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

const string artSoccer = 
"    __\n"
" .'\".'\"'.\n"
":._.""._.:\n"
":  \\__/  :\n"
" './  \\.'\n"
"    \"\"\n"
    "\"\"";

const string artToyCar = 
" ________________\n"
"|  | #####  | ####\n"
"|  |_#####  |_#####___\n"
"|_   ___     ___    |_\\\n"
"|_|__/   \\___/   \\____|\n"
"     \\___/   \\___/     \n";

const string riddle = "There is one thing that goes around the house and also inside the house but it never touches anything. What is it?";

string sisterName;

string promptUser(string prompt) {
  string userInput;

  cout << prompt + "\n> ";
  cin >> userInput;

  return userInput;
}

void clearScreen() {
  cout << "\x1B[2J\x1B[H";
}

void enterToContinue(string s) {
  cout << s;
  cin.ignore();
  clearScreen();
}

void enterToContinue(string s, bool clear) {
  cout << s;
  cin.ignore();

  if (clear) {
    clearScreen();
  }
}

void introduction() {
  sisterName = promptUser("Enter a tragic sister name: ");

  enterToContinue("You wake up..");
  enterToContinue("You're lying down.");
  enterToContinue("You must be.. lying down in your cozy bed.. yes, you're in your room and.. that stomping?");
  enterToContinue("It's your sister!");
  enterToContinue("It's " + sisterName + ", yes! And she's bringing breakfast! The most beautiful breakfast you've ever seen!");
  enterToContinue("You can almost taste it");
  enterToContinue("It smells like, it smells like... what does it smell like?");
  enterToContinue("Oh well...");
  enterToContinue("It's a beautiful day, and you feel the sun beaming down on your skin");
  enterToContinue("You feel that.. you feel the feeling that sun makes when it beams down on your skin. Whatever it is, you feel it. You do.");
  enterToContinue("Yes! And your sister, " + sisterName + ", is here with you. Just like the good old times!");
  enterToContinue("...");
  enterToContinue("*sobbing*");
  enterToContinue("...");
  enterToContinue("--Good old times?");
  enterToContinue("What good old times?");
  enterToContinue("New times are good too! All times are great, including this one!");
  enterToContinue("Indeed, this is the best time ever, right now.");
  enterToContinue("Right here, in my bed, in my cozy bed, with " + sisterName + " right here..");
  enterToContinue("--Wait--");
  enterToContinue("Where is she?");

  enterToContinue("Surely--");
  enterToContinue("She's probably downstairs, that's all.");
  enterToContinue("Breakfast is taking a little longer than expected, that's all.");
	enterToContinue("You're in your room, and you're waiting for " + sisterName + " to finish making breakfast, that's all.");
  enterToContinue("THAT.");
  enterToContinue("IS.");
  enterToContinue("ALL.");
  enterToContinue("...");
}

void renderArt(int artName) {
  switch (artName) {
    // Display the door
  case 0:
    cout << artDoor;
    break;

    // Display the clock
  case 1:
    cout << artClock;
    break;

    // Display the wall item
  case 2:
    cout << artWall;
    break;

  // Display the floor
  case 3:
    cout << artFloor;
    break;

  // Display the dresser      
  case 4:
    cout << artDresser;
    break;
  
  // Display the old room's floor
  case 5:
    cout << artOldRoomFloor;
    break;

  // Display the three doors
  case 6:
    cout << artThreeDoors;
    break;
  
  // Display the painting
  case 7:
    cout << artPainting;
    break;

  // Display the completed painting
  case 8:
    cout << artPaintingCompleted;
    break;
  
  // Display the funeral
  case 9:
    cout << artFuneral;
    break;

  // Display the soccer ball
  case 10:
    cout << artSoccer;
    break;

  // Display the toy car
  case 11:
    cout << artToyCar;
    break;
  
  default:
    break;
  }

  cout << "\n";
}

bool isInt(string s) {
	bool ret = true;
    
	for (char c : s) {
		if (
			c != '0' &&
			c != '1' &&
            c != '2' &&
            c != '3' &&
            c != '4' &&
            c != '5' &&
            c != '6' &&
            c != '7' &&
            c != '8' &&
            c != '9'
        ) ret = false;
	}
	return ret;
}

// Tic-Tac-Toe
void ticTacToe() {
  string b[9][2];
	
  const string x0 = " \\/ ";
  const string x1 = " /\\ ";
  const string o0 = " _  ";
  const string o1 = "|_| ";
  const string blank = "    ";
  
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 2; j++) b[i][j] = blank;
  }

	clearScreen();
	cin.ignore();
	enterToContinue("You can't use the O's. You just can't. They were--");
	enterToContinue("They are--");
	enterToContinue("For " + sisterName + ".");

	bool completed = false;

  while (true) {

    string ans;
    do {
			ans = promptUser("\n\nYour move (1-9) or stop playing (s): ");
    } while (
			ans.length() != 1 &&
			ans[0] != '1' &&
			ans[0] != '2' && 
			ans[0] != '3' && 
			ans[0] != '4' && 
			ans[0] != '5' &&
			ans[0] != '6' &&
			ans[0] != '7' && 
			ans[0] != '8' &&
			ans[0] != '9' &&
			ans[0] != 's');
		
		if (ans[0] == 's') break;
		
    int num = ans[0] - '1';
		b[num][0] = x0;
    b[num][1] = x1;


    clearScreen();

    cout <<
        " __________________________\n"
        "|1 " + b[0][0] + "  |2 " + b[1][0] + "  |3 " + b[2][0] + "  |\n"
        "|  " + b[0][1] + "  |  " + b[1][1] + "  |  " + b[2][1] + "  |\n"
        "|________|________|________|\n"
        "|4 " + b[3][0] + "  |5 " + b[4][0] + "  |6 " + b[5][0] + "  |\n"
        "|  " + b[3][1] + "  |  " + b[4][1] + "  |  " + b[5][1] + "  |\n"
        "|________|________|________|\n"
        "|7 " + b[6][0] + "  |8 " + b[7][0] + "  |9 " + b[8][0] + "  |\n"
        "|  " + b[6][1] + "  |  " + b[7][1] + "  |  " + b[8][1] + "  |\n"
        "|________|________|________|";
  }
	if (!completed) return false;
  renderArt(8);
  enterToContinue("Wait--");
  enterToContinue("This looks interesting..");
  enterToContinue("Indeed, it looks like it would fit quite nicely in the painting.");
}

void escapeRoom() {
  bool painting = false;
  bool ticTacToe = false;
  bool escape = false;
  string userInput = "y";
  
  if (userInput == "y") {
    clearScreen();

    while (!escape) {
      // Display wall
      clearScreen();
      renderArt(2);

      do {
        userInput = promptUser("Which item do you want to inspect? Enter a number. \n\t1. Clock\n\t2. Floor\n\t3. Door\n\t4. Dresser\n\t5. Painting");
      } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5");
      clearScreen();
      if (userInput == "1") {
        renderArt(1);
        cout << "\nThe time is frozen at 1 o'clock.\n";
        cin.ignore();
      } else if (userInput == "2") {
        renderArt(3);
        string toyInspect;
        do {
            toyInspect = promptUser("Which toy do you want to inspect? Enter a number. \n\t1. Soccer ball\n\t2. Toy car\n\t3. Tic-Tac-Toe (top)\n\t4. TicTacToe (bottom)\n\t5. Rocket");
        } while (toyInspect != "1" && toyInspect != "2" && toyInspect != "3" && toyInspect != "4" && toyInspect != "5");

          if (toyInspect == "1") {
            renderArt(10);
            cout << "You've never liked soccer. But right now, you want to play. You want to play with " << sisterName << ". Maybe after breakfast.";
            cin.ignore();
          } else if (toyInspect == "2") {
            renderArt(11);
            cout << "You got this toy car for christmas and " << sisterName << " always played with it instead of you.\n";
            cout << "You remember getting into many arguments because it was YOUR toy, but now you wish that you let her play with it more..";
            cin.ignore();
          } else if (toyInspect == "3") {
            ticTacToe();
            ticTacToe = true;
          } else if (toyInspect == "4") {
            enterToContinue("It was no use trying to teach " + sisterName + " tic-tac-toe. She just drew pictures on the board anyways.");
          } else if (toyInspect == "5") {
            enterToContinue("You were going to go to the moon with " + sisterName + ".");
						enterToContinue("--What?");
						enterToContinue("You still are. Indeed, you'll go tommorow. No, today. After breakfast. You and " + sisterName);
          }
    
        enterToContinue("", false);
        cin.ignore();
      } else if (userInput == "3") {
        renderArt(0);

        if (painting && ticTacToe) {
          escape = true;
        } else {
          enterToContinue("You're missing something...");
        }

  
        if (painting && ticTacToe) {          
          enterToContinue("You escaped!");
          enterToContinue("You look behind you into the room.");
          enterToContinue("It looks oddly familiar...");
          enterToContinue("You realise that this used to be your sister's room, but now-");
          enterToContinue(" it's empty.");
        } else {
          enterToContinue("You can't escape yet.");
        }
      } else if (userInput == "4") {
        renderArt(4);

        if (!painting) {
          painting = true;
        
          enterToContinue("You open a drawer in the dresser", false);
  
          //what do you find?          
        }   
      } else {
          enterToContinue("You open the drawer in the dresser, and you don't find anything...BECAUSE YOU ALREADY FOUND IT", false);
        }
  
        if (userInput == "5"){
          renderArt(4);
          
          enterToContinue("Was that-");
          enterToContinue("Your sister's painting?");
          enterToContinue("Why is it incomplete?");

          do {
            userInput = promptUser("Would you like to start the painting riddle? (y/n)");
          } while (userInput != "y" && userInput != "n");
				
          if (userInput == "y"){
            clearScreen();
            
            // Show painting
            renderArt(7);

            userInput = promptUser(riddle);
            for (char &c : userInput) c = tolower(c);
            while (userInput != "sun") {
                do {
                    userInput = promptUser("Good try. Try Again (y/n)?");
                } while (userInput != "y" && userInput != "n");
                if (userInput == "y") {
									clearScreen();
									renderArt(7);
									userInput = promptUser(riddle);
									for (char &c : userInput) c = tolower(c);
                }
                else break;
            }
          
            if (userInput == "sun") {
						  clearScreen();
						  cin.ignore();
              enterToContinue("Oh right-");
              enterToContinue("You were supposed to complete it with " + sisterName + ". Together.");
              enterToContinue("It needs to be completed. That's all. She'll come back after you complete it. Surely.");
            }
          }
        }
        
        cin.ignore();
      }

    cout << "...great job.\n";
    return;
  }
}
void leavingRoom() {
  enterToContinue("OK, Lets get out of this room...");
  enterToContinue("(You look for the Door)");
  cout<<"There are three doors..."


/// nobody touch this it is delicate.
void threeDoors() {
	int seg = 0;
	string ans;

	while(ans != "b" || seg != -1) {
		string one = to_string(seg * 3 + 1);
		string two = to_string(seg * 3 + 2);
		string three = to_string(seg * 3 + 3);

		string a[3][3];
		for (int i = 0; i < 3; i++) {
			string nstr = to_string(seg * 3 + 1 + i);
			if (nstr.length() == 1) {
				a[i][0] = " ";
				a[i][1] = " ";
				a[i][2] = nstr[0];
			}
			else if (nstr.length() == 2) {
				a[i][0] = " ";
				a[i][1] = nstr[0];
				a[i][2] = nstr[1];
			}
			else {
				a[i][0] = nstr[0];
				a[i][1] = nstr[1];
				a[i][2] = nstr[2];
			}
		}

		clearScreen();
		cout << 
		"	        ┌─────┐   ┌─────┐   ┌─────┐\n"  
		"	        | " + a[0][0] + a[0][1] + a[0][2] + " |   | " + a[1][0] + a[1][1] + a[1][2] + " |   | " + a[2][0] + a[2][1] + a[2][2] + " |\n"
		"<--back(b)  |    x|   |    x|   |    x|  next(n)-->\n"
		"            |     |   |     |   |     |\n"
		"────────────└─────┘───└─────┘───└─────┘────────────\n";
		cin >> ans;
		if (tolower(ans[0]) == 'n') seg++;
		else if (tolower(ans[0]) == 'b') seg--;
		else if (isInt(ans)) {
			int ansI = 0;
			for (char c : ans) {
				ansI *= 10;
				ansI += c - '0';
			}
			clearScreen();
			cin.ignore();
			if (ansI < seg * 3 + 1 || ansI > seg * 3 + 3) {
				cout << "Hmm.. where is that room?" << endl;
				cin.ignore();
			}
			else {
				cout << "Room " + ans + " is empty. " + sisterName + " must be in the next room. She has to be." << endl;
				cin.ignore();
			} 
		}
	}
}

void context() {
  enterToContinue("I thought I escaped..");
  enterToContinue("You look around you and you're still in the same room as before.");
  enterToContinue("But now, there's toys on the floor..");

  renderArt(5);
  enterToContinue("How did these get here?");

  renderArt(5);
  enterToContinue("OHH " + sisterName + " we must've been playing with them earlier!");

  renderArt(5);
  enterToContinue("Why isn't " + sisterName + "here? We need to finish playing..");

  renderArt(5);
  enterToContinue("I might as well finish the games on my own...");
  enterToContinue("I'll play tic-tac-toe first.");
}

void ending() {
  enterToContinue("FINALLY");
  enterToContinue("WHERE IS SHE??");
  enterToContinue("She has to be here somewhere...");
  // funeral scene at door 100
  for (int i = 0; i < 100; ++i) { 
    threeDoors();    
  }
  renderArt(9);
}

int main() {
  introduction();
  escapeRoom();
  context();
  ticTacToe();
  threeDoors();
  //ending();

  return 0;

  // create a funeral scene and picture with (Best) Clock in the picture of the funeral after you complete the 3 doors

}

/*
What if: 
- Trapped in a jungle, complete adventure to get out
- Riddles (with graphics and simple animations)
- Escape room
- Drone 0679:
- You wake up on a hard, cold, floor. Your muscles are sore and can't feel anything from the neck up. Somehow, your eyes blink open. 
- IMAGE OF ROBOT

Hello. I am 0670. Please accept my challenge.
- Accept / Decline.

Great

Setup:
- start with an animation
Hey.. there isn't any time for that right now..

Drone 0679 - 

Graphics/Animations:
- Introduction
    - Trees?
    - Blurred trees? (to symbolize running)

Games:
- [x] Tic-Tac-Toe
- [ ] 3 doors
- 

Stoescape roomry:
  Why did the sister die
  - Character finds out after challenges and is able to move on from death
Escape room:
use key and code to escape
- Clock
  - time of death
  - 1 = code for door to escape
- Floor
  - loose floorboard
  - need a tool to look under floor
  - if you have the tool, discover key to door
- Drawers
  - look in the drawers to get tool
- Painting
  - Was created by sister (character reflects and is helped with moving on)

---
introduction():
    enterToContinue("You wake up..");
		enterToContinue("You're lying down.");
		enterToContinue("You must be.. lying down in your cozy bed.. yes, you're in your room and.. that stomping?");
    enterToContinue("It's your sister!");
		enterToContinue("It's " + sisterName + ", yes! She's bringing breakfast! The most beautiful breakfast you've ever seen!");
		enterToContinue("You can almost see it..");
		enterToContinue("It smells like... the most wonderful thing you've ever smelled!");
		enterToContinue("You can almost smell it, wafting up through the stairs..");
		enterToContinue("It's the most wonderful morning you've ever lived!");
		enterToContinue("You can almost feel it..");
		enterToContinue("You're almost alive.");
		enterToContinue("Yes! And " + sisterName + " is here with you. Just like the good old times!");
		enterToContinue("...");
		enterToContinue("*sobbing*");
		enterToContinue("...");
		enterToContinue("--Good old times?");
		enterToContinue("What good old times?");
		enterToContinue("New times are good too! All times are great, including this one!");
		enterToContinue("Indeed, this is the best time ever, right now.");
		enterToContinue("Right here, in my bed, in my cozy bed, with " + sisterName + "right here..");
		enterToContinue("--Wait--");
		enterToContinue("Where is she?");
		enterToContinue("Surely--");
		enterToContinue("Surely--");
		enterToContinue("Surely!--");
		enterToContinue("She's fine,");
		enterToContinue("Surely, she's fine, right?");
		enterToContinue("She's fine!");
		enterToContinue("SHE'S FINE GODDAMIT");
		enterToContinue("SHE'S THE MOST FINE I'VE EVER FUCKING SEEN");
		enterToContinue("She's fine.");;
		enterToContinue("She's still downstairs, that's all.");
		enterToContinue("Breakfast is taking a little longer than expected, that's all.");
		enterToContinue("It's those new eggs, that's all");
		enterToContinue("That's all it is, silly me! It's those new eggs. Yes, those new eggs take longer to cook. I'll never buy them again. I'll make sure of it.");
		enterToContinue("I'm in my room, and I'm waiting for her to finish cooking breakfast, that's all. THAT. IS. ALL.");

		enterToContinue("Surely, surely, surely..");
		enterToContinue("Oh, you went downstairs to take out the trash! come on, just come back for a second, " + sisterName + ".");
		enterToContinue("Come back for a second please. I know breakfast is taking a little longer to make than expected! It's those ");
*/
// tic tac toe, 3 doors, and 

  // enterToContinue("-- STOP. STOP! Don't do this to yourself again. You know where you really are. Just accept it.");

  // Play a game with sister   
  //  enterToContinue("You begin running away and you suddenly find yourself in a jungle. Now you're lost and you need to find a way to escape.");ticTac