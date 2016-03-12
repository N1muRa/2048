//
//  main.cpp
//  2048
//
//  Created by Vam on 16/3/10.
//  Copyright © 2016年 apple. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int a[4][4];
int num[2]={2,4};

bool full(){
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            if (a[i][j]==0) {
                return false;
            }
        }
    }
    return true;
}

void print(){
    system("cls");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
}

void init(){
    int x = rand()%4;
    int y = rand()%4;
    a[x][y]=2;
    if (x==0) {
        a[x+1][y]=num[rand()%2];
    }
    else if(x==3){
        a[x-1][y]=num[rand()%2];
    }else if(y==0){
        a[x][y+1]=num[rand()%2];
    }else if(y==3){
        a[x][y-1]=num[rand()%2];
    }else{
        a[x+1][y]=num[rand()%2];
    }
    print();
}

bool up(){
    bool move = false;
    for (int j=0; j<4; j++) {
        int i=0,k=0,pre=0;
        bool fir = true;
        while (i<4) {
            if (a[i][j]==0) {
                i++;
                continue;
            }else{
                if (fir) {
                    pre = k;
                    a[pre][j] = a[i][j];
                    if (i!=pre) {
                        a[i][j]=0;
                        move = true;
                    }
                    k++;
                    i++;
                    fir = false;
                }else{
                    if (a[i][j] == a[pre][j]) {
                        a[pre][j] *= 2;
                        a[i][j] = 0;
                        i++;
                        move = true;
                        fir = true;
                    }else{
                        pre = k;
                        a[pre][j] = a[i][j];
                        if (i!=pre) {
                            a[i][j]=0;
                            move = true;
                        }
                        k++;
                        i++;
                        fir = false;
                    }
                }
            }
        }
    }
    if (!move) {
        print();
        return  move;
    }
    int x;
    do{
        x = rand()%4;
    }while (a[3][x]!=0);
    a[3][x] = num[rand()%2];
    print();
    return move;
}

bool left(){
    bool move = false;
    for (int i=0; i<4; i++) {
        int j=0,k=0,pre=0;
        bool fir = true;
        while (j<4) {
            if (a[i][j]==0) {
                j++;
                continue;
            }else{
                if (fir) {
                    pre = k;
                    if (j!=pre) {
                        a[i][pre] = a[i][j];
                        a[i][j]=0;
                        move = true;
                    }
                    k++;
                    j++;
                    fir = false;
                }else{
                    if (a[i][j] == a[i][pre]) {
                        a[i][pre] *= 2;
                        a[i][j] = 0;
                        j++;
                        move = true;
                        fir = true;
                    }else{
                        pre = k;
                        a[i][pre] = a[i][j];
                        if (j!=pre) {
                            a[i][j]=0;
                            move = true;
                        }
                        k++;
                        j++;
                        fir = false;
                    }
                }
            }
        }
    }
    if (!move) {
        print();
        return  move;
    }
    int x;
    do{
        x = rand()%4;
    }while (a[x][3]!=0);
    a[x][3] = num[rand()%2];
    print();
    return move;
}

bool down(){
    bool move = false;
    for (int j=0; j<4; j++) {
        int i=3,k=3,pre=3;
        bool fir = true;
        while (i>=0) {
            if (a[i][j]==0) {
                i--;
                continue;
            }else{
                if (fir) {
                    pre = k;
                    a[pre][j] = a[i][j];
                    if (i!=pre) {
                        a[i][j]=0;
                        move = true;
                    }
                    k--;
                    i--;
                    fir = false;
                }else{
                    if (a[i][j] == a[pre][j]) {
                        a[pre][j] *= 2;
                        a[i][j] = 0;
                        i--;
                        move = true;
                        fir = true;
                    }else{
                        pre = k;
                        a[pre][j] = a[i][j];
                        if (i!=pre) {
                            a[i][j]=0;
                            move = true;
                        }
                        k--;
                        i--;
                        fir = false;
                    }
                }
            }
        }
    }
    if (!move) {
        print();
        return  move;
    }
    int x;
    do{
        x = rand()%4;
    }while (a[0][x]!=0);
    a[0][x] = num[rand()%2];
    print();
    return move;
}

bool right(){
    bool move = false;
    for (int i=0; i<4; i++) {
        int j=3,k=3,pre=3;
        bool fir = true;
        while (j>=0) {
            if (a[i][j]==0) {
                j--;
                continue;
            }else{
                if (fir) {
                    pre = k;
                    if (j!=pre) {
                        a[i][pre] = a[i][j];
                        a[i][j]=0;
                        move = true;
                    }
                    k--;
                    j--;
                    fir = false;
                }else{
                    if (a[i][j] == a[i][pre]) {
                        a[i][pre] *= 2;
                        a[i][j] = 0;
                        j--;
                        move = true;
                        fir = true;
                    }else{
                        pre = k;
                        a[i][pre] = a[i][j];
                        if (j!=pre) {
                            a[i][j]=0;
                            move = true;
                        }
                        k--;
                        j--;
                        fir = false;
                    }
                }
            }
        }
    }
    if (!move) {
        print();
        return  move;
    }
    int x;
    do{
        x = rand()%4;
    }while (a[x][0]!=0);
    a[x][0] = num[rand()%2];
    print();
    return move;
}

void play(){
    char dir;
    while (cin >> dir ) {
        if (dir=='w') {
            if((!up())&&full()){
                cout << "YOU DEAD\n";
                break;
            }
        }else if(dir=='a'){
            if((!left())&&full()){
                cout << "YOU DEAD\n";
                break;
            }
        }else if(dir=='s'){
            if((!down())&&full()){
                cout << "YOU DEAD\n";
                break;
            }
        }else if(dir=='d'){
            right();
        }else{
            cout << "WRONG\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    play();
    return 0;
}
