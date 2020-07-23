#ifndef CLOSENESS_H
#define CLOSENESS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <list>

#include "Config.h"
#include "RegionAreas.h"
#include "RegionArea.h"

using namespace std;

class ClosenessDist
{
	private:
	public:
		static void RunSim(Config &config, RegionAreas &areas);
		static void printDay(vector <RegionArea> &areas, int day);
		static bool BFS(vector <vector <int> > adj, int src, int dest, int v, int pred[], int dist[]);
		static int shortestDist(vector <vector<int> > adj, int s, int dest, int v);
		static void calcClosenessVals(vector<vector <int> > adjList, vector <RegionArea> &areas);
		static void allocateVaccines(vector <RegionArea> &areas, int vaccines);
};

#endif