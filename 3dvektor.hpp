//#ifndef 3DVEKTOR_HPP
//#define 3DVEKTOR_HPP
#include <iostream>

class Vector3D
{ 
	public:
		double x,y,z;
		Vector3D(double, double, double);
		Vector3D operator+(const Vector3D &a) const;
		Vector3D operator-(const Vector3D &a) const;
		Vector3D operator*(const double) const;
		Vector3D operator/(double) const;
		Vector3D kreuzprodukt(Vector3D &a) const;
		double betrag();
		double skalarprodukt(Vector3D &a);
		double winkel(Vector3D &a);
		double abstand (const Vector3D &a);
		std::string asString();
		double spatprodukt(Vector3D &a, Vector3D &b);
		Vector3D norm();
};	

