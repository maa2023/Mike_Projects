#include "RegionLayout.h"

RegionLayout::RegionLayout(int size)
{
	this->size = size;
	for(int i = 0; i < size; i++)
	{
		vector<bool> row;
		for (int j = 0; j < size; j++)
		{
			row.push_back(false);
		}
		adjacencyMatrix.push_back(row);
	}
}

int RegionLayout::getSize() const
{
	return size;
}

bool RegionLayout::getAdjacency(int areaAId, int areaBId) const
{
	return adjacencyMatrix.at(areaAId - 1).at(areaBId - 1);
}

void RegionLayout::setAdjacency(int areaAId, int areaBId, bool adjacency)
{
	adjacencyMatrix.at(areaAId - 1).at(areaBId - 1) = adjacency;
}

RegionLayout RegionLayout::loadFromFile(const string& fileName)
{
	vector<vector<string>> data = InputHelper::readCsv(fileName);
	int size = data.size() - 1;
	RegionLayout layout(size);
	
	for (int i = 1; i < size + 1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			bool adjacency = stoi(data.at(i).at(j));
			layout.setAdjacency(i, j, adjacency);
		}
	}
	return layout;
}
