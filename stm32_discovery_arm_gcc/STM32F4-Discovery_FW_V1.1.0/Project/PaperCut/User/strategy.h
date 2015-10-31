#ifndef _STRATEGY_H
#define _STRATEGY_H

enum STATUS
{
	PREPARE,
	START,
	PAUSE,
	STOP,

	STATUS_NUM
};

enum PROP
{
	NONE = 0,

	//Defence
	SHELD = 1,
	IMMUNE = 2,
	CLEAR = 3,
	NC1 = 4, //NC

	//Attack
	BOMB = 5,
	DIZZY = 6,
	BOWLING = 7,
	MAGNET = 8,

	//Track
	SWAMP = 9,
	LANDMINE = 10, //A
	NC2 = 11, //NC
	VORTEX = 12, //B

	//Special
	PICK = 13, //E

	PROP_NUM
};

struct RECEIVE
{
	char ID : 2;
	char Status : 2;
	char WarningA : 1;
	char WarningB : 1;
	char WarningC : 1;
	char WarningD : 1;

	char If_track : 2; //enum Prop
	char Prop_num : 3;
	char Track_cond : 3;

	char PropI : 4;
	char PropII : 4;

	char PeopleA[2]; //{x,y}
	char PeopleB[2];
	char PeopleC[2];
	char PeopleD[2];
	char PropA[2];
	char PropB[2];
	char PropC[2];
	char PropD[2];

	char Source : 4; //May change
	char Target : 4; //May change

	char PropNow; //enum Prop
	char CheckD;
	char CheckA;
};

struct SEND
{
	char OurID;
	char TargetID;
	char PropID;
};

extern struct RECEIVE ReceiveAI;
extern struct SEND SendAI;
extern char ToBeSent[3];
void parseReceivedPack(char *ReceivePacket);
#endif