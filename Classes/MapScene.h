//
//  MapScene.h
//  Nin
//
//  Created by gama6 on 2014/12/05.
//
//

#ifndef __Nin__MapScene__
#define __Nin__MapScene__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

class MapScene : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;

  public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MapScene);
};

#endif /* defined(__Nin__MapScene__) */
