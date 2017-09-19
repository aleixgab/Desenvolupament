#include <iostream>
#include "Point3D.h"

int main()
{
	Point3D p(1, 2, 3);
	Point3D p1(4,8,6);


	std::cout << "vector 1    (" << p.coords[0] << ", " << p.coords[1] << ", " << p.coords[2] << ")" <<  std::endl;
	std::cout << "vector 2   (" << p1.coords[0] << ", " << p1.coords[1] << ", " << p1.coords[2] << ")\n" << std::endl;

	Point3D sum;
	Point3D res;
	Point3D res2;
	Point3D mult;



	sum = p + p1;
	res = p - p1;
	res2 = p1 - p;
	mult = p * p1;

	std::cout << "sum  (" << sum.coords[0] << ", " << sum.coords[1] << ", " << sum.coords[2] << ")" << std::endl;
	std::cout << "res 1st - 2nd  (" << res.coords[0] << ", " << res.coords[1] << ", " << res.coords[2] << ")" << std::endl;
	std::cout << "res 2nd - 1st  (" << res2.coords[0] << ", " << res2.coords[1] << ", " << res2.coords[2] << ")" << std::endl;
	std::cout << "mult  (" << mult.coords[0] << ", " << mult.coords[1] << ", " << mult.coords[2] << ")" << std::endl;



	system("pause");
	return 0;
}