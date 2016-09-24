#ifndef EROSION_H
#define EROSION_H

#include "Thread.h"
#include "EmptyImagen.h"
#include "Imagen.h"
#include <mutex>

//Filtro Erosion
class Erosion: public Thread  {
  public:
    Erosion(EmptyImagen *img, int inifil, int finfil,
      Imagen *pat, EmptyImagen &nimg, std::mutex &m);//Constructor
    /*Aplica un filtro a una imagen desde una fila hasta otra segun un patron
    y lo setea en la nueva imagen*/
    virtual void run();
    virtual ~Erosion();//Destructor
  private:
  	EmptyImagen *img;
    Imagen *pat;
    EmptyImagen &nimg;
    int inifil;
    int finfil;
    std::mutex &m;
    //Busca si hay coincidencia total entre la imagen y el patron
    bool coincidencia(EmptyImagen *img,int fil,int col, Imagen *pat);
};


#endif
