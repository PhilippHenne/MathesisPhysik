#include <iostream>
#include <vector>
#include "himmelskoerper.hpp"
//#include "simulation.hpp"

class universe
{
//	private:
//		std::vector<sky_object*> objects ;

	public:
		std::vector<sky_object*> objects;
		universe(int i);
		~universe();
		std::string asString();
		Vector3D setF(unsigned int);
		Vector3D set_acc(unsigned int);
};