#ifndef ANIMALSHELTER_H   
#define ANIMALSHELTER_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Animal 
{
    public:
        string type;  // "dog" or "cat"
        int order;    // Timestamp or order of arrival
        Animal(string s, int o);
};

class AnimalShelter
{
    private:
        queue<Animal> dogs;
        queue<Animal> cats;
        int order;
    public:
        AnimalShelter();
        void enqueue(const string& type);
        Animal dequeueAny();
        Animal dequeueDog();
        Animal dequeueCat();
};

#endif // ANIMALSHELTER_H