#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Board.h"
#include <string>
#include <list>
#include "Actor.h"
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
//keeps track of the game world(including all its inhabitants)

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetPath);
    ~StudentWorld();
  virtual int init(); //will be called when game starts
                    //will construct a representation of the current board and populate it with initial objects
                    //return GWSTATUS_CONTINUE_GAME
  virtual int move(); //after the game is initiallized, move will be called
                        //everytime move is called, must run a single tick of game
                        //ask the actor to do something
                        //disposing actors that need to disappear
  virtual void cleanUp();//called when Peach and Yoshi complete current game.
                        //deleting all remaining actors
                        //
    
private:
    bool canloadBoard();
    void loadActors();
    Board m_board;
    std::list<Actor*> m_actors;
    std::list<Actor*> m_players;
};

#endif // STUDENTWORLD_H_
