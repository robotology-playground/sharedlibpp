// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2011 Department of Robotics Brain and Cognitive Sciences - Istituto Italiano di Tecnologia
 * Authors: Ali Paikan and Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#include <cstddef>

#if defined(_WIN32)
#  include <windows.h>
#else
#  include <dlfcn.h>
#endif

#include <SharedLibrary.h>

using namespace shlibpp;


SharedLibrary::SharedLibrary() :
    implementation(nullptr) {
}

SharedLibrary::SharedLibrary(const char *filename) :
    implementation(nullptr) {
    open(filename);
}

SharedLibrary::~SharedLibrary() {
    close();
}

bool SharedLibrary::open(const char *filename) {
    err_message.clear();
    close();
#if defined(_WIN32)
    implementation = (void*)LoadLibrary(filename);
    LPTSTR msg = nullptr;
    FormatMessage(
       FORMAT_MESSAGE_FROM_SYSTEM |FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
       nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
       (LPTSTR)&msg, 0, nullptr);

    if(msg != nullptr) {
        err_message = std::string(msg);
       // release memory allocated by FormatMessage()
       LocalFree(msg); msg = nullptr;
    }
    return (implementation != nullptr);
#else
    implementation = dlopen(filename, RTLD_LAZY);
    char* msg = dlerror();
    if(msg)
        err_message = msg;
    return implementation!=nullptr;
#endif
}

bool SharedLibrary::close() {
    if (implementation!=nullptr) {
#if defined(_WIN32)
        FreeLibrary((HINSTANCE)implementation);
#else
        dlclose(implementation);
#endif
        implementation = nullptr;
    }
    return true;
}

void *SharedLibrary::getSymbol(const char *symbolName) {
    err_message.clear();
    if (implementation==nullptr) return nullptr;
#if defined(_WIN32)
    FARPROC proc = GetProcAddress((HINSTANCE)implementation, symbolName);
    LPTSTR msg = nullptr;
    FormatMessage(
       FORMAT_MESSAGE_FROM_SYSTEM |FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
       nullptr, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
       (LPTSTR)&msg, 0, nullptr);

    if(msg != nullptr) {
        err_message = std::string(msg);
       // release memory allocated by FormatMessage()
       LocalFree(msg); msg = nullptr;
    }
    return (void*)proc;
#else
    dlerror();
    void* func = dlsym(implementation,symbolName);
    char* msg = dlerror();
    if(msg)
        err_message = msg;
    return func;
#endif
}

bool SharedLibrary::isValid() const {
    return implementation != nullptr;
}

std::string SharedLibrary::getLastNativeError() const {
    return err_message;
}
