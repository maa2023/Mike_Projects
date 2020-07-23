#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "KeyValuePair.h"

using namespace std;

class InputHelper
{
private:
	/**
	 * Split a string using a delimiter and return a vector of the values
	 */
	static vector<string> split(const string& line, char delimiter);
public:
	/**
	 * Get a vector of key value pairs from the file
	 */
	static vector<KeyValuePair> getValuesFromFile(const string& fileName);

	/**
	 * Read a csv file in a matrix of values
	 */
	static vector<vector<string>> readCsv(const string& fileName);
};

#endif
