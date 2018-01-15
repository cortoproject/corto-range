/* This is a managed file. Do not delete this comment. */

#include <corto/range/range.h>

int16_t corto_range_construct(
    corto_range this)
{
    /* Validate if ranges are not overlapping */
    if (this->lo.medium_alert <= this->lo.high_alert) {
        corto_throw(
            "medium_alert (%f) of 'lo' should not be lower than high_alert (%f)",
            this->lo.medium_alert,
            this->lo.high_alert);
        goto error;
    }

    if (this->hi.medium_alert >= this->hi.high_alert) {
        corto_throw(
            "medium_alert (%f) of 'lo' should not be higher than high_alert (%f)",
            this->hi.medium_alert,
            this->hi.high_alert);
        goto error;
    }

    if (this->lo.medium_alert >= this->hi.medium_alert) {
        corto_throw(
            "medium_alert (%f) of 'lo' should not be higher than medium_alert of 'hi' (%f)",
            this->lo.medium_alert,
            this->hi.medium_alert);
        goto error;
    }

    return 0;
error:
    return -1;
}
