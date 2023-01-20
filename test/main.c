
#include"cvv/string_view.h"
#include"stdio.h"
#include"stdbool.h"

void write_sv(cvv_sv sv) {
  fwrite(cvv_sv_data(sv), cvv_sv_size(sv), 1, stdout);
}

void answer(int num, bool state) {
  printf(state ? "%02i " : "(((%02i))) ", num);
}

void bool_sv_sv(bool(*foo)(cvv_sv, cvv_sv), bool *answers) {
  cvv_sv strings[4];
  strings[0] = cvv_sv_new_sz("Hello, World!");
  strings[1] = cvv_sv_new_sz("Hello,");
  strings[2] = cvv_sv_new_sz("World!");
  strings[3] = cvv_sv_new_sz("");
  size_t size = sizeof(strings) / sizeof(cvv_sv);
  int n = 0;
  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      answer(n, foo(strings[i], strings[j]) == answers[n]);
      n++;
    }
  }
}

void char_sv(char(*foo)(cvv_sv), char *answers) {
  cvv_sv strings[4];
  strings[0] = cvv_sv_new_sz("Hello, World!");
  strings[1] = cvv_sv_new_sz("Hello,");
  strings[2] = cvv_sv_new_sz("World!");
  strings[3] = cvv_sv_new_sz("");
  size_t size = sizeof(strings) / sizeof(cvv_sv);
  int n = 0;
  for (size_t i = 0; i < size; i++) {
    answer(n, foo(strings[i]) == answers[i]);
    n++;
  }
}

int main() {
  const char *nothing_sz = "";
  const char *hello_sz = "Hello,";
  const char *world_sz = "World!";
  const char *hw_sz = "Hello, World!";
  cvv_sv nothing = cvv_sv_new_sz(nothing_sz);
  cvv_sv hello = cvv_sv_new_sz(hello_sz);
  cvv_sv world = cvv_sv_new_sz(world_sz);
  cvv_sv hw = cvv_sv_new_sz(hw_sz);
  printf("\n%s\n", "cvv_sv_empty");
  answer(0, cvv_sv_empty(nothing));
  answer(1, !cvv_sv_empty(hello));
  printf("\n%s\n", "cvv_sv_size");
  answer(0, cvv_sv_size(nothing) == 0);
  answer(1, cvv_sv_size(hello) == 6);
  answer(2, cvv_sv_size(world) == 6);
  answer(3, cvv_sv_size(hw) == 13);
  printf("\n%s\n", "cvv_sv_data");
  answer(0, cvv_sv_data(nothing) == nothing_sz);
  answer(1, cvv_sv_data(hello) == hello_sz);
  answer(2, cvv_sv_data(world) == world_sz);
  answer(3, cvv_sv_data(hw) == hw_sz);
  printf("\n%s\n", "cvv_sv_compare");
  // TODO: cvv_sv_compare eq lt gt variants to check as bool_sv_sv
  answer(0, cvv_sv_compare(hw, hw) == 0);
  answer(1, cvv_sv_compare(hello, world) < 0);
  answer(2, cvv_sv_compare(world, hello) > 0);
  printf("\n%s\n", "cvv_sv_starts_with");
  static bool answers_cvv_sv_starts_with[] = {
    true, true, false, true,
    false, true, false, true,
    false, false, true, true,
    false, false, false, true,
  };
  bool_sv_sv(cvv_sv_starts_with, answers_cvv_sv_starts_with);
  printf("\n%s\n", "cvv_sv_ends_with");
  static bool answers_cvv_sv_ends_with[] = {
    true, false, true, true,
    false, true, false, true,
    false, false, true, true,
    false, false, false, true,
  };
  bool_sv_sv(cvv_sv_ends_with, answers_cvv_sv_ends_with);
  printf("\n%s\n", "cvv_sv_contains");
  static bool answers_cvv_sv_contains[] = {
    true, true, true, true,
    false, true, false, true,
    false, false, true, true,
    false, false, false, true,
  };
  bool_sv_sv(cvv_sv_contains, answers_cvv_sv_contains);
  printf("\n%s\n", "cvv_sv_rfind");
  char ch = 'o';
  answer(0, cvv_sv_rfind(hw, hw) == 0);
  answer(1, cvv_sv_rfind(hw, hello) == 0);
  answer(2, cvv_sv_rfind(hw, world) == 7);
  answer(3, cvv_sv_rfind(hw, cvv_sv_new_char(&ch)) == 8);
  printf("\n%s\n", "cvv_sv_front");
  static char answers_cvv_sv_front[4] = { 'H', 'H', 'W', '\0' };
  char_sv(cvv_sv_front, answers_cvv_sv_front);
  printf("\n%s\n", "cvv_sv_back");
  static char answers_cvv_sv_back[4] = { '!', ',', '!', '\0' };
  char_sv(cvv_sv_back, answers_cvv_sv_back);
  printf("\n%s\n", "cvv_sv_remove_prefix");
  answer(0, cvv_sv_compare(world, cvv_sv_remove_prefix(hw, 7)) == 0);
  answer(1, cvv_sv_compare(hw, cvv_sv_remove_prefix(hw, 0)) == 0);
  answer(2, cvv_sv_empty(cvv_sv_remove_prefix(hw, cvv_sv_size(hw))));
  printf("\n%s\n", "cvv_sv_remove_suffix");
  answer(0, cvv_sv_compare(hello, cvv_sv_remove_suffix(hw, 7)) == 0);
  answer(1, cvv_sv_compare(hw, cvv_sv_remove_suffix(hw, 0)) == 0);
  answer(2, cvv_sv_empty(cvv_sv_remove_suffix(hw, cvv_sv_size(hw))));

  // TODO: test cvv_sv_begin, cvv_sv_end, cvv_sv_rbegin, cvv_sv_rend

  // TODO: test cvv_bsv_find_first_of, cvv_bsv_find_last_of

  // TODO: test cvv_bsv_find_first_not_of, cvv_bsv_find_last_not_of

  return 0;
}
