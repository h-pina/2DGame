cmake_minimum_required(VERSION 3.10)
project(2DGame)

#list source files to be included in compilation
add_executable(${PROJECT_NAME} 
	external/glad/src/glad.c
	src/main.cpp
	src/Application.cpp
	src/Mesh.cpp
)

#Run glfw CMakeLists.txt 
add_subdirectory(external/glfw)

#list include directories 
target_include_directories(${PROJECT_NAME} 
	PUBLIC external/glfw/include
	PUBLIC external/glad/include
)

#list libraries to be included with -I
target_link_libraries(${PROJECT_NAME} glfw GL)
