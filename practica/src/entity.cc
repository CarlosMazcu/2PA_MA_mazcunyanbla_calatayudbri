//
//
//

#include "entity.h"
#include "animation.h"
#include "game_manager.h"

uint64_t Entity::next_id_ = 0;

Entity::Entity()
{
  tag_ = 0;
  enable_ = true;
  position_ = {0.0f, 0.0f};
  rotation_ = 0.0f;
  scale_ = {1.0f, 1.0f};
  speed_ = 1.0f;
  // animation_ = nullptr;

  id_ = Entity::next_id_;
  Entity::next_id_ ++;
}


Entity::Entity(const Entity& copy)
{
  tag_ = copy.tag_;
  enable_ = copy.enable_;
  position_ = copy.position_;
  rotation_ = copy.rotation_;
  scale_ = copy.scale_;
  // animation_ = nullptr;

  id_ = Entity::next_id_;
  Entity::next_id_++;
}

Entity::Entity(int tag, bool enable, Vec2 pos, float rot, Vec2 scale) 
{
    tag_ = tag;
    enable_ = enable;
    position_ = pos; 
    rotation_ = rot;
    scale_ = scale;
}

// Entity::~Entity()
// {
//   stopAnimation();
// }

void Entity::init(int tag, bool enable, Vec2 pos, float rot, Vec2 scale, float speed)
{
  tag_ = tag;
  enable_ = enable;
  position_ = pos;
  rotation_ = rot;
  scale_ = scale;
  speed_ = speed;

  // animation_ = nullptr; 
}

void Entity::set_position(const Vec2& pos)
{
    position_ = pos;
}
void Entity::set_rotation(const float rads)
{
    rotation_ = rads;
}
void Entity::set_scale(const Vec2 &scale)
{
  scale_ = scale;
}

Vec2 Entity::position() const {
    return position_;
} 

float Entity::rotation() const
{
  return rotation_; 
}

Vec2 Entity::scale() const
{
    return scale_;
}

uint64_t Entity::id() const{
  return id_;
}

void initAllEntityParallax()
{
  GameManager &GM = GameManager::Instance();
  Texture *text;

  //Space background
  text = text->TextureFactory("../data/parallax/Space_Background.png");
  for(int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.space[i].texture_handle_ = text;
    GM.all_sprites.parallax.space[i].Entity::init(0, true, {(float)(i * GM.all_sprites.parallax.space[i].width()), 
                               -(float)(GM.all_sprites.parallax.space[i].height()/4)}, 0.0f, {1.0f, 1.0f}, 10.0f);
  }
  //Clouds
  text = text->TextureFactory("../data/parallax/near-clouds.png");
  for(int i = 0; i < 6; i++)
  {
    GM.all_sprites.parallax.clouds[i].texture_handle_ = text;
    GM.all_sprites.parallax.clouds[i].Entity::init(1, true, {(float)(i * GM.all_sprites.parallax.clouds->width()),
                                                            60.0f}, 0.0f, {2.0f, 2.0f}, 20.0f);
  }
  //mountains
  text = text->TextureFactory("../data/parallax/mountain.png");
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.mountains[i].texture_handle_ = text;
    GM.all_sprites.parallax.mountains[i].Entity::init(2, true, {(float)(i * GM.all_sprites.parallax.mountains->width()),
                                                      230.0f}, 0.0f, {1.0f, 1.0f}, 60.0f);
  }
  //small trees
  text = text->TextureFactory("../data/SpriteSheet/background_sheet.png");
  text->init(text->getHandle(), 526, 428, 220, 20);
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.smallTrees[i].texture_handle_ = text;
    GM.all_sprites.parallax.smallTrees[i].Entity::init(3, true, {(float)(i * GM.all_sprites.parallax.smallTrees->width()),
                                                       360.0f}, 0.0f, {1.0f, 1.0f}, 100.0f);
  }
  //bigtrees
  text = text->TextureFactory("../data/SpriteSheet/background_sheet.png");
  text->init(text->getHandle(), 265, 409, 253, 43);
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.bigTrees[i].texture_handle_ = text;
    GM.all_sprites.parallax.bigTrees[i].Entity::init(4, true, {(float)(i * GM.all_sprites.parallax.bigTrees->width()), 
                                                      340.0f}, 0.0f, {1.0f, 1.0f}, 150.0f);
  }
  text = text->TextureFactory("../data/parallax/grass.png");
  for (int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.grass[i].texture_handle_ = text;
    GM.all_sprites.parallax.grass[i].Entity::init(5, true, {(float)(i * GM.all_sprites.parallax.grass->width()), 
                                                      375.0f}, 0.0f, {1.0f, 1.0f}, 230.0f);
  }
}

