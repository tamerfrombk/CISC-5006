ADD_LIBRARY(catch STATIC catch_amalgamated.cpp)
TARGET_INCLUDE_DIRECTORIES(catch PRIVATE ${CMAKE_PROJECT_DIR})

ADD_EXECUTABLE(open_hash_table_tests open_hash_table_tests.cpp)
TARGET_LINK_LIBRARIES(open_hash_table_tests PRIVATE catch)
TARGET_INCLUDE_DIRECTORIES(open_hash_table_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

ADD_EXECUTABLE(trie_tests trie_tests.cpp)
TARGET_LINK_LIBRARIES(trie_tests PRIVATE catch)
TARGET_INCLUDE_DIRECTORIES(trie_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)