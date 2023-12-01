/**
 * @file game_manager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-11-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__ 1

#include "gsprite.h"

class GameManager{
 public:
  static GameManager& Instance()
  {
    if(nullptr == instance_)
    {
      instance_ = new GameManager();
    }
    return *instance_;
  }
  // all globals go here
  struct TWindow
  {
    bool welcome, parallax, transform, exit, credits;
  };
  
  TWindow window_bool;

/*   struct TConst
  {
    const int kSpace = 2;
    const int kClouds = 7;
    const int kMountains = 7;
    const int kSmallTrees = 7;
    const int kBigTrees = 7;
    const int kGrass = 4;

  };

  TConst kSprites;
 */
  struct TParallax
  {
    Sprite space[2];
    Sprite clouds[6];
    Sprite mountains[8];
    Sprite smallTrees[8];
    Sprite bigTrees[8];
    Sprite grass[2];

  };

  struct TSprite
  {
    Sprite manektrik[4];
    TParallax parallax;
  };

  TSprite all_sprites;
  float incrSpeed_ = 1.0f;
 

  enum
  {
    kWelcomeWindow = 0,
    kParallaxWindow = 1,
    kTransformWindow = 2,
    kExitWindow = 3,
    kCreditsWindow = 4,
  };


  
  Vec2 windowSize = {640.0f, 480.0f};

  float current_time, last_time, dt;
 private:
  GameManager(){}; //this MAY change :)
  GameManager(const GameManager& other){};

  static GameManager* instance_; 
};


#endif