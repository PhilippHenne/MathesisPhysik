#include <iostream>
#include "himmelskoerper.hpp"

sky_object::sky_object(double pos_x, double pos_y, double pos_z, double v_x, double v_y, double v_z, double m): pos_x(pos_x), pos_y(pos_y), pos_z(pos_z), v_x(v_x), v_y(v_y),v_z(v_z), m(m)
{}

Vector3D sky_object::get_pos()
{
	return Vector3D(pos_x, pos_y, pos_z);
}

Vector3D sky_object::get_v()
{
	return Vector3D(v_x, v_y, v_z);
}
