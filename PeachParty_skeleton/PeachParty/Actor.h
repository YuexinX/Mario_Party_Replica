#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

class StudentWorld;
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
//base class
class Actor: public GraphObject
{
public:
    Actor(StudentWorld *world, int imageID, int startX, int startY, int startDirection=0, int depth = 0)
    :GraphObject(imageID, startX, startY, startDirection){};
    virtual void doSomething() = 0;
protected:
    StudentWorld* getWorld() const;
private:
    StudentWorld *m_world;
};



//player: image iD, sprite direction of 0 degrees. start walking direction of right. starting x,y. player 1 or 2. graphical depth of 0, size 1, ticks to move value of 0, starts out in the waiting to roll state.
class player_avatar: public Actor
{
public:
    player_avatar(StudentWorld *world, int imageID, int startX, int startY, int playerNum)
    :Actor(world, imageID, startX, startY), tick_to_move(0), m_playerNum(playerNum),waitToRoll(true), walk_dir(0){};
    //doSomething
    virtual void doSomething();
private:
    int tick_to_move;
    int m_playerNum;
    bool waitToRoll;
    int walk_dir;
};




//peach
class Peach:public player_avatar
{
public:
    Peach(StudentWorld *world, int startX, int startY)
    :player_avatar(world, IID_PEACH, startX, startY, 1){};
    
};
//yoshi
class Yoshi:public player_avatar
{
public:
    Yoshi(StudentWorld *world, int startX, int startY)
    :player_avatar(world, IID_YOSHI, startX, startY, 2){};
};



//coin squares
class coinSquare:public Actor
{
public:
    coinSquare(StudentWorld *world, int startX, int startY, int imageID, int type)
    :Actor(world, imageID, startX, startY, 0, 1),coinNum(type), alive(true){};
    virtual void doSomething();
private:
    int coinNum;
    bool alive;
};

class redSquare:public coinSquare
{
public:
  redSquare(StudentWorld *world, int startX, int startY)
    :coinSquare(world, startX, startY, IID_RED_COIN_SQUARE,-3){};
};

class blueSquare:public coinSquare
{
public:
    blueSquare(StudentWorld *world, int startX, int startY)
    :coinSquare(world, startX, startY, IID_BLUE_COIN_SQUARE, 3){};
};




//star squares






//Directional Squares
//Bank Squares
//Event Squares
//Dropping Squares
//Boo
//Bowser
//Vortexes

#endif // ACTOR_H_
