
project(templates)

set(HEDEAR_FILES Templates.h)
set(SOURCE_FILES Templates.cpp)

add_library(libtemplates STATIC ${SOURCE_FILES})
target_include_directories(libtemplates PUBLIC .)

add_executable(templates ${SOURCE_FILES} main.cpp)

target_link_libraries(templates libtemplates)

