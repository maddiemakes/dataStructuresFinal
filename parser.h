/* Author: Jordan Wells
 * Date 28 Oct 2015
 * Date last modified: 28 Oct 2015
 * Program: parser.h
 */
#include<stdio.h>
#include<string.h>
#include "characters.h"
#include "rooms.h"

int dictionary(char* word, Character* player);

void parser(int gameWon, Character* player)
{
    char input [80];
    while(gameWon == 0)
    {
        printf(">>>");
        scanf(" %79[0-9a-zA-Z ]", input);
        
        switch (dictionary(input, player)) {
            default:        //input is not a valid command
                printf("I don't understand. Could you phrase that differently?\n");
                break;
            case -1:        //quit
                printf("Aw, sorry to see you go\n");
                gameWon = 1;
                break;
            case -2:        //who am I?
                printf("You are %s\n", player->name);
                break;
            case 0:         //no
                break; 
            case 1:         //yes
                break;
            case 2:         //greeting like "hi"
                printf("Ah yes hello there!\n");
                break;
            case 3:         //look around
                roomCheck(player);
                break;
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                advanceStage(player, dictionary(input, player));
                break;
        }
    }
};

int dictionary(char* word, Character* player)
{
    //each type of word or input is categorized with possible inputs
    char* greeting[] = {"hi","hey","hey there","hello"};
    char* look[] = {"look","look around"};
    char* struggle[] = {"struggle","flop","fight","break free","free itself","splash","evolve"};
    char* yes[] = {"yes","okay","yup","sure","alright","all right","mmk","ok","ya","yeah","yea","yah","yeet","of course"};
    char* statues[] = {"look at John Wayne", "look at Gunslinger", "look at Armstrong", "look at Juggernaut",
    "look at Ezio","look at Assassin","look at Edward","look at Alchemist","look at Link","look at Knight"};
    
    //checks to see if "input" is one of the phrases the computer knows
    
    if(!strcmp(word,"no")) { return 0; }
    if(!strcmp(word,"quit")) { return -1; }
    if(!strcmp(word,"who")||!strcmp(word,"who am I")||!strcmp(word,"who am i")) { return -2; }

    for(int k = 0; k<14;k++) {
        if(!strcmp(word,yes[k]))
        {
            return 1;
        }
    }
    
    for(int k = 0; k < 2;k++) {
        if(!strcmp(word,look[k])) {
            return 3;
        }
    }

    for(int k = 0; k < 4;k++) {
        if(!strcmp(word, greeting[k])) 
        {
            return 2;
        }
    }
    
    for(int k = 0; k < 7;k++) {
        if(!strcmp(word,struggle[k]))
        {
            return 4;
        }
    }
    
    if(!strcmp(word,"use switch")||!strcmp(word,"flip switch")){ return 5; }
    
    if(!strcmp(word,"look statues") || !strcmp(word,"look at statues")) { return 6; }
    if(!strcmp(word,"push button")) { return 8; }
    
    for(int k = 0; k<10;k++)
    {
        if(!strcmp(word,statues[k])) { return 7; }
    }
    
    return -3;
};