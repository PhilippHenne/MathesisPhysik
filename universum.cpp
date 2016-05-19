#include <iostream>
#include <sstream>
#include <vector>
#include "universum.hpp"
// Bedeutung von Konstante i:
// 1: Universum mit Sonne, Erde und Mond

double G = 1;
universe::universe(int i)
{
	if (i == 1)
	{
//		objects.push_back(sky_object (0.,2.,4.,3.,2.,1.,1.));
//		objects.push_back(sky_object (1.,1.,1.,1.,1.,1.,0.5));
//		objects.push_back(sky_object (5.,5.,5.,2.,2.,2.,0.1));		
		
		sky_object* sun = new sky_object (0.,0.,0.,0.,0.,0.,1.);
		sky_object* earth = new sky_object (10.,0.,0.,0.,0.,0.,1.);
//		sky_object* moon = new sky_object(-1.657103868749121*(0.1),9.706382026425472*(0.1),-1.879812512691582*(0.0001),(-1.728100931961937*(0.01))/84600,(-3.525371122447977*(0.001))/84600,(4.909148618073602*(0.00001))/84600, 1/27068510);

		objects.push_back(sun);
		objects.push_back(earth);
//		objects.push_back(moon);
		
	}
}	

universe::~universe()
{
}


Vector3D universe::setF(unsigned int a)
{
	Vector3D temp(0.,0.,0.);
	std::vector<Vector3D> forces (objects.size(), temp);
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (i == a)
			{
				forces.at(a) = forces.at(a);
			}
			else
			{
				Vector3D abstand_vec (objects.at(a)->get_pos() - objects.at(i)->get_pos());
				//std::cout << abstand_vec.asString() << std::endl;
				double abstand = objects.at(a)->get_pos().abstand(objects.at(i)->get_pos());
				//std::cout << abstand << std::endl;
				forces.at(a) = forces.at(a) + ((abstand_vec * ((objects.at(a)->m * objects.at(i)->m)/(abstand*abstand*abstand)))* -G);
			}
		}
	return forces.at(a);
}

Vector3D universe::set_acc(unsigned int a)
{
	return setF(a)/objects.at(a)->m;
}

std::string universe::asString()
{
		std::stringstream s;
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			s << "Objekt " << i+1 <<" Position: " << objects.at(i)->get_pos().asString() << "Geschwindigkeit: "
			<< objects.at(i)->get_v().asString() << "Kraft: " << setF(i).asString() << "Beschleunigung: " << set_acc(i).asString() << std::endl; 
		}
		return s.str();
}

//(-1.630229002588497*(0.1),9.704723344534316*(0.1),-1.955367328932975*(0.0001),(-1.723383356491747*(0.01))/84600,(-2.969134550063944*(0.001))/84600,(-4.433758674928828*(0.0000001))/84600,1/332946)
//3.964 * (0.00000000000001)