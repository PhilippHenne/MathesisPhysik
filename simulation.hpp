#include <iostream>
#include <vector>
#include "universum.hpp"

class Simulation
{
	public:
		universe* u;
		std::vector<double> rk4_input;
		std::vector<double> rk4_output;
		Simulation(universe*);
		void update_v_pos();
};