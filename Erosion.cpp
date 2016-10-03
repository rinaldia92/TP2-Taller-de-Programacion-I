#include "Erosion.h"

Erosion::Erosion(Imagen &img, int inifil, int finfil,
  Imagen &pat, Imagen &nimg, std::mutex &m):
  img(img),pat(pat),nimg(nimg),inifil(inifil),finfil(finfil),m(m){
}

bool Erosion::coincidencia(Imagen &img,int fil,int col, Imagen &pat){
  int fila,columna;
  int filapatron,columnapatron;
  int centfil,centcolum;
  int value,valuepatron;
  bool coincidencia = true;

  centfil = pat.GetHeight()/2;
  centcolum = pat.GetWidht()/2;
  filapatron = 0;
  columnapatron = 0;

  fila = fil - centfil;
  columna = col - centcolum;

  while (coincidencia && (fila <= fil + centfil)){
    while (coincidencia && (columna <= col + centcolum)){
      value = img.GetValue(fila,columna);
      valuepatron = pat.GetValue(filapatron,columnapatron);
      if (valuepatron == 1 && value == 0){
        coincidencia = false;
      }
      columnapatron++;
      columna++;
    }
    fila++;
    filapatron++;
    columna = col - centcolum;
    columnapatron = 0;
  }
  return coincidencia;
}

void Erosion::run(){
    int i,j;
    int centfil,centcolum;
    int filas,columnas;
    int inicio,fin;
    columnas = img.GetWidht();
    filas = img.GetHeight();
    centfil = pat.GetHeight()/2;
    centcolum = pat.GetWidht()/2;
    if (inifil < centfil){
      inicio = centfil;
    } else {
      inicio = inifil;
    }
    if (finfil > filas - centfil-1){
      fin = filas-centfil;
    } else {
      fin = finfil;
    }

    for (i = inicio; i < fin; i++){
      for (j = centcolum; j < columnas-centcolum; j++){
          if (this->coincidencia(img,i,j,pat)){
            nimg.SetValue(i,j,1);
          }
      }
    }
}

Erosion::~Erosion(){
}
