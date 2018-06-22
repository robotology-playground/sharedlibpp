/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef SHAREDLIBPP_SHAREDLIBRARYFACTORY_H
#define SHAREDLIBPP_SHAREDLIBRARYFACTORY_H

#include <string>
#include <SharedLibraryClassApi.h>


namespace shlibpp {

/**
 * A wrapper for a named factory method in a named shared library.
 * This wrapper will do some basic checks that the named method does
 * indeed behave like a YARP plugin hook before offering access to it.
 * This is to avoid accidents, it is not a security mechanism.
 */
class SharedLibraryFactory
{
public:
    /**
     * The status of a factory can be:
     *  - None: Not configured yet
     *  - OK: Present and sane
     *  - LibraryNotFound: Named shared library was not found
     *  - LibraryNotLoaded: Named shared library failed to load
     *  - FactoryNotFound: Named method wasn't present in library
     *  - FactoryNotFunctional: Named method is not working right
     */
    enum class Status : std::uint32_t
    {
        None = 0,            //!< Not configured yet.
        OK,                  //!< Present and sane.
        LibraryNotFound,     //!< Named shared library was not found.
        LibraryNotLoaded,    //!< Named shared library failed to load.
        FactoryNotFound,     //!< Named method wasn't present in library.
        FactoryNotFunctional //!< Named method is not working right.
    };

    /**
     * Constructor for unconfigured factory.
     */
    explicit SharedLibraryFactory();

    /**
     * Constructor.
     *
     * @param dll_name name/path of shared library.
     * @param fn_name name of factory method, a symbol within the shared library.
     */
    explicit SharedLibraryFactory(const char *dll_name,
                                  const char *fn_name = nullptr);

    /**
     * Destructor
     */
    virtual ~SharedLibraryFactory();

    /**
     * Configure the factory.
     *
     * @param dll_name name/path of shared library.
     * @param fn_name name of factory method, a symbol within the shared library.
     * @return true on success.
     */
    bool open(const char *dll_name, const char *fn_name = nullptr);

    /**
     * Check if factory is configured and present.
     *
     * @return true iff factory is good to go.
     */
    bool isValid() const;

    /**
     * Get the status of the factory.
     *
     * @return one of the SharedLibraryFactory::STATUS_* codes.
     */
    Status getStatus() const;

    /**
     * Get the latest error of the factory.
     *
     * @return the latest error.
     */
    std::string getError() const;

    /**

     * Get the factory API, which has creation/deletion methods.
     *
     * @return the factory API
     */
    const SharedLibraryClassApi& getApi() const;

    /**
     * Get the current reference count of this factory.
     *
     * @return the current reference count of this factory.
     */
    int getReferenceCount() const;

    /**
     * Increment the reference count of this factory.
     *
     * @return the current reference count of this factory, after increment.
     */
    int addRef();

    /**
     * Decrement the reference count of this factory.
     *
     * @return the current reference count of this factory, after decrement.
     */
    int removeRef();

    /**
     * Get the name associated with this factory.
     *
     * @return the name associated with this factory.
     */
    std::string getName() const;

    /**
     * Get the type associated with this factory.
     *
     * @return the type associated with this factory.
     */
    std::string getClassName() const;

    /**
     * Get the base type associated with this factory.
     *
     * @return the base type associated with this factory.
     */
    std::string getBaseClassName() const;

    /**
     *
     * Specify function to use as factory.
     *
     * @param factory function to use as factory.
     *
     * @result true on success.
     *
     */
    bool useFactoryFunction(void *factory);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
    class Private;
    Private* mPriv;
#endif
};

} // namespace shlibpp

#endif // SHAREDLIBPP_SHAREDLIBRARYFACTORY_H
