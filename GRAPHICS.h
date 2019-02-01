#pragma once
#include <string>
#include "CONSTANTS.h"
using namespace std;

const string GRASS = "^^^^^^^^^^^^^^^^^^^";

const string base[BASE_LINES] = {	"   /^^^^^^^^^^^\\   ",
									"  /^^^^^^^^^^^^^\\  ",
									" /^^^^^^^^^^^^^^^\\ "};

const string shown[LINES] = {	"      /\\___/\\      ",//podwójne slashe
								"     / * . * \\     ",
								"    (   v v   )    ",
								"     )       (     " };

const string hidden[LINES] = {  "                   ",
								"                   ",
								"                   ",
								"                   " };

const string dead[LINES] = {	"     * * * * *     ",
								"      /\\___/\\      ",
								"     / X . X \\     ",
								"    (    O    )    " };

const string miss[LINES] = {	"             _   _ ",
								"   /\\ /\\  | /   /  ",
								"  /  V  \\ | \\   \\  ",
								" /       \\|_/  _/  " };

