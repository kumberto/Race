#ifndef ROADWAY_H
#define ROADWAY_H

#include <vector>

class Roadway
{
	public:
		Roadway();
		~Roadway();
	private:
		void initRoadway();
		std::vector<std::vector<char>> roadway_;
};

#endif