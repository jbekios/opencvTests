#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
int main(int argc, char** argv )
{

    // Declarar una matriz 
    Mat image;
    // Creo la matriz con una imagen
    image = imread("/home/jbekios/CODE/opencvTests/VICENT.jpeg");
    // image == 0, no cargo la imagen
    if ( !image.data )
    {
        //Indicar un error
        printf("No image data \n");
        return -1;
    }
    // image == 1, muestro la imagen
    // Creo una ventana vacia que tien nombre "Mi ventana"
    namedWindow("Mi ventana", WINDOW_AUTOSIZE );
    // Coloco la imagen dentro de la ventana vacia
    imshow("Mi ventana", image);
    // El programa queda en espera de una tecla
    waitKey(0);

    return 0;
}
