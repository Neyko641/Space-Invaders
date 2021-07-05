#include <string>
#include <vector>
#include <time.h> 
/*
Space Invaders:
Rules can be found at : (http://www.classicgaming.cc/classics/space-invaders/play-guide)
*/
const char * PLAYER_SPRITE[] = { " =A= ", "=====" };

const char * PLAYER_EXPLOSION_SPRITE[] = { ",~^.'", "=====", "'+-`.", "=====" };

const char PLAYER_MISSILE_SPRITE = '|';

const char * SHIELD_SPRITE[] = { "/IIIII\\", "IIIIIII", "I/   \\I" };

const char * ALIEN30_SPRITE[] = { "/oo\\", "<  >", "/oo\\", "/\"\"\\" };

const char * ALIEN20_SPRITE[] = { " >< ", "|\\/|", "|><|", "/  \\" };

const char * ALIEN10_SPRITE[] = { "/--\\", "/  \\", "/--\\", "<  >" };

const char * ALIEN_EXPLOSION[] = { "\\||/", "/||\\" };

const char* ALIEN_BOMB_SPRITE = "\\|/-";

const char * ALIEN_UFO_SPRITE[] = { "_/oo\\_", "=q==p=" };

const char * FILE_NAME = "TextInvadersHighScoresTable.txt";

enum
{
	SHIELD_SPRITE_HEIGHT = 3,
	SHIELD_SPRITE_WIDTH = 7,
	NUM_ALIEN_ROWS = 5,
	NUM_ALIEN_COLUMNS = 11,
	MAX_NUMBER_OF_ALIEN_BOMBS = 3,
	MAX_NUMBER_OF_LIVES = 3,
	PLAYER_SPRITE_WIDTH = 5,
	PLAYER_SPRITE_HEIGHT = 2,
	NOT_IN_PLAY = -1,
	PLAYER_MOVEMENT_AMOUNT = 2,
	PLAYER_MISSILE_SPEED = 1,
	FPS = 20,
	NUM_SHIELDS = 4,
	ALIEN_SPRITE_WIDTH = 4,
	ALIEN_SPRITE_HEIGHT = 2,
	ALIENS_X_PADDING = 1,
	ALIENS_Y_PADDING = 1,
	ALIEN_EXPLOSION_TIME = 4,
	ALIEN_BOMB_SPEED = 1,
	WAIT_TIME = 10,
	NUM_LEVELS = 10,
	ALIEN_UFO_SPRITE_WIDTH = 6,
	ALIEN_UFO_SPRITE_HEIGHT = 2,
	MAX_NUMBER_OF_CHARACTERS_IN_NAME = 3,
	MAX_ALPHABET_CHARACTERS = 26,
	MAX_HIGH_SCORES = 10,

};

enum AlienState
{
	AS_ALIVE = 0,
	AS_DEAD,
	AS_EXPLODING
};

enum GameState
{
	GS_INTRO = 0,
	GS_HIGH_SCORES,
	GS_PLAY,
	GS_PLAYER_DEAD,
	GS_WAIT,
	GS_GAME_OVER
};

struct Position
{
	int x;
	int y;
};

struct Size
{
	int width;
	int height;
};

struct Player
{
	Position position;
	Position missile;
	Size spriteSize;
	int animation;
	int lives; //max 3
	int score;
};

struct Shield
{
	Position position;
	char * sprite[SHIELD_SPRITE_HEIGHT];
};

struct AlienBomb
{
	Position position;
	int animation;
};

struct AlienSwarm
{
	Position position;
	AlienState aliens[NUM_ALIEN_ROWS][NUM_ALIEN_COLUMNS];
	AlienBomb bombs[MAX_NUMBER_OF_ALIEN_BOMBS];
	Size spriteSize;
	int animation;
	int direction; // > 0 - for going right, < 0 - for going left, 1 or -1
	int numberOfBombsInPlay;
	int movementTime; //this is going capture how fast the aliens should be going
	int explosionTimer; //This going to capture how long to explode for
	int numAliensLeft; //this is to capture when to go to the next level
	int line; //This to capture when the aliens win - starts at the current level and decreases to 0 - once it's 0 then the aliens
};

struct AlienUFO
{
	Position position;
	Size size;
	int points; // from 50 - 200
};

struct Score
{
	int score;
	std::string name; //std:: because we're not saying using namespace std; - in this file
};

struct HighScoreTable
{
	std::vector<Score> scores;
};

struct Game
{
	Size windowSize;
	GameState currentState;
	int level;
	int waitTimer;
	clock_t gameTimer;

	int gameOverHPositionCursor; //where the horizontal cursor is
	char playerName[MAX_NUMBER_OF_CHARACTERS_IN_NAME + 1];
	int gameOverVPositionCursor[MAX_NUMBER_OF_CHARACTERS_IN_NAME];

};



