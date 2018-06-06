#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../repository/hash_table.h"

TEST_CASE( "HashTable", "[init]" ) {
  HashTable* ht = new HashTable();
	int *c;
	c = new int[M];
	string *v;
	v = new string[M];

  SECTION("init") {
    REQUIRE( ht->isEmpty() == true );
    REQUIRE( ht->size() == 0 );
  }

  SECTION("Adding elements") {
    REQUIRE(ht->add(3, "Lolita") == true); // pos 3
    REQUIRE(ht->add(6, "Tess of the D'Urbervilles") == true); // pos 6
    REQUIRE(ht->add(29, "Anna Karenina") == true); // pos 0
    REQUIRE(ht->add(32, "Karamazov Brothers") == true); // pos 1
    REQUIRE(ht->add(13, "Jane Eyre") == true); // pos 2
    REQUIRE(ht->add(3, "Pride and Prejudice") == true); // pos 4
    REQUIRE(ht->add(3, "Lolita") == false); // pos 3
  }
}
