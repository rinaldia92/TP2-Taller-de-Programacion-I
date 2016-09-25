#ifndef EMPTYIMAGEN_H
#define EMPTYIMAGEN_H

#include <vector>
#include <string>

/*Clase que representa una imagen como una matriz inicializada en 0 en base
a la cantidad de filas y columnas que posee. Se lo implemento a traves de un
vector*/

class EmptyImagen{
    public:
      EmptyImagen(int height,int width);//Constructor
      int GetValue(int row, int column);//Obtiene el valor segun fila y columna
      int GetHeight();//Obtiene cantidad de filas
      int GetWidht();//Obtiene cantidad de columnas
      int SetValue(int row, int column,int value);//Setea valor en fila columna
      int ClearImagen();
      int PrintImagen();//Imprime la imagen
      virtual ~EmptyImagen();
    protected:
    private:
      std::vector<int> matrix;
      int width;
      int height;
};

#endif
