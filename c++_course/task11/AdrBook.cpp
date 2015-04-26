#include "AdrBook.h"

AdrBook::AdrBook()
{
}

void AdrBook::add(const string &name, const string &town, const string &street, const string &house)
{
	mAdrBook.insert(make_pair(name, make_shared<address>(town, street, house)));
}

void AdrBook::addHousemate(const string &newOneName, const string &name)
{
	mAdrBook.insert(make_pair(newOneName, move(mAdrBook[name])));
}

void AdrBook::remove(const string &name)
{
	mAdrBook.erase(name);
}

string AdrBook::addres(const string &name)
{
	return mAdrBook[name]->makeAdr();
}
