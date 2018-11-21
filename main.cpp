#include<stdio.h>
#include<stdlib.h>                         //for system(),rand() and all
#include<string.h>
#include<windows.h>                        //getstdhandle/consoleptr
#include<graphics.h>                         //cstlib.h
#include<dos.h>
#include<time.h>
#include<iostream>
#include<vector>
#include<stack>
#include<chrono>
#include<fstream>
#include<algorithm>
#define delay5 Sleep(50)

using namespace std;
using namespace chrono;
fstream fileObj;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void learnTyping();
void credit();
void playGame();
void showHighScores();

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition);
}

void SetColor(int ForgC)
{
   WORD wColor;

   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;

                     //We use csbi for the wAttributes word.
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
               //Mask out all but the background attribute, and add in the forgournd     color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
   }
   return;
}

class Keyboard
{
private:
  int choice;
public:
  Keyboard()
  {
      choice = 1;
  }

  void qwerty(int option)
  {
    if(option == 1)
    {
      system("cls");
      gotoXY(20,5);printf(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");delay5;
      gotoXY(20,6);printf("| ~ |   |   |   |   |   |   |   |   |   |   |   |   | <-    |\n");delay5;
      gotoXY(20,7);printf("|---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n");delay5;
      gotoXY(20,8);printf("| ->| | Q | W | E | R | T | Y | U | I | O | P | { | } |  \\  |\n");delay5;
      gotoXY(20,9);printf("|-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n");delay5;
      gotoXY(20,10);printf("| Caps |   |   |   |   |   |   |   |   |   |   |   |  Enter |\n");delay5;
      gotoXY(20,11);printf("|------'---'---'---'---'---'---'---'---'---'---'---'--------|\n");delay5;
      gotoXY(20,12);printf("| Shift  |   |   |   |   |   |   |   |   |   |   |    Shift |\n");delay5;
      gotoXY(20,13);printf("|--------'----'---'---'---'---'---'---'---'---'------'------|\n");delay5;
      gotoXY(20,14);printf("| ctrl |  Fn  | alt |                  | alt  |  [+] | ctrl |\n");delay5;
      gotoXY(20,15);printf("'------'------'-----'------------------'------'------'------'\n");delay5;

      gotoXY(20,20);printf(" On an English keyboard, the QWERTY row keys are Q-W-E-R and U-I-O-P");
      cin.get();
      gotoXY(20,21);printf(" The little finger of the left hand sits on the Q, the ring finger on the W,");
      cin.get();
      gotoXY(20,22);printf(" the middle finger on the E and the pointer on the R.");
      cin.get();
      gotoXY(20,23);printf(" The pointer of the right hand takes the U, the middle finger the I,");
      cin.get();
      gotoXY(20,24);printf(" the ring finger the O and the little finger of the left");
      cin.get();
      gotoXY(20,25);printf(" hand rests on the P key.Often, the R and J home row keys have");
      cin.get();
      system("cls");
      delay5;
      gotoXY(45,25);system("pause");
      system("cls");

    }

    else if(option == 2)
    {
      system("cls");
      gotoXY(20,5);printf(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");delay5;
      gotoXY(20,6);printf("| ~ |   |   |   |   |   |   |   |   |   |   |   |   |  <-   |\n");delay5;
      gotoXY(20,7);printf("|---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n");delay5;
      gotoXY(20,8);printf("| ->| |   |   |   |   |   |   |   |   |   |   |   |   |  \\  |\n");delay5;
      gotoXY(20,9);printf("|-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n");delay5;
      gotoXY(20,10);printf("| Caps | A | S | D | F | G | H | J | K | L | ; | ' |  Enter |\n");delay5;
      gotoXY(20,11);printf("|------'---'---'---'---'---'---'---'---'---'---'---'--------|\n");delay5;
      gotoXY(20,12);printf("| Shift  |   |   |   |   |   |   |   |   |   |   |    Shift |\n");delay5;
      gotoXY(20,13);printf("|--------'----'---'---'---'---'---'---'---'---'------'------|\n");delay5;
      gotoXY(20,14);printf("| ctrl |  Fn  | alt |                  | alt  |  [+] | ctrl |\n");delay5;
      gotoXY(20,15);printf("'------'------'-----'------------------'------'------'------'\n");delay5;

      gotoXY(20,20);printf(" On an English keyboard, the home row keys are A-S-D-F and J-K-L-;");
      cin.get();
      gotoXY(20,21);printf(" The little finger of the left hand sits on the A, the ring finger on the S,");
      cin.get();
      gotoXY(20,22);printf(" the middle finger on the D and the pointer on the F.");
      cin.get();
      gotoXY(20,23);printf(" The pointer of the right hand takes the J, the middle finger the K,");
      cin.get();
      gotoXY(20,24);printf(" the ring finger the L and the little finger of the left");
      cin.get();
      gotoXY(20,25);printf(" hand rests on the ; key.Often, the F and J home row keys have");
      cin.get();
      gotoXY(20,26);printf(" raised lines on them, in order to guide the hand to correct finger placement.");
      cin.get();
      gotoXY(20,27);printf(" A set of upward, downward and side-to-side reaching movements governs typing,");
      cin.get();
      gotoXY(20,28);printf(" with each finger responsible for a series of keys in the direct radius.");
      cin.get();
      system("cls");
      delay5;
      gotoXY(45,25);system("pause");
      //asdfgh
      system("cls");
    }

    else if(option == 3)
    {
      system("cls");
      gotoXY(20,5);printf(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");delay5;
      gotoXY(20,6);printf("| ~ |   |   |   |   |   |   |   |   |   |   |   |   | <-    |\n");delay5;
      gotoXY(20,7);printf("|---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n");delay5;
      gotoXY(20,8);printf("| ->| |   |   |   |   |   |   |   |   |   |   |   |   |  \\  |\n");delay5;
      gotoXY(20,9);printf("|-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n");delay5;
      gotoXY(20,10);printf("| Caps |   |   |   |   |   |   |   |   |   |   |   |  Enter |\n");delay5;
      gotoXY(20,11);printf("|------'---'---'---'---'---'---'---'---'---'---'---'--------|\n");delay5;
      gotoXY(20,12);printf("| Shift  | Z | X | C | V | B | N | M | < | > | ? |    Shift |\n");delay5;
      gotoXY(20,13);printf("|--------'----'---'---'---'---'---'---'---'---'------'------|\n");delay5;
      gotoXY(20,14);printf("| ctrl |  Fn  | alt |                  | alt  |  [+] | ctrl |\n");delay5;
      gotoXY(20,15);printf("'------'------'-----'------------------'------'------'------'\n");delay5;

      gotoXY(20,20);printf(" On an English keyboard, the bottom row keys are Z-X-C-V and N-M");
      cin.get();
      gotoXY(20,21);printf(" The little finger of the left hand sits on the Z, the ring finger on the X,");
      cin.get();
      gotoXY(20,22);printf(" the middle finger on the C and the pointer on the V.");
      cin.get();
      gotoXY(20,23);printf(" The pointer of the right hand takes the N, the middle finger the M,");
      cin.get();
      gotoXY(20,24);printf(" hand rests on the ; key on the  home row");
      cin.get();
      gotoXY(20,25);printf(" with each finger responsible for a series of keys in the direct radius.");
      cin.get();
      system("cls");
      delay5;
      gotoXY(45,25);system("pause");
      system("cls");
    }

    else if(option == 4)
    {
      system("cls");
      gotoXY(20,5);printf(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");delay5;
      gotoXY(20,6);printf("| ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | + | <-    |\n");delay5;
      gotoXY(20,7);printf("|---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n");delay5;
      gotoXY(20,8);printf("| ->| |   |   |   |   |   |   |   |   |   |   |   |   |  \\  |\n");delay5;
      gotoXY(20,9);printf("|-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n");delay5;
      gotoXY(20,10);printf("| Caps |   |   |   |   |   |   |   |   |   |   |   |  Enter |\n");delay5;
      gotoXY(20,11);printf("|------'---'---'---'---'---'---'---'---'---'---'---'--------|\n");delay5;
      gotoXY(20,12);printf("| Shift  |   |   |   |   |   |   |   |   |   |   |    Shift |\n");delay5;
      gotoXY(20,13);printf("|--------'----'---'---'---'---'---'---'---'---'------'------|\n");delay5;
      gotoXY(20,14);printf("| ctrl |  Fn  | alt |                  | alt  |  [+] | ctrl |\n");delay5;
      gotoXY(20,15);printf("'------'------'-----'------------------'------'------'------'\n");delay5;
      cin.get();
      gotoXY(20,20);printf(" On an English keyboard, the num row keys are numbers from 0-9");
      cin.get();
      gotoXY(20,21);printf(" The little finger of the left hand sits on the 1, the ring finger on the 2,");
      cin.get();
      gotoXY(20,22);printf(" the middle finger on the 3 and the pointer on the 4.");
      cin.get();
      gotoXY(20,23);printf(" The pointer of the right hand takes the 7, the middle finger the 8,");
      cin.get();
      gotoXY(20,24);printf(" the ring finger the 9 and the little finger of the left");
      cin.get();
      gotoXY(20,25);printf(" hand rests on the 0 key.Often, the - and + keys are excluded from");
      cin.get();
      gotoXY(20,26);printf(" the rest of the num row");
      cin.get();
      system("cls");
      delay5;
      gotoXY(45,25);system("pause");
      system("cls");
    }
  }

};

class Player
{
private:
  float score;
  char name[20];
  int difficulty;
public:
  Player(char pName[]="N00B1E")
  {
      score = 0.3;
      difficulty = 10;
      strcpy(name,pName);
  }
  void displayScore(float timeTaken,stack<string>correct,stack<string>incorrect)
  {
      float totalWords = correct.size() + incorrect.size();
      float accuracy = (correct.size() / totalWords) * 100;
      float speed    = (correct.size() / timeTaken) * 100;
      score = (accuracy * correct.size());

      gotoXY(40,8);
      printf("Name = %s",name);
      Sleep(300);
      gotoXY(40,11);
      printf("Typing speed = %f",speed);
      Sleep(300);
      gotoXY(40,13);
      printf("Typing accuracy = %f",accuracy);
      Sleep(300);
      gotoXY(40,15);
      Sleep(300);
      printf("Total score = %f",score);
//      printf("Total score = %f",accuracy);
//      Sleep(300);
      Sleep(5000);
      system("cls");
  }

  void setDifficulty(int setDifficulty,char pName[])
  {
      if(setDifficulty>0)
        setDifficulty = 20;
      difficulty = setDifficulty;
      strcpy(name,pName);
  }

  void playGame()
  {
      stack<string> correctWords;
      stack<string> incorrectWords;
      vector<string> sentences;
      sentences.push_back("Sphinx");
      sentences.push_back("black");
      sentences.push_back("quartz");
      sentences.push_back("judge");
      sentences.push_back("vow");
      sentences.push_back("Jackdaws");
      sentences.push_back("love");
      sentences.push_back("sphinx");
      sentences.push_back("quartz");
      sentences.push_back("Pack");
      sentences.push_back("box");
      sentences.push_back("five");
      sentences.push_back("dozen");
      sentences.push_back("liquor");
      sentences.push_back("jugs");
      sentences.push_back("quick");
      sentences.push_back("onyx");
      sentences.push_back("goblin");
      sentences.push_back("jumps");
      sentences.push_back("over");
      sentences.push_back("lazy");
      sentences.push_back("dwarf");
      sentences.push_back("fjord");
      sentences.push_back("bank");
      sentences.push_back("glyphs");
      sentences.push_back("vext");
      sentences.push_back("quiz");
      sentences.push_back("razorback");
      sentences.push_back("jumping");
      sentences.push_back("frogs");
      sentences.push_back("level");
      sentences.push_back("piqued");
      sentences.push_back("gymnasts");
      sentences.push_back("Cozy");
      sentences.push_back("lummox");
      sentences.push_back("gives");
      sentences.push_back("smart");
      sentences.push_back("squid");
      sentences.push_back("job");
      sentences.push_back("pen");
      srand(time(0));
      char typedWord[20];
      auto timeStart = high_resolution_clock::now();
      while(difficulty--)
      {
          char testCase[20];
          int random = rand() % 35;
          strcpy(testCase,sentences[random].c_str());
          system("cls");
          gotoXY(50,10);
          printf("Q-\" %s \"\n",testCase);
          gotoXY(50,12);
          printf("A-  ");
          scanf("%s",&typedWord);
          if(strcmp(typedWord,testCase)==0)
              correctWords.push(testCase);
          else
              incorrectWords.push(testCase);
      }
      cin.get();
      auto timeEnd = high_resolution_clock::now();
      int timeTaken = duration_cast<seconds>(timeEnd - timeStart).count();
      system("cls");
      displayScore(timeTaken,correctWords,incorrectWords);
      fileObj.open("scores.txt",ios::app);
      if(!fileObj.is_open())
      {
        printf("file failed\n");
        exit(1);
      }
      fileObj<<name<<"\t"<<score<<"\n";
      fileObj.close();
  }
}playerObj;

int main()
{
    int menu_item=0, x=7;
    gotoXY(45,25);system("pause");
    Sleep(500);
    system("cls");
    gotoXY(48,7); printf("*");

	while(1==1)
	{
        gotoXY(50,7);  printf(" Play TypeRacer");
		gotoXY(50,8);  printf(" Learning the art");
		gotoXY(50,9);  printf(" Game Settings");
		gotoXY(50,10); printf(" High-scores");
		gotoXY(50,11); printf(" Credits");
		gotoXY(50,12); printf(" Exit");
		system("pause>nul");

		if(GetAsyncKeyState(VK_DOWN) && x != 12) //down button pressed
		{
			gotoXY(48,x); printf("  ");
			x++;
			gotoXY(48,x); printf("*");
			menu_item++;
			continue;
		}

		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
		{
			gotoXY(48,x);
            printf("  ");
			x--;
			gotoXY(48,x);
            printf("*");
			menu_item--;
			continue;
		}

		if(GetAsyncKeyState(VK_RETURN))
        { // Enter key pressed
			switch(menu_item)
            {
				case 0:
                {
                    system("cls");
                    gotoXY(50,7);
                    printf(" Play TypeRacer");
                    Sleep(700);
                    system("cls");
                    playerObj.playGame();
                    break;
				}

				case 1:
                {
                    gotoXY(35,5);
                    system("cls");
                    gotoXY(50,8);
                    printf(" Learning the art");
                    Sleep(700);
                    system("cls");
                    learnTyping();
                    break;
				}

				case 2:
                {
                    system("cls");
                    gotoXY(50,9);
                    printf(" Game Settings");
                    Sleep(700);
                    system("cls");
                    int difficulty;
                    char playerName[20];
                    gotoXY(20,8);printf("MMMMMMMMM             MMMMMMMMM                             DDDDDDDD\n");delay5;
                    gotoXY(20,9);printf("M::::::::M           M::::::::M                             d::::::d\n");delay5;
                    gotoXY(20,10);printf("M:::::::::M         M:::::::::M                             d:::::d             \n");delay5;
                    gotoXY(20,11);printf("M::::::::::M       M::::::::::M   ooooooooooo       ddddddddd:::::d     eeeeeeeeeeee        \n");delay5;
                    gotoXY(20,12);printf("M:::::::::::M     M:::::::::::M oo:::::::::::oo   dd::::::::::::::d   ee::::::::::::ee       \n");delay5;
                    gotoXY(20,13);printf("M:::::::M::::M   M::::M:::::::Mo:::::::::::::::o d::::::::::::::::d  e::::::eeeee:::::ee     \n");delay5;
                    gotoXY(20,14);printf("M::::::M M::::M M::::M M::::::Mo:::::ooooo:::::od:::::::ddddd:::::d e::::::e     e:::::e     \n");delay5;
                    gotoXY(20,15);printf("M::::::M  M::::M::::M  M::::::Mo::::o     o::::od::::::d    d:::::d e:::::::eeeee::::::e     \n");delay5;
                    gotoXY(20,16);printf("M::::::M   M:::::::M   M::::::Mo::::o     o::::od:::::d     d:::::d e:::::::::::::::::e      \n");delay5;
                    gotoXY(20,17);printf("M::::::M    M:::::M    M::::::Mo::::o     o::::od:::::d     d:::::d e::::::eeeeeeeeeee       \n");delay5;
                    gotoXY(20,18);printf("M::::::M     MMMMM     M::::::Mo::::o     o::::od:::::d     d:::::d e:::::::e                \n");delay5;
                    gotoXY(20,19);printf("M::::::M               M::::::Mo:::::ooooo:::::od::::::ddddd::::::dde::::::::e               \n");delay5;
                    gotoXY(20,20);printf("M::::::M               M::::::Mo:::::::::::::::o d:::::::::::::::::d e::::::::eeeeeeee       \n");delay5;
                    gotoXY(20,21);printf("M::::::M               M::::::M oo:::::::::::oo   d:::::::::ddd::::d  ee:::::::::::::e       \n");delay5;
                    gotoXY(20,22);printf("MMMMMMMM               MMMMMMMM   ooooooooooo      ddddddddd   ddddd    eeeeeeeeeeeeee       \n");delay5;
                    gotoXY(45,25);printf("Type in a 0 for EASY or 1 for HARD");
                    gotoXY(45,26);scanf("%d",&difficulty);
                    gotoXY(45,27);printf("Type in your Name");
                    gotoXY(45,28);scanf("%s",&playerName);
                    playerObj.setDifficulty(difficulty,playerName);
                    system("cls");
                    break;
				}

				case 3:
                {
                    system("cls");
                    gotoXY(50,10);
                    printf(" High-scores");
                    Sleep(700);
                    showHighScores();
                    break;
				}

				case 4:
                {
                    system("cls");
                    gotoXY(50,11);
                    printf(" Credits");
                    Sleep(700);
                    credit();
                    break;
				}

				case 5:
                {
                    system("cls");
                    gotoXY(50,12);  printf(" Exit");
                    Sleep(700);
                    exit(0);
				}

			}

		}

	}



   return 0;
}

void learnTyping()
{
  Keyboard Learn;
  int menu_item=0, x=7;
  system("cls");
	gotoXY(48,7); printf("*");

	while(1==1)
	{
    gotoXY(50,7);  printf(" Lesson 1 \"QWERTY\" Row");
		gotoXY(50,8);  printf(" Lesson 2 \"ASDFGH\" Row");
		gotoXY(50,9);  printf(" Lesson 3 \"ZXCVBN\" Row");
		gotoXY(50,10); printf(" Lesson 4 \"NUMPAD\"");
		gotoXY(50,11); printf(" Return to MAIN MENU");

		system("pause>nul"); // the >nul bit causes it the print no message

		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				gotoXY(48,x); printf("  ");
				x++;
				gotoXY(48,x); printf("*");
				menu_item++;
				continue;
			}

		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(48,x); printf("  ");
				x--;
				gotoXY(48,x); printf("*");
				menu_item--;
				continue;
			}

		if(GetAsyncKeyState(VK_RETURN))
    {
			switch(menu_item)
      {
				case 0:
        {
			    system("cls");
			    gotoXY(50,7);
          printf(" Lesson 1 \"QWERTY\" Row");
			    Sleep(700);
			    system("cls");
          Learn.qwerty(1);
					break;
				}

				case 1:
        {
			    system("cls");
			    gotoXY(50,8);
          printf(" Lesson 2 \"ASDFGH\" Row");
			    Sleep(700);
			    system("cls");
					Learn.qwerty(2);
					break;
				}

				case 2:
        {
			    system("cls");
			    gotoXY(50,9);
          printf(" Lesson 3 \"ZXCVBN\" Row");
			    Sleep(700);
			    system("cls");
			    Learn.qwerty(3);
		      break;
				}

				case 3:
        {
			    system("cls");
			    gotoXY(50,10);
          printf(" Lesson 4 \"NUMPAD\"");
			    Sleep(700);
			    system("cls");
			    Learn.qwerty(4);
					break;
				}

				case 4:
        {
          system("cls");
          Sleep(700);
          main();
        }
      }
		}
	}

  system("cls");
}

void credit()
{
  gotoXY(20,5);printf(",---,---,---,---,---,---,---,---,---,---,---,---,---,-------,\n");delay5;
  gotoXY(20,6);printf("|   | T | Y | P | E | R | A | C | E | R |   | v | 1 |.0.0   |\n");delay5;
  gotoXY(20,7);printf("|---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n");delay5;
  gotoXY(20,8);printf("|     | S | A | M | A | R | T | H |   | 3 | 2 | 4 | 5 |     |\n");delay5;
  gotoXY(20,9);printf("|-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n");delay5;
  gotoXY(20,10);printf("|      | S | H | I | V | A | M |   | 3 | 2 | 5 | 7 |        |\n");delay5;
  gotoXY(20,11);printf("|------'---'---'---'---'---'---'---'---'---'---'---'--------|\n");delay5;
  gotoXY(20,12);printf("|        | S | U | K | H | J | O | T |   | 3 | 2 | 5 | 2    |\n");delay5;
  gotoXY(20,13);printf("|--------'----'---'---'---'---'---'---'---'---'------'------|\n");delay5;
  gotoXY(20,14);printf("| JIIT |  128 |     |                  |BATCH | F-8  | SEM 3|\n");delay5;
  gotoXY(20,15);printf("'------'------'-----'------------------'------'------'------'\n");delay5;
  std::cin.get();
  system("cls");
}

void showHighScores()
{
  system("cls");
  gotoXY(20,8);printf("BBBBBBBBBBBBBBBBB                                                                 dddddddd\n");delay5;
  gotoXY(20,9);printf("B::::::::::::::::B                                                                d::::::d\n");delay5;
  gotoXY(20,10);printf("B::::::BBBBBB:::::B                                                               d::::::d\n");delay5;
  gotoXY(20,11);printf("BB:::::B     B:::::B                                                              d:::::d\n");delay5;
  gotoXY(20,12);printf("  B::::B     B:::::B  ooooooooooo    aaaaaaaaaaaaa rrrrr   rrrrrrrrr      ddddddddd:::::d\n");delay5;
  gotoXY(20,13);printf("  B::::B     B:::::Boo:::::::::::oo  a::::::::::::ar::::rrr:::::::::r   dd::::::::::::::d\n");delay5;
  gotoXY(20,14);printf("  B::::BBBBBB:::::Bo:::::::::::::::o aaaaaaaaa:::::r:::::::::::::::::r d::::::::::::::::d\n");delay5;
  gotoXY(20,15);printf("  B:::::::::::::BB o:::::ooooo:::::o          a::::rr::::::rrrrr::::::d:::::::ddddd:::::d\n");delay5;
  gotoXY(20,16);printf("  B::::BBBBBB:::::Bo::::o     o::::o   aaaaaaa:::::ar:::::r     r:::::d::::::d    d:::::d\n");delay5;
  gotoXY(20,17);printf("  B::::B     B:::::o::::o     o::::o aa::::::::::::ar:::::r     rrrrrrd:::::d     d:::::d\n");delay5;
  gotoXY(20,18);printf("  B::::B     B:::::o::::o     o::::oa::::aaaa::::::ar:::::r           d:::::d     d:::::d\n");delay5;
  gotoXY(20,19);printf("  B::::B     B:::::o::::o     o::::a::::a    a:::::ar:::::r           d:::::d     d:::::d\n");delay5;
  gotoXY(20,20);printf("BB:::::BBBBBB::::::o:::::ooooo:::::a::::a    a:::::ar:::::r           d::::::ddddd::::::dd\n");delay5;
  gotoXY(20,21);printf("B:::::::::::::::::Bo:::::::::::::::a:::::aaaa::::::ar:::::r            d:::::::::::::::::d\n");delay5;
  gotoXY(20,22);printf("B::::::::::::::::B  oo:::::::::::oo a::::::::::aa:::r:::::r             d:::::::::ddd::::d\n");delay5;
  gotoXY(20,23);printf("BBBBBBBBBBBBBBBBB     ooooooooooo    aaaaaaaaaa  aaarrrrrrr              ddddddddd   ddddd\n");delay5;
  vector<string>highScores;
  string line;
  fileObj.open("scores.txt",ios::in);

  if(fileObj.fail())
     cout<<"failed";

  while(fileObj >> line)
  {
     highScores.push_back(line);
  }

  sort(highScores.begin(),highScores.end());

  for(int ii=0;ii+2<highScores.size();ii+=1)
  {
     gotoXY(40,26+ii);
     printf("%s\t\t\t\t%s\n",highScores[ii].c_str(),highScores[ii+2].c_str());
  }
  cin.get();
  fileObj.close();
  system("cls");
}
