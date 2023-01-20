/*
  File
cvv/cvv.h (C header)
  Description
Common C++ features and frequently used features.
  License
See End of file for license information
*/
/* Include guard */
#ifndef CVV_CVV_H_INCLUDED
#define CVV_CVV_H_INCLUDED
/*----------------------------------------------------------------
  Dependencies
----------------------------------------------------------------*/
#include"stddef.h"
#include"stdbool.h"
/*----------------------------------------------------------------
  Macros
----------------------------------------------------------------*/
/* Maximum size */
#define cvv_max_size ((size_t)-2)
/* Not a position */
#define cvv_npos ((size_t)-1)
/* Concatenation of macros */
#define CVV_CAT_STATIC(A, B) A ## B
#define CVV_CAT(A, B) CVV_CAT_STATIC(A, B)
/* Reference mark */
#define CVV_REF *
/* End of CVV_CVV_H_INCLUDED */
#endif
/*----------------------------------------------------------------
  License
----------------------------------------------------------------*/
/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>
*/
