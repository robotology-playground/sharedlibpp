/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include "MyMathCustom.h"
#include <SharedLibraryClass.h>

SHLIBPP_DEFINE_SHARED_SUBCLASS_CUSTOM(shlibpp::VOCAB('T', 'E', 'S', 'T'), shlibpp::VOCAB('T', 'S', 'E', 'T'), 42, my_math_custom, MyMathCustomImpl, MyMathCustom);

int MyMathCustomImpl::add(int a, int b)
{
    return (a+b);
}

int MyMathCustomImpl::sub(int a, int b)
{
    return (a-b);
}
