#pragma once

#include "any.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif
typedef struct AnyVectorIterator AnyVectorIterator;
typedef struct AnyVector AnyVector;
typedef struct AnyVectorMutationStamp AnyVectorMutationStamp;

OTIO_API AnyVector *AnyVector_create();

OTIO_API void AnyVector_destroy(AnyVector *self);

OTIO_API AnyVectorIterator *AnyVector_begin(AnyVector *self);

OTIO_API AnyVectorIterator *AnyVector_end(AnyVector *self);

OTIO_API int AnyVector_size(AnyVector *self);

OTIO_API int AnyVector_max_size(AnyVector *self);

OTIO_API int AnyVector_capacity(AnyVector *self);

OTIO_API void AnyVector_resize(AnyVector *self, int n);

OTIO_API bool AnyVector_empty(AnyVector *self);

OTIO_API void AnyVector_shrink_to_fit(AnyVector *self);

OTIO_API void AnyVector_reserve(AnyVector *self, int n);

OTIO_API void AnyVector_swap(AnyVector *self, AnyVector *other);

OTIO_API Any *AnyVector_at(AnyVector *self, int pos);

OTIO_API void AnyVector_push_back(AnyVector *self, Any *value);

OTIO_API void AnyVector_pop_back(AnyVector *self);

OTIO_API AnyVectorIterator *
AnyVector_insert(AnyVector *self, AnyVectorIterator *pos, Any *val);

OTIO_API void AnyVector_clear(AnyVector *self);

OTIO_API AnyVectorIterator *AnyVector_erase(AnyVector *self, AnyVectorIterator *pos);

OTIO_API AnyVectorIterator *AnyVector_erase_range(
        AnyVector *self, AnyVectorIterator *first, AnyVectorIterator *last);

OTIO_API void AnyVectorIterator_advance(AnyVectorIterator *iter, int dist);

OTIO_API AnyVectorIterator *
AnyVectorIterator_next(AnyVectorIterator *iter, int dist);

OTIO_API AnyVectorIterator *
AnyVectorIterator_prev(AnyVectorIterator *iter, int dist);

OTIO_API Any *AnyVectorIterator_value(AnyVectorIterator *iter);

OTIO_API bool
AnyVectorIterator_equal(AnyVectorIterator *lhs, AnyVectorIterator *rhs);

OTIO_API bool
AnyVectorIterator_not_equal(AnyVectorIterator *lhs, AnyVectorIterator *rhs);

OTIO_API void AnyVectorIterator_destroy(AnyVectorIterator *self);

OTIO_API AnyVectorMutationStamp *MutationStamp_create(AnyVector *v);

OTIO_API void MutationStamp_destroy(AnyVectorMutationStamp *self);

OTIO_API AnyVectorMutationStamp *
AnyVector_get_or_create_mutation_stamp(AnyVector *self);
