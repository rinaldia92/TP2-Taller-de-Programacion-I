#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>

/*Clase que representa una imagen como una matriz inicializada en 0 en base
a la cantidad de filas y columnas que posee. Se lo implemento a traves de un
vector*/

class Imagen{
    public:
      Imagen(int height,int width);//Constructor
      //Obtiene el valor segun fila y columna
      int GetValue(const int row,const int column);
      int GetHeight();//Obtiene cantidad de filas
      int GetWidht();//Obtiene cantidad de columnas
      //Setea valor en fila columna
      int SetValue(const int row,const int column,const int value);
      int ClearImagen();//Limpia la imagen
      int PrintImagen();//Imprime la imagen
      Imagen& operator=(Imagen &other);//Copia por asignacion
      virtual ~Imagen();
    protected:
      std::vector<int> matrix;
      int width;
      int height;
    private:
};

#endif
