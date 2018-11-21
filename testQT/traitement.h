#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#endif TRAITEMENT_H

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>// pour creer les fenetre d'affichage.
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <algorithm>
#include "math.h"


using namespace cv;
using namespace std;


Mat filtreMedianNVG(Mat src, int voisinage);

Mat filtreMoyenNVG(Mat src, int voisinage);




