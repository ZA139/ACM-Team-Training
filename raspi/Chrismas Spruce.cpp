#include <iostream>
using namespace std;
struct Point{
	int x,y;
	Point(int x=0,int y=0):x(x),y(y){}
};
Point operator - (const Point& a,const Point& b){
		return Point(a.x-b.x,a.y-b.y);
}
ostream& operator <<(ostream& out,const Point& p){
			out<<"("<<p.x<<","<<p.y<<")";
			return out;
}
int main(int argc, char **argv)
{
	Point a,b(4,2);
	a.x=3;
	cout<<b-a<<"\n";
	return 0;
}
