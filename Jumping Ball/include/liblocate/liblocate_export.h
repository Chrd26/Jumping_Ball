
#ifndef LIBLOCATE_API_H
#define LIBLOCATE_API_H

#ifdef LIBLOCATE_STATIC_DEFINE
#  define LIBLOCATE_API
#  define LIBLOCATE_NO_EXPORT
#else
#  ifndef LIBLOCATE_API
#    ifdef liblocate_EXPORTS
        /* We are building this library */
#      define LIBLOCATE_API __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define LIBLOCATE_API __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef LIBLOCATE_NO_EXPORT
#    define LIBLOCATE_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef LIBLOCATE_DEPRECATED
#  define LIBLOCATE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef LIBLOCATE_DEPRECATED_EXPORT
#  define LIBLOCATE_DEPRECATED_EXPORT LIBLOCATE_API LIBLOCATE_DEPRECATED
#endif

#ifndef LIBLOCATE_DEPRECATED_NO_EXPORT
#  define LIBLOCATE_DEPRECATED_NO_EXPORT LIBLOCATE_NO_EXPORT LIBLOCATE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef LIBLOCATE_NO_DEPRECATED
#    define LIBLOCATE_NO_DEPRECATED
#  endif
#endif

#endif /* LIBLOCATE_API_H */
