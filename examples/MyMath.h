// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright: (C) 2015 shlib++
 * Authors: Ali Paikan
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#ifndef _MYMATH_H_
#define _MYMATH_H_

class MyMath {
public:
    virtual int add(int a, int b) = 0;
    virtual int sub(int a, int b) = 0;
};

class MyMathImpl : public MyMath {
public:
	int add(int a, int b);
    int sub(int a, int b);
};

#endif //_MYMATH_H_
