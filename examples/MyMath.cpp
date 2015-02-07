// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright: (C) 2015 shlib++
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include "MyMath.h"
#include <SharedLibraryClass.h>

SHLIBPP_DEFINE_SHARED_SUBCLASS(my_math, MyMathImpl, MyMath);

int MyMathImpl::add(int a, int b) 
{
	return (a+b);
}

int MyMathImpl::sub(int a, int b) 
{
	return (a-b);
}
