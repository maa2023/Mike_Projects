#ifndef VACCINEDISTRIBUTOR_H
#define VACCINEDISTRIBUTOR_H

#include "RegionAreas.h"
#include "ClosenessDist.h"

enum DistributionStrategy {
	CLOSENESS_CENTRALITY,
	DEGREE_CENTRALITY,
	RANDOM
};

/**
 * This class is going to handle the vaccine distribution
 * It takes the Graph of the areas, and a distribution strategy, and the number of available vaccines
 * 
*/
class VaccineDistributor
{
private:
	vector<RegionArea> areas;
	vector <vector<int>> adjacencyMatrix;

	int numOfVaccines;
	DistributionStrategy strategy;

	VaccineDistributor();
public:
	VaccineDistributor(RegionAreas& areas, int numOfVaccines, DistributionStrategy strategy);
	void simulate();
};


#endif // !VACCINEDISTRIBUTOR_H
