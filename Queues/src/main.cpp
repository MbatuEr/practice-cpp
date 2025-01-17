#include "../header/AnimalShelter.h"

int main()
{
    AnimalShelter shelter;

    shelter.enqueue("dog");
    shelter.enqueue("cat");
    shelter.enqueue("dog");
    shelter.enqueue("cat");

    try {
        Animal adopted1 = shelter.dequeueAny();
        std::cout << "Adopted: " << adopted1.type << " with order: " << adopted1.order << std::endl;

        Animal adopted2 = shelter.dequeueDog();
        std::cout << "Adopted: " << adopted2.type << " with order: " << adopted2.order << std::endl;

        Animal adopted3 = shelter.dequeueCat();
        std::cout << "Adopted: " << adopted3.type << " with order: " << adopted3.order << std::endl;
    } catch(const std::exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}