#include <iostream>

class Context {
    private:
        char border;

        void drawBorder() {
            for (int i = 0; i < width; i++) {
                std::cout << border;
            }
            std::cout << std::endl;
        }

        bool drawObject(Object o, int i, int j) {
            if (i == o.y && j == o.x) {
                std::cout << o.sprite;
                return true;
            }

            return false;
        }

        void drawOther(Snake s, Fruit f) {
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

        void Draw(Snake s, Fruit f) {
            system("clear");

            drawBorder();
            drawOther(s, f);
            drawBorder();
        }
};