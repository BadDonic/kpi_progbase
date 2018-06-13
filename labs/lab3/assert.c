#include <assert.h>
#include "function.h"
#include <string.h>
#include <pbconsole.h>
#include <stdlib.h>

void test(void) {
  assert(!strcmp(GetName("asdasdasdasd"), "asdasdasdasd"));
  assert(!strcmp(GetName("asdasd2asdasd"), "0"));
  assert(!strcmp(GetName("asd asd2asdasd"), "0"));
  assert(!strcmp(GetName("asdasd  asdasd"), "0"));
  assert(!strcmp(GetName("asd.asdasdasd"), "0"));
  assert(!strcmp(GetName("123123"), "0"));
  assert(!strcmp(GetName("\n"), "0"));
  assert(!strcmp(GetName(""), "0"));

  assert(GetYear("12") == -1);
  assert(GetYear("1999") == 1999);
  assert(GetYear("asdasdasd") == -1);
  assert(GetYear("12ad adasd") == -1);
  assert(GetYear("0") == -1);
  assert(GetYear("") == 0);
  assert(GetYear("-123") == -1);

  assert(GetSpeed("") == 0);
  assert(GetSpeed("3") == 0);
  assert(GetSpeed("asdasdasdasd") == 0);
  assert(GetSpeed("2 sdadsad") == 0);
  assert(GetSpeed("2") == 2);
  assert(GetSpeed("100") == 100);
  assert(GetSpeed("-26") == 0);


  assert(GetMonthlyFee("asdasdasd") == 0.0);
  assert(GetMonthlyFee("") == 0.0);
  assert(GetMonthlyFee("12.345") == 0.0);
  assert(GetMonthlyFee("-123") == 0.0);
  assert(GetMonthlyFee("23.83") == (float)23.83);
  return;
}
