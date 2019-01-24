/* range.h
 * This is the main package file. Include this file in other projects.
 * Only modify inside the header-end and body-end sections.
 */

#ifndef CORTO_RANGE_H
#define CORTO_RANGE_H

#include "bake_config.h"

#define CORTO_RANGE_ETC ut_locate("corto.range", NULL, UT_LOCATE_ETC)

/* $header() */
/* Definitions that are required by package headers (native types) go here. */
/* $end */

#include "_type.h"
#include "_interface.h"
#include "_load.h"
#include "_binding.h"

#include <corto.range.c>

/* $body() */
/* Definitions here that need your package headers go here. */
/* $end */

#endif

