# Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

# cmake_minimum_required(VERSION 2.6)


INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}
                    ../include)

ADD_LIBRARY(mymath SHARED MyMath.cpp MyMath.h)


IF(WIN32)
    LINK_LIBRARIES(sharedlib++)
ELSE()
    LINK_LIBRARIES(sharedlib++ dl)
ENDIF()

ADD_EXECUTABLE(math_test math_test.cpp)

