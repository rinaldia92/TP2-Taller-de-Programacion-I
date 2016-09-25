#include "Imagen.h"
#include <iostream>
#include <string>

Imagen::Imagen(int height,int width):EmptyImagen(height,width){
  this->width = width;
  this->height = height;
  this->matrix.assign(width*height,0);
}

int Imagen::SetRow(int row, std::string line){
  std::string aux;
  int it;
  int value;
  for (it = 0; it < this->width; it++){
    aux = line.substr(it,1);
    if (aux == "#"){
      value = 1;
    } else {
      value = 0;
    }
    this->SetValue(row,it,value);
  }
  return 0;
}

Imagen& Imagen::operator=(EmptyImagen &other){
  int i,j,value;

  this->ClearImagen();
  this->height = other.GetHeight();
  this->width = other.GetWidht();

  for (i = 0; i< this->height; i++){
    for (j = 0; j< this->width; j++){
        value = other.GetValue(i,j);
        this->SetValue(i,j,value);
    }
  }
  return *this;
}

Imagen::~Imagen(){
}
