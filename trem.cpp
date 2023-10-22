#include "trem.h"
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <QMutex>
#include <QWaitCondition>
#include <QtCore>
#include <QSemaphore>

QMutex mutex01;
QMutex mutex02;
QMutex mutex03;
QMutex mutex04;

int vef = 0;

//Construtor dos trens
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

//Apos o start,  a função é executada
void Trem::run(){
    while(true){
        if (velocidade == 200){
            emit updateGUI(ID, x,y);    //resposavel por emitir um sinal
            msleep(1000);
        }
        else{
            switch(ID){
                case 1:     //No caso do Trem 1
                    if(x == 180 && y == 210) {
                        mutex01.lock();
                    }

                    if( x == 330 && y == 230) {
                        mutex01.unlock();
                    }

                    if(x == 310 && y == 210) {
                        mutex02.lock();
                    }

                    if(x == 310 && y == 330) {
                        mutex02.unlock();
                    }

                    // Movimentacao
                    if (x == 330 && y < 330){
                        y+=10;
                    }

                    else if (x < 330 && y == 210){
                        x+=10;
                    }
                    else if (x == 60 && y > 210){
                        y-=10;
                    }
                    else if (x > 60 && y == 330){
                        x-=10;
                    }

                    emit updateGUI(ID,x,y);    //Emite um sinal
                    break;


                case 2: //No caso do Trem 2
                    if(x == 350 && y == 330) {
                        mutex02.lock();
                    }
                    if(x == 350 && y == 210) {
                        mutex02.unlock();
                    }
                    if(x == 330 && y == 230) {
                        mutex03.lock();
                    }
                    if(x == 490 && y == 210) {
                        mutex03.unlock();
                    }
                    if(x == 450 && y == 210) {
                         mutex04.lock();
                    }
                    if(x == 600 && y == 230) {
                        mutex04.unlock();
                    }

                    // Movimentacao
                    if (x < 600 && y == 210){
                        x+=10;
                    }
                    else if (x == 600 && y < 330){
                        y+=10;
                    }
                    else if (x > 330 && y == 330){
                        x-=10;
                    }
                    else if (x == 330 && y > 210){
                        y-=10;
                    }
                    emit updateGUI(ID,x,y);    //Emite um sinal
                    break;


                case 3: //No caso do Trem 3

                    if (x < 870 && y == 210){
                        x+=10;
                    }
                    else if (x == 870 && y < 330){
                        y+=10;
                    }
                    else if (x > 600 && y == 330){
                        x-=10;
                    }
                    else if (x == 600 && y > 210){
                        y-=10;
                    }
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;


                case 4: //No caso do Trem 4


                    if(x == 470 && y == 190) {
                        mutex01.lock();
                    }
                    if(x == 200 && y == 190) {
                        mutex01.unlock();
                    }
                    if(x == 470 && y == 190) {
                        mutex03.lock();
                    }
                    if(x == 310 && y == 210) {
                        mutex03.unlock();
                    }

                    // Mivimentacao
                    if (x < 470 && y == 80){
                        x+=10;
                    }
                    else if (x == 470 && y < 210){
                        y+=10;
                    }
                    else if (x > 200 && y == 210){
                        x-=10;
                    }
                    else if (x == 200 && y > 80){
                        y-=10;
                    }
                    emit updateGUI(ID, x,y);    //Emite um sinal
                    break;


                case 5: //No caso do Trem 5
                    if(x == 620 && y == 210) {
                        mutex03.lock();
                    }
                    if(x == 490 && y == 80) {
                        mutex03.unlock();
                    }
                    if(x == 620 && y == 210) {
                         mutex04.lock();
                    }
                    if(x == 470 && y == 190) {
                        mutex04.unlock();
                    }


                    // Movimentacao
                    if (x < 740 && y == 80){
                        x+=10;
                    }
                    else if (x == 740 && y < 210){
                        y+=10;
                    }
                    else if (x > 470 && y == 210){
                        x-=10;
                    }
                    else if (x == 470 && y > 80){
                        y-=10;
                    }
                    emit updateGUI(ID,x,y);    //Emite um sinal
                    break;

                default:
                    break;
            }
            msleep(velocidade);
        }
    }
}
//aceleração do trem
void Trem::aceleracao(int valor){
    this->velocidade = 200 - valor;
}


