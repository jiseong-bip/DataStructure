//
//  main.c
//  polynomial
//
//  Created by 전지성 on 2023/03/22.
//

#include <stdio.h>

#define MAX(a, b) (((a) > (b))?(a):(b))
#define MAX_DEREE 101

typedef struct{
    int degree;
    double coef[MAX_DEREE];
} polynomial;

polynomial poly_add1(polynomial A, polynomial B){
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = MAX(A.degree, B.degree);
    
    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if(degree_a > degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        }
        else if (degree_a == degree_b)
        {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        }
        else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}

void print_poly(polynomial p){
    for(int i = p.degree; i > 0; i--){
        printf("%3.1fx^%d + ",p.coef[p.degree-i],i);
    }
    printf("%3.1f\n", p.coef[p.degree]);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    polynomial a = {5, {3,0,0,0,0,5}};
    polynomial b = {6, {5,3,2,2,1,8,8}};
    print_poly(a);
    print_poly(b);
    
    polynomial c = poly_add1(a, b);
    print_poly(c);
    
    return 0;
}
