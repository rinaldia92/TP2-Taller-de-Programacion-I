#include "Imagen.h"
#include <iostream>


Imagen::Imagen(int height ,int width){
  this->width = width;
  this->height = height;
  this->matrix.assign(width*height,0);
}

int Imagen::SetValue(int row, int column,int value){
  int pos;
  pos = (this->width)*row + column;
  this->matrix[pos] = value;
  return 0;
}

int Imagen::GetValue(int row, int column){
  int pos;
  pos = (this->width)*row + column;
  return this->matrix[pos];
}

int Imagen::GetWidht(){
  return this->width;
}

int Imagen::GetHeight(){
  return this->height;
}

int Imagen::ClearImagen(){
  int i,j;
  for (i = 0; i< this->height; i++){
    for (j = 0; j< this->width; j++){
        this->SetValue(i,j,0);
    }
  }
  return 0;
}

int Imagen::PrintImagen(){
  int i,j,value;
  std::cout << this->width << " " << this->height << std::endl;
  for (i = 0; i< this->height; i++){
    for (j = 0; j< this->width; j++){
        value = this->GetValue(i,j);
        if (value == 1)
          std::cout << "#";
        else
          std::cout << ".";
    }
      std::cout << std::endl;
  }
  return 0;
}

Imagen& Imagen::operator=(Imagen &other){
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
  other.ClearImagen();
  return *this;
}

Imagen::~Imagen(){
}
