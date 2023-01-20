/*
  File
char_traits.c (C source)
  Description
Implements cvv/char_traits.h
  License
See end of file for license information
*/
/*----------------------------------------------------------------
  Dependencies
----------------------------------------------------------------*/
#include"string.h"
/*----------------------------------------------------------------
  Templates
----------------------------------------------------------------*/
#define IMPLEMENT_CVV_CHAR_TRAITS
#define override_cvv_ct_null
#define override_cvv_ct_length
#define override_cvv_ct_eq
#define override_cvv_ct_lt
#define override_cvv_ct_assign
#define override_cvv_ct_assign_array
#include"cvv/char_traits.h"
/*----------------------------------------------------------------
  Static functions
----------------------------------------------------------------*/
char cvv_ct_null() {
  return '\0';
}
size_t cvv_ct_length(const char *s) {
  return strlen(s);
}
bool cvv_ct_eq(char c, char d) {
  return c == d;
}
bool cvv_ct_lt(char c, char d) {
  return (unsigned char)c < (unsigned char)d;
}
void cvv_ct_assign(char CVV_REF r, char c) {
  *r = c;
}
void cvv_ct_assign_array(char *p, size_t n, char c) {
  memset(p, c, n);
}
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
