#ifndef DILATACION_H
#define DILATACION_H

#include "Imagen.h"
#include "Thread.h"
#include <mutex>

class Dilatacion: public Thread{
  public:
    Dilatacion(Imagen &img, int inifil, int finfil,
      Imagen &pat, Imagen &nimg, std::mutex &m);//Constructor
    //Aplica el filtro a una imagen
    virtual void  run();
    virtual ~Dilatacion();//Destructor
  private:
    Imagen &img;
    Imagen &pat;
    Imagen &nimg;
    int inifil;
    int finfil;
    std::mutex &m;
    //Busca si hay coincidencia parcial entre la imagen y el patron
    bool coincidencia(Imagen &img,int fil,int col, Imagen &pat);
};


#endif
