#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
StudentWorld *Actor::getWorld() const
{
    return m_world;
}

void player_avatar::doSomething()
{
    if(waitToRoll)
    {
        switch (getWorld()->getAction(m_playerNum))
        {
            case ACTION_ROLL:
            {
                int die_roll = randInt(1, 10);
                tick_to_move = die_roll * 8;
                waitToRoll = false;
                break;
            }
            case ACTION_NONE:
                break;
        }
    }
    else
    {
        //if()//if avatar can't continue moving forward in its current direction anymore
            //up over down
            //right over left
            //update the walking direction and the sprite direction if necessary
            
        moveAtAngle(walk_dir, 2);//move two pixels in the walk direction
        tick_to_move --;
        if(tick_to_move == 0)
            waitToRoll = true;
    }
}

void coinSquare::doSomething()
{
    if(!alive)
        return;
}

