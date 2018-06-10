#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <iostream>
#include "../repository/list.h"
#include "../repository/entry.h"
#include "../repository/hash_table.h"

TEST_CASE( "List", "[adding, deleting, searching, sorting]" ) {

  SECTION("Init empty list") {
    auto list = new List();
    REQUIRE(list->count() == 0);
  }

  SECTION("Adding elements at the beginning") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_4 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_5 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_3 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    list->insertFirst(entry_1);
    list->insertFirst(entry_2);
    list->insertFirst(entry_3);
    list->insertFirst(entry_4);
    list->insertFirst(entry_5);
    list->insertFirst(entry_6);
    list->insertFirst(entry_7);

    REQUIRE(list->count() == 7);
  }

  SECTION("Deleting elements at the beginning") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_4 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_5 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_3 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    list->insertFirst(entry_1);
    list->insertFirst(entry_2);
    list->insertFirst(entry_3);
    list->insertFirst(entry_4);
    list->insertFirst(entry_5);
    list->insertFirst(entry_6);
    list->insertFirst(entry_7);

    REQUIRE(list->count() == 7);

    auto deletedEntry_1 = list->deleteFirst();
    auto deletedEntry_2 = list->deleteFirst();

    REQUIRE(list->count() == 5);
    REQUIRE(deletedEntry_1->data->email == "kill_bill@movie.com");
    REQUIRE(deletedEntry_2->data->email == "disney@disney.com");
  }

  SECTION("Deleting specific element") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_4 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_5 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_3 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    list->insertFirst(entry_1);
    list->insertFirst(entry_2);
    list->insertFirst(entry_3);
    list->insertFirst(entry_4);
    list->insertFirst(entry_5);
    list->insertFirst(entry_6);
    list->insertFirst(entry_7);

    REQUIRE(list->count() == 7);

    auto deletedEntry_1 = list->deleteElement(entry_3);

    REQUIRE(list->count() == 6);
    REQUIRE(deletedEntry_1->data->email == "serious_sam@gmail.com");
  }

  SECTION("Deleting from a single element") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    list->insertFirst(entry_1);
    REQUIRE(list->count() == 1);
    auto deletedEntry_1 = list->deleteElement(entry_1);
    REQUIRE(list->count() == 0);
    REQUIRE(deletedEntry_1->data->email == "babyboy@yahoo.com");
  }


  SECTION("Retrive specific item") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_4 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_5 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_3 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    list->insertFirst(entry_1);
    list->insertFirst(entry_2);
    list->insertFirst(entry_3);
    list->insertFirst(entry_4);
    list->insertFirst(entry_5);
    list->insertFirst(entry_6);
    list->insertFirst(entry_7);

    REQUIRE(list->count() == 7);

    auto item_found = list->getElement("notworthy@gmail.com");
    REQUIRE(item_found->data->email == "notworthy@gmail.com");
  }

  SECTION("Sorting the list") {
    auto list = new List();
    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_3 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_4 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_5 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    list->insertFirst(entry_1);
    list->insertFirst(entry_2);
    list->insertFirst(entry_3);
    list->insertFirst(entry_4);
    list->insertFirst(entry_5);
    list->insertFirst(entry_6);
    list->insertFirst(entry_7);

    REQUIRE(list->count() == 7);
    // list->sort();
  }
}

TEST_CASE( "HashTable", "[adding, deleting, searching, sorting]" ) {

  SECTION("Emtpy init") {
    auto ht = new HashTable();
    REQUIRE(ht->count() == 0);
  }


  SECTION("Add to hashTable") {
    auto ht = new HashTable();

    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_3 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_4 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_5 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    ht->add(entry_1);
    ht->add(entry_2);
    ht->add(entry_3);
    ht->add(entry_4);
    ht->add(entry_5);
    ht->add(entry_6);
    REQUIRE(ht->count() == 6);
  }

  SECTION("Remove from hashTable") {
    auto ht = new HashTable();

    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_3 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_4 = new Entry(20, "Yang Gi", "notworthy@gmail.com");
    auto entry_5 = new Entry(10, "Wu Tang", "serious_sam@gmail.com");
    auto entry_6 = new Entry(999, "Mu Lan", "disney@disney.com");
    auto entry_7 = new Entry(12345, "Zhou Ma", "kill_bill@movie.com");

    ht->add(entry_1);
    ht->add(entry_2);
    ht->add(entry_3);
    ht->add(entry_4);
    REQUIRE(ht->count() == 4);
    ht->remove(entry_4->email);
    ht->remove(entry_1->email);
    REQUIRE(ht->count() == 2);
  }

  SECTION("Test HT iterator") {
    auto ht = new HashTable();
    HashTableIterator* iter = new HashTableIterator(ht);
    iter->next();
    REQUIRE(iter->valid() == false);

    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_3 = new Entry(30, "Lao Liew", "nospam@hotmail.com");

    ht->add(entry_1);
    ht->add(entry_2);
    ht->add(entry_3);

    iter->next();
    REQUIRE(iter->valid() == true);
    iter->next();
    REQUIRE(iter->valid() == true);
    iter->next();
    REQUIRE(iter->valid() == false);
  }

  SECTION("Test HT iterator") {
    auto ht = new HashTable();
    HashTableIterator* iter = new HashTableIterator(ht);
    iter->next();
    REQUIRE(iter->valid() == false);

    auto entry_1 = new Entry(1, "Zhāng Li", "babyboy@yahoo.com");
    auto entry_2 = new Entry(10, "Wang Chu", "i_hate_monday@gmail.com");
    auto entry_3 = new Entry(30, "Lao Liew", "nospam@hotmail.com");
    auto entry_4 = new Entry(20, "Yang Gi", "notworthy@gmail.com");

    ht->add(entry_4);
    ht->add(entry_1);
    ht->add(entry_2);
    ht->add(entry_3);

    iter->next();
    REQUIRE(iter->valid() == true);
    REQUIRE(iter->getCurrent()->data->email == "nospam@hotmail.com");

    iter->next();
    REQUIRE(iter->valid() == true);
    REQUIRE(iter->getCurrent()->data->email == "i_hate_monday@gmail.com");

    iter->next();
    REQUIRE(iter->valid() == true);
    REQUIRE(iter->getCurrent()->data->email == "babyboy@yahoo.com");
  }
}
