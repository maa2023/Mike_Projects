#include "VaccineDistributor.h"


VaccineDistributor::VaccineDistributor(RegionAreas& areas, int numOfVaccines, DistributionStrategy strategy) : numOfVaccines(numOfVaccines), strategy(strategy)
{
	//gets the adjacency list
	adjacencyMatrix = areas.getList();

	//creates an updatable list of the areas
	for (int i = 1; i < areas.size() + 1; i++) {
		this->areas.push_back(areas.getArea(i));
	}

	ClosenessDist::calcClosenessVals(adjacencyMatrix, this->areas);
}

void VaccineDistributor::simulate()
{
	if (strategy == CLOSENESS_CENTRALITY) {
		ClosenessDist::allocateVaccines(areas, numOfVaccines);
	} 
	else if (strategy == DEGREE_CENTRALITY) {
		// Degree centrality
	}
	else {
		// Random
	}
}
