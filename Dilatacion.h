#ifndef DILATACION_H
#define DILATACION_H

#include "EmptyImagen.h"
#include "Imagen.h"
#include "Thread.h"
#include <mutex>

class Dilatacion: public Thread {
  public:
    Dilatacion(EmptyImagen *img, int inifil, int finfil,
      Imagen *pat, EmptyImagen &nimg, std::mutex &m);//Constructor
    /*Aplica un filtro a una imagen desde una fila hasta otra segun un patron
    y lo setea en la nueva imagen*/
    virtual void  run();
    virtual ~Dilatacion();//Destructor
  private:
    EmptyImagen *img;
    Imagen *pat;
    EmptyImagen &nimg;
    int inifil;
    int finfil;
    std::mutex &m;
    //Busca si hay coincidencia parcial entre la imagen y el patron
    bool coincidencia(EmptyImagen *img,int fil,int col, Imagen *pat);
};


#endif
