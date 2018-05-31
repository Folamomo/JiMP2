
project(subtract)

set(HEDEAR_FILES Subtract.h)
set(SOURCE_FILES Subtract.cpp)

add_library(libsubtract STATIC ${SOURCE_FILES})
target_include_directories(libsubtract PUBLIC .)

add_executable(subtract ${SOURCE_FILES} main.cpp)

target_link_libraries(subtract libsubtract)

