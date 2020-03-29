#include "Object.cpp"
#include "Snake.cpp"
#include "Fruit.cpp"
#include "Context.cpp"

class Game {
    private:
        static const bool gameOver = false;

    public:
        static void Start() {
            Context c = Context(40, 20);
            Snake * s = new Snake(c.width, c.height);
            Fruit * f = new Fruit(c.width, c.height);

            while (!gameOver) {
                c.Draw(s, f);
                c.MoveObject(s, f);
            }
        }
};