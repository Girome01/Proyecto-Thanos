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
    QString m_date = QDate::currentDate().toString();
    string date = m_date.toStdString();
    if(ui->cmbEliminar->currentText() == QVariant("Corvus Glaive").toString()){
        elimHumanos.CorvusGlaive(mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimCorvus;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Corvus Glaive mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbEliminar->currentText() == QVariant("Midnight").toString()){
        elimHumanos.Midnight(mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimMidnight;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Midnight mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbEliminar->currentText() == QVariant("Nebula").toString()){
        elimHumanos.Nebula(mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimNebula;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Nebula mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbEliminar->currentText() == QVariant("Ebony Maw").toString()){
        elimHumanos.EbonyMaw(mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimEbony;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Ebony Maw mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbEliminar->currentText() == QVariant("Black Dwarf").toString()){
        int veces = ui->entEliminar->text().toInt();
        elimHumanos.BlackDwarf(veces, mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimBlack;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Black Dwarf mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
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
