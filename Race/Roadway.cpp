#include "stdafx.h"
#include "Roadway.h"


Roadway::Roadway()
: roadway_(1000, std::vector<char>(31, ' '))
{
}


Roadway::~Roadway()
{
}

void Roadway::initRoadway()
{
	for (int i = 0; i < 1000; i++) {
		if (i < 40) {
			for (int j = 0; j < 31; j++) {
				if (j == 2) {
					roadway_[i][j] = '#';
				}
				if (j = 12) {
					roadway_[i][j] = '|';
				}
				if (j == 22) {
					roadway_[i][j] = '#';
				}
			}
		}
		else if (i >= 40 && i < 46) {
			for (int j = 0; j < 31; j++) {
				if (j == 3 || j == 23 && i < 42) {
					roadway_[i][j] = '#';
				}
				else if (j == 4 || j == 24 && (i == 42 || i == 43)) {
					roadway_[i][j] = '#';
				}
				else if (j == 5 || j == 25 && (i == 44 || i == 45)) {
					roadway_[i][j] = '#';
				}
				if (j == 13 && i < 42) {
					roadway_[i][j] = '|';
				}
				else if (j == 14 && (i == 42 || i == 43)) {
					roadway_[i][j] = '|';
				}
				else if (j == 15 && (i == 44 || i == 45)) {
					roadway_[i][j] = '|';
				}
			}
		}
	}
}
