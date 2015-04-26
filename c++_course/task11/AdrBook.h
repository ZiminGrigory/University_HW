#pragma once
#include <string>
#include <memory>
#include <map>

using namespace std;


class AdrBook
{
public:
	AdrBook();
	void add(const string& name, const string& town, const string& street, const string& house);
	void addHousemate(const string& newOneName, const string& name);
	void remove(const string& name);
	string addres(const string& name);

private:
	struct address
	{
		address(const string& town, const string& street, const string& house)
			: town(town), street(street), house(house)
		{
		}
		string makeAdr() {
			return town + " " + street + " " + house;
		}
		string town, street, house;
	};
	map<string, shared_ptr<address>> mAdrBook;
};
