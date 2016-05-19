#include <iostream>
#include <vector>
#include "simulation.hpp"
//include "universum.hpp"

using namespace std;

int main()
{
	universe* u1 = new universe(1);
	cout << u1->asString() <<  endl;

	Simulation* sim = new Simulation(u1);
	sim->update_v_pos();
	
	delete u1;
	delete sim;
}