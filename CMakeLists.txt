cmake_minimum_required(VERSION 3.14)

project(TestLog4Qt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)

list(APPEND EXTRA_LIBS ${PROJECT_SOURCE_DIR}/Log4QtBin/lib/log4qt.lib)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/Log4QtBin/include")

add_executable(TestLog4Qt
  main.cpp
)
target_link_libraries(TestLog4Qt Qt${QT_VERSION_MAJOR}::Core ${EXTRA_LIBS})
target_include_directories(TestLog4Qt PUBLIC ${EXTRA_INCLUDES})
