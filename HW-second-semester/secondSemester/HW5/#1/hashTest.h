#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "hashTable.h"
#include "hasher.h"

class HashTest : public QObject
{
  Q_OBJECT
public:
  explicit HashTest(QObject *parent = 0) : QObject(parent) {}

private slots:
  void init()
  {
      hashTable = new HashTable();
      hashTable->chooseHasher(&function1);
  }

  void cleanup()
  {
      delete hashTable;
  }

  void testAdd()
  {
      hashTable->addValue("I am Grigory");
      QVERIFY(hashTable->searchValue("I am Grigory"));

  }
  void testRemove()
  {
      hashTable->addValue("books");
      hashTable->deleteValue("computer");
      hashTable->deleteValue("books");
      QVERIFY(hashTable->searchValue("books") == 0);
  }

  void differentHashFunc()
  {
      hashTable->chooseHasher(&function1);
      hashTable->addValue("books");
      QVERIFY(hashTable->searchValue("books"));
      hashTable->chooseHasher(&function2);
      QVERIFY(hashTable->searchValue("books") == 1);
  }

  void printStatistic()
  {
      hashTable->addValue("books");
      hashTable->addValue("books");
      hashTable->addValue("books");
      hashTable->giveStatistics();
  }


private:
    HashTable *hashTable;
    SimpleHasher function1;
    NormalHasher function2;
};

