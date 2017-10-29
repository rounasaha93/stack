cmake_minimum_required(VERSION 3.8)
project(Stack)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Stack.cpp Stack.h StackByInheritence.cpp StackByInheritence.h LinearList.h SwitBoxApplication.cpp binaryNumberConversion.cpp ChainNode.h LinkedListChain.h StackByLL.cpp StackByLL.h)
add_executable(Stack ${SOURCE_FILES} SwitBoxApplication.cpp)