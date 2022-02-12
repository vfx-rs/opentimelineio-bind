#pragma once

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

struct Any;
typedef struct Any Any;

OTIO_API void Any_destroy(Any *self);
