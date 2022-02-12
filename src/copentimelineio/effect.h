#pragma once

#include "anyDictionary.h"
#include "serializableObject.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct RetainerEffect RetainerEffect;
typedef struct Effect Effect;

OTIO_API RetainerEffect *RetainerEffect_create(Effect *obj);

OTIO_API Effect *RetainerEffect_take_value(RetainerEffect *self);

OTIO_API Effect *RetainerEffect_value(RetainerEffect *self);

OTIO_API void RetainerEffect_managed_destroy(RetainerEffect *self);

OTIO_API Effect *Effect_create(
        const char *name, const char *effect_name, AnyDictionary *metadata);

OTIO_API const char *Effect_effect_name(Effect *self);

OTIO_API void Effect_set_effect_name(Effect *self, const char *effect_name);

OTIO_API const char *Effect_name(Effect *self);

OTIO_API void Effect_set_name(Effect *self, const char *name);

OTIO_API AnyDictionary *Effect_metadata(Effect *self);

OTIO_API bool Effect_to_json_file(
        Effect *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);

OTIO_API const char *Effect_to_json_string(
        Effect *self, OTIOErrorStatus *error_status, int indent);

OTIO_API bool Effect_is_equivalent_to(Effect *self, OTIOSerializableObject *other);

OTIO_API Effect *Effect_clone(Effect *self, OTIOErrorStatus *error_status);

OTIO_API const char *Effect_schema_name(Effect *self);

OTIO_API int Effect_schema_version(Effect *self);
