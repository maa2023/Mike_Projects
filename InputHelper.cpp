#include "InputHelper.h"

vector<string> InputHelper::split(const string& line, char delimiter)
{
	vector<string> tokens;
	stringstream lineStream(line);
	string token;
	while(getline(lineStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

vector<KeyValuePair> InputHelper::getValuesFromFile(const string& fileName)
{
	vector<KeyValuePair> values;
	ifstream file;
	
	file.open(fileName);
	if (!file.good())
	{
		return values;
	}

	string line;
	while (getline(file, line))
	{
		if(!line.empty())
		{
			KeyValuePair keyValuePair;
			vector<string> tokens = split(line, ':');
			if (tokens.size() >= 1)
				keyValuePair.setKey(tokens.at(0));
			if (tokens.size() >= 2)
				keyValuePair.setValue(tokens.at(1));
			values.push_back(keyValuePair);
		}
	}
	return values;
}

vector<vector<string>> InputHelper::readCsv(const string& fileName)
{
	vector<vector<string>> data;
	ifstream file;

	file.open(fileName);
	if (!file.good())
	{
		return data;
	}

	string line;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			vector<string> values = split(line, ',');
			data.push_back(values);
		}
	}
	return data;
}
