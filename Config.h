#ifndef CONFIG_H
#define CONFIG_H

#include <string>

#include "KeyValuePair.h"
#include "InputHelper.h"

using namespace std;

class Config
{
private:
	static const string POPULATION_FILE;
	static const string REGION_FILE;
	static const string INFECTED_AREA;
	static const string INFECTIOUS_PERIOD;
	static const string CONTACT_RATE;
	static const string NUM_OF_VACCINES;
	
	string populationFile;
	string	regionFile;

	int infectedArea;
	int infectiousPeriod;
	int contactRate;
	int numOfVaccines;

public:
	Config();


	string getPopulationFile() const;
	void setPopulationFile(const string& populationFile);
	
	string getRegionFile() const;
	void setRegionFile(const string& regionFile);
	
	int getInfectedArea() const;
	void setInfectedArea(int infectedArea);
	
	int getInfectiousPeriod() const;
	void setInfectiousPeriod(int infectiousPeriod);
	
	int getContactRate() const;
	void setContactRate(int contactRate);
	
	int getNumOfVaccines() const;
	void setNumOfVaccines(int numOfVaccines);

	static Config loadFromFile(const string& fileName);
};

#endif


