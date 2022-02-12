#pragma once
#include "any.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef struct AnyDictionaryIterator AnyDictionaryIterator;
typedef struct AnyDictionary AnyDictionary;
typedef struct AnyDictionaryMutationStamp AnyDictionaryMutationStamp;

OTIO_API AnyDictionary*                            AnyDictionary_create();
OTIO_API void                   AnyDictionary_destroy(AnyDictionary* self);
OTIO_API void                   AnyDictionary_clear(AnyDictionary* self);
OTIO_API AnyDictionaryIterator* AnyDictionary_begin(AnyDictionary* self);
OTIO_API AnyDictionaryIterator* AnyDictionary_end(AnyDictionary* self);
OTIO_API void AnyDictionary_swap(AnyDictionary* self, AnyDictionary* other);
OTIO_API AnyDictionaryIterator*
                       AnyDictionary_erase(AnyDictionary* self, AnyDictionaryIterator* pos);
OTIO_API AnyDictionaryIterator* AnyDictionary_erase_range(
    AnyDictionary*         self,
    AnyDictionaryIterator* first,
    AnyDictionaryIterator* last);
OTIO_API int   AnyDictionary_erase_key(AnyDictionary* self, const char* key);
OTIO_API int   AnyDictionary_size(AnyDictionary* self);
OTIO_API int   AnyDictionary_max_size(AnyDictionary* self);
OTIO_API bool AnyDictionary_empty(AnyDictionary* self);
OTIO_API AnyDictionaryIterator*
    AnyDictionary_find(AnyDictionary* self, const char* key);
OTIO_API AnyDictionaryIterator*
    AnyDictionary_insert(AnyDictionary* self, const char* key, Any* anyObj);
OTIO_API void AnyDictionaryIterator_advance(AnyDictionaryIterator* iter, int dist);
OTIO_API AnyDictionaryIterator*
    AnyDictionaryIterator_next(AnyDictionaryIterator* iter, int dist);
OTIO_API AnyDictionaryIterator*
            AnyDictionaryIterator_prev(AnyDictionaryIterator* iter, int dist);
OTIO_API const char* AnyDictionaryIterator_key(AnyDictionaryIterator* iter);
OTIO_API Any*        AnyDictionaryIterator_value(AnyDictionaryIterator* iter);
OTIO_API bool       AnyDictionaryIterator_equal(
          AnyDictionaryIterator* lhs, AnyDictionaryIterator* rhs);
OTIO_API bool AnyDictionaryIterator_not_equal(
    AnyDictionaryIterator* lhs, AnyDictionaryIterator* rhs);
OTIO_API void AnyDictionaryIterator_destroy(AnyDictionaryIterator* self);
OTIO_API AnyDictionaryMutationStamp*
     AnyDictionaryMutationStamp_create(AnyDictionary* d);
OTIO_API void AnyDictionaryMutationStamp_destroy(AnyDictionaryMutationStamp* self);
OTIO_API AnyDictionaryMutationStamp*
    AnyDictionary_get_or_create_mutation_stamp(AnyDictionary* self);
