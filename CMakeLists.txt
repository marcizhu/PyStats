cmake_minimum_required(VERSION 3.12)
project(PyStats LANGUAGES CXX)

#---------------------------------------------------------------------------------------
# set default build to debug
#---------------------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

#---------------------------------------------------------------------------------------
# project config
#---------------------------------------------------------------------------------------
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
	src/T.cpp
	src/Uniform.cpp
	src/Weibull.cpp)

find_package(OpenMP)
if(OpenMP_CXX_FOUND AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
	message(STATUS "OpenMP: Enabled")
	target_link_libraries(pystats PUBLIC OpenMP::OpenMP_CXX)
else()
	message(AUTHOR_WARNING "OpenMP: DISABLED")
endif()

target_link_libraries(pystats PRIVATE gcem stats)
target_include_directories(pystats PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
