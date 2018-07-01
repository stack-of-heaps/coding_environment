#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using std::endl;
using std::cout;
using std::cin;
using std::string;

int matchRecordOneUp[5];
int matchRecordCPU[5];
void playJudge();
void playGame();

int main()
{    
  playGame();
  playJudge();
  return 0;
}

void playGame()
{
    unsigned seed = time(0);
    srand(seed); // Now we have good rando
    static int gameCounter = 1;
    bool keepPlaying = true;
    char playAgain;
    int oneUp, // human player
        cpu;   // computer 
    
  do
  {
      cout << "Starting game " << gameCounter << endl;
      gameCounter++;
      for (int round = 0; round + 1 < 6; round++)
      {
      cout << "Round " << round + 1 << endl;
      cout << "1: Rock" << endl << "2: Paper" << endl << "3: Scissors" << endl;
      cin >> oneUp;
               
        while (oneUp < 1 || oneUp > 3)
            {
            cout << "Please enter 1, 2, or 3." << endl;
            cin >> oneUp;
            }
            
    cpu = 1 + rand() % 3;  // CPU move

    matchRecordOneUp[round] = oneUp;
    matchRecordCPU[round] = cpu;
    }
     
    cout << "Keep playing? Y or N";
    cin >> playAgain;
    switch (playAgain)
    {
        case 'Y':
        case 'y': keepPlaying = true;
                break;
        case 'N':
        case 'n': keepPlaying = false;
                break;
    } 
  } while (keepPlaying);
   
  for (int z = 0; z < 5; z++)
    cout << "Human: " << matchRecordOneUp[z] << " -- CPU : " << matchRecordCPU[z] << endl;
}

void playJudge() // Summarizes the game. Announces the winner.
{
    //1 rock 2 paper 3 scizzors
    int manPlay, cpuPlay;
    string oneUpDescrip[5];
    string cpuDescrip[5];
    string matchResult[5];

    for (int x = 0; x < 5; x++)
    {
        switch (matchRecordOneUp[x])
        {
            case 1:
                    switch (matchRecordCPU[x])
                     { 
                         case 1: matchResult[x] = "Tie.";
                                 cpuDescrip[x] = "computer plays rock.";
                                 break;
                         case 2: matchResult[x] = "Computer wins.";
                                 cpuDescrip[x] = "computer plays paper.";
                                 break;
                         case 3: matchResult[x] = "Human wins.";
                                 cpuDescrip[x] = "computer plays scissors.";
                                 break;
                     }
                     oneUpDescrip[x] = "Human plays rock, ";

                    break;
            case 2:    
                     switch (matchRecordCPU[x])
                     { 
                         case 1: matchResult[x] = " Computer loses.";
                                 cpuDescrip[x] = "computer plays rock.";
                                 break;
                         case 2: matchResult[x] = " Tie.";
                                 cpuDescrip[x] = "computer plays paper.";
                                 break;
                         case 3: matchResult[x] = " Computer wins.";
                                 cpuDescrip[x] = "computer plays scissors.";
                                 break;
                     } 
                     oneUpDescrip[x] = "Human plays paper, ";
                     break;
            case 3:  switch (matchRecordCPU[x])
                     { 
                         case 1: matchResult[x] = " Computer wins.";
                                 cpuDescrip[x] = "computer plays stone.";
                                 break;
                         case 2: matchResult[x] = " Human wins.";
                                 cpuDescrip[x] = "computer plays paper.";
                                 break;
                         case 3: matchResult[x] = " Tie.";
                                 cpuDescrip[x] = " computer plays scissors.";
                                 break;
                     }
                     oneUpDescrip[x] = "Human plays scissors, ";
                     break;
        }
        cout << oneUpDescrip[x] << cpuDescrip[x] << matchResult[x] << endl;
    }

}