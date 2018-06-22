/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef _SHLIBPP_YARPSHAREDLIBRARYCLASSFACTORY_
#define _SHLIBPP_YARPSHAREDLIBRARYCLASSFACTORY_

#include <SharedLibraryFactory.h>

namespace shlibpp {

/**
 *
 * A type-safe wrapper for SharedLibraryFactory, committing to
 * creation/destruction of instances of a particular super-class.
 * Note that we take on faith that the named factory method in the
 * named shared library does in fact create the named type.
 *
 */
template <class T>
class SharedLibraryClassFactory : public SharedLibraryFactory
{
public:
    SharedLibraryClassFactory()
    {
    }

    SharedLibraryClassFactory(const char *dll_name, const char *fn_name = 0/*nullptr*/) :
            SharedLibraryFactory(dll_name,fn_name)
    {
    }

    T *create() const
    {
        if (!isValid()) {
            return nullptr;
        }
        return (T *)getApi().create();
    }

    void destroy(T *obj) const
    {
        if (!isValid()) {
            return;
        }
        getApi().destroy(obj);
    }
};

} // namespace shlibpp

#endif
