
project(academiaqueries)

set(HEDEAR_FILES AcademiaQueries.h)
set(SOURCE_FILES AcademiaQueries.cpp)

add_library(libacademiaqueries STATIC ${SOURCE_FILES})
target_include_directories(libacademiaqueries PUBLIC .)

add_executable(academiaqueries ${SOURCE_FILES} main.cpp)

target_link_libraries(academiaqueries libacademiaqueries)

