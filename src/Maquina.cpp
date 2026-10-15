#include "Maquina.h"

#include <string>
#include <iostream>

Maquina::Maquina(int id, const std::string& nombre):id(id), nombre(nombre), encendida(false),
enFalla(false), piezasProcesadas(0),tiempoTrabajado(0), paros(0){}

void Maquina::registrarPieza(){
this->piezasProcesadas++;
}

void Maquina::agregarTiempo(int segundos){
   this->tiempoTrabajado+= segundos;
}

void Maquina::encender(){
   std::cout << "Se encendio" << this->nombre << " \n";
   this->encendida = true;
} 

void Maquina::apagar(){
   this->encendida = false;
}

bool Maquina::estaEncendida() const{
   if(this->encendida==true){
      return true;
   }else return false;
};

bool Maquina::estaEnFalla() const{  
   if(this->enFalla==true){
       return true;
   }else return false;
};

bool Maquina::puedeProcesar() const {
   if(this->estaEncendida() == true && estaEnFalla() == false){
      return true;
   }else return false;
}

void Maquina::reportarFalla(){
   if(estaEnFalla() == true){
   registrarMantenimiento();
   apagar();
   }
}

void Maquina::registrarMantenimiento(){
   this->paros ++;
   this->enFalla=false;
   this->encendida=true;
};

int Maquina::getPiezasProcesadas() const{
   return this->piezasProcesadas;
}

int Maquina::getId() const{
   return this->id;
};

std::string Maquina::getNombre() const{
   return this->nombre;
};

int Maquina::getTiempoTrabajado() const {
   return this->tiempoTrabajado;
}

int Maquina::getParos() const{
return this->paros;
}

void Maquina::mostrarEstado () const{
std::cout << getNombre() << getId()  << ".........." << 
getPiezasProcesadas() << "piezas " << getTiempoTrabajado() << "segundos "
<< getParos() << "paros.\n";
      std::cout << "Se apago" << this->nombre << " \n";
}