//
//  TitleScene.cpp
//  Nin
//
//  Created by dorodoro on 2014/11/28.
//
//

#include "TitleScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

Scene* TitleScene::createScene()
{
  auto scene = Scene::create();
  auto layer = TitleScene::create();
  scene->addChild(layer);

  return scene;
}

bool TitleScene::init()
{
  if ( !Layer::init() ) return false;

  //Welcome Message
  auto windowSize = Director::getInstance()->getWinSize();
  
  node = CSLoader::getInstance()->createNodeFromProtocolBuffers("MainScene.csb");
  this->addChild(node);
  
  this->scheduleUpdate();
  return true;
}
void TitleScene::update(float delta){
  int clouds[3] = {10, 11, 12};
  for (int i = 0; i < 3; i++) {
    int tag_no = clouds[i];
    auto c = dynamic_cast<Sprite*>(node->getChildByTag(tag_no));
    auto pos = c->getPosition();
    //log("%f : %f", pos.x, pos.y);
    float moved_x, moved_y;
    if (pos.x < 640 + 100){
      moved_x = pos.x + tag_no - 8;
    } else {
      moved_x = 0;
    }
    c->setPosition(moved_x, pos.y);
  }
}
bool TitleScene::onTouchBegan(Touch* pTouch, Event* pEvent)
{
  return true;
}

void TitleScene::onTouchMoved(Touch* pTouch, Event* pEvent)
{
  return;
}

void TitleScene::onTouchEnded(Touch* pTouch, Event* pEvent)
{
  return;
}
