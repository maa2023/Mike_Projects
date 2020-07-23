#include "KeyValuePair.h"

KeyValuePair::KeyValuePair()
{
	key = "";
	value = "";
}

KeyValuePair::KeyValuePair(const string& key, const string& value)
{
	this->key = key;
	this->value = value;
}

string KeyValuePair::getKey() const
{
	return key;
}

void KeyValuePair::setKey(const string& key)
{
	this->key = key;
}

string KeyValuePair::getValue() const
{
	return value;
}

void KeyValuePair::setValue(const string& value)
{
	this->value = value;
}
