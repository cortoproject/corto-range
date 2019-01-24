/* This is a managed file. Do not delete this comment. */

#include <corto.range>

int16_t corto_range_construct(
    corto_range this)
{
    /* Validate if ranges are not overlapping */
    if (this->lo.medium_alert < this->lo.high_alert) {
        ut_throw(
            "medium_alert (%f) of 'lo' should not be lower than high_alert (%f)",
            this->lo.medium_alert,
            this->lo.high_alert);
        goto error;
    }

    if (this->hi.medium_alert > this->hi.high_alert) {
        ut_throw(
            "medium_alert (%f) of 'lo' should not be higher than high_alert (%f)",
            this->hi.medium_alert,
            this->hi.high_alert);
        goto error;
    }

    if (this->lo.medium_alert > this->hi.medium_alert) {
        ut_throw(
            "medium_alert (%f) of 'lo' should not be higher than medium_alert of 'hi' (%f)",
            this->lo.medium_alert,
            this->hi.medium_alert);
        goto error;
    }

    /* Add value member of specified type */
    corto_member m_value = corto_declare(this, "value", corto_member_o);
    if (!m_value) {
        goto error;
    }
    corto_set_ref(&m_value->type, this->type);
    if (corto_define(m_value)) {
        goto error;
    }

    /* Add members that specifies runtime ranges */
    corto_member m_lo = corto_declare(this, "lo", corto_member_o);
    if (!m_lo) {
        goto error;
    }
    corto_set_ref(&m_lo->type, corto_rangespec_o);
    m_lo->_default = ut_asprintf("{%f,%f}", this->lo.medium_alert, this->lo.high_alert);
    if (corto_define(m_lo)) {
        goto error;
    }

    corto_member m_hi = corto_declare(this, "hi", corto_member_o);
    if (!m_hi) {
        goto error;
    }
    corto_set_ref(&m_hi->type, corto_rangespec_o);
    m_hi->_default = ut_asprintf("{%f,%f}", this->hi.medium_alert, this->hi.high_alert);
    if (corto_define(m_hi)) {
        goto error;
    }

    /* Call super constructor */
    return corto_struct_construct(this);
error:
    return -1;
}
