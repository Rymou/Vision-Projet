
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>// pour creer les fenetre d'affichage.
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <algorithm>
#include "math.h"
#include "traitement.h"


using namespace cv;
using namespace std;



Mat filtreMedianNVG(Mat src, int voisinage){
	Mat dst = src.clone();
	if (voisinage % 2 != 1) return Mat();
	Rect roi = Rect(0, 0, voisinage, voisinage);
	int *voisins = new int[voisinage*voisinage]; // un tableau pour le calcul de la médiane
	for (int x = 0; x < src.rows; x++){
		for (int y = 0; y < src.cols; y++){
			if (x< (voisinage - 1) / 2 || x>(src.rows - 1 - (voisinage - 1) / 2) || y< (voisinage - 1) / 2 ||
				y>(src.cols - 1 - (voisinage - 1) / 2)) // pour le bord copier les mêmes valeurs des pixels
			{
				dst.at<uchar>(x, y) = src.at<uchar>(x, y);
			}
			else
			{
				// on centre le voisinage sur le pixel en cours
				roi.y = x - (voisinage - 1) / 2;
				roi.x = y - (voisinage - 1) / 2;
				Mat img_roi = src(roi);
				for (int i = 0; i < voisinage; i++){
					for (int j = 0; j < voisinage; j++){
						voisins[i*voisinage + j] = img_roi.at<uchar>(i, j);
					}
				}
				sort(voisins, voisins + (voisinage*voisinage)); // on classe les valeurs
				dst.at<uchar>(x, y) = voisins[(voisinage - 1) / 2 + 1]; // on choisit la valeur médiane
			}
		}
	}
	return dst;
}




Mat filtreMoyenNVG(Mat src, int voisinage){
	Mat dst = src.clone();

	if (voisinage % 2 != 1) return Mat();
	Rect roi = Rect(0, 0, voisinage, voisinage);
	int moyenne = 0;
	for (int x = 0; x < src.rows; x++){
		for (int y = 0; y < src.cols; y++){
			if (x< (voisinage - 1) / 2 || x>(src.rows - 1 - (voisinage - 1) / 2) || y< (voisinage - 1) / 2 || y>(src.cols - 1 - (voisinage - 1) / 2)) // pour le bord copier les mêmes valeurs des pixels
			{
				dst.at<uchar>(x, y) = src.at<uchar>(x, y);
			}
			else
			{
				moyenne = 0;
				// on centre le voisinage sur le pixel en cours
				roi.y = x - (voisinage - 1) / 2;
				roi.x = y - (voisinage - 1) / 2;
				Mat img_roi = src(roi);
				for (int i = 0; i < voisinage; i++){
					for (int j = 0; j < voisinage; j++){
						moyenne += img_roi.at<uchar>(i, j);
					}
				}
				moyenne /= voisinage*voisinage;
				dst.at<uchar>(x, y) = moyenne;
			}
		}
	}
	return dst;
}