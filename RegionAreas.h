#ifndef REGIONAREAS_H
#define REGIONAREAS_H

#include <iostream>
#include <vector>

#include "KeyValuePair.h"
#include "InputHelper.h"
#include "RegionArea.h"

using namespace std;

class RegionAreas
{
private:
	vector<RegionArea> areas;	
	vector<vector <int> > adjacencyList;
	int listSize;
	
public:
	RegionAreas();

	int size() const;
	RegionArea getArea(int areaId) const;

	void setAdjacencyList(vector <vector <int> > list);
	vector<vector <int> > getList();
	int getListSize();

	static RegionAreas loadFromFile(const string& fileName);
	void printAdjacency();
};

#endif


