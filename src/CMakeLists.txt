aux_source_directory(. SRC_LISTS)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
add_library(srclib ${SRC_LISTS})
#message(STATUS "mylib1的原文件：${SRC_LISTS}")