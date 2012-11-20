#include  <CUnit/CUnit.h>
#include  <CUnit/Basic.h>
#include  <stdlib.h>

#include  "compare.h"

/**
 * @brief compare(int,int)的测试用例
 */
static void compare_int_int(void)
{
	
	//equal,return 0
	{
		int a=1;
		int b=1;
		CU_ASSERT(0 == compare(a,b));
	}

	//a>b,return 1
	{
		int a=3;
		int b=1;
		CU_ASSERT(1 == compare(a,b));
	}

	//a<b,return -1
	{
		int a=3;
		int b=5;
		CU_ASSERT(-1 == compare(a,b));
	}
	
}

/**
 * @brief compare.h的TestInfo
 */
static CU_TestInfo compare_h[] = {
	{"compare_int_int",compare_int_int},
	CU_TEST_INFO_NULL,
};

/**
 * @brief library模块的SuitInfo
 */
static CU_SuiteInfo library[] = {
	{"compare_h",NULL,NULL,compare_h},
	CU_SUITE_INFO_NULL,
};

int main(int argc, char *argv[])
{
	if(CU_initialize_registry() != CUE_SUCCESS) 
	{
		fprintf(stderr,"Failed CU_initialize %s:%d\n",__FILE__,__LINE__);
		exit(-1);
	}
	if(CU_is_test_running())
	{
		fprintf(stderr,"Failed CU_is_test_running %s:%d\n",__FILE__,__LINE__);
		exit(-1);
	}
	if(CU_register_suites(library) != CUE_SUCCESS)
	{
		fprintf(stderr,"Failed CU_register_suites library %s:%d\n",__FILE__,__LINE__);
		exit(-1);
	}

	CU_basic_set_mode(CU_BRM_NORMAL);
	CU_set_error_action(CUEA_IGNORE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;
}
