#include <iostream>
class Brick_abs{
	public:
        char kind;
        char direction;
        char x;
        char y;
		Brick_abs(){};
		virtual ~Brick_abs(){};
		virtual int get_shape() const = 0;
		virtual void random_set_brick() = 0;
};