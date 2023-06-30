#include <stdio.h>
#include <unistd.h>

#define height 20
#define width 10

// Make a general struct for template 
// Make a "create" function for each shape that returns the template struct \
// With the dimensions for that shape.

typedef struct {
    // 4x4 Grid
    // A B C D
    int Atop;
    int Abot;
    int Btop;
    int Bbot;
    int Ctop;
    int Cbot;
    int Dtop;
    int Dbot;
}Shape; 

Shape *createLShape(Shape *template)
{   // 3x3 Grid
    // A B C
    // 0 ■ 0
    // 0 ■ 0
    // 0 ■ ■
    template->Btop = 0;
    template->Bbot = 3;
    template->Ctop = 2;
    template->Cbot = 3;

    return template;
}

void printBoard(char *PlayGround[height][width]) 
{
    printf("---------------------\n");
    for (int i=0; i<20; ++i) {
        printf("|");
        for (int j=0; j<10; ++j) {
            printf("%s|", PlayGround[i][j]);
        }
        printf("\n");
    }
}

void moveShape(char *PlayGround[height][width], Shape *template, int startPos)
{
    for (int i=template->Atop; i<template->Abot; ++i) {
        PlayGround[i][startPos] = "■";
    }

    for (int i=template->Btop; i<template->Bbot; ++i) {
        PlayGround[i][startPos+1] = "■";
    }

    for (int i=template->Ctop; i<template->Cbot; ++i) {
        PlayGround[i][startPos+2] = "■";
    }
    
    if (template->Abot != 0)
        template->Atop++, template->Abot++;
        
    if (template->Bbot != 0)
        template->Btop++, template->Bbot++;

    if (template->Cbot != 0)
        template->Ctop++, template->Cbot++;
}

void clearShape(char *PlayGround[height][width], Shape *template, int startPos)
{
    if (template->Atop != 0)
        PlayGround[template->Atop-2][startPos] = " ";

    if (template->Btop != 0) 
        PlayGround[template->Btop-2][startPos+1] = " ";

    if (template->Ctop != 0)
        PlayGround[template->Ctop-2][startPos+2] = " ";

    // for (int i=template->Atop; i<template->Abot; ++i) {
    //     PlayGround[i][startPos] = " ";
    // }

    // for (int i=template->Btop; i<template->Bbot; ++i) {
    //     PlayGround[i][startPos+1] = " ";
    // }

    // for (int i=template->Ctop; i<template->Cbot; ++i) {
    //     PlayGround[i][startPos+2] = " ";
    // }
}

int main () 
{
    char *PlayGround[height][width]; 

    // Initialize empty board
    for (int i=0; i<20; ++i) {
        for (int j=0; j<10; ++j) {
            PlayGround[i][j] = " ";
        }
    }

    // Print empty board
    printBoard(PlayGround);
    // TODO: Make this process random {
    Shape template = {0};
    createLShape(&template);
    // }

    while(1) {
        sleep(1);
        moveShape(PlayGround, &template, 5);
        clearShape(PlayGround, &template, 5);
        printBoard(PlayGround);
    }

    return 0;
}


