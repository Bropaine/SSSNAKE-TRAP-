// Basic Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Written by Jared Hall June 6th 2022 
//#pragma comment(lib, "Winmm.lib")
//#include <mmsystem.h>
#include "pch.h"
#include <iostream>
#include <chrono>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include "color.h"


using namespace std;

HANDLE wHnd;    // Handle to write to the console.
HANDLE rHnd;    // Handle to read from the console
ofstream highScoreFileof;
ifstream highScoreFileif;
bool gameOver;
 int width = 50;
int height = 25;
int x, y, fruitX, fruitY, score, fruit2X, fruit2Y, fruit3X, fruit3Y;
int snakeSpeedLR = 315;
int snakeSpeedUD = 615;
int levelCount = 1;
int tailX[100], tailY[100];
int nTail;
int highScore = 0;





enum eDirection { STOP = 0, LEFT, Right, UP, Down};
eDirection dir;


void Setup()
{
   
    //open high score file andstore the value in the high Score variable
   
    highScoreFileif.open("highScoreFile.txt");
    highScoreFileif >> highScore;
    highScoreFileif.close();

    //starts the game loop and sets up the direction logic to stop. randomly places fruit and initializes the score
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    fruit2X = rand() % width;
    fruit2Y = rand() % height;
    fruit3X = rand() % width;
    fruit3Y = rand() % height;
    score = 0;
    //Plays background music.
    PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//BackgroundLoop.wav"), NULL, SND_NOSTOP | SND_LOOP | SND_ASYNC);
    
}

void Draw()
{
    
    system("cls");  
  //  system("clear");
    for (int i = 0; i < width+2; i++)
        cout  << hue::grey << "#";
        cout << endl;
        //draw snake head and boundries

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout  << hue::grey << "#";
            
            if (i == y && j == x)
           
                cout   << hue::green << "O";
        
            //draw fruit
            else if (i == fruitY && j == fruitX)
                cout  << hue::yellow << "F";
            else if (i == fruit2Y && j == fruit2X)
                cout  << hue::purple << "F";
            else if (i == fruit3Y && j == fruit3X)
                cout << hue::light_red << "F";

            else 
            {
                bool print = false;

                for (int k = 0; k < nTail; k++)
                {
                    //obsolete bug fix from previous build
                    
                   // if (tailX[k] == j && tailY[k] == i && dir == LEFT)
                   // {
                     //   cout << "o";
                        
                    //    print = true;
                   // }
                   /* else */ if (tailX[k] == j && tailY[k] == i)
                    {

                        cout  << hue::green << "o";
                        
                        print = true;

                    }
                   
                }
           
                if (!print)
                    cout << " ";
                                              
            }
       
            if (j == width - 1)
                cout  << hue::grey << "#";
        }
        
        cout << endl;
      
    }

    for (int i = 0; i < width+2; i++)
        cout  << hue::grey << "#";
    cout << endl;
    
  //high score adds up in real time as long as score exceeds previous high score.  
      if (score > highScore)
      if (score > highScore)
    
         highScore = score;
  
    
// Output
    cout << "SSSNAKE TRAP!" << endl;
    cout << endl;
    cout << "HighScore " << highScore << endl;
    cout << "Score: " << score << endl;
    cout << endl;
    
    cout << "Level: " << levelCount << endl;
    
    cout << endl;
    cout << endl;
    cout << "Use 'W A S D' to control the Snake.";
    cout << endl;
    cout << "Press 'x' to quit game." << endl;
        
}


