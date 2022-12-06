#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "main.h"

void test_open_file(void);
void test_close_file(void);

void test_check_args(void);

#endif
