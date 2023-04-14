#include "StudentWorld.h"
#include "GameConstants.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}

StudentWorld::~StudentWorld()
{
    cleanUp();
}
int StudentWorld::init()
{
    //initialize the data structures used to keep track of your game's world
    //allocate the insert Peach and Yoshi objects into the game world.
    //allocate and insert all of the other objects into the game world as described
    //to load board:
if(!canloadBoard())
    return GWSTATUS_BOARD_ERROR;
else
{
    loadActors();
    
	startCountdownTimer(99);  // this placeholder causes timeout after 5 seconds
    return GWSTATUS_CONTINUE_GAME;
}
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you hit ESC.
    // Notice that the return value GWSTATUS_NOT_IMPLEMENTED will cause our framework to end the game.
    
    if (timeRemaining() <= 0)
    {
		playSound(SOUND_GAME_FINISHED);
        setFinalScore(getWinnerStars(), getWinnerCoins());
        return GWSTATUS_PEACH_WON;
    }
    //ask peach to move;
    list<Actor*>::iterator it1;
    it1 = m_players.begin();
    while(it1 != m_players.end())
    {
        (*it1)->doSomething();
        it1++;
    }
    //ask the square to move;
    list<Actor*>::iterator it2;
    it2 = m_actors.begin();
    while(it2 != m_actors.end())
    {
        (*it2)->doSomething();
        it2++;
    }
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    list<Actor*>::iterator it1;
    list<Actor*>::iterator next;
    it1 = m_players.begin();
    while(it1 != m_players.end())
    {
        next = ++it1;
        --it1;
        delete *it1;
        m_players.erase(it1);
        it1 = next;
    }
    //ask the square to move;
    list<Actor*>::iterator it2;
    it2 = m_actors.begin();
    while(it2 != m_actors.end())
    {
        next = ++it2;
        --it2;
        delete *it2;
        m_actors.erase(it2);
        it2 = next;
    }
}

bool StudentWorld::canloadBoard()
{
    //int board_number = getBoardNumber();

//std::string file_name = "/board0"+ to_string(board_number) + ".txt";
    std::string board_file = assetPath() + "board01.txt";
//std::string board_file = assetPath() + file_name;
Board::LoadResult result =m_board.loadBoard(board_file);
if(result == Board::load_fail_bad_format || result == Board::load_fail_file_not_found)
    return false;
    return true;
 }

void StudentWorld::loadActors()
{
    for(int gy = 0; gy<BOARD_HEIGHT;gy++)
        for(int gx=0; gx<BOARD_WIDTH;gx++)
        {
            Board::GridEntry ge = m_board.getContentsOf(gx, gy);
            switch (ge)
            {
                case Board::player:
                {
                    m_players.push_back(new Peach(this, gx*SPRITE_WIDTH, gy*SPRITE_HEIGHT));
                    m_actors.push_back(new blueSquare(this, gx*SPRITE_WIDTH, gy*SPRITE_HEIGHT));
                    break;
                }
                case Board::blue_coin_square:
                {
                    m_actors.push_back(new blueSquare(this, gx*SPRITE_WIDTH, gy*SPRITE_HEIGHT));
                    break;
                }
                case Board::red_coin_square:
                {
                    m_actors.push_back(new blueSquare(this,gx*SPRITE_WIDTH, gy*SPRITE_HEIGHT));
                    break;
                }
                default:
                    break;
            }
        }
}
/*
for(int gy = 0; gy<BOARD_HEIGHT; gy++)
{
    for(int gx = 0; gx<BOARD_WIDTH; gx++)
    {
        Board::GridEntry ge=m_board.getContentsOf(gx, gy);
        switch (ge)
        {
            case ;
        }
    }
}
*/
