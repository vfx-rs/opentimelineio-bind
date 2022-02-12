#pragma once

#include "anyDictionary.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct FreezeFrame FreezeFrame;

OTIO_API FreezeFrame *FreezeFrame_create(const char *name, AnyDictionary *metadata);

OTIO_API double FreezeFrame_time_scalar(FreezeFrame *self);

OTIO_API void FreezeFrame_set_time_scalar(FreezeFrame *self, double time_scalar);

OTIO_API const char *FreezeFrame_effect_name(FreezeFrame *self);

OTIO_API void
FreezeFrame_set_effect_name(FreezeFrame *self, const char *effect_name);

OTIO_API const char *FreezeFrame_name(FreezeFrame *self);

OTIO_API void FreezeFrame_set_name(FreezeFrame *self, const char *name);

OTIO_API AnyDictionary *FreezeFrame_metadata(FreezeFrame *self);

OTIO_API bool FreezeFrame_to_json_file(
        FreezeFrame *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *FreezeFrame_to_json_string(
        FreezeFrame *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool
FreezeFrame_is_equivalent_to(FreezeFrame *self, OTIOSerializableObject *other);

OTIO_API FreezeFrame *
FreezeFrame_clone(FreezeFrame *self, OTIOErrorStatus *error_status);

OTIO_API const char *FreezeFrame_schema_name(FreezeFrame *self);

OTIO_API int FreezeFrame_schema_version(FreezeFrame *self);
