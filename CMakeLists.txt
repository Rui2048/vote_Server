cmake_minimum_required(VERSION 3.10)
project(test)
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
#add_subdirectory(${PROJECT_SOURCE_DIR}/protobuf)
include_directories(${PROJECT_SOURCE_DIR}/include)
aux_source_directory(${PROJECT_SOURCE_DIR} SRC_LISTS)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBS srclib protolib protobuf)

link_directories(BEFORE ${PROJECT_BINARY_DIR}/lib)

add_executable(server ${SRC_LISTS})
#add_dependencies(server mylib1 mylib2)

target_link_libraries(server ${LIBS})
