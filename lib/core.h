#pragma once

#ifndef P3D_EXPORT
#if defined _WIN32 || defined __CYGWIN__ || defined _MSC_VER
#define P3D_EXPORT __declspec(dllexport)
#define P3D_IMPORT __declspec(dllimport)
#define P3D_HIDDEN
#elif defined __GNUC__ && __GNUC__ >= 4
#define P3D_EXPORT __attribute__((visibility("default")))
#define P3D_IMPORT __attribute__((visibility("default")))
#define P3D_HIDDEN __attribute__((visibility("hidden")))
#else /* Unsupported compiler */
#define P3D_EXPORT
#define P3D_IMPORT
#define P3D_HIDDEN
#endif
#endif

#ifndef P3D_API
#if defined P3D_API_EXPORT
#define P3D_API P3D_EXPORT
#elif defined P3D_API_IMPORT
#define P3D_API P3D_IMPORT
#else /* No API */
#define P3D_API
#endif
#endif

#include "entt/entt.hpp"

#ifdef ENTT_ID_TYPE
#define P3D_ID_TYPE ENTT_ID_TYPE
#else
#define P3D_ID_TYPE std::size_t
#endif