#pragma once

#include "anyDictionary.h"
/*#include "composition.h" //importing this give an error (Composable not defined) in mapCOmposableTimeRange.h */
#include "copentime/rationalTime.h"
#include "errorStatus.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct RetainerComposable RetainerComposable;
typedef struct Composable Composable;
struct Composition; /*A workaround for now,
                     * instead of including composition.h*/
typedef struct Composition Composition;

OTIO_API RetainerComposable *RetainerComposable_create(Composable *obj);
OTIO_API Composable *RetainerComposable_take_value(RetainerComposable *self);
OTIO_API Composable *RetainerComposable_value(RetainerComposable *self);
OTIO_API void RetainerComposable_managed_destroy(RetainerComposable *self);

OTIO_API Composable *Composable_create();
OTIO_API Composable *Composable_create_with_name_and_metadata(
        const char *name, AnyDictionary *metadata);
OTIO_API bool Composable_visible(Composable *self);
OTIO_API bool Composable_overlapping(Composable *self);
OTIO_API Composition *Composable_parent(Composable *self);
OTIO_API RationalTime
Composable_duration(Composable *self, OTIOErrorStatus *error_status);
OTIO_API const char *Composable_name(Composable *self);
OTIO_API AnyDictionary *Composable_metadata(Composable *self);
OTIO_API void Composable_set_name(Composable *self, const char *name);
OTIO_API bool Composable_to_json_file(
        Composable *self,
        const char *file_name,
        OTIOErrorStatus *error_status,
        int indent);
OTIO_API const char *Composable_to_json_string(
        Composable *self, OTIOErrorStatus *error_status, int indent);
OTIO_API bool Composable_is_equivalent_to(Composable *self, OTIOSerializableObject *other);
OTIO_API Composable *
Composable_clone(Composable *self, OTIOErrorStatus *error_status);
OTIO_API const char *Composable_schema_name(Composable *self);
OTIO_API int Composable_schema_version(Composable *self);