void initAllEntityCharacter()
{
  GameManager &GM = GameManager::Instance();

  
  // main character
  for (int i = 0; i < 8; i++)
  {
    Texture *text_main_character;
    text_main_character = text_main_character->TextureFactory("../data/SpriteSheet/main_character.png");
    text_main_character->init(text_main_character->getHandle(), 367 + (61 * i), 132, 44, 44);

    GM.all_sprites.maincharacter[i].texture_handle_ = text_main_character;
    GM.all_sprites.maincharacter[i].Entity::init(6, true, {i * 61.0f, 100.0f}, 0.0f, {1.0f, 1.0f}, 20.0f);
  }

  // manektrik
  for (int i = 0; i < 4; i++)
  {
    Texture *text_manektrik;
    text_manektrik = text_manektrik->TextureFactory("../data/SpriteSheet/characters_sheet.png");
    text_manektrik->init(text_manektrik->getHandle(), i * 57, 0, 57, 46);

    GM.all_sprites.manektrik[i].texture_handle_ = text_manektrik;
    GM.all_sprites.manektrik[i].Entity::init(7, true, {i * 57.0f, 50.0f}, 0.0f, {1.0f, 1.0f}, 20.0f);
  }
  //volbeat
  for (int i = 0; i < 2; i++)
  {
    Texture *text_volbeat;
    text_volbeat = text_volbeat->TextureFactory("../data/SpriteSheet/characters_sheet.png");
    text_volbeat->init(text_volbeat->getHandle(), 236 + (i * 30), 0, 24 + (i * 6), 27);

    GM.all_sprites.volbeat[i].texture_handle_ = text_volbeat;
    GM.all_sprites.volbeat[i].Entity::init(8, true, {i * 27.0f, 140.0f}, 0.0f, {1.0f, 1.0f}, 20.0f);
  }
  
}

