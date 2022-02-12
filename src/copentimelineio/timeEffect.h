#pragma once

#include "copentimelineio/anyDictionary.h"
#include "errorStatus.h"
#include "serializableObject.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct TimeEffect TimeEffect;

OTIO_API TimeEffect* TimeEffect_create(
    const char* name, const char* effect_name, AnyDictionary* metadata);
OTIO_API const char* TimeEffect_effect_name(TimeEffect* self);
OTIO_API void TimeEffect_set_effect_name(TimeEffect* self, const char* effect_name);
OTIO_API const char*    TimeEffect_name(TimeEffect* self);
OTIO_API void           TimeEffect_set_name(TimeEffect* self, const char* name);
OTIO_API AnyDictionary* TimeEffect_metadata(TimeEffect* self);
OTIO_API bool          TimeEffect_to_json_file(
             TimeEffect*      self,
             const char*      file_name,
             OTIOErrorStatus* error_status,
             int              indent);
OTIO_API const char* TimeEffect_to_json_string(
    TimeEffect* self, OTIOErrorStatus* error_status, int indent);
OTIO_API bool
    TimeEffect_is_equivalent_to(TimeEffect* self, OTIOSerializableObject* other);
OTIO_API TimeEffect*
            TimeEffect_clone(TimeEffect* self, OTIOErrorStatus* error_status);
OTIO_API const char* TimeEffect_schema_name(TimeEffect* self);
OTIO_API int         TimeEffect_schema_version(TimeEffect* self);
