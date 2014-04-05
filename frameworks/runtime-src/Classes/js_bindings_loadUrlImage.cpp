#include "LoadUrlImage.h"
#include "ScriptingCore.h"

bool JSB_LoadUrlImage_loadUrlImage(JSContext *cx, uint32_t argc, jsval *vp){
	std::string url ;
	
	jsval *argv = JS_ARGV(cx, vp);	
	jsval_to_std_string(cx, argv[0], &url);	

	LoadUrlImage::loadUrlImage(url.c_str(),JSVAL_TO_INT(argv[1]));

	return true;
}
void register_LoadUrlImage_js(JSContext* cx, JSObject* global)
{
	JS::RootedValue nsval(cx);
    JS::RootedValue tmpval(cx);
    JS::RootedObject pJsbObject(cx);

	JS_GetProperty(cx, global, "LoadUrlImage", &nsval);
	if (nsval == JSVAL_VOID) {
		pJsbObject = JS_NewObject(cx, NULL, NULL, NULL);
		nsval = OBJECT_TO_JSVAL(global);
		JS_SetProperty(cx, global, "LoadUrlImage", nsval);
	}
    else
    {
		JS_ValueToObject(cx, nsval, &pJsbObject);
    }

	JS_DefineFunction(cx, global, "loadUrlImage", JSB_LoadUrlImage_loadUrlImage, 2, JSPROP_READONLY | JSPROP_PERMANENT);
}
