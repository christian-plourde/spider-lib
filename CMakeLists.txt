cmake_minimum_required(VERSION 3.14)
project(SpiderLib)

set(CMAKE_CXX_STANDARD 17)
link_directories(Data_Structures)
link_directories(Utilities)
add_library(SpiderLib SHARED Data_Structures/Linked_List/LinkedList.cpp Utilities/SmartPointer.cpp)