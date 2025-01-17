#include "../header/AnimalShelter.h"

using namespace std;

Animal::Animal(string s, int o) : type(s), order(o) {}

AnimalShelter::AnimalShelter(): order(0) {}

void AnimalShelter::enqueue(const string& type)
{
    if (type == "dog")
    {
        dogs.push(Animal("dog", ++order));
    } else if (type == "cat")
    {
        cats.push(Animal("cat", ++order));
    } else {
        cerr << "Invalid animal type!" << endl;
    }    
}

Animal AnimalShelter::dequeueAny()
{
    if (dogs.empty() && cats.empty())
    {
        throw runtime_error("No animals available for adoption.");
    }

    if (dogs.empty())
    {
        return dequeueCat();
    } else if (cats.empty())
    {
        return dequeueDog();
    }
    
    if (dogs.front().order < cats.front().order)
    {
        return dequeueDog();
    } else {
        return dequeueCat();
    }
}

Animal AnimalShelter::dequeueDog()
{
    if (dogs.empty())
    {
        throw runtime_error("No dogs available for adaption.");
    }
    Animal dog = dogs.front();
    dogs.pop();
    return dog;
}

Animal AnimalShelter::dequeueCat()
{
    if (cats.empty())
    {
        throw runtime_error("No cats available for adaption.");
    }
    Animal cat = cats.front();
    cats.pop();
    return cat;
}