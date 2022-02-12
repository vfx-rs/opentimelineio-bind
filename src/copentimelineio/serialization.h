#pragma once

#include "errorStatus.h"
#include "any.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API const char *serialize_json_to_string(
        Any *value, OTIOErrorStatus *error_status, int indent);

OTIO_API bool serialize_json_to_file(
        Any *value,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
