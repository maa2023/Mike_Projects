#include "RegionAreaVertex.h"

RegionAreaVertex::RegionAreaVertex()
{
}

RegionAreaVertex::RegionAreaVertex(RegionArea value) : value(value)
{
}

RegionAreaVertex::~RegionAreaVertex()
{
}

RegionArea RegionAreaVertex::getValue() const
{
	return value;
}

void RegionAreaVertex::setValue(const RegionArea& value)
{
	this->value = value;
}

const vector<RegionAreaVertex*>& RegionAreaVertex::getAdjacents()
{
	return adjacents;
}
