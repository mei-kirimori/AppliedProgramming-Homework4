#include <iostream>
using namespace std;

class Move
{
public:
    int speed;
	int distance;
	bool walking;
	bool dashing;
	bool stopped;
	Move(int setSpeed,int setDistance)
	{
		
		speed = setSpeed;
		distance = setDistance;
		walking = false;
		dashing = false;
		stopped = true;

	}
	void walk()
	{
		walking = true;
		dashing = false;
		stopped = false;
		distance += speed;
	}

	void dash()
	{
		walking = false;
		dashing = true;
		stopped = false;
		distance += speed * 2;
	}

	void stop()
	{
		walking = false;
		dashing = false;
		stopped = true;
	}
};



int main()
{
    Move player(5, 0);
}