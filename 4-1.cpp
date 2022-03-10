#include<cmath>

class Coordinate
{
public:
	//Coordinate(): x(0), y(0){}
	Coordinate(int a=0, int b=0): x(a), y(b){}
	Coordinate(Coordinate &it): x(it.x), y(it.y){}

	int getX(){return x;}
	int getY(){return y;}
	void setX(int val){x = val;}
	void setY(int val){y = val;}
	void showCoordInfo(){ std::cout << "(" << x << ", " << y << ")\n";}

private:
	int x;
	int y;
};

class Segment // using two Coordinate to represent a segment
{
public:
Segment(Coordinate _a, Coordinate _b)
{
  a.x = _a.x;
  a.y = _a.y;

  b.x = _b.x;
  b.y = _b.y;
}

// return the intersection with another segment if exist, return NULL when there are no intersection.
Coordinate *getIntersection(Segment s)
{
// doing
}

float length() // return the length of segment
{
return sqrt(a*a+b*b);
}

Coordinate getCoordinateA() { return a; }

Coordinate getCoordinateB() { return b; }

private:

Coordinate a, b;

};
