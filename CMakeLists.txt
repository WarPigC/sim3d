cmake_minimum_required(VERSION 3.28)
project(sim3d)


# sets binary output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# tell clang lsp to not yell errors
# it tells lsp where to look for files in the directories
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

add_executable( 
	sim3d
	./src/main.cpp
	./src/pos.cpp
	./src/render.cpp
)

target_include_directories(sim3d PRIVATE ${CMAKE_SOURCE_DIR}/include)
