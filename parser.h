/* Author: Jordan Wells
 * Date 28 Oct 2015
 * Date last modified: 28 Oct 2015
 * Program: parser.c
 */
#include<stdio.h>
void parser(int gameWon)
{
    char *words [80];
    while(gameWon == 0)
    {
        printf(">>>");
        scanf("%79s", &words);
        printf("words: %s\n", words);
        if(words == "hi")
        {
            printf("hey");
        }
    }

};
