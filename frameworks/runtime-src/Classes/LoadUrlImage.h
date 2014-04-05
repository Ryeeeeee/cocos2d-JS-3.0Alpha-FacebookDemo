
#ifndef __LOAD_URL_IMAGE__
#define __LOAD_URL_IMAGE__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "network/HttpClient.h"

class LoadUrlImage : public cocos2d::Ref
{
public:
	static LoadUrlImage* getInstance();
	
	//download image from network and add to CCTextureCache,not save to disk
	static void loadUrlImage(const char* url,int cbIndex);

	//onHttpRequestCompleted
	void onLoadCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response);
	
private:
	LoadUrlImage();
	static void callJsFunction(int cbIndex,const char* imageKey);

};


#endif