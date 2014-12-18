//
//  TitleScene.h
//  Nin
//
//  Created by 矢島 新太郎 on 2014/11/28.
//
//

#ifndef __Nin__TitleScene__
#define __Nin__TitleScene__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace std;

class TitleScene : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;
    cocos2d::Node *node;
    cocos2d::Sprite *sprite;
    void pushStart(cocos2d::Ref *sender, TouchEventType type);

  public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);
    void update(float delta);
};

#endif /* defined(__Nin__TitleScene__) */
