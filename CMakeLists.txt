cmake_minimum_required(VERSION 3.12)
project(pystats LANGUAGES CXX)

#---------------------------------------------------------------------------------------
# set default build to debug
#---------------------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose Release or Debug" FORCE)
endif()

#---------------------------------------------------------------------------------------
# compiler config
#---------------------------------------------------------------------------------------
set(CMAKE_CXX_EXTENSIONS OFF)

option(CODE_COVERAGE "Enable coverage reporting" OFF)
option(BUILD_TESTS "Build unit tests" OFF)

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

if(BUILD_TESTS)
	enable_testing()
#	add_subdirectory(tests)
endif()

add_subdirectory(deps)

pybind11_add_module(pystats
	src/pystats.cpp
	src/Utils.cpp
	src/Bernoulli.cpp
	src/Beta.cpp
	src/Binomial.cpp
	src/Cauchy.cpp
	src/ChiSquared.cpp
	src/Exponential.cpp
	src/F.cpp
	src/Gamma.cpp
	src/Inverse-Gamma.cpp
	src/Laplace.cpp
	src/Log-Normal.cpp
	src/Logistic.cpp
	src/Normal.cpp
	src/Poisson.cpp
	src/StudentT.cpp
	src/Uniform.cpp
	src/Weibull.cpp)

target_link_libraries(pystats PRIVATE gcem stats)
target_include_directories(pystats PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
