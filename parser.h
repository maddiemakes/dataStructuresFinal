/* Author: Jordan Wells
 * Date 28 Oct 2015
 * Date last modified: 28 Oct 2015
 * Program: parser.h
 */
#include<stdio.h>
#include<string.h>
void parser(int gameWon)
{
    char words [80];
    while(gameWon == 0)
    {
        printf(">>>");
        scanf(" %79[0-9a-zA-Z ]", words);
        if(!strcmp(words,"hi"))
        {
            printf("hey\n");
        }
        if(!strcmp(words,"hi there"))
        {
            printf("heyoo\n");
        }
        if(!strcmp(words,"look") || !strcmp(words,"look around"))
        {
            printf("You're in a room. There is a package on the floor.\n");
        }
        if(!strcmp(words,"pickup") || !strcmp(words,"pick up"))
        {
            printf("You pick up the package.\n");
        }
    }
};
