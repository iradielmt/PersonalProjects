#pragma once
#include <deque>
#include <string>
#include <iostream>

using namespace std;

//Defined struct called Car to define cars using name, model, and plate.
struct Car
{
    string carName;
    string carModel;
    string carPlate;
};

//Defined class Queue to include member functions that are used to call all the services by each exhibition.
class Queue
{
public:
    void addCar(Car c);
    bool checkCarPlate(string p);
    void addVipCar(Car v);
    void auctionCar(Car c);
    void cancelCar(Car c);
    void listCars();

private:
    deque <Car> carQueue;
};

//Function that adds a regular car to the back of the queue.
void Queue::addCar(Car c)
{
    carQueue.push_back(c);
}

//Function that checks if a car has a plate number.
bool checkCarPlate(string p)
{
    if (p == "\n")
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Function that adds a VIP car to the front of the queue.
void Queue::addVipCar(Car v)
{
    carQueue.push_front(v);
}

//Function that moves a car to the auction place. VIP cars will have first priority. If the queue is empty, then a message is displayed.
void Queue::auctionCar(Car c)
{
    if (carQueue.empty())
    {
        cout << "No more cars." << endl;
    }

    else
    {
        cout << carQueue[0].carName << " " << carQueue[0].carModel << " " << carQueue[0].carPlate << endl;
        for (deque <Car>::iterator iter = carQueue.begin(); iter != carQueue.end();)
        {
            iter = carQueue.erase(iter);
            break;
        }
    }
}

//Function that removes a car from the queue by receiving user input & matching the correct car in the queue.
//If the car that is entered is not in the queue, then an error message is displayed.
void Queue::cancelCar(Car c)
{
    for (deque <Car>::iterator iter = carQueue.begin(); iter != carQueue.end(); iter++)
    {
        if (iter->carName == c.carName && iter->carModel == c.carModel && iter->carPlate == c.carPlate)
        {
            iter = carQueue.erase(iter);
            break;
        }
        else
        {
            cout << "Car Does Not Exist." << endl;
            break;
        }
    }
}

//Function that lists all cars currently in the queue (car name, car model, and car plate).
void Queue::listCars()
{
    for (deque <Car>::iterator iter = carQueue.begin(); iter != carQueue.end(); iter++)
    {
        cout << iter->carName << " " << iter->carModel << " " << iter->carPlate << endl;
    }
}

