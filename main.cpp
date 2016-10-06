#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Imagen.h"
#include "Filtrador.h"

#define COD_RET_EXITO 0

  int main(int argc, char *argv[]){
    int i,j,k;
    int cantthreads;
    std::string filtro;
    std::string patron;
    int filimg,colimg;
    int filpat,colpat;
    std::string archivo;
    std::string aux;

    if (argc < 4 || argc%2 != 0){
      return 1;
    }

    getline(std::cin, archivo);
    std::istringstream iss(archivo);
    iss >> colimg;
    iss >> filimg;
    Imagen imagen(filimg,colimg);

    for (i = 0; i < filimg; i++){
        getline(std::cin, archivo);
        std::istringstream iss(archivo);
        iss >> archivo;
        for (j = 0; j < colimg; j++){
          aux = archivo.substr(j,1);
          if (aux == "#"){
            imagen.SetValue(i,j,1);
          } else {
            imagen.SetValue(i,j,0);
          }
        }
    }

    Imagen nuevaimagen(filimg,colimg);

    cantthreads = atoi(argv[1]);

    Filtrador filtrador;

    for (k = 2; k < argc-1; k+=2){
      filtro = argv[k];
      patron = argv[k+1];
      std::istringstream iss2(patron);
      iss2 >> colpat;
      iss2 >> filpat;
      Imagen impatron(filpat,colpat);
      for (i = 0; i < filpat; i++){
          iss2 >> patron;
          for (j = 0; j < colpat; j++){
            aux = patron.substr(j,1);
            if (aux == "#"){
              impatron.SetValue(i,j,1);
            } else {
              impatron.SetValue(i,j,0);
            }
          }
      }

      filtrador.AplicarFiltro(filtro,cantthreads,imagen,impatron,nuevaimagen);
      filtro.clear();
      patron.clear();
    }

    imagen.PrintImagen();

    return COD_RET_EXITO;
}
