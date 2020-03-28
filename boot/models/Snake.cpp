class Snake: public Object {
    public: 
        Snake(int width, int height) {
            this->x = width / 2;
            this->y = height / 2;
            this->sprite = '@';
        }
};