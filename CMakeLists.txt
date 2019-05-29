cmake_minimum_required(VERSION 3.11)
project(memo)
set(CMAKE_CXX_STANDARD 14)

#=====================================================================================#
#|----------------------------------| INCLUDES |-------------------------------------|#
#=====================================================================================#

include_directories(sources)
include_directories(libs/PDCurses)

#=====================================================================================#
#|--------------------------------| SOURCE GROUPS |----------------------------------|#
#=====================================================================================#

file(GLOB SOURCES sources/*.cpp sources/*.h)
file(GLOB CURSES sources/Curses/*.cpp sources/Curses/*.h)
file(GLOB STATES sources/States/*.cpp sources/States/*.h)
file(GLOB STATES_NEW sources/States/NewState/*.cpp sources/States/NewState/*.h)
file(GLOB STATES_VIEW sources/States/ViewState/*.cpp sources/States/ViewState/*.h)

source_group("" FILES ${SOURCES})
source_group("Curses" FILES ${CURSES})
source_group("States" FILES ${STATES})
source_group("States\\NewState" FILES ${STATES_NEW})
source_group("States\\ViewState" FILES ${STATES_VIEW})

#=====================================================================================#
#|-----------------------------------| TARGETS |-------------------------------------|#
#=====================================================================================#

file(GLOB_RECURSE SOURCES sources/*.cpp sources/*.h)

add_executable(memo ${SOURCES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT memo)

#=====================================================================================#
#|----------------------------------| LINKAGE |--------------------------------------|#
#=====================================================================================#

set(PDCURSES_LIB ${CMAKE_SOURCE_DIR}/libs/PDCurses/build/pdcurses.lib)
target_link_libraries(memo ${PDCURSES_LIB})
