/*
 *  .file eglplus/enums/gl_colorspace_def.ipp
 *
 *  Automatically generated header file. DO NOT modify manually,
 *  edit 'source/enums/eglplus/gl_colorspace.txt' instead.
 *
 *  Copyright 2010-2014 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifdef EGLPLUS_LIST_NEEDS_COMMA
# undef EGLPLUS_LIST_NEEDS_COMMA
#endif

#if defined EGL_GL_COLORSPACE_sRGB
# if EGLPLUS_LIST_NEEDS_COMMA
   EGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined sRGB
#  pragma push_macro("sRGB")
#  undef sRGB
   EGLPLUS_ENUM_CLASS_VALUE(sRGB, EGL_GL_COLORSPACE_sRGB)
#  pragma pop_macro("sRGB")
# else
   EGLPLUS_ENUM_CLASS_VALUE(sRGB, EGL_GL_COLORSPACE_sRGB)
# endif
# ifndef EGLPLUS_LIST_NEEDS_COMMA
#  define EGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#if defined EGL_GL_COLORSPACE_LINEAR
# if EGLPLUS_LIST_NEEDS_COMMA
   EGLPLUS_ENUM_CLASS_COMMA
# endif
# if defined Linear
#  pragma push_macro("Linear")
#  undef Linear
   EGLPLUS_ENUM_CLASS_VALUE(Linear, EGL_GL_COLORSPACE_LINEAR)
#  pragma pop_macro("Linear")
# else
   EGLPLUS_ENUM_CLASS_VALUE(Linear, EGL_GL_COLORSPACE_LINEAR)
# endif
# ifndef EGLPLUS_LIST_NEEDS_COMMA
#  define EGLPLUS_LIST_NEEDS_COMMA 1
# endif
#endif
#ifdef EGLPLUS_LIST_NEEDS_COMMA
# undef EGLPLUS_LIST_NEEDS_COMMA
#endif

