/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"
#include "converter.h"
#include "project_settings.h"

static Converter *module = NULL;

void register_converter_types() {
    module = memnew(Converter);

    ClassDB::register_class<Converter>();

    ProjectSettings::get_singleton()->add_singleton( ProjectSettings::Singleton("Converter", module) );
}

void unregister_converter_types() {
    memdelete(module);
}