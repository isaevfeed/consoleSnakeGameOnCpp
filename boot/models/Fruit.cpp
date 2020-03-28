#include <iostream>

class Fruit: public Object {
    public:
        Fruit(int width, int height) {
            this->x = rand() % width;
            this->y = rand() % height;
            this->sprite = 'o';
        }
};