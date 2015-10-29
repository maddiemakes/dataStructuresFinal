//contains all the rooms in the game

#include<stdio.h>

//rooms need to know/have:
//  an id           - how we can reference it
//
//  text            - what the room says when you arrive
//                  - what is said when you "look around"
//
//  object list     - what is in the room
//                  - (what objects can be interacted with?)
//
//  exit list       - what exits are there to other rooms
//                  - links to those rooms (so player can leave)
//                  - reference links (for code reference)
//                  - how is the room exited to those
//void rooms()
//{
    // switch () {
    //     case 1:
    //         printf("it is dark.\n");
    //         break;
    //     default:
    //         printf("default\n");
    //         break;
    // }
//};
void roomCheck(Character* player)
{
    switch (player->room) {
        default:
            break;
        case 1:
            switch (player->stage) {
                case 1:
                    printf("The room around you is dark and you can’t see anything. You notice you are sitting in a chair with your hands tied to the back of it.\n");
                    printf("You can feel that the rope is tied loosely. You think to yourself, what would magicarp do?\n");
                    break;
                case 2:
                    printf("The room is dark and you can't see anything. Feeling around the wall, you notice a light switch nearby.\n");
                    break;
                case 3:
                    printf("You are in a circular room with wooden floors and stone walls.\n");
                    printf("There is the chair that you were sitting in, and behind it, five STATUES, each holding a weapon.\n");
                    break;
            }
        case 2:
            break;
    }
};

int advanceStage(Character* player, int input) {
    switch (player->room) {
        case 1:
            switch(player->stage) {
                case 1:
                    if(input == 4)
                    {
                        player->stage++;
                        printf("The bonds break with the lightest tug, and you’re free to stand up. It’s dark, and you can’t see anything.\n");
                        printf("As soon as you stand up your hands brush against a wall and you feel a switch.\n");
                        break;
                    }
                case 2:
                    if(input == 5)
                    {
                        player->stage++;
                        printf("Dim yellow lights flicker on and illuminate the room.\n");
                        roomCheck(player);
                        break;
                    }
                case 3:
                    if (input==6) 
                    {
                        printf("You take a closer look at the statues and notice they have inscriptions under each.\n");
                        printf("From left to right, the statues are labeled as:\n'John Wayne the Gunslinger'\n");
                        printf("'Armstrong the Juggernaut'\n'Ezio the Assassin'\n'Edward the Alchemist' and \n'Link the Knight.'\n");
                        printf("You can't help but wonder who these individuals are.\n");
                        break;
                    }
                    if (input == 7)
                    {
                        printf("You look closer at the statue and notice a small round button protruding from the side.\n");
                        break;
                    }
                    if (input == 8)
                    {
                        player->stage++;
                        printf("You press the button and...\n");
                        break;
                    }
                printf("That won't work here. Try again.\n");
            }
            break;
    }
}
