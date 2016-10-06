#ifndef FILTRADOR_H
#define FILTRADOR_H

#include "Imagen.h"
#include "Dilatacion.h"
#include "Erosion.h"
#include <string>
#include <vector>
#include <thread>
#include <mutex>

#define DILATACION "d"
#define EROSION "e"

class Filtrador{
  public:
    Filtrador();//Constructor
    //Aplica algun filtro a una imagen en cierta cantidad de threads
    int AplicarFiltro(std::string filtro,int cantthreads, Imagen &img,
      Imagen &pat, Imagen &nimg);
    virtual ~Filtrador();//Destructor
  private:
    std::vector<Thread*> threads;
    std::mutex m;
};


#endif
