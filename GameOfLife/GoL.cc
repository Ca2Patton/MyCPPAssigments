//Name: Caitlin A. Patton
//September 14th, 2013
//This is an example of code found on the internet.
#include <iostream>
#define HEIGHT 4
#define WIDTH 4

struct Shape {
	public:
		char xCoord;
		char yCoord;
		char height;
		char width;
		char **figure;
};

struct Glider : public Shape {
	static const char GLIDER_SIZE = 3;
	Glider (char x, char y);
	~Glider();
};

struct Blinker : public Shape {
	static const char BLINKER_HEIGHT = 3;
	static const char BLINKER_WIDTH = 1;
	Blinker (char x, char y);
	~Blinker();
};

class GameOfLife {
	public:
		GameOfLife(Shape sh);
		void print();
		void update();
		char getState(char state, char xCoord, char yCoord, bool toggle);
		void iterate(unsigned int iterations);
	private:
		char world[HEIGHT][WIDTH];
		char otherWorld[HEIGHT][WIDTH];
		bool toggle;
		Shape shape;
};

GameOfLife::GameOfLife(Shape sh) :
	shape(sh),
	toggle(true)
{
	for(char counter = 0; counter < HEIGHT; counter++) {
		for(char nCount = 0; nCount < WIDTH; nCount++){
			world[counter][nCount] = '.';
		}
	}
	for(char counter = shape.yCoord; counter - shape.yCoord < shape.height; counter++) {
		for(char nCount = shape.xCoord; nCount - shape.xCoord < shape.width; nCount++) {
			if(counter < HEIGHT && nCount < WIDTH) {
				world[counter][nCount] = shape.figure[counter - shape.yCoord][nCount - shape.xCoord];
			}
		}
	}
}
void GameOfLife::print() {
	if(toggle) {
		for(char counter = 0; counter < HEIGHT; counter++) {
			for(char nCount = 0; nCount < WIDTH; nCount++) {
				std::cout << world[counter][nCount];
			}
			std::cout << std::endl;
		}
	}
	for(char counter = 0; counter < WIDTH; counter++) {
		std::cout << '=';
	}
	std::cout << std::endl;
}

void GameOfLife::update() {
	if(toggle) {
		for(char counter = 0; counter < HEIGHT; counter++) {
			for(char nCount = 0; nCount < WIDTH; nCount++) {
				otherWorld[counter][nCount] = GameOfLife::getState(world[counter][nCount], counter, nCount, toggle);
			}
		}
		toggle = !toggle;
	}
	else {
		for(char counter = 0; counter < HEIGHT; counter++) {
			for(char nCount = 0; nCount < WIDTH; nCount++) {
				world[counter][nCount] = GameOfLife::getState(otherWorld[counter][nCount], counter, nCount, toggle);
			}
		}
		toggle = !toggle;
	}
}

char GameOfLife::getState(char state, char yCoord, char xCoord, bool toggle) {
	char neighbors = 0;
	if(toggle) {
		for(char counter = yCoord - 1; counter <= yCoord + 1; counter++){
			for(char nCount = xCoord - 1; nCount <= xCoord + 1; nCount++) {
				if(counter == yCoord && nCount == xCoord) {
					continue;
				}
				if(counter > -1 && counter < HEIGHT && nCount > -1 && nCount < WIDTH) {
					if (world[counter][nCount] == 'X') {
						neighbors++;
					}
				}
			}
		}
	}
	else {
		for(char counter =yCoord -1; counter <= yCoord + 1; counter++) {
			for(char nCount = xCoord - 1; nCount <= xCoord + 1; nCount++) {
				if(counter == yCoord && nCount == xCoord) {
					continue;
				}
				if(counter > -1 && counter < HEIGHT && nCount > -1 && nCount < WIDTH) {
					if(otherWorld[counter][nCount] == 'X') {
						neighbors++;
					}
				}
			}
		}
	}
	if(state == 'X') {
		return(neighbors > 1 && neighbors < 4)  ? 'X' : '.';
	}
	else {
		return(neighbors == 3) ? 'X' : '.';
	}
}

void GameOfLife::iterate(unsigned int iterations) {
	for(int counter = 0; counter < iterations; counter++) {
		print();
		update();
	}
}

Glider::Glider(char x, char y) {
	xCoord = x;
	yCoord = y;
	height = GLIDER_SIZE;
	width = GLIDER_SIZE;
	figure = new char*[GLIDER_SIZE];
	for(char counter = 0; counter < GLIDER_SIZE; counter++) {
		figure[counter] = new char[GLIDER_SIZE];
	}
	for(char counter = 0; counter < GLIDER_SIZE; counter++) {
		for(char nCount = 0; nCount < GLIDER_SIZE; nCount++) {
			figure[counter][nCount] = '.';
		}
	}
	figure[0][1] = 'X';
	figure[1][2] = 'X';
	figure[2][0] = 'X';
	figure[2][1] = 'X';
	figure[2][2] = 'X';
}

Glider::~Glider() {
	for(char counter = 0; counter < GLIDER_SIZE; counter++) {
		delete[] figure[counter];
	}
	delete[] figure;
}

Blinker::Blinker(char x, char y) {
	xCoord = x;
	yCoord = y;
	height = BLINKER_HEIGHT;
	width = BLINKER_WIDTH;
	figure = new char*[BLINKER_HEIGHT];
	for(char counter = 0; counter < BLINKER_HEIGHT; counter++) {
		figure[counter] = new char[BLINKER_WIDTH];
	}
	for(char counter = 0; counter < BLINKER_HEIGHT; counter++) {
		for(char nCount = 0; nCount < BLINKER_WIDTH; nCount++) {
			figure[counter][nCount] = 'X';
		}
	}
}

Blinker::~Blinker() {
	for(char counter = 0; counter < BLINKER_HEIGHT; counter++) {
		delete[] figure[counter];
	}
	delete[] figure;
}

int main(){
	Glider glider(0,0);
	GameOfLife gol(glider);
	gol.iterate(5);
	Blinker blinker(1,0);
	GameOfLife gol2(blinker);
	gol2.iterate(4);
}
