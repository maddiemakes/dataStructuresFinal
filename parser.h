/* Author: Madison Wells
 * Date 28 Oct 2015
 * Date last modified: 28 Oct 2015
 * Program: parser.h
 */
#include<stdio.h>
#include<string.h>
#include "characters.h"
#include "rooms.h"
#include "memoryCard.h"

//includes all possible user input
int dictionary(char* word, Character* player);

void parser(int gameWon, Character* player)
{
    char input [80];
    while(gameWon == 0)
    {
        printf(">>>");                      //user input styling
        scanf(" %79[0-9a-zA-Z ]", input);   //user input
        
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
            case -4:
                save(player);
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
            //these cases are all actions
            //the actions check to see if they are the correct action
            //to advance the story, based on where the player is
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
    if(!strcmp(word,"quit")) { return -1; }         //allows user to quit the game
    if(!strcmp(word,"who")||!strcmp(word,"who am I")||!strcmp(word,"who am i")) { return -2; }  //allows user to know who their character is
    if(!strcmp(word,"save")) {return -4;}

    //in order to get the program to check for all possible types of a category,
    //runs a for loop to cycle through them all and checks for ==
    for(int k = 0; k<14;k++) {
        if(!strcmp(word,yes[k]))
        {
            return 1;       // each one returns a different case value
        }
    }
    
    for(int k = 0; k < 2;k++) {
        if(!strcmp(word,look[k])) {
            return 3;       //diff types of "look"
        }
    }

    for(int k = 0; k < 4;k++) {
        if(!strcmp(word, greeting[k])) 
        {
            return 2;       //diff "hellos"
        }
    }
    
    for(int k = 0; k < 7;k++) {
        if(!strcmp(word,struggle[k]))
        {
            return 4;       //what would magikarp do?
        }
    }
    
    if(!strcmp(word,"use switch")||!strcmp(word,"flip switch")){ return 5; } //use the switch Luke
    
    if(!strcmp(word,"look statues") || !strcmp(word,"look at statues")) { return 6; }   // oh those look cool
    if(!strcmp(word,"push button")) { return 8; }   // I wonder what this does
    
    for(int k = 0; k<10;k++)
    {
        if(!strcmp(word,statues[k])) { return 7; }  //let's look closer at the statues
    }
    
    return -3;  //default return value for no match
};
