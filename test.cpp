#include <iostream>
#include<cmath>

class Point
{
public:
	float x, y;
  Point &operator=(const Point& buf)
  {
    this->x = buf.x;
    this->y = buf.y;

    std::cout << "overload" << '\n';
    return *this;
  }
};

class Segment
{
public:
	Segment()
	{
	}
	Segment(Point _a, Point _b)
	{
		a = _a;
		b = _b;
	}

private:
	Point a, b;
};
int main()
{
    double c = (double)1/2 * abs(-1*1.5);
    std::cout << c << '\n';


    return 0;
}
