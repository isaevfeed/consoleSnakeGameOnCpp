#include <iostream>
#include <unistd.h>

class Context {
    private:
        char border;

        void drawBorder() {
            for (int i = 0; i < width; i++) {
                std::cout << border;
            }
            std::cout << std::endl;
        }

        bool drawObject(Object * o, int i, int j) {
            if (i == o->y && j == o->x) {
                std::cout << o->sprite;
                return true;
            }

            return false;
        }

        void drawOther(Snake * s, Fruit * f) {
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (j == 0 || j == width - 1) {
                        std::cout << border;
                        continue;
                    }

                    if (drawObject(s, i, j) || drawObject(f, i, j)) {
                        continue;
                    }
                    
                    std::cout << " ";
                }

                std::cout << std::endl;
            }
        }

    public:
        int width;
        int height;

        Context(int width, int height) {
            this->width = width;
            this->height = height;
            this->border = '#';
        }

        void Draw(Snake * s, Fruit * f) {
            system("clear");

            drawBorder();
            drawOther(s, f);
            drawBorder();
        }

        void MoveObject(Snake * s, Fruit * f) {
            if (s->x < f->x) {
                s->x = s->x + 1;
            } else if (s->x > f->x) {g
                s->x = s->x - 1;
            }
            
            if (s->y < f->y) {
                s->y = s->y + 1;
            } else if (s->y > f->y) {
                s->y = s->y - 1;
            }

            if (s->x == f->x && s->y == f->y) {
                f->x = rand() % width;
                f->y = rand() % height;
            }

            usleep(100000);
        }
};