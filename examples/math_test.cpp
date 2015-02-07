// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright: (C) 2015 shlib++
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <stdio.h>
#include "MyMath.h"

#include <SharedLibraryClass.h>
#include <SharedLibrary.h>


int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("Usage: %s <library file name>\n", argv[0]);
		printf("for example: %s libmymath.so\n", argv[0]);
		return 0;
	}

	// create an instance of shared library class factory to load the library
	printf("Loading the shared library... \n");
    shlibpp::SharedLibraryClassFactory<MyMath> myMathFactory(argv[1], "my_math");
    if (!myMathFactory.isValid()) {
        printf("error (%s) : %s\n", shlibpp::Vocab::decode(myMathFactory.getStatus()).c_str(),
                                    myMathFactory.getLastNativeError().c_str());
		return 1;
	}

	// create an instance of the class and call its functions
    shlibpp::SharedLibraryClass<MyMath> myMath(myMathFactory);    
	printf("Calling some of its functions... \n");
	printf("15 + 12 = %d\n", myMath->add(15, 12));
	printf("15 - 12 = %d\n", myMath->sub(15, 12));

    return 0;
}
