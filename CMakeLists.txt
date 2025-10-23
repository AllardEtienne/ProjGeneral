# CMakeList.txt : projet CMake pour ProjGlobal, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.29)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (Projet  LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release) 


# Reference la toolchain conan
set(CMAKE_TOOLCHAIN_FILE out/conan_toolchain.cmake)
# Trouve et lie les bibliothèques
find_package(boost REQUIRED)
find_package(GTest REQUIRED)



add_library(ParceDecimal SHARED "ParceDecimal/ParceDecimal.cpp")
target_include_directories(ParceDecimal
	PUBLIC "ParceDecimal"
)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (ProjGlobal "ProjGlobal.cpp")
target_link_libraries(ProjGlobal PUBLIC ParceDecimal)


# TODO: Ajoutez des tests et installez des cibles si nécessaire.
