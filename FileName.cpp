#include <iostream>
#include <Windows.h>
using namespace std;
//Увиличиваем змейку на один фрагмент
void largeSnake(Snake*& snake, int length) {
    Snake* new_snake = new Snake[length]{};
    for (int i = 0; i < length; i++) {
        if (i < length - 1) {
            new_snake[i] = snake[i];
        }
        else {
            new_snake[length - 1] = { 0, snake[length - 2].positionX, snake[length - 2].positionY };
        }
    }
    delete[] snake;
    snake = new_snake;
}

//Двигаем змейку на одну клетку в заданом направлении
void snakeMove(Snake* snake, int length, int** board) {
    board[snake[length - 1].positionY][snake[length - 1].positionX] = 0;
    for (int i = length - 1; i > 0; i--) {
        snake[i].positionX = snake[i - 1].positionX;
        snake[i].positionY = snake[i - 1].positionY;
    }
    if (snake[0].direction == 4) {
        snake[0].positionY += 1;
    }
    else if (snake[0].direction == 3) {
        snake[0].positionX -= 1;
    }
    else if (snake[0].direction == 2) {
        snake[0].positionY -= 1;
    }
    else if (snake[0].direction == 1) {
        snake[0].positionX += 1;
    }


}

int main()
{

}