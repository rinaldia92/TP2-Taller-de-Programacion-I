#ifndef EROSION_H
#define EROSION_H

#include "Thread.h"
//#include "Imagen.h"
#include "Imagen.h"
#include <mutex>

//Filtro Erosion
class Erosion: public Thread{
  public:
    Erosion(Imagen &img, int inifil, int finfil,
      Imagen &pat, Imagen &nimg, std::mutex &m);//Constructor
    /*Aplica un filtro a una imagen desde una fila hasta otra segun un patron
    y lo setea en la nueva imagen*/
    virtual void run();
    virtual ~Erosion();//Destructor
  private:
  	Imagen &img;
    Imagen &pat;
    Imagen &nimg;
    int inifil;
    int finfil;
    std::mutex &m;
    //Busca si hay coincidencia total entre la imagen y el patron
    bool coincidencia(Imagen &img,int fil,int col, Imagen &pat);
};


#endif
