cmake_minimum_required(VERSION 3.17)
project(Exams)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARIES
        gtest
        pthread)
add_executable(part_1 main.cpp exam_details_test.cpp sorted_list_test.cpp examDetails.cpp examDetails.h sortedList.h)
target_link_libraries(part_1 ${LIBRARIES})