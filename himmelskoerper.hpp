//#ifndef HIMMELSKOERPER_HPP
//#define HIMMELSKOERPER_HPP
#include <iostream>
#include "3dvektor.hpp"

class sky_object //public Vector3D
{
	private:
		double pos_x, pos_y, pos_z, v_x, v_y, v_z;
		
	public:
		double m;
		sky_object(double, double, double, double, double, double, double);
		Vector3D get_v();
		Vector3D get_pos();
//		Vector3D f(std::vector);
//		Vector3D acc();
//		Vector3D update_v();
//		Vector3D update_pos();
};