/*
  File
cvv/basic_string_view.t.h (C template header)
  Description
The template cvv_basic_string_view describes an object
that can refer to a constant contiguous sequence of char-like objects
with the first element of the sequence at position zero
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
#ifndef cvv_bsv
#define cvv_bsv cvv_sv
#endif
/* Char traits for the same T */
#define CVV_NESTED_TEMPLATE
#include"cvv/char_traits.t.h"
#undef CVV_NESTED_TEMPLATE
/*----------------------------------------------------------------
  Members
----------------------------------------------------------------*/
typedef struct cvv_bsv {
  const T *data;
  size_t size;
} cvv_bsv;
/*----------------------------------------------------------------
  Local names
----------------------------------------------------------------*/
#define cvv_bsv_new CVV_CAT(cvv_bsv, _new)
#define cvv_bsv_new_copy CVV_CAT(cvv_bsv, _new_copy)
#define cvv_bsv_new_array CVV_CAT(cvv_bsv, _new_array)
#define cvv_bsv_new_sz CVV_CAT(cvv_bsv, _new_sz)
#define cvv_bsv_new_char CVV_CAT(cvv_bsv, _new_char)
#define cvv_bsv_begin CVV_CAT(cvv_bsv, _begin)
#define cvv_bsv_end CVV_CAT(cvv_bsv, _end)
#define cvv_bsv_rbegin CVV_CAT(cvv_bsv, _rbegin)
#define cvv_bsv_rend CVV_CAT(cvv_bsv, _rend)
#define cvv_bsv_at CVV_CAT(cvv_bsv, _at)
#define cvv_bsv_front CVV_CAT(cvv_bsv, _front)
#define cvv_bsv_back CVV_CAT(cvv_bsv, _back)
#define cvv_bsv_data CVV_CAT(cvv_bsv, _data)
#define cvv_bsv_size CVV_CAT(cvv_bsv, _size)
#define cvv_bsv_empty CVV_CAT(cvv_bsv, _empty)
#define cvv_bsv_remove_prefix CVV_CAT(cvv_bsv, _remove_prefix)
#define cvv_bsv_remove_suffix CVV_CAT(cvv_bsv, _remove_suffix)
#define cvv_bsv_substr CVV_CAT(cvv_bsv, _substr)
#define cvv_bsv_compare CVV_CAT(cvv_bsv, _compare)
#define cvv_bsv_starts_with CVV_CAT(cvv_bsv, _starts_with)
#define cvv_bsv_ends_with CVV_CAT(cvv_bsv, _ends_with)
#define cvv_bsv_contains CVV_CAT(cvv_bsv, _contains)
#define cvv_bsv_find CVV_CAT(cvv_bsv, _find)
#define cvv_bsv_rfind CVV_CAT(cvv_bsv, _rfind)
#define cvv_bsv_find_first_of CVV_CAT(cvv_bsv, _find_first_of)
#define cvv_bsv_find_last_of CVV_CAT(cvv_bsv, _find_last_of)
#define cvv_bsv_find_first_not_of CVV_CAT(cvv_bsv, _find_first_not_of)
#define cvv_bsv_find_last_not_of CVV_CAT(cvv_bsv, _find_last_not_of)
/*----------------------------------------------------------------
  Constructors
----------------------------------------------------------------*/
/* Default constructor. Constructs an empty cvv_bsv */
cvv_bsv cvv_bsv_new();
/* Copy constructor. Constructs a view of the same content as other */
cvv_bsv cvv_bsv_new_copy(cvv_bsv other);
/* Constructs a view of the character array */
cvv_bsv cvv_bsv_new_array(const T *ptr, size_t count);
/* Constructs a view of the null-terminated character string */
cvv_bsv cvv_bsv_new_sz(const T *sz);
/* Constructs a view of the single character */
cvv_bsv cvv_bsv_new_char(const T *ch);
/*----------------------------------------------------------------
  Iterators
----------------------------------------------------------------*/
/* Returns an iterator to the first character of the view */
const T *cvv_bsv_begin(cvv_bsv self);
/* Returns an iterator to the character following
 * the last character of the view */
