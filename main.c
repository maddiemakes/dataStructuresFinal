/* Authors: Jordan Wells, Sicheng Zeng, Yuxuan Liu
 * Date 22 Oct 2015
 * Date last modified: 22 Oct 2015
 * Program: main.c
 */
#include<stdio.h>
// #include "memoryCard.h"
#include "settings.h"
#include "inventory.h"
#include "characters.h"
#include "combat.h"
#include "parser.h"


int main(int argc, char** argv)
{
    int gameWon = 0;
    char input [80];
    
    Character* player = makeCharacter();
    
    printf("Ah, yes, hello there adventurer. I apologize but I seem to have forgotten your name.\n");
    printf("What was your name again?\n");
    while(1)
    {
        printf(">>>");
        scanf(" %79[0-9a-zA-Z ]", input);
        if(dictionary(input,player) == 0)
        {
            printf("How rude! Hmph. You know I don't have to take you on a journey.\n");
            printf("I'll give you another chance. What is your name?\n");
        }
        else if(dictionary(input,player) != -3)
        {
            printf("No silly, that can't be your name! Try again.\n");
        }
        else {
            break;
        }
    }
    player->name = input;
    printf("Ah yes, that's right! You're %s! How could I forget?\n", player->name);
    printf("Now, %s, why don't you have a look around?\n", player->name);
    
    parser(gameWon, player);
    
    return 0;
}