void updateParallax()
{
  GameManager &GM = GameManager::Instance();
  // space
    for (int i = 0; i < 2; i++)
  {

    GM.all_sprites.parallax.space[i].position_.x += ((GM.all_sprites.parallax.space[i].speed_ * GM.dt) * GM.incr_speed_);

    if (GM.all_sprites.parallax.space[i].position_.x >=
        (float)((GM.all_sprites.parallax.space[i].width())))
    {
      GM.all_sprites.parallax.space[i].position_.x =
          -(float)(GM.all_sprites.parallax.space[i].width());
    }
    }
    //clouds
    for(int i = 0; i < 6; i++)
    {
      //move
      GM.all_sprites.parallax.clouds[i].position_.x += ((GM.all_sprites.parallax.clouds[i].speed_ * GM.dt) * GM.incr_speed_);
      //teleport
      if((GM.all_sprites.parallax.clouds[i].position_.x) >= GM.windowSize.x)
      {
        if(i == 5){
          GM.all_sprites.parallax.clouds[i].position_.x = GM.all_sprites.parallax.clouds[i - i].position_.x - GM.all_sprites.parallax.clouds[i].width();
        }else{
          GM.all_sprites.parallax.clouds[i].position_.x = GM.all_sprites.parallax.clouds[i + 1].position_.x - GM.all_sprites.parallax.clouds[i].width();
        }
      }
    }
    //mountains
    for(int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.mountains[i].position_.x += ((GM.all_sprites.parallax.mountains[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.mountains[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.mountains[i].position_.x = GM.all_sprites.parallax.mountains[i - i].position_.x - GM.all_sprites.parallax.mountains[i].width();
        }
        else
        {
          GM.all_sprites.parallax.mountains[i].position_.x = GM.all_sprites.parallax.mountains[i + 1].position_.x - GM.all_sprites.parallax.mountains[i].width();
        }
      }
    }
    //small trees
    for (int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.smallTrees[i].position_.x += ((GM.all_sprites.parallax.smallTrees[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.smallTrees[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.smallTrees[i].position_.x = GM.all_sprites.parallax.smallTrees[i - i].position_.x - GM.all_sprites.parallax.smallTrees[i].width();
        }
        else
        {
          GM.all_sprites.parallax.smallTrees[i].position_.x = GM.all_sprites.parallax.smallTrees[i + 1].position_.x - GM.all_sprites.parallax.smallTrees[i].width();
        }
      }
    }
    //big trees
    for (int i = 0; i < 8; i++)
    {
      GM.all_sprites.parallax.bigTrees[i].position_.x += ((GM.all_sprites.parallax.bigTrees[i].speed_ * GM.dt) * GM.incr_speed_);
      if ((GM.all_sprites.parallax.bigTrees[i].position_.x) >= GM.windowSize.x)
      {
        if (i == 7)
        {
          GM.all_sprites.parallax.bigTrees[i].position_.x = GM.all_sprites.parallax.bigTrees[i - i].position_.x - GM.all_sprites.parallax.bigTrees[i].width();
        }
        else
        {
          GM.all_sprites.parallax.bigTrees[i].position_.x = GM.all_sprites.parallax.bigTrees[i + 1].position_.x - GM.all_sprites.parallax.bigTrees[i].width();
        }
      }
    }
    //grass
    for (int i = 0; i < 2; i++)
    {

      GM.all_sprites.parallax.grass[i].position_.x += ((GM.all_sprites.parallax.grass[i].speed_ * GM.dt) * GM.incr_speed_) ;

      if (GM.all_sprites.parallax.grass[i].position_.x >=
          (float)((GM.all_sprites.parallax.grass[i].width())))
      {
        GM.all_sprites.parallax.grass[i].position_.x =
            -(float)(GM.all_sprites.parallax.grass[i].width());
      }
    }

}

void drawParallax()
{
  GameManager &GM = GameManager::Instance();
  //space
  for (int i = 0; i < 2; i++)
  {
    GM.all_sprites.parallax.space[i].draw();
  }
  //clouds
  for(int i = 0; i < 6; i++)
  {
    GM.all_sprites.parallax.clouds[i].draw();
  }
  //mountains
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.mountains[i].draw();
  }
  //small trees
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.smallTrees[i].draw();
  }
  //big trees
  for (int i = 0; i < 8; i++)
  {
    GM.all_sprites.parallax.bigTrees[i].draw();
  }
  //grass
  for (int i = 0; i < 2; i++)
  {
     GM.all_sprites.parallax.grass[i].draw();
  }
}

void drawSprites()
{
  GameManager &GM = GameManager::Instance();
  for(int i = 0; i < 8; i++)
  {
    GM.all_sprites.maincharacter[i].draw();
    
  }
  for (int i = 0; i < 4; i++)
  {
    GM.all_sprites.manektrik[i].draw();
  }
  for(int i = 0; i < 2; i++)
  {
    GM.all_sprites.volbeat[i].draw();
  }
}



// void Entity::PlayAnimation(const AnimationConfig &ac) 
// {
//   stopAnimation();
//   animation_ = new AnimationInstance(ac, this);
// }


// void Entity::update(float dt)
// {
//   if(true == enable_)
//   {
//     if(nullptr != animation_)
//     {
//       animation_->update(dt);
//     }
//   }
// }

// void Entity::stopAnimation()
// {
//   if(nullptr != animation_)
//   {
//     delete animation_;
//     animation_ = nullptr;
//   }
// }