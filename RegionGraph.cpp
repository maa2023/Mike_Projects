#include "RegionGraph.h"

RegionGraph::RegionGraph()
{
}

RegionGraph::~RegionGraph()
{
	for (unsigned i = 0; i < vertices.size(); i++)
	{
		delete vertices.at(i);
	}
}

unsigned int RegionGraph::size()
{
	return vertices.size();
}

RegionAreaVertex* RegionGraph::find(const RegionArea& value)
{
	RegionAreaVertex* vertex = nullptr;
	for(unsigned int i = 0; i < vertices.size(); i++)
	{
		if(vertices.at(i)->getValue() == value)
		{
			vertex = vertices.at(i);
			break;
		}
	}
	return vertex;
}

RegionAreaVertex* RegionGraph::add(const RegionArea& value)
{
	RegionAreaVertex* vertex = find(value);
	if (vertex == nullptr)
	{
		vertex = new RegionAreaVertex(value);
		vertices.push_back(vertex);
	}
	return vertex;
}

bool RegionGraph::addEdge(const RegionArea& u, const RegionArea& v)
{
	return addEdge(u, v, false);
}

bool RegionGraph::addEdge(const RegionArea& u, const RegionArea& v, bool isDirected)
{
	RegionAreaVertex* vertexU = find(u);
	if (vertexU == nullptr)
		return false;

	RegionAreaVertex* vertexV = find(v);
	if (vertexV == nullptr)
		return false;

	addEdge(vertexU, vertexV, isDirected);
	return true;
}

void RegionGraph::addEdge(RegionAreaVertex* u, RegionAreaVertex* v)
{
	addEdge(u, v, false);
}

void RegionGraph::addEdge(RegionAreaVertex* u, RegionAreaVertex* v, bool isDirected)
{
	u->adjacents.push_back(v);

	// If It's undirected, add an edge from the other direction
	if (!isDirected)
		v->adjacents.push_back(u);
}

const vector<RegionAreaVertex*>& RegionGraph::getVertices()
{
	return vertices;
}

RegionGraph* RegionGraph::initGraph(const RegionLayout& layout, const RegionAreas& areas)
{
	RegionGraph* graph = new RegionGraph();
	for(int i = 1; i < areas.size() + 1; i++)
	{
		graph->add(areas.getArea(i));
	}
	
	for(int i = 1; i < layout.getSize() + 1; i++)
	{
		for (int j = 1; j < layout.getSize() + 1; j++)
		{
			bool adjacency = layout.getAdjacency(i, j);
			if(adjacency)
			{
				RegionArea areaA = areas.getArea(i);
				RegionArea areaB = areas.getArea(j);
				graph->addEdge(areaA, areaB, true);
			}
		}
	}
	return graph;
}