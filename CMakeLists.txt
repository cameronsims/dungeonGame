cmake_minimum_required(VERSION 3.28)
project(RandomGeneratedDungeon)

# The OS Type
set(GUI_TYPE WIN32)

# The Files
file(GLOB SOURCE_FILES "src/*.cpp" "src/*/*.cpp")

# Setting an exe
add_executable(${PROJECT_NAME}  ${SOURCE_FILES})