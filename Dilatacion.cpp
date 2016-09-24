#include "Dilatacion.h"

Dilatacion::Dilatacion(EmptyImagen *img, int inifil, int finfil,
  Imagen *pat, EmptyImagen &nimg, std::mutex &m):
  img(img),pat(pat),nimg(nimg),inifil(inifil),finfil(finfil),m(m){
}

bool Dilatacion::coincidencia(EmptyImagen *img,int fil,int col, Imagen *pat){
  int fila,columna;
  int filapatron,columnapatron;
  int centfil,centcolum;
  int value,valuepatron;
  int cantfil,cantcolum;
  bool coincidencia = false;

  centfil = pat->GetHeight()/2;
  centcolum = pat->GetWidht()/2;
  cantfil = img->GetHeight();
  cantcolum = img->GetWidht();
  filapatron = 0;
  columnapatron = 0;

  for (fila = fil - centfil; fila <= fil + centfil; fila++){
    for (columna = col - centcolum; columna <= col + centcolum; columna++){
      if (fila >= 0 && columna >= 0 && fila < cantfil  && columna < cantcolum){
        value = img->GetValue(fila,columna);
        valuepatron = pat->GetValue(filapatron,columnapatron);
        if (valuepatron == 1 && value == 1){
          coincidencia = true;
        }
      }
      columnapatron++;
    }
    filapatron++;
    columnapatron = 0;
  }
  return coincidencia;
}

void Dilatacion::run(){
    int i,j;
    int columnas;
     m.lock();

    columnas = img->GetWidht();

    for (i = inifil; i < finfil; i++){
      for (j = 0; j < columnas; j++){
          if (this->coincidencia(img,i,j,pat)){
            nimg.SetValue(i,j,1);
          }
      }
    }
    m.unlock();
}

Dilatacion::~Dilatacion(){
}
