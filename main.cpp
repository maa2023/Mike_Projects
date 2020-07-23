#include <iostream>
#include <fstream>

#include "InputHelper.h"
#include "Config.h"
#include "RegionAreas.h"
#include "RegionLayout.h"
#include "RegionGraph.h"
#include "ClosenessDist.h"
#include "VaccineDistributor.h"

using namespace std;

string getFileNameFromUser(const string& message);
bool isFileExists(string fileName);

void printPopulations(const RegionAreas& areas);
void printRegionGraph(RegionGraph* graph, RegionAreas &areas);

int main()
{
	string configFile = getFileNameFromUser("Please enter the name of the configuration file:");
	Config config = Config::loadFromFile(configFile);
	RegionAreas areas = RegionAreas::loadFromFile(config.getPopulationFile());
	RegionLayout regionLayout = RegionLayout::loadFromFile(config.getRegionFile());
	RegionGraph* regionGraph = RegionGraph::initGraph(regionLayout, areas);
	ClosenessDist CDSim;

	DistributionStrategy strategy = CLOSENESS_CENTRALITY;
	VaccineDistributor vaccineDistributor(areas, config.getNumOfVaccines(), strategy);

	// Output populations
	printPopulations(areas);

	// Output graph
	printRegionGraph(regionGraph, areas);
	
	vaccineDistributor.simulate();
	// Output Closeness Distribtion
	CDSim.RunSim(config, areas);
	
	// Destroy graph before exiting
	delete regionGraph;
	return 0;
}

string getFileNameFromUser(const string& message)
{
	bool success = false;
	string fileName;
	while (!success)
	{
		cout << message;
		cin >> fileName;
		if (isFileExists(fileName)) {
			success = true;
		}
		else
		{
			cout << "File not found." << endl;
		}
	}
	return fileName;
}

bool isFileExists(string fileName)
{
	ifstream file;
	file.open(fileName);
	bool result = file.good();
	file.close();
	return result;
}

void printPopulations(const RegionAreas& areas)
{
	cout << "Regional Population" << endl;
	for (int i = 1; i < areas.size() + 1; i++)
	{
		cout << i << " " << areas.getArea(i).getPopulation() << endl;
	}
	cout << endl;
}

void printRegionGraph(RegionGraph* graph, RegionAreas &areas)
{
	cout << "Adjacency List" << endl;
	vector <vector <int> > adjacencyList;
	vector <int> neighbors;
	
	for (unsigned int i = 0; i < graph->size(); i++)
	{
		RegionAreaVertex* areaVertex = graph->getVertices().at(i);
		cout << areaVertex->getValue().getId() << ": ";
		for (unsigned int j = 0; j < areaVertex->getAdjacents().size(); j++)
		{
			RegionAreaVertex* adjacent = areaVertex->getAdjacents().at(j);
			int i = adjacent->getValue().getId();
			neighbors.push_back(i - 1);
			cout << i;
			if (j < areaVertex->getAdjacents().size() - 1)
			{
				cout << " ";
			}
		}
		adjacencyList.push_back(neighbors);
		neighbors.clear();
		cout << endl;
	}
	areas.setAdjacencyList(adjacencyList);
	
	
	cout << endl;
}

