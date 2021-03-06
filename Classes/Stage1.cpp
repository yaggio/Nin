//
//  Stage1.cpp
//  Nin
//
//  Created by yaggio on 2014/12/11.
//
//

#include "Stage1.h"

using namespace cocos2d;
using namespace std;

USING_NS_CC;

Scene* Stage1::createScene()
{
  auto scene = Scene::create();
  auto layer = Stage1::create();
  scene->addChild(layer);

  return scene;
}

bool Stage1::init()
{
  if ( !Layer::init() ) return false;

  //Welcome Message
  auto windowSize = Director::getInstance()->getWinSize();
  auto label = LabelTTF::create("Stage1", "Arial", 24);
  label->setPosition(windowSize.width / 2, windowSize.height / 2);
  this->addChild(label);
  
    // MAP
  TMXTiledMap* tile_map = TMXTiledMap::create("stage1.tmx");
  this->addChild(tile_map);
  // spritesheet
  auto cache = SpriteFrameCache::getInstance();
  cache->addSpriteFramesWithFile("sprites.plist");
  Sprite* sprite = Sprite::createWithSpriteFrameName("nin2.png");
  sprite->setScale(3);
  sprite->setPosition(300, 16*5 + 32);
  this->addChild(sprite);
  
  return true;
}
