/*
  File
cvv/char_traits.t.h (C template header)
  Description
Character traits classes specify character properties
and provide specific semantics for certain operations on characters
and sequences of characters
  License
See End of file for license information
*/
/* skip everything but remove local names */
#ifndef CVV_NESTED_TEMPLATE_END
/*----------------------------------------------------------------
  Dependencies
----------------------------------------------------------------*/
#include"cvv/cvv.h"
/*----------------------------------------------------------------
  Templates
----------------------------------------------------------------*/
/* Char-like type */
#ifndef T
#define T char
#endif
/* Name of new type */
#ifndef cvv_ct
#define cvv_ct cvv_ct
#endif
/*----------------------------------------------------------------
  Local names
----------------------------------------------------------------*/
#define cvv_ct_null CVV_CAT(cvv_ct, _null)
#define cvv_ct_assign CVV_CAT(cvv_ct, _assign)
#define cvv_ct_assign_array CVV_CAT(cvv_ct, _assign_array)
#define cvv_ct_eq CVV_CAT(cvv_ct, _eq)
#define cvv_ct_lt CVV_CAT(cvv_ct, _lt)
#define cvv_ct_move CVV_CAT(cvv_ct, _move)
#define cvv_ct_copy CVV_CAT(cvv_ct, _copy)
#define cvv_ct_compare CVV_CAT(cvv_ct, _compare)
#define cvv_ct_length CVV_CAT(cvv_ct, _length)
#define cvv_ct_find CVV_CAT(cvv_ct, _find)
/*----------------------------------------------------------------
  Static functions
----------------------------------------------------------------*/
/* Returns null-character */
T cvv_ct_null();
/* Assigns c to r, as if using r=c */
void cvv_ct_assign(T CVV_REF r, T c);
/* Assigns c to each character in the array p */
void cvv_ct_assign_array(T *p, size_t n, T c);
/* Returns whether characters c and d are considered equal */
bool cvv_ct_eq(T c, T d);
/* Returns whether character c is considered less than character d */
bool cvv_ct_lt(T c, T d);
/* Copies the array src to the array dst (may overlap) */
void cvv_ct_move(T *dst, const T *src, size_t n);
/* Copies the array src to the array dst (shall not overlap) */
void cvv_ct_copy(T *dst, const T *src, size_t n);
/* Compares arrays of characters */
int cvv_ct_compare(const T *p, const T *q, size_t n);
/* Returns the length of the null-terminated character sequence s */
size_t cvv_ct_length(const T *s);
/* Returns a pointer to the first character c in the array p */
const T *cvv_ct_find(const T *p, size_t n, T c);
/*----------------------------------------------------------------
  Implementation
----------------------------------------------------------------*/
#ifdef IMPLEMENT_CVV_CHAR_TRAITS
/*--------------------------------
  Dependencies
----------------------------------*/
#include"string.h"
/*--------------------------------
  Static functions
----------------------------------*/
#ifndef override_cvv_ct_null
T cvv_ct_null() {
  T temp;
  memset(&temp, 0, sizeof(T));
  return temp;
}
#endif
#ifndef override_cvv_ct_assign
void cvv_ct_assign(T CVV_REF r, T c) {
  memcpy(r, &c, sizeof(T));
}
#endif
#ifndef override_cvv_ct_assign_array
void cvv_ct_assign_array(T *p, size_t n, T c) {
  while (n != 0) {
    n--;
    cvv_ct_assign(&p[n], c);
  }
}
#endif
#ifndef override_cvv_ct_eq
bool cvv_ct_eq(T c, T d) {
  return memcmp(&c, &d, sizeof(T)) == 0;
}
#endif
#ifndef override_cvv_ct_lt
bool cvv_ct_lt(T c, T d) {
  return memcmp(&c, &d, sizeof(T)) < 0;
}
#endif
#ifndef override_cvv_ct_move
void cvv_ct_move(T *dst, const T *src, size_t n) {
  return memmove(dst, src, n * sizeof(T));
}
#endif
#ifndef override_cvv_ct_copy
void cvv_ct_copy(T *dst, const T *src, size_t n) {
  return memcpy(dst, src, n * sizeof(T));
}
#endif
#ifndef override_cvv_ct_compare
int cvv_ct_compare(const T *p, const T *q, size_t n) {
  while (n-- != 0) {
    if (!cvv_ct_eq(*p, *q)) {
      return cvv_ct_lt(*p, *q) ? -1 : 1;
    }
    p++;
    q++;
  }
  return 0;
}
#endif
#ifndef override_cvv_ct_length
size_t cvv_ct_length(const T *s) {
  size_t i = 0;
  T null = cvv_ct_null();
  while (!cvv_ct_eq(s[i], null)) {
    i++;
  }
  return i;
}
#endif
#ifndef override_cvv_ct_find
const T *cvv_ct_find(const T *p, size_t n, T c) {
  while (n-- != 0) {
    if (cvv_ct_eq(*p, c)) {
      return p;
    }
    p++;
  }
  return NULL;
}
#endif
/* End of IMPLEMENT_CVV_CHAR_TRAITS */
#endif
/* End of CVV_NESTED_TEMPLATE_END */
#endif
/*----------------------------------------------------------------
  Remove local names
----------------------------------------------------------------*/
/* Skip remove local names */
#ifndef CVV_NESTED_TEMPLATE
/* Remove local names of char traits */
#undef cvv_ct_null
#undef cvv_ct_assign
#undef cvv_ct_assign_array
#undef cvv_ct_eq
#undef cvv_ct_lt
#undef cvv_ct_copy
#undef cvv_ct_move
#undef cvv_ct_compare
#undef cvv_ct_length
#undef cvv_ct_find
/* End of CVV_NESTED_TEMPLATE */
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
