// Iradiel Torres
//12/13/2020


#include <iostream>
#include "Program6Utility.h"
using namespace std;


int main()
{
    //Initialized queues for each type of car.
    Queue newCars;
    Queue oldCars;
    Queue luxuryCars;

    //Initialized strings for user selection on menu options.
    string mainMenuChoice;
    string serviceOption;

    //Initialized boolean variables to proceed/return to different menu screens.
    bool mainMenuScreen = true;
    bool exhibitionScreen = true;

    //Initialized a struct to define cars using its methods.
    Car c;

    //Displays main menu screen.
    while (mainMenuScreen)
    {

        cout << "Welcome to Mercedes" << endl;
        cout << "1. New Cars" << endl;
        cout << "2. Old and historical cars" << endl;
        cout << "3. Luxury Cars" << endl;
        cout << "4. Exit" << endl;
        cout << "Please enter your choice" << endl;
        cin >> mainMenuChoice;
        cout << endl;

        //Option "1" takes user to New Cars exhibition menu.
        if (mainMenuChoice == "1")
        {
            exhibitionScreen = true;

            while (exhibitionScreen)
            {
                cout << "Welcome to exhibition: New Cars" << endl;
                cout << "Please enter your choice:" << endl;
                cout << "1. Add Car" << endl;
                cout << "2. Add VIP Car" << endl;
                cout << "3. Take Car to Auction" << endl;
                cout << "4. Cancel Car" << endl;
                cout << "5. List all currently queued Cars" << endl;
                cout << "6. Exit back to main menu" << endl;
                cin >> serviceOption;
                cout << endl;

                //Takes in car's name, model, and plate from user input & calls addCar function to add car to queue. 
                if (serviceOption == "1")
                {
                    cout << "Enter car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        newCars.addCar(c);
                    }
                }

                //Takes in VIP car's name, model, and plate from user input & calls addVIPCar function to add VIP car to queue.
                else if (serviceOption == "2")
                {
                    cout << "Enter VIP car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        newCars.addVipCar(c);
                    }
                }
                //Moves car to the auction. VIP's have priority. Calls auctionCar function.
                else if (serviceOption == "3")
                {
                    newCars.auctionCar(c);
                }
                //Takes in car's name, model and plate from user input to remove a car from the queue by calling cancelCar function.
                else if (serviceOption == "4")
                {
                    cout << "Enter car's name, model and plate to cancel: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        newCars.cancelCar(c);
                    }
                }
                //Lists all cars currently in the queue including regular and VIP's by calling the listCars function.
                else if (serviceOption == "5")
                {
                    newCars.listCars();
                }
                //Takes user away from the current exhibition screen.
                else if (serviceOption == "6")
                {
                    exhibitionScreen = false;

                }
                //If none of the options showed is pressed, then an error message is displayed.
                else
                {
                    cout << "Incorrect option, try again.";
                }
                cout << endl;
            }
        }
        //Option "2" takes user to old and historical cars exhibition menu.
        else if (mainMenuChoice == "2")
        {
            exhibitionScreen = true;

            while (exhibitionScreen)
            {
                cout << "Welcome to exhibition: Old and historical cars" << endl;
                cout << "Please enter your choice:" << endl;
                cout << "1. Add Car" << endl;
                cout << "2. Add VIP Car" << endl;
                cout << "3. Take Car to Auction" << endl;
                cout << "4. Cancel Car" << endl;
                cout << "5. List all currently queued Cars" << endl;
                cout << "6. Exit back to main menu" << endl;
                cin >> serviceOption;
                cout << endl;

                //Takes in car's name, model, and plate from user input & calls addCar function to add car to queue.
                if (serviceOption == "1")
                {
                    cout << "Enter car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        oldCars.addCar(c);
                    }
                }
                //Takes in VIP car's name, model, and plate from user input & calls addVIPCar function to add VIP car to queue.
                else if (serviceOption == "2")
                {
                    cout << "Enter VIP car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        oldCars.addVipCar(c);
                    }
                }
                //Moves car to the auction. VIP's have priority. Calls auctionCar function.
                else if (serviceOption == "3")
                {
                    oldCars.auctionCar(c);
                }
                //Takes in car's name, model and plate from user input to remove a car from the queue by calling cancelCar function.
                else if (serviceOption == "4")
                {
                    cout << "Enter car's name, model and plate to cancel: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        oldCars.cancelCar(c);
                    }
                }
                //Lists all cars currently in the queue including regular and VIP's by calling the listCars function.
                else if (serviceOption == "5")
                {
                    oldCars.listCars();
                }
                //Takes user away from the current exhibition screen.
                else if (serviceOption == "6")
                {
                    exhibitionScreen = false;
                }
                //If none of the options showed is pressed, then an error message is displayed.
                else
                {
                    cout << "Incorrect option, try again.";
                }
                cout << endl;
            }

        }
        //Option "3" takes user to Luxury Cars exhibition menu.
        else if (mainMenuChoice == "3")
        {
            exhibitionScreen = true;

            while (exhibitionScreen)
            {
                cout << "Welcome to exhibition: Luxury Cars" << endl;
                cout << "Please enter your choice:" << endl;
                cout << "1. Add Car" << endl;
                cout << "2. Add VIP Car" << endl;
                cout << "3. Take Car to Auction" << endl;
                cout << "4. Cancel Car" << endl;
                cout << "5. List all currently queued Cars" << endl;
                cout << "6. Exit back to main menu" << endl;
                cin >> serviceOption;
                cout << endl;

                //Takes in car's name, model, and plate from user input & calls addCar function to add car to queue.
                if (serviceOption == "1")
                {
                    cout << "Enter car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        luxuryCars.addCar(c);
                    }
                }
                //Takes in VIP car's name, model, and plate from user input & calls addVIPCar function to add VIP car to queue.
                else if (serviceOption == "2")
                {
                    cout << "Enter VIP car's name, model and plate: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        luxuryCars.addVipCar(c);
                    }
                }
                //Moves car to the auction. VIP's have priority. Calls auctionCar function.
                else if (serviceOption == "3")
                {
                    luxuryCars.auctionCar(c);
                }
                //Takes in car's name, model and plate from user input to remove a car from the queue by calling cancelCar function.
                else if (serviceOption == "4")
                {
                    cout << "Enter car's name, model and plate to cancel: ";
                    cin >> c.carName >> c.carModel >> c.carPlate;

                    if (checkCarPlate(c.carPlate))
                    {
                        luxuryCars.cancelCar(c);
                    }
                }
                //Lists all cars currently in the queue including regular and VIP's by calling the listCars function.
                else if (serviceOption == "5")
                {
                    luxuryCars.listCars();
                }
                //Takes user away from the current exhibition screen.
                else if (serviceOption == "6")
                {
                    exhibitionScreen = false;
                }
                //If none of the options showed is pressed, then an error message is displayed.
                else
                {
                    cout << "Incorrect option, try again.";
                }
                cout << endl;
            }
        }
        //Takes user away from the main menu to exit program.
        else if (mainMenuChoice == "4")
        {
            mainMenuScreen = false;
        }

        //If none of the options showed is pressed, then an error message is displayed.
        else
        {
            cout << "Incorrect option, try again.";
        }

        cout << endl;
    }

    return 0;
}

