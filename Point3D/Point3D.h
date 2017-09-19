#ifndef POINT3D_H
#define POINT3D_H

class Point3D{

private:

public:
	int coords[3];
	
	Point3D()
	{

		
	}

	Point3D(int x, int y, int z)
	{
		this->coords[0] = x;
		this->coords[1] = y;
		this->coords[2] = z;
	}

	~Point3D()
	{

	}

	Point3D operator+ (const Point3D& p) const
	{
		Point3D result (coords[0] + p.coords[0], coords[1] + p.coords[1], coords[2] + p.coords[2]);
		return result;
	}

	Point3D operator- (const Point3D& p) const
	{
		Point3D result(coords[0] - p.coords[0], coords[1] - p.coords[1], coords[2] - p.coords[2]);
		return result;
	}

	Point3D operator* (const Point3D& p) const
	{
		Point3D result(coords[0] * p.coords[0], coords[1] * p.coords[1], coords[2] * p.coords[2]);
		return result;
	}
};

#endif