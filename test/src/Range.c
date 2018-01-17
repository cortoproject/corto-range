/* This is a managed file. Do not delete this comment. */

#include <include/test.h>

void test_Range_tc_rangeInitialValues(
    test_Range this)
{
    test_RangeTest *o = corto_create(NULL, NULL, test_RangeTest_o);
    test_assert(o != NULL);

    test_assertflt(o->temperature.value, 0);
    test_assertflt(o->temperature.lo.medium_alert, -50.0);
    test_assertflt(o->temperature.lo.high_alert, -100.0);

    test_assertflt(o->temperature.hi.medium_alert, 50.0);
    test_assertflt(o->temperature.hi.high_alert, 100.0);

}
