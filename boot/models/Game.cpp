#include "Object.cpp"
#include "Snake.cpp"
#include "Fruit.cpp"
#include "Context.cpp"

class Game {
    private:
        static const bool gameOver = false;

    public:
        static void Start() {
            Context c = Context(20, 20);
            Snake s = Snake(c.width, c.height);
            Fruit f = Fruit(c.width, c.height);

            while (!gameOver) {
                c.Draw(s, f);
            }
        }
};