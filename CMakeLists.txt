cmake_minimum_required(VERSION 3.10)
project(Gratho VERSION 1.0 LANGUAGES CXX)

# add_library(items STATIC
#     src/items/Weapon.cpp
# )
# target_include_directories(items PUBLIC include)

add_library(characters STATIC
    src/characters/AttributeBoost.cpp
    src/characters/PlayerCharacterAncestry.cpp
    src/characters/PlayerCharacterClass.cpp
    src/characters/PlayerCharacterSheet.cpp
)
target_include_directories(characters PUBLIC include)
# target_link_libraries(characters PUBLIC items) 

add_executable(main_app src/main.cpp)
target_link_libraries(main_app PRIVATE characters) #add items or other library if necessary after characters