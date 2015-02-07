#  Sharedlib++
#  Copyright: (C) 2015 Ali Paikan
#  Authors: Ali Paikan <ali.paikan@gmail.com>
#
#  Copy Policy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
#


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

