#include <iostream>
#include <vector>
#include "simulation.hpp"

Simulation::Simulation(universe* u):u(u)
{
	
	for (unsigned int i = 0; i < u->objects.size(); i++)
		{	
			rk4_input.push_back(u->objects.at(i)->get_v().x);
			rk4_input.push_back(u->objects.at(i)->get_v().y);
			rk4_input.push_back(u->objects.at(i)->get_v().z);
			rk4_input.push_back(u->set_acc(i).x);
			rk4_input.push_back(u->set_acc(i).y);
			rk4_input.push_back(u->set_acc(i).z);
		}
	for (unsigned int i = 0; i < u->objects.size(); i++)
		{	
			rk4_output.push_back(u->objects.at(i)->get_pos().x);
			rk4_output.push_back(u->objects.at(i)->get_pos().y);
			rk4_output.push_back(u->objects.at(i)->get_pos().z);
			rk4_output.push_back(u->objects.at(i)->get_v().x);
			rk4_output.push_back(u->objects.at(i)->get_v().y);
			rk4_output.push_back(u->objects.at(i)->get_v().z);
		}
}


void Simulation::update_v_pos()
{
	float dt = 5;
	for (int j = 0; j <=100; j++)
		{
		for (unsigned int i = 0; i < rk4_input.size(); i++)
			{
				double k1 = dt * (rk4_input.at(i));
				double k2 = dt * (rk4_input.at(i) + (k1/2));
				double k3 = dt * (rk4_input.at(i) + (k2/2));
				double k4 = dt * (rk4_input.at(i) + (k3));
				rk4_output.at(i) = rk4_output.at(i) + ((k1+(2*k2)+(2*k3)+k4)/6);
				
			}
	if (j%10 == 0)
		{
			for (unsigned int i = 0; i < rk4_input.size(); i++){
				std::cout << rk4_output.at(i) << std::endl;
			}
		}
	}
}