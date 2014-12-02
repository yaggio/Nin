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

class TitleScene : public cocos2d::Layer
{
  private:
    cocos2d::EventListenerTouchOneByOne *eventListener;
    cocos2d::Node *node;

  public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);
    // EVENT 
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
};

#endif /* defined(__Nin__TitleScene__) */
