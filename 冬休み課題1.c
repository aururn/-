#include <stdio.h>
#include <math.h>

#define steps 10  

// f(x,y)
struct Data {
    double x;
    double y;
};

double f(double x, double y);

double p0(struct Data* data, int n);
double p1(struct Data* data, double h, int n);
double p2(struct Data* data, double h, int n);
double p3(struct Data* data, double h, int n);

int main() {

    int i=0;
    double r,h = 0.2;  
    struct Data data[steps + 1];

    // 初期条件
    data[0].x = 0.0;
    data[0].y = 2.0;

    do {
        data[i + 1].x = data[i].x + h;
        if(i==0) data[i + 1].y = p0(data, i);
        else if(i==1) data[i + 1].y = p1(data, h, i);
        else if(i==2) data[i + 1].y = p2(data, h, i);
        else data[i + 1].y = p3(data, h, i);

        i++;
        r=sqrt(4-data[i].x*data[i].x/2);
        printf("x = %.2f, y = %8.5f, (%8.5f)\n", data[i].x, data[i].y,r-data[i].y);
    }while(data[i].x<1.8 && i<steps);

    return 0;
}

// 関数
double f(double x, double y) {

    return (-0.5*x/y); 
}

// 0次
double p0(struct Data* data, int n) {
    return data[n].y;
}

// 1次
double p1(struct Data* data, double h, int n) {
    return data[n].y + h * f(data[n].x, data[n].y);
}

// 2次
double p2(struct Data* data, double h, int n) {
    return data[n].y + h / 2.0 * (3 * f(data[n].x, data[n].y) - f(data[n - 1].x, data[n - 1].y));
}

// 3次
double p3(struct Data* data, double h, int n) {
    return data[n].y + h / 12.0 * (23 * f(data[n].x, data[n].y) - 16 * f(data[n - 1].x, data[n - 1].y) + 5 * f(data[n - 2].x, data[n - 2].y));
}


/* 実行結果
x = 0.20, y =  2.00000, (-0.00501)
x = 0.40, y =  1.99000, (-0.01010)
x = 0.60, y =  1.96485, (-0.01037)
x = 0.80, y =  1.92895, (-0.01062)
x = 1.00, y =  1.88180, (-0.01098)
x = 1.20, y =  1.82253, (-0.01145)
x = 1.40, y =  1.74990, (-0.01209)
x = 1.60, y =  1.66221, (-0.01297)
x = 1.80, y =  1.55695, (-0.01423)
x = 2.00, y =  1.43037, (-0.01616)
*/
