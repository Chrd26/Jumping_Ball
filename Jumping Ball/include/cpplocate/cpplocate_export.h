
#ifndef CPPLOCATE_API_H
#define CPPLOCATE_API_H

#ifdef CPPLOCATE_STATIC_DEFINE
#  define CPPLOCATE_API
#  define CPPLOCATE_NO_EXPORT
#else
#  ifndef CPPLOCATE_API
#    ifdef cpplocate_EXPORTS
        /* We are building this library */
#      define CPPLOCATE_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define CPPLOCATE_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef CPPLOCATE_NO_EXPORT
#    define CPPLOCATE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef CPPLOCATE_DEPRECATED
#  define CPPLOCATE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef CPPLOCATE_DEPRECATED_EXPORT
#  define CPPLOCATE_DEPRECATED_EXPORT CPPLOCATE_API CPPLOCATE_DEPRECATED
#endif

#ifndef CPPLOCATE_DEPRECATED_NO_EXPORT
#  define CPPLOCATE_DEPRECATED_NO_EXPORT CPPLOCATE_NO_EXPORT CPPLOCATE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef CPPLOCATE_NO_DEPRECATED
#    define CPPLOCATE_NO_DEPRECATED
#  endif
#endif

#endif /* CPPLOCATE_API_H */
