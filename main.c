/* Authors: Jordan Wells, Sicheng Zeng, Yuxuan Liu
 * Date 22 Oct 2015
 * Date last modified: 22 Oct 2015
 * Program: main.c
 */
#include<stdio.h>
#include "memoryCard.h"
#include "settings.h"
#include "inventory.h"
#include "characters.h"
#include "combat.h"
#include "parser.h"
int main(int argc, char** argv)
{
    int gameWon = 0;
    parser(gameWon);
    return 0;
}
