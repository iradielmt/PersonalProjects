//Iradiel Torres
//09/12/2020

#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;


//This function allows players to roll a dice from values 1-6.
int rollDice()
{
    int value = (rand() % 6) + 1;
    return value;
}
//This function combines the values of two dice rolls to make the largest, combined value.
int diceTotal()
{
    int roll1 = rollDice();
    int roll2 = rollDice();

    int total1 = roll1 * 10 + roll2;
    int total2 = roll2 * 10 + roll1;

    if (total1 < total2)
    {
        total1 = total2;
    }
    cout << "Rolled " << roll1 << " and " << roll2 << ", making " << total1 << "." << endl;

    return total1;
}

int main()
{
    /* Initiliazed my player string for the human player to go first, as well as the computer time to output
    different results every run. Both player and computer score are initialized to 0 to keep track of the
    number of wins. numberToBeat and newNumberToBeat are initialized to 0 to reset the score if user wants
    to continue playing. */
    string player = "Human";
    srand(time(NULL));
    int humanScore = 0;
    int computerScore = 0;
    int numberToBeat = 0;
    int newNumberToBeat = 0;

    //Plays a dice game until the user exits by input.
    while (true)
    {
        cout << "Rolling 2 dice for " << player << ":" << endl;
        newNumberToBeat = diceTotal();

        //Compares players' scores and increments a point to player with highest number.
        if (newNumberToBeat < numberToBeat)
        {
            if (player == "Computer")
            {
                humanScore += 1;
            }
            else
                computerScore += 1;
            cout << endl;

            cout << "Unlucky roll for the " << player << " Player" << endl;
            cout << "The current score is - Human: " << humanScore << ", Computer: " << computerScore << endl;

            if (humanScore > computerScore)
            {
                cout << "Congrats, human player is winning !" << endl;
            }
            else if (humanScore == computerScore)
            {
                cout << "Interesting, game is tied !" << endl;
            }
            else
            {
                cout << "Too bad, human player is losing !" << endl;
            }

            cout << "=============================================" << endl;

            //Choise is used as user input to continue the game or not.
            cout << "Would you like to go again [Y/N]?";
            string choice = "";
            cin >> choice;

            if (choice == "Y" || choice == "y")
            {
                //Resets scores
                player = "Human";
                numberToBeat = 0;
                newNumberToBeat = 0;
                continue;
            }

            else
            {
                cout << "Thanks for playing !";
                break;
            }
        }
        //Sets and displays the highest number so far.
        numberToBeat = newNumberToBeat;
        cout << endl;
        cout << numberToBeat << " is the number to beat!" << endl;
        //Switches player's turn
        if (player == "Human")
        {
            player = "Computer";
        }
        else
        {
            player = "Human";
        }
    }
}

