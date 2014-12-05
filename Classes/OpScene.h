//
//  OpScene.h
//  Nin
//
//  Created by gama6 on 2014/12/04.
//
//

#ifndef __Nin__OpScene__
#define __Nin__OpScene__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;
class OpScene : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;
    cocos2d::Node *node;
    void pushSkip(cocos2d::Ref *sender, TouchEventType type);

  public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(OpScene);
};

#endif /* defined(__Nin__OpScene__) */
