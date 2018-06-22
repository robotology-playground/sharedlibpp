# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

# cmake_minimum_required(VERSION 2.6)


include_directories(${CMAKE_SOURCE_DIR}
                    ../include)

add_library(mymath MODULE MyMath.cpp MyMath.h)

add_executable(math_test math_test.cpp)
target_link_libraries(math_test sharedlib++)
