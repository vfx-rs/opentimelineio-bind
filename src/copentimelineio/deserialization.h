#pragma once

#include "any.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

OTIO_API bool deserialize_json_from_string(
        const char *input, Any *destination, OTIOErrorStatus *error_status);

OTIO_API bool deserialize_json_from_file(
        const char *file_name, Any *destination, OTIOErrorStatus *error_status);
