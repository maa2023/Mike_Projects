#ifndef KEYVALUEPAIR_H
#define KEYVALUEPAIR_H

#include <string>

using namespace std;

class KeyValuePair
{
private:
	string key;
	string value;

public:
	KeyValuePair();
	KeyValuePair(const string& key, const string& value);

	string getKey() const;
	void setKey(const string& key);

	string getValue() const;
	void setValue(const string& value);
};

#endif
