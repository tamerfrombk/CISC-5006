#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"

#include "linked_string.h"


SCENARIO("acceptance test for the implementation of LinkedString")
{
    GIVEN("an empty linked string")
    {
        LinkedString linked_string;

        WHEN("appending a single character 'c'")
        {
            linked_string.append('c');

            THEN("the linked_string should have a single character in it")
            {
                REQUIRE(linked_string.str() == "c");
            }
        }

        WHEN("appending a string")
        {
            linked_string.append("abc");

            THEN("the linked_string should have all the characters of the string in it")
            {
                REQUIRE(linked_string.str() == "abc");
            }
        }

        WHEN("removing a character")
        {
            linked_string.remove('a');

            THEN("the linked_string should still be empty")
            {
                REQUIRE(linked_string.empty());
            }
        }

        WHEN("clearing the string")
        {
            linked_string.clear();

            THEN("the linked_string should still be empty")
            {
                REQUIRE(linked_string.empty());
            }
        }

        WHEN("replacing any character with any other character")
        {
            linked_string.replace_all('c', 'd');

            THEN("the linked_string should still be empty")
            {
                REQUIRE(linked_string.empty());
            }
        }

        WHEN("getting the 0'th character")
        {
            char c = linked_string.at(0);

            THEN("the character should be NULL")
            {
                REQUIRE(c == '\0');
            }
        }

        WHEN("getting a substring from 0")
        {
            LinkedString str2 = linked_string.substr(0);

            THEN("the string returned should be empty")
            {
                REQUIRE(str2.empty());
            }
        }
    }

    GIVEN("a linked string with an initial string")
    {
        LinkedString linked_string("xyz");

        THEN("the linked_string should equal its initializing string")
        {
            linked_string.str() == "xyz";
        }

        WHEN("appending a single character 'c'")
        {
            linked_string.append('c');

            THEN("the linked_string should have c at the end")
            {
                REQUIRE(linked_string.str() == "xyzc");
            }
        }

        WHEN("appending a string")
        {
            linked_string.append("abc");

            THEN("the linked_string should have all the characters of the string appended")
            {
                REQUIRE(linked_string.str() == "xyzabc");
            }
        }

        WHEN("removing a character in the string")
        {
            linked_string.remove('x');

            THEN("the linked_string should not have the character in it")
            {
                REQUIRE(linked_string.str() == "yz");
            }
        }

        WHEN("the linked_string is cleared")
        {
            linked_string.clear();

            THEN("the string should now be empty")
            {
                REQUIRE(linked_string.empty());
            }
        }

        WHEN("replacing 'y' with any other character")
        {
            size_t num_replacements = linked_string.replace_all('y', 'd');

            THEN("the linked_string should have no instances of y")
            {
                REQUIRE(linked_string.str() == "xdz");
            }

            THEN("there should be one replacement")
            {
                REQUIRE(num_replacements == 1);
            }
        }

        WHEN("getting the 0'th character")
        {
            char c = linked_string.at(0);

            THEN("the character should be x")
            {
                REQUIRE(c == 'x');
            }
        }

        WHEN("getting a substring from 1")
        {
            LinkedString str2 = linked_string.substr(1);

            THEN("the string returned should be from index 1")
            {
                REQUIRE(str2.str() == "yz");
            }
        }
    }
}
