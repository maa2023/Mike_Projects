#include "RegionAreas.h"

RegionAreas::RegionAreas()
{

}

int RegionAreas::size() const
{
	return areas.size();
}


RegionArea RegionAreas::getArea(int areaId) const
{
	return areas.at(areaId - 1);
}

RegionAreas RegionAreas::loadFromFile(const string& fileName)
{
	RegionAreas population;
	vector<KeyValuePair> values = InputHelper::getValuesFromFile(fileName);
	
	for (unsigned int i = 0; i < values.size(); i++)
	{
		population.areas.push_back(RegionArea());
	}
	
	for (unsigned int i = 0; i < values.size(); i++)
	{
		int key = stoi(values.at(i).getKey());
		int value = stoi(values.at(i).getValue());
		
		population.areas.at(key - 1).setId(key);
		population.areas.at(key - 1).setPopulation(value);
	}
	return population;
}

void RegionAreas::setAdjacencyList(vector <vector <int> > list){
	adjacencyList = list;
	listSize = list.size();
	return;
}
vector<vector <int> > RegionAreas::getList(){
	return adjacencyList;
}
int RegionAreas::getListSize(){
	return listSize;
}
void RegionAreas::printAdjacency(){
	for(int i = 0; i < adjacencyList.size(); i++){
		cout << i + 1 << " : ";
		for(int j = 0; j < adjacencyList[i].size(); j++){
			cout << adjacencyList[i][j] << " ";
		}
		cout << endl;
	}
	return;
}