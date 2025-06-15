
class Point{int x,y,z;};
class Color{};
class Shape{
	Point center;
	Color col;
 public:
	Point where();
	void move(Point to);
	virtual void drow()const=0;
	virtual void rotate(int angle)=0;
};
class Circle:public Shape{
	int radius;
 public:
	void drow();
	void rotate(int);
};
