//
//  TitleScene.cpp
//  Nin
//
//  Created by dorodoro on 2014/11/28.
//
//

#include "TitleScene.h"
#include "OpScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocos2d::ui;
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

  // cocos studio
  // CSLoader::getInstance()->setRecordProtocolBuffersPath(true);
  FileUtils::getInstance()->addSearchPath("res");
  node = CSLoader::getInstance()->createNode("res/TitleScene.csb");
  this->addChild(node);
  // ui layer
  //Layer *ui_layer = dynamic_cast<Layer*>(CSLoader::getInstance()->createNodeFromProtocolBuffers("res/UiLayer.csb"));
  //this->addChild(ui_layer);
  
  node->getChildByName<ui::Button*>("Button_1")->addClickEventListener([](Ref *ref) {
   // ボタン押した時の処理
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, OpScene::createScene(), Color3B::WHITE));
  });

  // spritesheet
  auto cache = SpriteFrameCache::getInstance();
  cache->addSpriteFramesWithFile("sprites.plist");
  sprite = Sprite::createWithSpriteFrameName("nin2.png");
  sprite->setPosition(-50, 300);
  sprite->setScale(3);
  this->addChild(sprite);
  // move cloud
  this->scheduleUpdate();
  return true;
}
void TitleScene::update(float delta){
  // clouds
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
  // nin
  auto pos = sprite->getPosition();
  float moved_x, moved_y;
  if (pos.x < 640 + 100){
    moved_x = pos.x + 2;
  } else {
    moved_x = 0;
  }
  if (pos.x == 640/ 2){
    moved_y = 330;
  } else {
    moved_y = 300;
  }
  sprite->setPosition(moved_x, moved_y);
}
