#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include <list>

#include "RegionAreaVertex.h"
#include "RegionLayout.h"
#include "RegionAreas.h"

using namespace std;

class RegionGraph
{
private:
	vector<RegionAreaVertex*> vertices;

public:
	RegionGraph();
	~RegionGraph();

	unsigned int size();

	// nullptr if value is not found
	RegionAreaVertex* find(const RegionArea& value);

	// If the value is already there, it will return a pointer on its vertex
	// Else it will add it and return the new vertex
	RegionAreaVertex* add(const RegionArea& value);

	bool addEdge(const RegionArea& u, const RegionArea& v);
	bool addEdge(const RegionArea& u, const RegionArea& v, bool isDirected);

	void addEdge(RegionAreaVertex* u, RegionAreaVertex* v);
	void addEdge(RegionAreaVertex* u, RegionAreaVertex* v, bool isDirected);

	const vector<RegionAreaVertex*>& getVertices();

	static RegionGraph* initGraph(const RegionLayout& layout, const RegionAreas& areas);
	
};

#endif 