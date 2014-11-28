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
  
  auto node = CSLoader::getInstance()->createNodeFromProtocolBuffers("MainScene.csb");
  this->addChild(node);
  
  // move cloud)
  auto cloud = dynamic_cast<Sprite*>(node->getChildByTag(10));
  
  Vec2 point = cloud->getPosition();
  log("x座標は%fです", point.x);
  log("y座標は%fです", point.y);
  int move_x;
  if (point.x < 640 - cloud->getContentSize().width) {
    move_x = 640;
  } else {
    move_x = 0;
  }
  cloud->runAction(MoveTo::create(10.0f, Point(640, point.y)));

  return true;
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
