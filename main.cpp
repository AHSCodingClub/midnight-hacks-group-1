#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const string artDoor = "   ┌─────┐\n   |     |\n   |    x|\n   |     |\n───└─────┘───";
const string artClock = "  _______\n /  12   \\\n|    |    |\n|9   |/  3|\n|    *    |\n|         |\n \\___6___/";
const string artWall = "┌────────────────────────────┐\n|             🕐             |\n|                            |\n|    |-P1-|       |-P2-|     |\n|                            |\n└────────────────────────────┘";
const string artFloor = "______________________________________\n___________|_____________|_____________|\n______|____________|____________|_______\n___________|_____________|_____________|\n______|____________|____________|_______\n________|________----------__|_____________|\n______|____________|____________|_______\n___________|_____________|_____________|\n______|____________|____________|_______";

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

void introduction() {
  	string name = promptUser("What's your name?");
  	string sisterName = promptUser("Enter a tragic sister name.");
  	cout << "Welcome, " << name << ".";

    cout << "Press ENTER to continue on all pages, unless otherwise specified";
	
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
		enterToContinue("Right here, in my bed, in my cozy bed, with " + sisterName  + "right here..");
		enterToContinue("--Wait--");
		enterToContinue("Where is she?");
		enterToContinue("Surely, surely, sur..ely");
		enterToContinue("Oh, you went downstairs to take out the trash! come on, just come back for a second, " + sisterName + ".");
		enterToContinue("Come back for a second please. I know breakfast is taking a little longer to make than expected! It's those ");
		
		
		
	enterToContinue("-- STOP. STOP! Don't do this to yourself again. You know where you really are. Just accept it.");
 
		// Play a game with sister   
    enterToContinue("You begin running away and you suddenly find yourself in a jungle. Now you're lost and you need to find a way to escape.");
}

void renderArt(int artName) {
    switch (artName) {
        case 0:
          cout << artDoor << "\n";
          break;
        case 1: 
          cout << artClock << "\n";
          break;
        //  Display the wall item
        case 2:
          cout << artWall << "\n";
          break;
        // Display floor
        case 3:
          cout << artFloor << "\n";
          break;
        default: break;
    }
}

void escapeRoom() {
  string userInput = "";
  renderArt(0);
    
  do {
    userInput = promptUser("Do you want to accept the escape room challenge? (y/n)");
  }
  while (userInput != "y" && userInput != "n");

  if (userInput == "y") {
    clearScreen();
    int count = 0; // Once count reaches the total number of items, inspection is over
    cout << "Find a way out by inspecting items.\n";

    // Display wall
    renderArt(2);
    do {
      userInput = promptUser("Which item do you want to inpect first? Enter a number. \n\t1. Clock\n\t2. Floor");
    }
    while (userInput != "1" && userInput != "2" && userInput != "99");

    if (userInput == "1") {
      renderArt(1);
      cout << "\nThe time is frozen at 1 o'clock. This might be important information to escape.\n";
    }
    else if (userInput == "2") {
			
	}
  }
  else{
    cout << "...\nGreat job.\n";
    return;
  }
}

int main() {
    introduction();
    escapeRoom();
    
    return 0;
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

Story:
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
*/