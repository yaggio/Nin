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
  
  Node* node = CSLoader::getInstance()->createNodeFromProtocolBuffers("MainScene.csb");
  this->addChild(node);
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
