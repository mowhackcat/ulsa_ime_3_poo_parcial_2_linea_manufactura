#include "Maquina.h"

#include <string>
#include <iostream>
Maquina::Maquina(int id, const std::string& nombre):nombre(nombre), id(id){}

 void Maquina::encender(){
    this->encendida = true;
    std::cout << "se encendio" << this->nombre ;
 } 

 void Maquina::apagar(){
     this->encendida = false;
    std::cout << "se apago" << this->nombre ;
 }

   bool Maquina::estaEncendida() const{
    if(this->encendida==true){
        return true;
    }else return false;
   };
    bool Maquina::estaEnFalla() const{  
        if(this->enFalla==true){
        return true;
    }else return false;};

 bool Maquina::puedeProcesar() const {
    if(this->estaEncendida() == true && estaEnFalla() == false){
        return true;
    }else return false;
 }

void Maquina::reportarFalla(){
    if(this->enFalla == true){
        std::cout << "falla detectada, inicializando mantenimiento\n";
       apagar();
       std::cout << "...Realizando mantenimiento\n";
    }


}

 int Maquina::getId() const{
    return this->id;
 };

    std::string Maquina::getNombre() const{
        return nombre;
    };

