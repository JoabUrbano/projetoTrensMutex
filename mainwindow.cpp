#include "mainwindow.h"
#include "semaphore.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria os trens com seus respectivos IDs e posições X e Y
    trem1 = new Trem(1,60,270);
    trem2 = new Trem(2,460,210);
    trem3 = new Trem(3,870,270);
    trem4 = new Trem(4,330,80);
    trem5 = new Trem(5,600,80);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Dado isso, quando o sinal UPDATEGUI for chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros int do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    //Inicio da execução
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

// O sinal UPDATEGUI for emitido, com isso, a função é executada
void MainWindow::updateInterface(int id, int x, int y){
    //Noss "cases", ocorre a atualização da posição dos quadrados que representam os trens.
    switch(id){
    case 1: //Atualiza a posição do trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow(){
    delete ui;
}
//Aceleração dos trens
void MainWindow::on_velocidade_t1_valueChanged(int valor){
    trem1->aceleracao(valor);
}

void MainWindow::on_velocidade_t2_valueChanged(int valor){
    trem2->aceleracao(valor);
}

void MainWindow::on_velocidade_t3_valueChanged(int valor){
    trem3->aceleracao(valor);
}

void MainWindow::on_velocidade_t4_valueChanged(int valor){
    trem4->aceleracao(valor);
}

void MainWindow::on_velocidade_t5_valueChanged(int valor){
    trem5->aceleracao(valor);
}
