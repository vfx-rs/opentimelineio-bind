#pragma once

#include "anyDictionary.h"
#include "errorStatus.h"
#include "serializableObject.h"
#include "typeInfo.h"
#include <stdbool.h>

#ifdef __cplusplus
# define OTIO_API extern "C"
#else
# define OTIO_API
#endif

typedef OTIOSerializableObject* (*TypeRegistryCreateFunction)();
typedef void (*TypeRegistryUpgradeFunction)(AnyDictionary*);
typedef struct TypeRegistry TypeRegistry;

OTIO_API TypeRegistry*               TypeRegistry_instance();
/*bool                       TypeRegistry_register_type(
                          TypeRegistry*              self,
                          const char*                schema_name,
                          int                        schema_version,
                          TypeInfo*                  type,
                          TypeRegistryCreateFunction create, //unable to cast this function pointer to std::function because of the wrapped return type
                          const char*                class_name);*/
OTIO_API bool TypeRegistry_register_type_from_existing_type(
    TypeRegistry*    self,
    const char*      schema_name,
    int              schema_version,
    const char*      existing_schema_name,
    OTIOErrorStatus* error_status);
/*OTIO_API bool TypeRegistry_register_upgrade_function(
    TypeRegistry*               self,
    const char*                 schema_name,
    int                         version_to_upgrade_to,
    TypeRegistryUpgradeFunction upgrade_function);*/
OTIO_API OTIOSerializableObject* TypeRegistry_instance_from_schema(
    TypeRegistry*    self,
    const char*      schema_name,
    int              schema_version,
    AnyDictionary*   dict,
    OTIOErrorStatus* error_status);
OTIO_API bool TypeRegistry_set_type_record(
    TypeRegistry*       self,
    OTIOSerializableObject* var1,
    const char*         schema_name,
    OTIOErrorStatus*    error_status);
OTIO_API void TypeRegistry_destroy(TypeRegistry* self);
