#pragma once

#include "composable.h"

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct RetainerPairComposable RetainerPairComposable;

OTIO_API RetainerPairComposable *RetainerPairComposable_create(
        RetainerComposable *first, RetainerComposable *second);

OTIO_API RetainerComposable *
RetainerPairComposable_first(RetainerPairComposable *self);

OTIO_API RetainerComposable *
RetainerPairComposable_second(RetainerPairComposable *self);

OTIO_API void RetainerPairComposable_destroy(RetainerPairComposable *self);
