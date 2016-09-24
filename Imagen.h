#ifndef IMAGEN_H
#define IMAGEN_H

#include <vector>
#include <string>
#include "EmptyImagen.h"

class Imagen: public EmptyImagen {
    public:
      Imagen(int height,int width);//Constructor
      int SetRow(int row, std::string line);//Setea una fila completa
      virtual ~Imagen();//Destructor
    protected:
    private:
      std::vector<int> matrix;
      int width;
      int height;
};

#endif
