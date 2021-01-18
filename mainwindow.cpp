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
        int veces = ui->entEliminarFecha->text().toInt();
        elimHumanos.BlackDwarf(veces, mundo);
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimBlack;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Black Dwarf mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbEliminar->currentText() == QVariant("Thanos").toString()){

        if( ui->entEliminarFecha->text() != "" && ui->entElimNivel->text() != ""){
            int fecha = ui->entEliminarFecha->text().toInt();
            int nivel = ui->entElimNivel->text().toInt();
            // Eliminar con fecha y nivel de thanos
        }else if(ui->entEliminarFecha->text() != ""){
            int fecha = ui->entEliminarFecha->text().toInt();
            //Eliminar thanos solo de fecha
        }else if(ui->entElimNivel->text() != ""){
            int nivel = ui->entElimNivel->text().toInt();
            //Eliminar thanos por nivel
        }


        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        stringstream buff;
        buff << elimHumanos.elimBlack;
        string elim = buff.str();
        string txt = date+" | "+time+"-> Soy Thanos mate a "+elim;
        QString qstr = QString::fromStdString(txt);
        ui->txtmostrarDatos->setText(qstr);
    }
    ui->entEliminarFecha->setText("");
    ui->entElimNivel->setText("");
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
    int cantHumanos = ui->entCantHumanos->text().toInt();

}

void MainWindow::on_btnEnviarCorreo_clicked(){
    if(ui->cmbEnviarCorreo->currentText() == QVariant("Enviar Eliminar Humanos").toString()){

    }else if(ui->cmbEnviarCorreo->currentText() == QVariant("Enviar Salvar Humanos").toString()){

    }else if(ui->cmbEnviarCorreo->currentText() == QVariant("Enviar Todo la Humanidad").toString()){

    }

}

void MainWindow::on_btnBuscar_clicked(){
    consultas->setArbolMundo(arbol,mundo);
    if(ui->cmbBuscarPor->currentText() == QVariant("Humano Por ID").toString()){
        int buscar = ui->entBuscar->text().toInt();
        string consulta = consultas->consultaHumanoID(buscar,arbol->raiz);
        QString qstr = QString::fromStdString(consulta);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbBuscarPor->currentText() == QVariant("Familia Por ID").toString()){
        int buscar = ui->entBuscar->text().toInt();
        string consulta = consultas->consultaFamiliaID(buscar,arbol->raiz);
        QString qstr = QString::fromStdString(consulta);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbBuscarPor->currentText() == QVariant("Amigos por ID").toString()){
        int buscar = ui->entBuscar->text().toInt();
        string consulta = consultas->consultaAmigosID(buscar,arbol->raiz);
        QString qstr = QString::fromStdString(consulta);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbBuscarPor->currentText() == QVariant("Humanos por Deporte").toString()){
        QString buscar = ui->entBuscar->text();
        string consulta = consultas->consultaDeportes(buscar.toStdString());
        QString qstr = QString::fromStdString(consulta);
        ui->txtmostrarDatos->setText(qstr);
    }else if(ui->cmbBuscarPor->currentText() == QVariant("Humanos Vivos,Salvados,Eliminados").toString()){
        string consulta = consultas->humanosViviosSalvadosEliminados();
        QString m_date = QDate::currentDate().toString();
        string date = m_date.toStdString();
        QString m_time = QTime::currentTime().toString();
        string time = m_time.toStdString();
        string nombre = "Humanos Eliminados, vivos y salvados "+date+" | "+time;
        archivo->escribir(consulta,nombre);
        //Falta agregar que se envie por coprreo
    }
}

void MainWindow::on_btnPecar_clicked(){
    mundo->hacerPecar();
}

void MainWindow::on_btnBuenasAcciones_clicked(){
    mundo->hacerAccionesBuenas();
}
