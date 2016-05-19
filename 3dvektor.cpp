#include <iostream>
#include <cmath>
#include <sstream>
#include "3dvektor.hpp"

Vector3D::Vector3D(double x, double y, double z):x(x), y(y), z(z){}

Vector3D Vector3D::operator+(const Vector3D &a) const
	{
	return Vector3D(a.x + x, a.y + y, a.z + z);
	}

Vector3D Vector3D::operator-(const Vector3D &a) const
	{
	return Vector3D(x - a.x, y - a.y, z - a.z);
	}
	
Vector3D Vector3D::operator*(const double a) const
	{
	return Vector3D(x *a, y *a, z *a);
	}

Vector3D Vector3D::operator/(double a) const
	{
	return Vector3D(x/a, y/a, z/a);
	}

double Vector3D::betrag(){
	return sqrt(x*x + y*y + z*z);
	}

double Vector3D::skalarprodukt(Vector3D &a)
	{
	return (a.x * x + a.y * y + a.z * z);
	}

double Vector3D::winkel(Vector3D &a)
	{
	return acos((this->skalarprodukt(a))/(a.betrag() * betrag()));
	}

double Vector3D::abstand(const Vector3D &a)
	{
	return Vector3D(a.x - x, a.y - y, a.z - z).betrag();
	}

Vector3D Vector3D::kreuzprodukt(Vector3D &a) const
	{
	return Vector3D((y * a.z) - (z * a.y), (z)*(a.x) -(x)*(a.z), (x) * (a.y) - (y)*(a.x));
	}

double Vector3D::spatprodukt(Vector3D &a, Vector3D &b)
	{
	return (this->kreuzprodukt(a)).skalarprodukt(b);
	}

Vector3D Vector3D::norm()
	{
	double temp = this->betrag();
	return Vector3D(x/temp,y/temp,z/temp);
	}
	
std::string Vector3D::asString()
	{
	std::stringstream s;
	s << "(" << x << ", " << y << ", " << z << ") ";
	return s.str();
	}