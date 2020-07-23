#include "Config.h"

const string Config::POPULATION_FILE = "Population";
const string Config::REGION_FILE = "Region";
const string Config::INFECTED_AREA = "Infected Area";
const string Config::INFECTIOUS_PERIOD = "Infectious Period";
const string Config::CONTACT_RATE = "Contact Rate";
const string Config::NUM_OF_VACCINES = "Number of Vaccines";

Config::Config()
{
	populationFile = "";
	regionFile = "";

	infectedArea = 0;
	infectiousPeriod = 0;
	contactRate = 0;
	numOfVaccines = 0;
}

string Config::getPopulationFile() const
{
	return populationFile;
}

void Config::setPopulationFile(const string& populationFile)
{
	this->populationFile = populationFile;
}

string Config::getRegionFile() const
{
	return regionFile;
}

void Config::setRegionFile(const string& regionFile)
{
	this->regionFile = regionFile;
}

int Config::getInfectedArea() const
{
	return infectedArea;
}

void Config::setInfectedArea(const int infectedArea)
{
	this->infectedArea = infectedArea;
}

int Config::getInfectiousPeriod() const
{
	return infectiousPeriod;
}

void Config::setInfectiousPeriod(const int infectiousPeriod)
{
	this->infectiousPeriod = infectiousPeriod;
}

int Config::getContactRate() const
{
	return contactRate;
}

void Config::setContactRate(const int contactRate)
{
	this->contactRate = contactRate;
}

int Config::getNumOfVaccines() const
{
	return numOfVaccines;
}

void Config::setNumOfVaccines(const int numOfVaccines)
{
	this->numOfVaccines = numOfVaccines;
}

Config Config::loadFromFile(const string& fileName)
{
	Config config;
	vector<KeyValuePair> values = InputHelper::getValuesFromFile(fileName);
	for (unsigned int i = 0; i < values.size(); i++)
	{
		string key = values.at(i).getKey();
		string value = values.at(i).getValue();

		if (key == POPULATION_FILE)
			config.populationFile = value;
		else if (key == REGION_FILE)
			config.regionFile = value;
		else if (key == INFECTED_AREA)
			config.infectedArea = stoi(value);
		else if (key == INFECTIOUS_PERIOD)
			config.infectiousPeriod = stoi(value);
		else if (key == CONTACT_RATE)
			config.contactRate = stoi(value);
		else if (key == NUM_OF_VACCINES)
			config.numOfVaccines = stoi(value);	
	}
	return config;
}
