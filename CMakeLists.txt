cmake_minimum_required(VERSION 3.28)
project(sim3d)


# sets binary output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# tell clang lsp to not yell errors
# it tells lsp where to look for files in the directories
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

include(FetchContent)

FetchContent_Declare(
	SDL3_image
	GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
	GIT_TAG main
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SDL3_image)

# get SDL3 from system and set it to required
find_package(SDL3 REQUIRED)


add_executable( 
	sim3d
	./src/main.cpp
	./src/pos.cpp
	./src/render.cpp
	./src/cube.cpp
)

target_include_directories(sim3d PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(sim3d PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

add_custom_target( run
	COMMAND sim3d
	DEPENDS sim3d
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
