#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
// #include "../repository/hash_table.h"
#include "../repository/list.h"
#include "../repository/entry.h"

// TEST_CASE( "HashTable", "[init]" ) {
//   HashTable* ht = new HashTable();
// 	int *c;
// 	c = new int[M];
// 	string *v;
// 	v = new string[M];

//   SECTION("init") {
//     REQUIRE( ht->isEmpty() == true );
//     REQUIRE( ht->size() == 0 );
//   }

//   SECTION("Adding elements") {
//     REQUIRE(ht->add(3, "Lolita") == true); // pos 3
//     REQUIRE(ht->add(6, "Tess of the D'Urbervilles") == true); // pos 6
//     REQUIRE(ht->add(29, "Anna Karenina") == true); // pos 0
//     REQUIRE(ht->add(32, "Karamazov Brothers") == true); // pos 1
//     REQUIRE(ht->add(13, "Jane Eyre") == true); // pos 2
//     REQUIRE(ht->add(3, "Pride and Prejudice") == true); // pos 4
//     REQUIRE(ht->add(3, "Lolita") == false); // pos 3
//   }
// }


TEST_CASE( "HashTable", "[init]" ) {

  SECTION("Init empty list") {
    auto list = new List();
    REQUIRE(list->count() == 0);
  }

  SECTION("Adding elements") {
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
}
