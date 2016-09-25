#include "EmptyImagen.h"
#include <iostream>


EmptyImagen::EmptyImagen(int height ,int width){
  this->width = width;
  this->height = height;
  this->matrix.assign(width*height,0);
}

int EmptyImagen::SetValue(int row, int column,int value){
  int pos;
  pos = (this->width)*row + column;
  this->matrix[pos] = value;
  return 0;
}

int EmptyImagen::GetValue(int row, int column){
  int pos;
  pos = (this->width)*row + column;
  return this->matrix[pos];
}

int EmptyImagen::GetWidht(){
  return this->width;
}

int EmptyImagen::GetHeight(){
  return this->height;
}

int EmptyImagen::ClearImagen(){
  int i,j;
  for (i = 0; i< this->height; i++){
    for (j = 0; j< this->width; j++){
        this->SetValue(i,j,0);
    }
  }
  return 0;
}

int EmptyImagen::PrintImagen(){
  int i,j,value;
  std::cout<<this->width<<" "<<this->height<<std::endl;
  for (i = 0; i< this->height; i++){
    for (j = 0; j< this->width; j++){
        value = this->GetValue(i,j);
        if (value == 1)
          std::cout<<"#";
        else
          std::cout<<".";
    }
    //if (i != this->height -1)
      std::cout<<std::endl;
  }
  return 0;
}

EmptyImagen::~EmptyImagen(){
}
