#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_btnMostrarArbol_clicked(){
    arbol->print2D(arbol->raiz);
    QString dato = QString::fromLocal8Bit(arbol->arbolS.c_str());
    ui->txtArbol->setText(dato);
}

void MainWindow::on_btnEliminar_clicked(){
    if(ui->cmbEliminar->currentText() == QVariant("Corvus Glaive").toString()){
        elimHumanos.CorvusGlaive(mundo);
    }else if(ui->cmbEliminar->currentText() == QVariant("Midnight").toString()){
        elimHumanos.Midnight(mundo);
    }else if(ui->cmbEliminar->currentText() == QVariant("Nebula").toString()){
        elimHumanos.Nebula(mundo);
    }else if(ui->cmbEliminar->currentText() == QVariant("Ebony Maw").toString()){
        elimHumanos.EbonyMaw(mundo);
    }else if(ui->cmbEliminar->currentText() == QVariant("Black Dwarf").toString()){
        int veces = ui->entEliminar->text().toInt();
        elimHumanos.BlackDwarf(veces, mundo);
    }
    ui->entEliminar->setText("");
}


void MainWindow::on_btnSalvar_clicked(){
    if(ui->cmbSalvar->currentText() == QVariant("Ant Man").toString()){
        int veces = ui->entSalvar->text().toInt();

    }else if(ui->cmbSalvar->currentText() == QVariant("Ironman").toString()){

    }else if(ui->cmbSalvar->currentText() == QVariant("Thor").toString()){

    }else if(ui->cmbSalvar->currentText() == QVariant("Spiderman").toString()){

    }

    ui->entSalvar->setText("");
}

void MainWindow::on_btnCrearHumanos_clicked(){

}
