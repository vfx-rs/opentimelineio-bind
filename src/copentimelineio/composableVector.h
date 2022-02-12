#pragma once

#include "composable.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

struct ComposableVectorIterator;
typedef struct ComposableVectorIterator ComposableVectorIterator;
struct ComposableVector;
typedef struct ComposableVector ComposableVector;

OTIO_API ComposableVector*               ComposableVector_create();
OTIO_API void                      ComposableVector_destroy(ComposableVector* self);
OTIO_API ComposableVectorIterator* ComposableVector_begin(ComposableVector* self);
OTIO_API ComposableVectorIterator* ComposableVector_end(ComposableVector* self);
OTIO_API int                       ComposableVector_size(ComposableVector* self);
OTIO_API int                       ComposableVector_max_size(ComposableVector* self);
OTIO_API int                       ComposableVector_capacity(ComposableVector* self);
OTIO_API void  ComposableVector_resize(ComposableVector* self, int n);
OTIO_API bool ComposableVector_empty(ComposableVector* self);
OTIO_API void  ComposableVector_shrink_to_fit(ComposableVector* self);
OTIO_API void  ComposableVector_reserve(ComposableVector* self, int n);
OTIO_API void ComposableVector_swap(ComposableVector* self, ComposableVector* other);
OTIO_API Composable* ComposableVector_at(ComposableVector* self, int pos);
OTIO_API void ComposableVector_push_back(ComposableVector* self, Composable* value);
OTIO_API void ComposableVector_pop_back(ComposableVector* self);
OTIO_API ComposableVectorIterator* ComposableVector_insert(
    ComposableVector* self, ComposableVectorIterator* pos, Composable* val);
OTIO_API void                      ComposableVector_clear(ComposableVector* self);
OTIO_API ComposableVectorIterator* ComposableVector_erase(
    ComposableVector* self, ComposableVectorIterator* pos);
OTIO_API ComposableVectorIterator* ComposableVector_erase_range(
    ComposableVector*         self,
    ComposableVectorIterator* first,
    ComposableVectorIterator* last);
OTIO_API void ComposableVectorIterator_advance(ComposableVectorIterator* iter, int dist);
OTIO_API ComposableVectorIterator*
            ComposableVectorIterator_next(ComposableVectorIterator* iter, int dist);
OTIO_API ComposableVectorIterator*
            ComposableVectorIterator_prev(ComposableVectorIterator* iter, int dist);
OTIO_API Composable* ComposableVectorIterator_value(ComposableVectorIterator* iter);
OTIO_API bool       ComposableVectorIterator_equal(
          ComposableVectorIterator* lhs, ComposableVectorIterator* rhs);
OTIO_API bool ComposableVectorIterator_not_equal(
    ComposableVectorIterator* lhs, ComposableVectorIterator* rhs);
OTIO_API void ComposableVectorIterator_destroy(ComposableVectorIterator* self);
