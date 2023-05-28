//
//  main.c
//  dfs
//
//  Created by 전지성 on 2023/04/16.
//

#include <stdio.h>
#define MAX_STACK_SIZE 100

int top = -1;
int stack[MAX_STACK_SIZE];

void push(int value) {
    if (top < MAX_STACK_SIZE - 1) {
        stack[++top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1;
}

int is_empty() {
    return (top == -1);
}

void dfs(char maze[][6], int x, int y) {
    if (maze[x][y] == 'x') {
        printf("탈출에 성공했습니다!\n");
        return;
    }
    push(y);
    push(x);

    maze[x][y] = '2';
    printf("(%d,%d) 방문 -> ", x, y);

    // 위쪽 탐색
    if (x > 0 && maze[x-1][y] != '1' && maze[x-1][y] != '2') {
        dfs(maze, x-1, y);
    }
    // 오른쪽 탐색
    if (y < 5 && maze[x][y+1] != '1' && maze[x][y+1] != '2') {
        dfs(maze, x, y+1);
    }
    // 아래쪽 탐색
    if (x < 5 && maze[x+1][y] != '1' && maze[x+1][y] != '2') {
        dfs(maze, x+1, y);
    }
    // 왼쪽 탐색
    if (y > 0 && maze[x][y-1] != '1' && maze[x][y-1] != '2') {
        dfs(maze, x, y-1);
    }

    pop(); // 스택에서 x값 제거
    pop(); // 스택에서 y값 제거
}

int main() {
    char maze[6][6] = {
        { '1', '1', '1', '1', '1', '1' },
        { 'e', '0', '1', '0', '0', '1' },
        { '1', '0', '0', '0', '1', '1' },
        { '1', '0', '1', '0', '1', '1' },
        { '1', '0', '1', '0', '0', 'x' },
        { '1', '1', '1', '1', '1', '1' },
    };

    dfs(maze, 1, 0);

    return 0;
}

