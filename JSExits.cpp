#include "JSExits.h"

EMPTY_CTOR(exit)

void exit_finalize(JSContext *cx, JSObject *obj)
{
	myExit* pExit = (myExit*)JS_GetPrivate(cx, obj);
	delete pExit;
}

JSAPI_PROP(exit_getProperty)
{
	myExit* pExit = (myExit*)JS_GetPrivate(cx, obj);

	*vp = JSVAL_VOID;

	if(!pExit)
		return JS_TRUE;

	switch(JSVAL_TO_INT(id))
	{
		case EXIT_X:
			*vp = INT_TO_JSVAL(pExit->x);
			break;
		case EXIT_Y:
			*vp = INT_TO_JSVAL(pExit->y);
			break;
		case EXIT_TARGET:
			*vp = INT_TO_JSVAL(pExit->id);
			break;
		case EXIT_TYPE:
			*vp = INT_TO_JSVAL(pExit->type);
			break;
		case EXIT_TILEID:
			*vp = INT_TO_JSVAL(pExit->tileid);
			break;
		case EXIT_LEVELID:
			*vp = INT_TO_JSVAL(pExit->level);
			break;
		default:
			break;
	}

	return JS_TRUE;
}

