#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "open_addressed_hash_table.h"
#include <string>


SCENARIO("acceptance tests for open addressed hash table")
{
   GIVEN("a hash table with integer keys and string values")
   {
      OpenAddressedHashTable<std::string> hash_table;

      THEN("the hash table should be created empty")
      {
         REQUIRE(hash_table.num_elements() == 0);
      }

      WHEN("mapping 2 to 'foo'")
      {
         hash_table.insert(2, "foo");

         THEN("2 should be in the hash table and the size is 1")
         {
            REQUIRE(hash_table.contains(2));
            REQUIRE(hash_table.num_elements() == 1);
         }

         THEN("3 should not be in the hash table")
         {
            REQUIRE_FALSE(hash_table.contains(3));
         }

         THEN("2 should be mapped to 'foo'")
         {
            REQUIRE(hash_table.get_value(2, "bar") == "foo");
         }

         THEN("3 should be mapped to 'bar' because it is not in the hash table")
         {
            REQUIRE(hash_table.get_value(3, "bar") == "bar");
         }

         THEN("updating 2 to 'cat' should store 'cat'")
         {
            hash_table.update(2, "cat");

            REQUIRE(hash_table.get_value(2, "dog") == "cat");
         }

         THEN("updating a non existent key should insert it")
         {
            hash_table.update(3, "fire");

            REQUIRE(hash_table.get_value(3, "water") == "fire");
         }

         THEN("inserting 2 again should not update the value")
         {
            hash_table.insert(2, "cat");
            
            REQUIRE(hash_table.get_value(2, "dog") == "foo");
         }
      }

      AND_GIVEN("that the hash table has an initial capacity of 5")
      {
         THEN("inserting 6 elements should trigger a resize")
         {
            for (int i = 1; i <= 6; ++i) {
               hash_table.insert(i, std::to_string(i));
            }

            REQUIRE(hash_table.num_elements() == 6);

            AND_THEN("all the elements should still exist after resizing")
            {
               for (int i = 1; i <= 6; ++i) {
                  REQUIRE(hash_table.contains(i));
               }
            }
         }
      }
   }
}
