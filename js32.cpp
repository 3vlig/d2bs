#include "ScriptEngine.h"
#include "js32.h"

JSObject* BuildObject(JSContext* cx, JSClass* classp, JSFunctionSpec* funcs, JSPropertySpec* props, void* priv, JSObject* proto, JSObject* parent)
{
	JSObject* obj = JS_NewObject(cx, classp, proto, parent);

	if(obj)
	{
		// add root to avoid newborn root problem
		if(JS_AddRoot(&obj) == JS_FALSE)
			return NULL;
		if(obj && funcs && !JS_DefineFunctions(cx, obj, funcs))
			obj = NULL;
		if(obj && props && !JS_DefineProperties(cx, obj, props))
			obj = NULL;
		if(obj && priv)
			JS_SetPrivate(cx, obj, priv);
		JS_RemoveRoot(&obj);
	}
	return obj;
}
