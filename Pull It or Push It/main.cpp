//Iradiel Torres
//09/27/2020

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
using namespace std;

//Function to generate number.
int randNumber(int upper)
{
    int num = rand() % upper;
    return num;
}

//Function to display numbers.
void printCard(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(3) << arr[i];
    cout << endl;
}

//Function for the game to be played.
void playGame()
{
    //Initialized my integer values, arrays, and character for user input.
    int score = 0;
    int turnedCard = 0;
    int upcomingCard;
    int live[16];
    int dead[16];
    int deadSize = 0;
    int liveSize = 16;
    char choice;

    //For loop to increment live array.
    for (int i = 0; i < 16; i++)
        live[i] = i + 1;

    //Does while loop until size of array is 0.
    while (liveSize > 0)
    {
        sort(live, live + liveSize);
        sort(dead, dead + deadSize);
        cout << "Current score: " << score << endl;
        cout << "Dead cards: ";
        printCard(dead, deadSize);
        cout << "Live cards: ";
        printCard(live, liveSize);

        //Generates random number card and displays, and updates live array.
        upcomingCard = randNumber(liveSize);
        cout << "Next card: " << live[upcomingCard];
        int temp = live[upcomingCard];
        live[upcomingCard] = live[liveSize - 1];
        liveSize--;

        //If upcoming card is less than the turned card, then a 'Dead'
        //message will be displayed and the card is unplayable.
        if (temp < turnedCard)
        {
            cout << "\tDead" << endl << endl;
        }

        //Prompts user to take or leave the card, and adds to score if user takes it.
        //If user pushes it, then the card is dead.
        else
        {

            cout << endl;
            cout << endl;
            cout << "Pull It [P] or Push It [S]? ";

            cin >> choice;
            if (choice == 'P' || choice == 'p')
            {
                score += temp;
                turnedCard = temp;

            }
            else
            {
                dead[deadSize++] = temp;
            }
            cout << endl;
        }
    }
    //Displays final score.
    cout << endl << "Final Score: " << score << endl;

}

int main()
{
    //Time function to allow for random generator.
    srand(time(0));
    char choice;

    //while user choice is 'Y' or 'y' another game is played.
    do 
    {
        playGame();
        cout << "Do you want to play again ? (Y/N): ";
        cin >> choice;
    } 
    while(choice == 'y' || choice == 'Y');

    cout << "Thanks for playing !";

    return 0;
}


