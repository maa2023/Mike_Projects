#ifndef REGIONAREA_H
#define REGIONAREA_H

class RegionArea
{
private:
	int id;
	int population;
	int susceptible;
	int infected;
	int recovered;
	int vaccinated;
	float cValue;

public:
	RegionArea();
	RegionArea(int id, int population, int susceptible, int infected, int recovered, int vaccinated, float cValue);

	int getId() const;
	void setId(int id);
	
	int getPopulation() const;
	void setPopulation(int population);
	
	int getSusceptible() const;
	void setSusceptible(int susceptible);
	
	int getInfected() const;
	void setInfected(int infected);
	
	int getRecovered() const;
	void setRecovered(int recovered);
	
	int getVaccinated() const;
	void setVaccinated(int vaccinated);
	
	float getCValue() const;
	void setCValue(float cValue);

	friend bool operator==(const RegionArea& lhs, const RegionArea& rhs);
	friend bool operator!=(const RegionArea& lhs, const RegionArea& rhs);
};

#endif

