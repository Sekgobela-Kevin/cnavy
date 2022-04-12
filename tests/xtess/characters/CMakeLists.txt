cmake_minimum_required(VERSION 3.1)

add_library(xtesschrstestlib
    helpers/enable_characters_test.cpp

    character/character_test.cpp
    #characters/character_test.cpp

    characters/characters_test.cpp
    characters/bool_characters_test.cpp
    #characters/ratio_characters_test.cpp
    characters/summary_characters_test.cpp
    characters/static_compare_characters_test.cpp
    characters/compare_characters_test.cpp
    
    raw_token/raw_token_test.cpp
    raw_token/reference_token_test.cpp
)

target_include_directories(xtesschrstestlib PUBLIC helpers)