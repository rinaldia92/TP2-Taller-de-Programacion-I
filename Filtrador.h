#ifndef FILTRADOR_H
#define FILTRADOR_H

#include "Imagen.h"
#include "Dilatacion.h"
#include "Erosion.h"
#include <thread>
#include <mutex>

#define DILATACION "d"

//Filtro Erosion
class Filtrador{
  public:
    Filtrador();//Constructor
    int AplicarFiltro(std::string filtro,int cantthreads, Imagen &img,
      Imagen &pat, Imagen &nimg);
    virtual ~Filtrador();//Destructor
  private:
    std::vector<Thread*> threads;
    std::mutex m;
};


#endif
