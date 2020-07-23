#include "RegionArea.h"

RegionArea::RegionArea()
{
	id = 0;
	population = 0;
	susceptible = 0;
	infected = 0;
	recovered = 0;
	vaccinated = 0;
	cValue = 0;
}

RegionArea::RegionArea(int id, int population, int susceptible, int infected, int recovered, int vaccinated, float cValue)
{
	this->id = id;
	this->population = population;
	this->susceptible = susceptible;
	this->infected = infected;
	this->recovered = recovered;
	this->vaccinated = vaccinated;
	this->cValue = cValue;
}


int RegionArea::getId() const
{
	return id;
}

void RegionArea::setId(const int id)
{
	this->id = id;
}

int RegionArea::getPopulation() const
{
	return population;
}

void RegionArea::setPopulation(const int population)
{
	this->population = population;
}

int RegionArea::getSusceptible() const
{
	return susceptible;
}

void RegionArea::setSusceptible(const int susceptible)
{
	this->susceptible = susceptible;
}

int RegionArea::getInfected() const
{
	return infected;
}

void RegionArea::setInfected(const int infected)
{
	this->infected = infected;
}

int RegionArea::getRecovered() const
{
	return recovered;
}

void RegionArea::setRecovered(const int recovered)
{
	this->recovered = recovered;
}

int RegionArea::getVaccinated() const
{
	return vaccinated;
}

void RegionArea::setVaccinated(const int vaccinated)
{
	this->vaccinated = vaccinated;
}
	
float RegionArea::getCValue() const
{
	return cValue;
}

void RegionArea::setCValue(float cValue)
{
	this->cValue = cValue;
}

bool operator==(const RegionArea& lhs, const RegionArea& rhs)
{
	return lhs.id == rhs.id;
}

bool operator!=(const RegionArea& lhs, const RegionArea& rhs)
{
	return !(lhs == rhs);
}
