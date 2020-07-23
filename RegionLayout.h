#ifndef REGIONLAYOUT_H
#define REGIONLAYOUT_H

#include <vector>
#include <string>

#include "InputHelper.h"

using namespace std;

class RegionLayout
{
	int size;
	vector<vector<bool>> adjacencyMatrix;

public:
	RegionLayout(int size);

	int getSize() const;
	bool getAdjacency(int areaAId, int areaBId) const;
	void setAdjacency(int areaAId, int areaBId, bool adjacency);
	
	static RegionLayout loadFromFile(const string& fileName);
};

#endif