void Input()
{//key inputs
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = Right;
            
            break;
        case 'w':
            dir = UP;
            
            break;
        case 's':
            dir = Down;
            
            break;
        case 'x':
            gameOver = true;
            break;            
        }
    }
}
void Logic()
{
   
    
    //tail section stacking logic
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X = 0, prev2Y = 0;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {

        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }                            

    //movement logic needs to be cleaned up into functions to reduce duplicate code
    
    switch (dir)
    {
        
    case LEFT:
      
      
            x--;
            //this increases the snakes speed with the score.

            if (score == 0)
                Sleep(snakeSpeedLR);
            else if (score == 10)
                Sleep(snakeSpeedLR);
            else if (score == 20)
                Sleep(snakeSpeedLR);
            else if (score == 30)
                Sleep(snakeSpeedLR);
            else if (score == 40)
                Sleep(snakeSpeedLR);
            else if (score == 50)
                Sleep(snakeSpeedLR);
            else if (score == 60)
                Sleep(snakeSpeedLR);
            else if (score == 70)
                Sleep(snakeSpeedLR);
            else if (score == 80)
                Sleep(snakeSpeedLR);
            else if (score == 90)
                Sleep(snakeSpeedLR);
            else if (score == 100)
                Sleep(snakeSpeedLR);
            else if (score == 110)
                Sleep(snakeSpeedLR);
            else if (score == 120)
                Sleep(snakeSpeedLR);
            else if (score == 130)
                Sleep(snakeSpeedLR);
            else if (score == 140)
                Sleep(snakeSpeedLR);
            else if (score == 150)
                Sleep(snakeSpeedLR);
            else if (score == 160)
                Sleep(snakeSpeedLR);
            else if (score == 170)
                Sleep(snakeSpeedLR);
            else if (score == 180)
                Sleep(snakeSpeedLR);
            else if (score > 180)
                Sleep(25);
            //throttles snakes speed at the beginning of each new level
            if (levelCount == 2 && score >= 210)
            {

                if (score == 210)
                    Sleep(snakeSpeedUD);
                else if (score == 220)
                    Sleep(snakeSpeedUD);
                else if (score == 230)
                    Sleep(snakeSpeedUD);
                else if (score == 240)
                    Sleep(snakeSpeedUD);
                else if (score == 250)
                    Sleep(snakeSpeedUD);
                else if (score == 260)
                    Sleep(snakeSpeedUD);
                else if (score == 270)
                    Sleep(snakeSpeedUD);
                else if (score == 280)
                    Sleep(snakeSpeedUD);
                else if (score > 280 && score >= 310)
                    Sleep(100);


            }
            else if (levelCount == 3 && score >= 310)
            {

                if (score == 310)
                    Sleep(snakeSpeedUD);
                else if (score == 320)
                    Sleep(snakeSpeedUD);
                else if (score == 330)
                    Sleep(snakeSpeedUD);
                else if (score == 340)
                    Sleep(snakeSpeedUD);
                else if (score == 350)
                    Sleep(snakeSpeedUD);
                else if (score == 360)
                    Sleep(snakeSpeedUD);
                else if (score == 370)
                    Sleep(snakeSpeedUD);
                else if (score == 380)
                    Sleep(snakeSpeedUD);
                else if (score > 380 && score >= 410)
                    Sleep(100);
            }
            else if (levelCount == 4 && score >= 410)
            {

                if (score == 410)
                    Sleep(snakeSpeedUD);
                else if (score == 420)
                    Sleep(snakeSpeedUD);
                else if (score == 430)
                    Sleep(snakeSpeedUD);
                else if (score == 440)
                    Sleep(snakeSpeedUD);
                else if (score == 450)
                    Sleep(snakeSpeedUD);
                else if (score == 460)
                    Sleep(snakeSpeedUD);
                else if (score == 470)
                    Sleep(snakeSpeedUD);
                else if (score == 480)
                    Sleep(snakeSpeedUD);
                else if (score > 480 && score >= 510)
                    Sleep(100);
            }
            else if (levelCount == 5 && score >= 510)
            {

                if (score == 510)
                    Sleep(snakeSpeedUD);
                else if (score == 520)
                    Sleep(snakeSpeedUD);
                else if (score == 530)
                    Sleep(snakeSpeedUD);
                else if (score == 540)
                    Sleep(snakeSpeedUD);
                else if (score == 550)
                    Sleep(snakeSpeedUD);
                else if (score == 560)
                    Sleep(snakeSpeedUD);
                else if (score == 570)
                    Sleep(snakeSpeedUD);
                else if (score == 580)
                    Sleep(snakeSpeedUD);
                else if (score > 580 && score >= 610)
                    Sleep(100);
            }

        
           


        break;

        
    case Right:
        x++;
        
        if (score == 0)
            Sleep(snakeSpeedLR);
        else if (score == 10)
            Sleep(snakeSpeedLR);
        else if (score == 20)
            Sleep(snakeSpeedLR);
        else if (score == 30)
            Sleep(snakeSpeedLR);
        else if (score == 40)
            Sleep(snakeSpeedLR);
        else if (score == 50)
            Sleep(snakeSpeedLR);
        else if (score == 60)
            Sleep(snakeSpeedLR);
        else if (score == 70)
            Sleep(snakeSpeedLR);
        else if (score == 80)
            Sleep(snakeSpeedLR);
        else if (score == 90)
            Sleep(snakeSpeedLR);
        else if (score == 100)
            Sleep(snakeSpeedLR);
        else if (score == 110)
            Sleep(snakeSpeedLR);
        else if (score == 120)
            Sleep(snakeSpeedLR);
        else if (score == 130)
            Sleep(snakeSpeedLR);
        else if (score == 140)
            Sleep(snakeSpeedLR);
        else if (score == 150)
            Sleep(snakeSpeedLR);
        else if (score == 160)
            Sleep(snakeSpeedLR);
        else if (score == 170)
            Sleep(snakeSpeedLR);
        else if (score == 180)
            Sleep(snakeSpeedLR);
       
        else if (score > 180)
            Sleep(25);

        //throttles snakes speed at the beginning of each new level
        if (levelCount == 2 && score >= 210)
        {

            if (score == 210)
                Sleep(snakeSpeedUD);
            else if (score == 220)
                Sleep(snakeSpeedUD);
            else if (score == 230)
                Sleep(snakeSpeedUD);
            else if (score == 240)
                Sleep(snakeSpeedUD);
            else if (score == 250)
                Sleep(snakeSpeedUD);
            else if (score == 260)
                Sleep(snakeSpeedUD);
            else if (score == 270)
                Sleep(snakeSpeedUD);
            else if (score == 280)
                Sleep(snakeSpeedUD);
            else if (score > 280 && score <= 310)
                Sleep(100);

        }
        else if (levelCount == 3 && score >= 310)
        {

            if (score == 310)
                Sleep(snakeSpeedUD);
            else if (score == 320)
                Sleep(snakeSpeedUD);
            else if (score == 330)
                Sleep(snakeSpeedUD);
            else if (score == 340)
                Sleep(snakeSpeedUD);
            else if (score == 350)
                Sleep(snakeSpeedUD);
            else if (score == 360)
                Sleep(snakeSpeedUD);
            else if (score == 370)
                Sleep(snakeSpeedUD);
            else if (score == 380)
                Sleep(snakeSpeedUD);
            else if (score > 380 && score >= 410)
                Sleep(100);
        }
        else if (levelCount == 4 && score >= 410)
        {

            if (score == 410)
                Sleep(snakeSpeedUD);
            else if (score == 420)
                Sleep(snakeSpeedUD);
            else if (score == 430)
                Sleep(snakeSpeedUD);
            else if (score == 440)
                Sleep(snakeSpeedUD);
            else if (score == 450)
                Sleep(snakeSpeedUD);
            else if (score == 460)
                Sleep(snakeSpeedUD);
            else if (score == 470)
                Sleep(snakeSpeedUD);
            else if (score == 480)
                Sleep(snakeSpeedUD);
            else if (score > 480 && score >= 510)
                Sleep(100);
        }
        else if (levelCount == 5 && score >= 510)
        {

            if (score == 510)
                Sleep(snakeSpeedUD);
            else if (score == 520)
                Sleep(snakeSpeedUD);
            else if (score == 530)
                Sleep(snakeSpeedUD);
            else if (score == 540)
                Sleep(snakeSpeedUD);
            else if (score == 550)
                Sleep(snakeSpeedUD);
            else if (score == 560)
                Sleep(snakeSpeedUD);
            else if (score == 570)
                Sleep(snakeSpeedUD);
            else if (score == 580)
                Sleep(snakeSpeedUD);
            else if (score > 580)
                Sleep(100);
        }


         

    


        
       
        break;
    case UP:
        y--;
        if (score == 0)
            Sleep(snakeSpeedUD);
        else if (score == 10)
            Sleep(snakeSpeedUD);
        else if (score == 20)
            Sleep(snakeSpeedUD);
        else if (score == 30)
            Sleep(snakeSpeedUD);
        else if (score == 40)
            Sleep(snakeSpeedUD);
        else if (score == 50)
            Sleep(snakeSpeedUD);
        else if (score == 60)
            Sleep(snakeSpeedUD);
        else if (score == 70)
            Sleep(snakeSpeedUD);
        else if (score == 80)
            Sleep(snakeSpeedUD);
        else if (score == 90)
            Sleep(snakeSpeedUD);
        else if (score == 100)
            Sleep(snakeSpeedUD);
        else if (score == 110)
            Sleep(snakeSpeedUD);
        else if (score == 120)
            Sleep(snakeSpeedUD);
        else if (score == 130)
            Sleep(snakeSpeedUD);
        else if (score == 140)
            Sleep(snakeSpeedUD);
        else if (score == 150)
            Sleep(snakeSpeedUD);
        else if (score == 160)
            Sleep(snakeSpeedUD);
        else if (score == 170)
            Sleep(snakeSpeedUD);
        else if (score == 180)
            Sleep(snakeSpeedUD);
        else if (score > 180)
            Sleep(25);

        //throttles snakes speed at the beginning of each new level
        if (levelCount == 2 && score >= 210)
        {

            if (score == 210)
                Sleep(snakeSpeedUD);
            else if (score == 220)
                Sleep(snakeSpeedUD);
            else if (score == 230)
                Sleep(snakeSpeedUD);
            else if (score == 240)
                Sleep(snakeSpeedUD);
            else if (score == 250)
                Sleep(snakeSpeedUD);
            else if (score == 260)
                Sleep(snakeSpeedUD);
            else if (score == 270)
                Sleep(snakeSpeedUD);
            else if (score == 280)
                Sleep(snakeSpeedUD);
            else if (score > 280 && score >= 310)
                Sleep(100);


        }
        else if (levelCount == 3 && score >= 310)
        {

            if (score == 310)
                Sleep(snakeSpeedUD);
            else if (score == 320)
                Sleep(snakeSpeedUD);
            else if (score == 330)
                Sleep(snakeSpeedUD);
            else if (score == 340)
                Sleep(snakeSpeedUD);
            else if (score == 350)
                Sleep(snakeSpeedUD);
            else if (score == 360)
                Sleep(snakeSpeedUD);
            else if (score == 370)
                Sleep(snakeSpeedUD);
            else if (score == 380)
                Sleep(snakeSpeedUD);
            else if (score > 380 && score >= 410)
                Sleep(100);
        }
        else if (levelCount == 4 && score >= 410)
        {

            if (score == 410)
                Sleep(snakeSpeedUD);
            else if (score == 420)
                Sleep(snakeSpeedUD);
            else if (score == 430)
                Sleep(snakeSpeedUD);
            else if (score == 440)
                Sleep(snakeSpeedUD);
            else if (score == 450)
                Sleep(snakeSpeedUD);
            else if (score == 460)
                Sleep(snakeSpeedUD);
            else if (score == 470)
                Sleep(snakeSpeedUD);
            else if (score == 480)
                Sleep(snakeSpeedUD);
            else if (score > 480 && score >= 510)
                Sleep(100);
        }
        else if (levelCount == 5 && score >= 510)
        {

            if (score == 510)
                Sleep(snakeSpeedUD);
            else if (score == 520)
                Sleep(snakeSpeedUD);
            else if (score == 530)
                Sleep(snakeSpeedUD);
            else if (score == 540)
                Sleep(snakeSpeedUD);
            else if (score == 550)
                Sleep(snakeSpeedUD);
            else if (score == 560)
                Sleep(snakeSpeedUD);
            else if (score == 570)
                Sleep(snakeSpeedUD);
            else if (score == 580)
                Sleep(snakeSpeedUD);
            else if (score > 580 && score >= 610)
                Sleep(100);
        }



      
        

        break;
    case Down:
        y++;
        if (score == 0)
            Sleep(snakeSpeedUD);
        else if (score == 10)
            Sleep(snakeSpeedUD);
        else if (score == 20)
            Sleep(snakeSpeedUD);
        else if (score == 30)
            Sleep(snakeSpeedUD);
        else if (score == 40)
            Sleep(snakeSpeedUD);
        else if (score == 50)
            Sleep(snakeSpeedUD);
        else if (score == 60)
            Sleep(snakeSpeedUD);
        else if (score == 70)
            Sleep(snakeSpeedUD);
        else if (score == 80)
            Sleep(snakeSpeedUD);
        else if (score == 90)
            Sleep(snakeSpeedUD);
        else if (score == 100)
            Sleep(snakeSpeedUD);
        else if (score == 110)
            Sleep(snakeSpeedUD);
        else if (score == 120)
            Sleep(snakeSpeedUD);
        else if (score == 130)
            Sleep(snakeSpeedUD);
        else if (score == 140)
            Sleep(snakeSpeedUD);
        else if (score == 150)
            Sleep(snakeSpeedUD);
        else if (score == 160)
            Sleep(snakeSpeedUD);
        else if (score == 170)
            Sleep(snakeSpeedUD);
        else if (score == 180)
            Sleep(snakeSpeedUD);
        else if (score > 180 && score < 210)
            Sleep(25);

        //throttles snakes speed at the beginning of each new level
        if (levelCount == 2 && score >= 210)
        {
            
            if (score == 210)
                Sleep(snakeSpeedUD);
            else if (score == 220)
                Sleep(snakeSpeedUD);
            else if (score == 230)
                Sleep(snakeSpeedUD);
            else if (score == 240)
                Sleep(snakeSpeedUD);
            else if (score == 250)
                Sleep(snakeSpeedUD);
            else if (score == 260)
                Sleep(snakeSpeedUD);
            else if (score == 270)
                Sleep(snakeSpeedUD);
            else if (score == 280)
                Sleep(snakeSpeedUD);
            else if (score > 280 && score >= 310)
                Sleep(100);
        }
        else if (levelCount == 3 && score >= 310)
        {

            if (score == 310)
                Sleep(snakeSpeedUD);
            else if (score == 320)
                Sleep(snakeSpeedUD);
            else if (score == 330)
                Sleep(snakeSpeedUD);
            else if (score == 340)
                Sleep(snakeSpeedUD);
            else if (score == 350)
                Sleep(snakeSpeedUD);
            else if (score == 360)
                Sleep(snakeSpeedUD);
            else if (score == 370)
                Sleep(snakeSpeedUD);
            else if (score == 380)
                Sleep(snakeSpeedUD);
            else if (score > 380 && score >= 410)
                Sleep(100);
        }
        else if (levelCount == 4 && score >= 410)
        {

            if (score == 410)
                Sleep(snakeSpeedUD);
            else if (score == 420)
                Sleep(snakeSpeedUD);
            else if (score == 430)
                Sleep(snakeSpeedUD);
            else if (score == 440)
                Sleep(snakeSpeedUD);
            else if (score == 450)
                Sleep(snakeSpeedUD);
            else if (score == 460)
                Sleep(snakeSpeedUD);
            else if (score == 470)
                Sleep(snakeSpeedUD);
            else if (score == 480)
                Sleep(snakeSpeedUD);
            else if (score > 480 && score >= 510)
                Sleep(100);
        }
        else if (levelCount == 5 && score >= 510)
        {

            if (score == 510)
                Sleep(snakeSpeedUD);
            else if (score == 520)
                Sleep(snakeSpeedUD);
            else if (score == 530)
                Sleep(snakeSpeedUD);
            else if (score == 540)
                Sleep(snakeSpeedUD);
            else if (score == 550)
                Sleep(snakeSpeedUD);
            else if (score == 560)
                Sleep(snakeSpeedUD);
            else if (score == 570)
                Sleep(snakeSpeedUD);
            else if (score == 580)
                Sleep(snakeSpeedUD);
            else if (score > 580 && score >= 610)
                Sleep(100);
        }
           
    
           

        

        break;

    default:

        break;
    }
   
    //Each level is marked by a reduced boundry size level increases if score is 
    if (score == 200 || score == 300 || score == 400 || score == 500)
    {
        //level transition sound pauses game process while playing to allow users to prepare for next level
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//NextLevel.wav"), NULL, SND_NODEFAULT | SND_FILENAME);
        //Plays background music.
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//BackgroundLoop.wav"), NULL, SND_NOSTOP | SND_LOOP | SND_ASYNC);

        width = width - 5;
        height = height - 5;
        score += 10;
        levelCount++;
       
        

    }
    // logic if snake head lands on fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        snakeSpeedLR -= 15;
        snakeSpeedUD -= 15;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
       //plays sound when fruit is eaten
       PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//EatFruit.wav"), NULL, SND_NODEFAULT | SND_FILENAME);
       //Plays background music.
       PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//BackgroundLoop.wav"), NULL, SND_NOSTOP | SND_LOOP | SND_ASYNC);
    }
    else if (x == fruit2X && y == fruit2Y)
    {
        score += 10;
        //increases the speed of snake
        snakeSpeedLR -= 15;
        snakeSpeedUD -= 15;
        //randomly replaces the eaten fruit
        fruit2X = rand() % width;
        fruit2Y = rand() % height;
        // adds a tail segment
        nTail++;
        //plays sound when fruit is eaten
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//EatFruit.wav"), NULL,  SND_NODEFAULT | SND_FILENAME);
        //Plays background music.
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//BackgroundLoop.wav"), NULL, SND_NOSTOP | SND_LOOP | SND_ASYNC);
    }
    else if (x == fruit3X && y == fruit3Y)
    {
        score += 10;
        snakeSpeedLR -= 15;
        snakeSpeedUD -= 15;
        fruit3X = rand() % width;
        fruit3Y = rand() % height;
        nTail++;
        //plays sound when fruit is eaten
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//EatFruit.wav"), NULL, SND_NODEFAULT | SND_FILENAME);
        //restarts music loop after sound
        PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//BackgroundLoop.wav"), NULL, SND_NOSTOP | SND_LOOP | SND_ASYNC);

        

    }
   
    //Bugfix for borders pushing out when the snale tail sections print

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    //game terminates when snake head collides with tail section
    for (int i = 0; i < nTail; i++)

        if (tailX[i] == x && tailY[i] == y)
            //Sound plays to indicate game over 
        {   
            cout << dye::red("Game Over! :-(");

            PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//GameOver.wav"), NULL, SND_NODEFAULT | SND_FILENAME);
            //ensures the gameover sound has time to play before termination of the program.
            Sleep(2000);
            if (score > 600)
            {
                cout << "Congratulations!! You have completed Snake Trap! Play again and beat your highscore!" << endl;
                cout << "Created by Jared Hall" << endl;

                PlaySound(TEXT("C://Users//jradh//OneDrive//Desktop//Game Sound Files//EndGame.wav"), NULL, SND_NODEFAULT | SND_FILENAME);
               
            }
            gameOver = true;

        }
}




int main()
{
    
    // Set up the handles for reading/writing:
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);

    // Change the console window title:
      SetConsoleTitle(L"SSSNAKE TRAP!");
    // Set up the required window size:
    SMALL_RECT windowSize = { 0, 0, 50, 100 };
    // Change the console window size
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    
    // Create a COORD to hold the buffer size
    COORD bufferSize = { 10, 10 };
  //  SetConsoleScreenBufferSize(wHnd, bufferSize);

    //initial setup
    Setup();
   
    //game loop 
    while (!gameOver)
    {
     

        Input();
        Draw();
        Logic();
       
    }

    //writes highScore to txt file when game ends to be recalled at the begenning of the next game.
    
    highScore = score;
    highScoreFileof.open("highScoreFile.txt");
    highScoreFileof << highScore;
    highScoreFileof.close();

    return 0;
}

