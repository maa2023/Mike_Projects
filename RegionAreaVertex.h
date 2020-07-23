#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include "RegionArea.h"

using namespace std;

class RegionAreaVertex
{
private:
	RegionArea value;
	vector<RegionAreaVertex*> adjacents;

public:
	RegionAreaVertex();
	RegionAreaVertex(RegionArea value);
	~RegionAreaVertex();

private:
	void operator delete(void*) {}

public:

	RegionArea getValue() const;
	void setValue(const RegionArea& value);

	const vector<RegionAreaVertex*>& getAdjacents();

	friend class RegionGraph;
};

#endif




