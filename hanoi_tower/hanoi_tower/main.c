//
//  main.c
//  hanoi_tower
//
//  Created by 전지성 on 2023/03/22.
//

#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if(n <= 0) printf("잘못된 입력입니다.");
    if(n == 1) printf("%d을 %c에서 %c으로 옮긴다\n", n, from, to);
    else {
        hanoi_tower((n-1), from, to, tmp);
        printf("%d을 %c에서 %c으로 옮긴다\n", n, from, to);
        hanoi_tower((n-1), tmp, from, to);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}
