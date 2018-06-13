#include <test.h>

START_TEST(stringToList_ProviderPtr_FirstFilledList) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18";
		Provider * result = Convert_stringToList(string);
		ck_assert(result != NULL);
		ck_assert_int_eq(Provider_countList(result), 1);
		ck_assert_str_eq(Provider_getProvName(result), "SunNet");
		ck_assert_str_eq(Provider_getOwnerName(result), "Danya");
		ck_assert_str_eq(Provider_getOwnerSurname(result), "Dzenik");
		ck_assert_int_eq(*Provider_getYear(result), 1994);
		ck_assert_int_eq(*Provider_getAge(result), 18);
		ck_assert(*Provider_getAnnualProfit(result) - 1500.44 < 0.001);
		Provider_freeList(&result);
	}
END_TEST
START_TEST(stringToList_ProviderPtr_SecondFilledNode) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18 LanNet 1934 1000.24 Ivan Bog 78";
		Provider * list = Convert_stringToList(string);
		ck_assert_int_eq(Provider_countList(list), 2);
		Provider * result = Provider_getStructure(list, 1);
		ck_assert(result != NULL);
		ck_assert_str_eq(Provider_getProvName(result), "LanNet");
		ck_assert_str_eq(Provider_getOwnerName(result), "Ivan");
		ck_assert_str_eq(Provider_getOwnerSurname(result), "Bog");
		ck_assert_int_eq(*Provider_getYear(result), 1934);
		ck_assert_int_eq(*Provider_getAge(result), 78);
		ck_assert(abs(*Provider_getAnnualProfit(result) - 1000.24) < 0.001);
		Provider_freeList(&list);
	}
END_TEST
START_TEST(structureToString_void_filledString) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18";
		char result[STR_SIZE] = "";
		Provider * self = Convert_stringToList(string);
		Convert_structureToString(result, self);
		ck_assert_str_eq(result, "SunNet 1994 1500.44 Danya Dzenik 18");
		Provider_freeList(&self);
		ck_assert_ptr_null(self);
	}
END_TEST

START_TEST(changeFieldInList_void_someProvName) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18";
		char data[STR_SIZE] = "LanNet";
		Provider * self = Convert_stringToList(string);
		Convert_changeFieldInList(self, 0, 0, data);
		ck_assert_str_eq(Provider_getProvName(self), data);
		Provider_freeList(&self);
		ck_assert_ptr_null(self);
	}
END_TEST

START_TEST(changeFieldInList_void_someYear) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18";
		char data[STR_SIZE] = "1803";
		Provider * self = Convert_stringToList(string);
		Convert_changeFieldInList(self, 0, 1, data);
		ck_assert_int_eq(*Provider_getYear(self), 1803);
		Provider_freeList(&self);
		ck_assert_ptr_null(self);
	}
END_TEST

START_TEST(changeFieldInList_void_someAnnualProfit) {
		char * string = "SunNet 1994 1500.44 Danya Dzenik 18";
		char data[STR_SIZE] = "250.35";
		Provider * self = Convert_stringToList(string);
		Convert_changeFieldInList(self, 0, 2, data);
		ck_assert(abs(*Provider_getAnnualProfit(self) - 250.35) < 0.001);
		Provider_freeList(&self);
		ck_assert_ptr_null(self);
	}
END_TEST

START_TEST(GetNHigherAnnualProfit_Provider_SpecialProvider) {
		char * string = "SunNet 1999 123 Danya Dzenik 18 LanNet 1998 19032 Vlad Krem 19 Ukr 2004 1.231 Dimon Blag 23 Indys 1983 1000.99 Valentin Ivanovich 49";
		Provider * self = Convert_stringToList(string);
		Provider * HighAnnualProf = Convert_GetNHigherAnnualProfit(self, 2);
		char result[STR_SIZE] = "";
		Convert_structureToString(result, HighAnnualProf);
		ck_assert_str_eq(result, "LanNet 1998 19032 Vlad Krem 19");
		strcpy(result, "");
		Convert_structureToString(result, Provider_getStructure(HighAnnualProf, 1));
		ck_assert_str_eq(result, "Indys 1983 1000.99 Valentin Ivanovich 49");
		Provider_freeList(&self);
		Provider_freeList(&HighAnnualProf);
		ck_assert_ptr_null(self);
		ck_assert_ptr_null(HighAnnualProf);
	}
END_TEST

START_TEST(GetNHigherAnnualProfit_Provider_nullPointer) {
		char * string = "SunNet 1999 123 Danya Dzenik 18 LanNet 1998 19032 Vlad Krem 19 Ukr 2004 1.231 Dimon Blag 23 Indys 1983 1000.99 Valentin Ivanovich 49";
		Provider * self = Convert_stringToList(string);
		Provider * HighAnnualProf = Convert_GetNHigherAnnualProfit(self, 0);
		ck_assert_ptr_null(HighAnnualProf);
		Provider_freeList(&self);
		ck_assert_ptr_null(self);
	}
END_TEST

START_TEST(correctName_bool_trueCase) {
		ck_assert(!correctName(""));
		ck_assert(!correctName("danya"));
		ck_assert(!correctName("Danya1"));
		ck_assert(!correctName("Danya "));
		ck_assert(!correctName("-Danya "));
		ck_assert(!correctName("Danya Ivan"));
		ck_assert(correctName("Danya"));
	}
END_TEST

START_TEST(correctYear_bool_trueCase) {
		ck_assert(!correctYear(""));
		ck_assert(!correctYear("123.2"));
		ck_assert(!correctYear(" 194"));
		ck_assert(!correctYear("Danya"));
		ck_assert(!correctYear("1799"));
		ck_assert(!correctYear("2032"));
		ck_assert(correctYear("1942"));
	}
END_TEST

START_TEST(correctIndex_bool_trueCase) {
		ck_assert(correctIndex("", 2));
		ck_assert(!correctIndex("123.2", 5));
		ck_assert(!correctIndex("Danya", 4));
		ck_assert(!correctIndex("-1", 4));
		ck_assert(!correctIndex("6", 3));
		ck_assert(correctIndex("2", 3));
	}
END_TEST


Suite *test_suite() {
	Suite *s = suite_create("Convert");
	TCase *tc_list;

	tc_list = tcase_create("List");
	tcase_add_test(tc_list, stringToList_ProviderPtr_FirstFilledList);
	tcase_add_test(tc_list, stringToList_ProviderPtr_SecondFilledNode);
	tcase_add_test(tc_list, structureToString_void_filledString);
	tcase_add_test(tc_list, changeFieldInList_void_someProvName);
	tcase_add_test(tc_list, changeFieldInList_void_someYear);
	tcase_add_test(tc_list, changeFieldInList_void_someAnnualProfit);
	tcase_add_test(tc_list, GetNHigherAnnualProfit_Provider_SpecialProvider);
	tcase_add_test(tc_list, GetNHigherAnnualProfit_Provider_nullPointer);

	TCase * tc_sample = tcase_create("CorrectData");
	tcase_add_test(tc_sample, correctName_bool_trueCase);
	tcase_add_test(tc_sample, correctYear_bool_trueCase);
	tcase_add_test(tc_sample, correctIndex_bool_trueCase);
	suite_add_tcase(s, tc_sample);
	suite_add_tcase(s, tc_list);
	return s;
}

int test(void) {
	Suite *s = test_suite();
	SRunner *sr = srunner_create(s);
	srunner_set_fork_status(sr, CK_NOFORK);

	srunner_run_all(sr, CK_VERBOSE);

	int num_tests_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return num_tests_failed;
}

