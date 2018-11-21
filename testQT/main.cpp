#include "testqt.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>  
#include <opencv2/video/background_segm.hpp>
#include <Windows.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	testQT w;
	w.show();
	return a.exec();





}
