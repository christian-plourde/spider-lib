cmake_minimum_required(VERSION 3.14)
project(SpiderLib)

set(CMAKE_CXX_STANDARD 17)
include_directories(Data_Structures)
include_directories(Utilities)
add_library(SpiderLib SHARED Data_Structures/Linked_List/LinkedList.cpp Utilities/SmartPointer.cpp Utilities/Clock.cpp)