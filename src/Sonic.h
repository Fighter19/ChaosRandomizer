#pragma once
#include <stdint.h>
#include <windows.h>

#define PACK( __Declaration__ ) __pragma( pack(push, 1) ) __Declaration__ __pragma( pack(pop) )

class cRoot;

enum SA2BChaoGarden : char
{
	CHAO = 1,
	DARK = 3,
	HERO = 2
};

enum SA2BAnimalFlags
{
	NONE = 0,
	SEAL = 1,
	PENGUIN = 1 << 1,
	OTTER = 1 << 2,
	PEACOCK = 1 << 3,
	SWALLOW = 1 << 4,
	PARROT = 1 << 5,
	DEER = 1 << 6,
	RABBIT = 1 << 7,
	KANGAROO = 1 << 8,
	GORILLA = 1 << 9,
	LION = 1 << 10,
	ELEPHANT = 1 << 11,
	MOLE = 1 << 12,
	KOALA = 1 << 13,
	SKUNK = 1 << 14

};

namespace SA2BColour {
	enum Type {
		NORMAL,
		YELLOW,
		WHITE,
		BROWN,
		SKYBLUE,
		PINK,
		BLUE,
		GREY,
		GREEN,
		RED,
		LIMEGREEN,
		PURPLE,
		ORANGE,
		BLACK,
		POWDERBLUE = 21,
		DEEPDARKBLUE = 82,
		DARKERGREY = 30,
		INDIANRED = 133,
		LIGHTCORAL = 140,
		SALMON = 177,
		DARKSALMON = 237,
		CRIMSON = 157,
		PINKTRANS = 203,
		LIGHTPINK = 217,
		HOTPINK = 151,
		MEDIUMVIOLETRED = 211,
		PALEVIOLETRED = 187,
		LIGHTVIOLETRED = 213,
		VIOLETRED = 226,
		PALEGOLDENROD = 193,
		THISTLE = 247,
		PLUM = 171,
		VIOLET = 202,
		ORCHID = 238,
		MAGENTA = 248,
		MEDIUMORCHID = 176,
		MEDIUMPURPLE = 165,
		BLUEVIOLET = 196,
		DARKVIOLET = 191,
		DARKMAGENTA = 229,
		PURPLETRANS = 17,
		DARKPURPLE = 145,
		DARKSLATEBLUE = 153,
		SLATEBLUE = 146,
		GREENYELLOW = 224,
		LAWNGREEN = 215,
		PALELIMEGREEN = 220,
		LIMEGREENTRANS = 239,
		LIGHTPALEGREEN = 189,
		PALEGREEN = 205,
		LIGHTGREEN = 147,
		PALESPRINGGREEN = 250,
		LIGHTSPRINGGREEN = 253,
		SPRINGGREEN = 139,
		MEDIUMSEAGREEN = 163,
		DARKSEAGREEN = 207,
		PALETURQUOISE = 143,
		PALEAQUAMARINE = 241,
		LIGHTAQUAMARINE = 181,
		AQUAMARINE = 175,
		TURQUOISE = 212,
		MEDIUMTURQUOISE = 199,
		STEELBLUE = 235,
		POWDERBLUETRANS = 120,
		CORNFLOWERBLUE = 236,
		NAVYBLUE = 251,
		WHEAT = 152,
		BURLYWOOD = 155,
		TAN = 149,
		ROSYBROWN = 214,
		MEDIUMGOLDENROD = 131,
		GOLDENROD = 190,
		DARKGOLDENROD = 232,
		PERU = 244,
		DARKGREY = 217
	};

	static const Type All[] = {
		NORMAL,
		YELLOW,
		WHITE,
		BROWN,
		SKYBLUE,
		PINK,
		BLUE,
		GREY,
		GREEN,
		RED,
		LIMEGREEN,
		PURPLE,
		ORANGE,
		BLACK,
		POWDERBLUE,
		DEEPDARKBLUE,
		DARKERGREY,
		INDIANRED,
		LIGHTCORAL,
		SALMON,
		DARKSALMON,
		CRIMSON,
		PINKTRANS,
		LIGHTPINK,
		HOTPINK,
		MEDIUMVIOLETRED,
		PALEVIOLETRED,
		LIGHTVIOLETRED,
		VIOLETRED,
		PALEGOLDENROD,
		THISTLE,
		PLUM,
		VIOLET,
		ORCHID,
		MAGENTA,
		MEDIUMORCHID,
		MEDIUMPURPLE,
		BLUEVIOLET,
		DARKVIOLET,
		DARKMAGENTA,
		PURPLETRANS,
		DARKPURPLE,
		DARKSLATEBLUE,
		SLATEBLUE,
		GREENYELLOW,
		LAWNGREEN,
		PALELIMEGREEN,
		LIMEGREENTRANS,
		LIGHTPALEGREEN,
		PALEGREEN,
		LIGHTGREEN,
		PALESPRINGGREEN,
		LIGHTSPRINGGREEN,
		SPRINGGREEN,
		MEDIUMSEAGREEN,
		DARKSEAGREEN,
		PALETURQUOISE,
		PALEAQUAMARINE,
		LIGHTAQUAMARINE,
		AQUAMARINE,
		TURQUOISE,
		MEDIUMTURQUOISE,
		STEELBLUE,
		POWDERBLUETRANS,
		CORNFLOWERBLUE,
		NAVYBLUE,
		WHEAT,
		BURLYWOOD,
		TAN,
		ROSYBROWN,
		MEDIUMGOLDENROD,
		GOLDENROD,
		DARKGOLDENROD,
		PERU,
		DARKGREY

	};
}

enum ClassroomLessonFlags
{

};

enum ToyFlags
{

};

enum SA2BSonicState
{
	IDLE = 0,
	WALK = 1,
	HOLD = 21,
	PUTDOWN = 20
};

SA2BSonicState GetSonicState();

enum SA2BBodyType
{
	NORMALCHAO,
	EGGCHAO,
	OMOCHAO,
	ANIMAL,
	NO_BODY = 5
};

PACK(
union Chao
{
	struct
	{
		char pad1[0x12]; // 0x00 - 0x11

		char name[7]; // 0x12

					  //char pad2[0x68]; // 0x13 -
		char pad2[0x67];
		int8_t type;


		SA2BChaoGarden garden;
		int8_t happiness;

		char pad3[0x07];

		short lifespan1;
		short lifespan2;
		short reincarnations;

		bool reset;



		/*
		SA2BAnimalFlags animalBehaviours;
		ClassroomLessonFlags classRoomSkills;
		ToyFlags toys;
		*/
		short animalBehaviours; //0x118
		int classRoomSkills; // 0x160
		short toys; // 0x164
	};
	char buffer[0x800];

});