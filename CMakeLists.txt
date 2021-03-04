cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        main.cpp
        agtgraphicprimitiveifc.h
        agtgpline.h
        agtgpline.cpp
        agtTypPoint.h
        agtTypPoint.cpp
        agtTypColor.cpp
        agtTypColor.h
        agtgprectangle.cpp
        agtgprectangle.h
        agtgpdot.cpp
        agtgpdot.h
        agtgpcircle.cpp
        agtgpcircle.h
        agtmessagebroker.cpp
        agtmessagebroker.h
        agtobjecttree.cpp
        agtobjecttree.h
        tree.h)
#
# glfw
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(untitled PRIVATE glfw)


# glad
add_subdirectory(lib/glad EXCLUDE_FROM_ALL)
target_link_libraries(untitled PRIVATE glad)