const T *cvv_bsv_end(cvv_bsv self);
/* Returns a reverse iterator to the first character
 * of the reversed view */
const T *cvv_bsv_rbegin(cvv_bsv self);
/* Returns a reverse iterator to the character following
 * the last character of the reversed view */
const T *cvv_bsv_rend(cvv_bsv self);
/*----------------------------------------------------------------
  Element access
----------------------------------------------------------------*/
/* Returns a character at specified location pos */
T cvv_bsv_at(cvv_bsv self, size_t pos);
/* Returns the first character */
T cvv_bsv_front(cvv_bsv self);
/* Returns the last character */
T cvv_bsv_back(cvv_bsv self);
/* Returns a pointer to the underlying character array */
const T *cvv_bsv_data(cvv_bsv self);
/*----------------------------------------------------------------
  Capacity
----------------------------------------------------------------*/
/* Returns the number of T elements */
size_t cvv_bsv_size(cvv_bsv self);
/* Checks if the view has no characters */
bool cvv_bsv_empty(cvv_bsv self);
/*----------------------------------------------------------------
  Modifiers
----------------------------------------------------------------*/
/* Moves the start of the view forward by count characters */
cvv_bsv cvv_bsv_remove_prefix(cvv_bsv self, size_t count);
/* Moves the end of the view back by count characters */
cvv_bsv cvv_bsv_remove_suffix(cvv_bsv self, size_t count);
/*----------------------------------------------------------------
  Operations
----------------------------------------------------------------*/
/* Returns a view of the substring [pos, pos + count) */
cvv_bsv cvv_bsv_substr(cvv_bsv self, size_t pos, size_t count);
/* Compares two character sequences */
int cvv_bsv_compare(cvv_bsv self, cvv_bsv other);
/* Checks if the string view begins with the given prefix */
bool cvv_bsv_starts_with(cvv_bsv self, cvv_bsv prefix);
/* Checks if the string view ends with the given suffix */
bool cvv_bsv_ends_with(cvv_bsv self, cvv_bsv suffix);
/* Checks if the string view contains the given substring */
bool cvv_bsv_contains(cvv_bsv self, cvv_bsv substring);
/* The first occurence of substring */
size_t cvv_bsv_find(cvv_bsv self, cvv_bsv substring);
/* The last occurrence of substring */
size_t cvv_bsv_rfind(cvv_bsv self, cvv_bsv substring);
/* The first occurrence of any of the characters of chars */
size_t cvv_bsv_find_first_of(cvv_bsv self, cvv_bsv chars);
/* The last occurence of any of the characters of chars */
size_t cvv_bsv_find_last_of(cvv_bsv self, cvv_bsv chars);
/* The first character not equal to any of the characters of chars */
size_t cvv_bsv_find_first_not_of(cvv_bsv self, cvv_bsv chars);
/* The last character not equal to any of the characters of chars */
size_t cvv_bsv_find_last_not_of(cvv_bsv self, cvv_bsv chars);
/*----------------------------------------------------------------
  Implementation
----------------------------------------------------------------*/
#ifdef IMPLEMENT_CVV_BASIC_STRING_VIEW
/*--------------------------------
  Constructors
----------------------------------*/
#ifndef override_cvv_bsv_new
cvv_bsv cvv_bsv_new() {
  return cvv_bsv_new_array(NULL, 0);
}
#endif
#ifndef override_cvv_bsv_new_copy
cvv_bsv cvv_bsv_new_copy(cvv_bsv other) {
  return other;
}
#endif
#ifndef override_cvv_bsv_new_array
cvv_bsv cvv_bsv_new_array(const T *ptr, size_t count) {
  return (cvv_bsv) { .data = ptr, .size = count };
}
#endif
#ifndef override_cvv_bsv_new_sz
cvv_bsv cvv_bsv_new_sz(const T *sz) {
  return cvv_bsv_new_array(sz, cvv_ct_length(sz));
}
#endif
#ifndef override_cvv_bsv_new_char
cvv_bsv cvv_bsv_new_char(const T *ch) {
  return cvv_bsv_new_array(ch, 1);
}
#endif
/*--------------------------------
  Iterators
----------------------------------*/
#ifndef override_cvv_bsv_begin
const T *cvv_bsv_begin(cvv_bsv self) {
  if (self.size == 0) {
    return NULL;
  }
  return self.data;
}
#endif
#ifndef override_cvv_bsv_end
const T *cvv_bsv_end(cvv_bsv self) {
  if (self.size == 0) {
    return NULL;
  }
  return &self.data[self.size];
}
#endif
#ifndef override_cvv_bsv_rbegin
const T *cvv_bsv_rbegin(cvv_bsv self) {
  if (self.size == 0) {
    return NULL;
  }
  return &self.data[self.size - 1];
}
#endif
#ifndef override_cvv_bsv_rend
const T *cvv_bsv_rend(cvv_bsv self) {
  if (self.size == 0) {
    return NULL;
  }
  return &self.data[-1];
}
#endif
/*--------------------------------
  Element access
----------------------------------*/
#ifndef override_cvv_bsv_at
T cvv_bsv_at(cvv_bsv self, size_t pos) {
  if (self.size == 0) {
    return cvv_ct_null();
  }
  return self.data[pos % self.size];
}
#endif
#ifndef override_cvv_bsv_front
T cvv_bsv_front(cvv_bsv self) {
  return cvv_bsv_at(self, 0);
}
#endif
#ifndef override_cvv_bsv_back
T cvv_bsv_back(cvv_bsv self) {
  return cvv_bsv_at(self, self.size - 1);
}
#endif
#ifndef override_cvv_bsv_data
const T *cvv_bsv_data(cvv_bsv self) {
  return self.data;
}
#endif
/*--------------------------------
  Capacity
----------------------------------*/
#ifndef override_cvv_bsv_size
size_t cvv_bsv_size(cvv_bsv self) {
  return self.size;
}
#endif
#ifndef override_cvv_bsv_empty
bool cvv_bsv_empty(cvv_bsv self) {
  return self.size == 0;
}
#endif
/*--------------------------------
  Modifiers
----------------------------------*/
#ifndef override_cvv_bsv_remove_prefix
cvv_bsv cvv_bsv_remove_prefix(cvv_bsv self, size_t count) {
  if (count >= self.size) {
    return cvv_bsv_new();
  }
  return cvv_bsv_new_array(self.data + count, self.size - count);
}
#endif
#ifndef override_cvv_bsv_remove_suffix
cvv_bsv cvv_bsv_remove_suffix(cvv_bsv self, size_t count) {
  if (count >= self.size) {
    return cvv_bsv_new();
  }
  return cvv_bsv_new_array(self.data, self.size - count);
}
#endif
/*--------------------------------
  Operations
----------------------------------*/
#ifndef override_cvv_bsv_substr
cvv_bsv cvv_bsv_substr(cvv_bsv self, size_t pos, size_t count) {
  if (pos >= self.size) {
    return cvv_bsv_new();
  }
  if (pos + count > self.size) {
    count = self.size - pos;
  }
  return cvv_bsv_new_array(self.data + pos, count);
}
#endif
#ifndef override_cvv_bsv_compare
int cvv_bsv_compare(cvv_bsv self, cvv_bsv other) {
  size_t size = self.size < other.size ? self.size : other.size;
  return cvv_ct_compare(self.data, other.data, size);
}
#endif
#ifndef override_cvv_bsv_starts_with
bool cvv_bsv_starts_with(cvv_bsv self, cvv_bsv prefix) {
  if (self.size < prefix.size) {
    return false;
  }
  cvv_bsv self_prefix = cvv_bsv_substr(self, 0, prefix.size);
  return cvv_bsv_compare(self_prefix, prefix) == 0;
}
#endif
#ifndef override_cvv_bsv_ends_with
bool cvv_bsv_ends_with(cvv_bsv self, cvv_bsv suffix) {
  if (self.size < suffix.size) {
    return false;
  }
  size_t pos = self.size - suffix.size;
  cvv_bsv self_suffix = cvv_bsv_substr(self, pos, suffix.size);
  return cvv_bsv_compare(self_suffix, suffix) == 0;
}
#endif
#ifndef override_cvv_bsv_contains
bool cvv_bsv_contains(cvv_bsv self, cvv_bsv substring) {
  return cvv_bsv_find(self, substring) != cvv_npos;
}
#endif
#ifndef override_cvv_bsv_find
size_t cvv_bsv_find(cvv_bsv self, cvv_bsv substring) {
  if (self.size < substring.size) {
    return cvv_npos;
  }
  size_t limit = self.size - substring.size;
  for (size_t i = 0; i <= limit; i++) {
    cvv_bsv part = cvv_bsv_substr(self, i, substring.size);
    if (cvv_bsv_compare(part, substring) == 0) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
#ifndef override_cvv_bsv_rfind
size_t cvv_bsv_rfind(cvv_bsv self, cvv_bsv substring) {
  if (self.size < substring.size) {
    return cvv_npos;
  }
  size_t limit = self.size - substring.size;
  size_t i = limit;
  for (size_t j = 0; j <= limit; j++, i--) {
    cvv_bsv part = cvv_bsv_substr(self, i, substring.size);
    if (cvv_bsv_compare(part, substring) == 0) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
#ifndef override_cvv_bsv_find_first_of
size_t cvv_bsv_find_first_of(cvv_bsv self, cvv_bsv chars) {
  for (size_t i = 0; i < self.size; i++) {
    cvv_bsv char_view = cvv_bsv_new_char(&self.data[i]);
    if (cvv_bsv_contains(chars, char_view)) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
#ifndef override_cvv_bsv_find_last_of
size_t cvv_bsv_find_last_of(cvv_bsv self, cvv_bsv chars) {
  size_t i = self.size - 1;
  for (size_t j = 0; j < self.size; j++, i--) {
    cvv_bsv char_view = cvv_bsv_new_char(&self.data[i]);
    if (cvv_bsv_contains(chars, char_view)) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
#ifndef override_cvv_bsv_find_first_not_of
size_t cvv_bsv_find_first_not_of(cvv_bsv self, cvv_bsv chars) {
  for (size_t i = 0; i < self.size; i++) {
    cvv_bsv char_view = cvv_bsv_new_char(&self.data[i]);
    if (!cvv_bsv_contains(chars, char_view)) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
#ifndef override_cvv_bsv_find_last_not_of
size_t cvv_bsv_find_last_not_of(cvv_bsv self, cvv_bsv chars) {
  size_t i = self.size - 1;
  for (size_t j = 0; j < self.size; j++, i--) {
    cvv_bsv char_view = cvv_bsv_new_char(&self.data[i]);
    if (!cvv_bsv_contains(chars, char_view)) {
      return i;
    }
  }
  return cvv_npos;
}
#endif
/* End of IMPLEMENT_CVV_BASIC_STRING_VIEW */
#endif
/* End of CVV_NESTED_TEMPLATE_END */
#endif
/*----------------------------------------------------------------
  Remove local names
----------------------------------------------------------------*/
/* Skip remove local names */
#ifndef CVV_NESTED_TEMPLATE
/* Remove local names of basic string view */
#undef cvv_bsv_new
#undef cvv_bsv_new_copy
#undef cvv_bsv_new_array
#undef cvv_bsv_new_sz
#undef cvv_bsv_new_char
#undef cvv_bsv_begin
#undef cvv_bsv_end
#undef cvv_bsv_rbegin
#undef cvv_bsv_rend
#undef cvv_bsv_at
#undef cvv_bsv_front
#undef cvv_bsv_back
#undef cvv_bsv_data
#undef cvv_bsv_size
#undef cvv_bsv_empty
#undef cvv_bsv_remove_prefix
#undef cvv_bsv_remove_suffix
#undef cvv_bsv_substr
#undef cvv_bsv_compare
#undef cvv_bsv_starts_with
#undef cvv_bsv_ends_with
#undef cvv_bsv_contains
#undef cvv_bsv_find
#undef cvv_bsv_rfind
#undef cvv_bsv_find_first_of
#undef cvv_bsv_find_last_of
#undef cvv_bsv_find_first_not_of
#undef cvv_bsv_find_last_not_of
/* Remove local names of char traits */
#define CVV_NESTED_TEMPLATE_END
#include"cvv/char_traits.t.h"
#undef CVV_NESTED_TEMPLATE_END
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
