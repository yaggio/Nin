//
//  Stage1.h
//  Nin
//
//  Created by yaggio on 2014/12/11.
//
//

#ifndef __Nin__Stage1__
#define __Nin__Stage1__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

class Stage1 : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;

  public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Stage1);
};

#endif /* defined(__Nin__Stage1__) */
