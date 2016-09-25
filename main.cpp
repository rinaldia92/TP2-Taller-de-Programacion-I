#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Imagen.h"
#include "Dilatacion.h"
#include "Erosion.h"
#include <mutex>

#define COD_RET_EXITO 0

  int main(int argc, char *argv[]){
    int i,j,k;
    int cantthreads;
    //int cantfilasthreads;
    int filasimagen;
    std::string filtro;
    std::string patron;
    std::string filas,columnas;
    std::string archivo;
    std::vector<Thread*> threads;
    std::mutex m;

    if (argc < 4 || argc%2 != 0){
      return 1;
    }

    getline(std::cin, archivo);
    std::istringstream iss2(archivo);
    iss2 >> columnas;
    iss2 >> filas;
    filasimagen = stoi(filas);
    Imagen imagen(stoi(filas),stoi(columnas));

    for (i = 0; i < stoi(filas); i++){
        getline(std::cin, archivo);
        std::istringstream iss2(archivo);
        iss2 >> archivo;
        imagen.SetRow(i,archivo);
    }

    EmptyImagen nuevaimagen(stoi(filas),stoi(columnas));

    cantthreads = atoi(argv[1]);
    //cantfilasthreads = imagen.GetHeight()/cantthreads;

    i = 0;
    for (k = 2; k < argc-1; k+=2){
      filtro = argv[k];
      patron = argv[k+1];
      std::istringstream iss(patron);
      iss >> columnas;
      iss >> filas;
      Imagen impatron(stoi(filas),stoi(columnas));
      for (j = 0; j < stoi(filas); j++){
          iss >> patron;
          impatron.SetRow(j,patron);
      }

      if (filtro == "d"){
        for (j = 0; j < cantthreads; j++){
        	threads.push_back(new Dilatacion(&imagen,(j/cantthreads)*filasimagen,((j+1)/cantthreads)*filasimagen,&impatron,nuevaimagen,m));
        }

        for (j = 0; j < cantthreads; j++){
            threads[j]->start();
        }
        for (j = 0; j < cantthreads; j++){
            threads[j]->join();
            delete (threads[j]);
        }
        threads.clear();

      } else {

      	for (j = 0; j < cantthreads; j++){
      		threads.push_back(new Erosion(&imagen,(j/cantthreads)*filasimagen,((j+1)/cantthreads)*filasimagen,&impatron,nuevaimagen,m));
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
      i++;
      imagen = nuevaimagen;
    }

    imagen.PrintImagen();

    return COD_RET_EXITO;
}
