#include <vector>
#define CATCH_CONFIG_MAIN

#include "catch_amalgamated.hpp"
#include "trie.h"
#include <string>


SCENARIO("acceptance tests for trie")
{
   GIVEN("a trie")
   {
      Trie trie;

      THEN("the trie should be created empty")
      {
         REQUIRE(trie.num_words() == 0);
      }

      THEN("the longest and shortest words are empty")
      {
         REQUIRE(trie.shortest_word().empty());
         REQUIRE(trie.longest_word().empty());
      }

      THEN("the alphabetically first and last words are empty")
      {
         REQUIRE(trie.alphabetically_first().empty());
         REQUIRE(trie.alphabetically_last().empty());
      }

      WHEN("inserting one word that is a prefix of another into the trie")
      {
         trie.insert("on");
         trie.insert("one");

         THEN("there should be two words in the trie")
         {
            REQUIRE(trie.num_words() == 2);
         }

         THEN("there should be one word with that prefix in the trie")
         {
            std::vector<std::string> words = trie.words_with_prefix("on");

            REQUIRE(words.size() == 1);
            REQUIRE(words[0] == "one");
         }

         THEN("the trie only contains words, not substrings")
         {
            REQUIRE_FALSE(trie.contains("o"));
         }
      }

      WHEN("inserting two identical words")
      {
         trie.insert("foo");
         trie.insert("foo");

         THEN("they should not be duplicated")
         {
            REQUIRE(trie.num_words() == 1);
         }
      }

      WHEN("inserting the following words into the trie")
      {
         for (std::string word : {
            "apple",
            "rain",
            "zoo",
            "principle",
            "robot",
            "lake",
            "apron",
            "rotate",
            "article",
            "look",
            "fake"
         }) {
            trie.insert(word);
         }

         THEN("there should be 11 words")
         {
            REQUIRE(trie.num_words() == 11);
         }

         THEN("the longest word should be 'principle'")
         {
            REQUIRE(trie.longest_word() == "principle");
         }

         THEN("the shortest word should be 'zoo'")
         {
            REQUIRE(trie.shortest_word() == "zoo");
         }

         THEN("the alphabetically first word is 'apple'")
         {
            REQUIRE(trie.alphabetically_first() == "apple");
         }

         THEN("the alphabetically last word is 'zoo'")
         {
            REQUIRE(trie.alphabetically_last() == "zoo");
         }

         THEN("two words have prefix 'ap'")
         {
            std::vector<std::string> words = trie.words_with_prefix("ap");
            REQUIRE(words.size() == 2);
            REQUIRE(words[0] == "apple");
            REQUIRE(words[1] == "apron");
         }
      }
   }
}
