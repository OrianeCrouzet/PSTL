cmake_minimum_required(VERSION 3.15)
project(PSTL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

# Définition du chemin de SDL2
set(SDL2_PATH "/usr/include/SDL2")
set(SDL2_INCLUDE_DIR "${SDL2_PATH}/include/SDL2")
set(SDL2_LIB_DIR "${SDL2_PATH}/lib")
set(SDL2_DLL_DIR "${SDL2_PATH}/bin")

# Ajout des répertoires include
include_directories(${SDL2_INCLUDE_DIR} pop_source/utils)

# Ajout des répertoires de librairies
link_directories(${SDL2_LIB_DIR})

# Définition des fichiers sources
file(GLOB_RECURSE SRC_FILES "pop_source/source/*.c")
file(GLOB_RECURSE HEADER_FILES "pop_source/utils/*.h")

# Ajout de l'exécutable
add_executable(PSTL ${SRC_FILES} ${HEADER_FILES})

# Liaison avec SDL2
target_link_libraries(PSTL SDL2 SDL2main)

# Copier la DLL automatiquement après la compilation
add_custom_command(TARGET PSTL POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DLL_DIR}/SDL.dll"
        $<TARGET_FILE_DIR:PSTL>)
