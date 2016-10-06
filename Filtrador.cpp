#include "Filtrador.h"
#include <string>

Filtrador::Filtrador(){
}

int Filtrador::AplicarFiltro(std::string filtro,int cantthreads, Imagen &img,
  Imagen &pat, Imagen &nimg){
    int i,j,filas;
    filas = img.GetHeight();
    if (filtro == DILATACION){
      for (j = 0; j < cantthreads; j++){
        threads.push_back(new Dilatacion(img,(j/cantthreads)*filas,
                    ((j+1)/cantthreads)*filas,pat,nimg,m));
      }

      for (j = 0; j < cantthreads; j++){
          threads[j]->start();
      }
      for (j = 0; j < cantthreads; j++){
          threads[j]->join();
          delete (threads[j]);
      }
      threads.clear();
    } else{
      if (filtro == EROSION){
        for (j = 0; j < cantthreads; j++){
          threads.push_back(new Erosion(img,(j/cantthreads)*filas,
                  ((j+1)/cantthreads)*filas,pat,nimg,m));
        }

        for (j = 0; j < cantthreads; j++){
            threads[j]->start();
        }
        for (j = 0; j < cantthreads; j++){
            threads[j]->join();
            delete (threads[j]);
        }
        threads.clear();
      }
    }
    i++;
    img = nimg;
    return 0;
}

Filtrador::~Filtrador(){
}
