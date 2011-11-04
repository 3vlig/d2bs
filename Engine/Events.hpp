#pragma once

#include "Engine.hpp"

#include "js32.hpp"

extern JSClass event_class;
extern JSClassSpec event_classes[];
extern JSModuleSpec event_modules[];

JSAPI_FUNC(event_addListener);
JSAPI_FUNC(event_removeListener);
JSAPI_FUNC(event_removeListeners);
JSAPI_FUNC(event_fire);
