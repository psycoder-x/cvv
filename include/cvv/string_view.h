/*
  File
cvv/string_view.h (C header)
  Description
Makes a string view according to the template cvv/basic_string_view.t.h
Where T = char, cvv_bsv = cvv_sv, and cvv_ct = cvv_ct
Where cvv_ct is a cvv/char_traits.t.h that use the same type (T)
  License
See end of file for license information
*/
/* Include guard */
#ifndef CVV_STRING_VIEW_H_INCLUDED
#define CVV_STRING_VIEW_H_INCLUDED
/* Using the template cvv/basic_string_view.t.h */
#define T char
#define cvv_bsv cvv_sv
#define cvv_ct cvv_ct
#include"cvv/basic_string_view.t.h"
#undef T
#undef cvv_bsv
#undef cvv_ct
/* End of CVV_STRING_VIEW_H_INCLUDED */
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
