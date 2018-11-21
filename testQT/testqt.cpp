
#include "testqt.h"


#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/video/background_segm.hpp>  
#include <opencv2/video/background_segm.hpp>
#include <Windows.h>
#include <QKeyEvent>
#include "traitement.h"


using namespace cv;
using namespace std;



static cv::Mat frame2; //image capturée
static cv::Mat frame;  //vidéo
static cv::Mat dessin; //image dessin
cv::Mat gray;
bool beginTraitement = false;
cv::Point cercle2, cercle1;
Vec3b intensity1;
Vec3b intensity2;
int blue1, blue2, green1, green2, red1, red2, lastX1,lastX2,lastY1,lastY2;

testQT::testQT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.b1, SIGNAL(clicked()), this, SLOT(testClick()));
	//connect(ui.b1, SIGNAL(clicked(), this, SLOT())
}

testQT::~testQT()
{


}

void testQT::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_R)
	{
		beginTraitement = true;
		Mat mask, hsv_image;
		//ui.label_res->settext("you pressed r");
		std::cout << " you pressed r, and the captured image has been saved " << std::endl;
		//frame = frame2.clone();
		
		//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
		
		Mat frameFiltered = frame2.clone();
		//frameFiltered = filtreMedianNVG(frame2, 3);
		//cvtColor(frameFiltered, gray, COLOR_BGR2HSV);
		intensity1 = frameFiltered.at<Vec3b>(300, 200);
		intensity2 = frameFiltered.at<Vec3b>(400, 200);
		//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frameFiltered.data, frameFiltered.cols, frameFiltered.rows, frameFiltered.step, QImage::Format_RGB888)));

		blue1 = intensity1.val[0];
		green1 = intensity1.val[1];
		red1 = intensity1.val[2];
		blue2 = intensity2.val[0];
		green2 = intensity2.val[1];
		red2 = intensity2.val[2];
		lastX1 = 200;
		lastX2 = 200;
		lastY1 = 300;
		lastY2 = 400;
		string ka = std::to_string(blue1) + " " + std::to_string(green1) + " " + std::to_string(red1) + "   :::  " + std::to_string(blue2) + " " + std::to_string(green2) + " " + std::to_string(red2);
		//QString qstr = QString::fromStdString(ka);



	}
}


bool myInRange(int low,int  high, int x)
{
	return ((x - high)*(x - low) <= 0);
}


void testQT::testClick()  {
	

	VideoCapture cap;
	
	dessin = imread("C:\\Users\\USER\\Documents\\Master2\\Vision\\image_blanche.jpg");
	cv::resize(dessin, dessin, cv::Size(521, 471));
	ui.label_res->setPixmap(QPixmap::fromImage(QImage(dessin.data, dessin.cols, dessin.rows, dessin.step, QImage::Format_RGB888)));
	cercle1 = Point(300, 200);
	cercle2 = Point(400, 200);
	
	Mat imgLines = Mat::zeros(dessin.size(), CV_8UC3);
	if(!cap.open(0)) return;
	while (1){
		//Mat dessin = frame;
		
		cap >> frame2;
		Mat img = frame2.clone();
		
		bool bSuccess = cap.read(frame2); // lire une nouvelle frame depuis la vidéo
		circle(frame2, Point2i(300, 200), 7, Scalar(0, 200, 500), 2, 3);
		circle(frame2, Point2i(400, 200), 7, Scalar(0, 200, 500), 2, 3);

		if (!bSuccess) //le cas d'un échec 
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}



		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				Vec3b v = frame2.at<Vec3b>(i, j);
				img.at<Vec3b>(i, j) = Vec3b(v[2], v[1], v[0]);
			}
		}
		//frame2 = img.clone();


		cv::resize(img, img, cv::Size(701, 461));
		ui.camera->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));
		//frame = frame2.clone();
		//Début Traitement 
		if (beginTraitement == true){
			//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frame2.data, frame2.cols, frame2.rows, frame2.step, QImage::Format_RGB888)));

		
			
				//ui.label_res->setText("kakouuche");
				Mat imgHSV;

				//cvtColor(frame2, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
				Scalar s;
				Mat imageRes = img.clone();
				
				//Vec3b v1 = imageRes.at<Vec3b>(300, 200);
				//Mat imgThresholded;
				imageRes = filtreMedianNVG(imageRes, 3);

				vector<int> pixelsP2;
				vector<int> pixelsP1;
				
				int iP1 = 0;
				int iP2 = 0;
				for (int i = 0; i < imageRes.rows; i++){
					for (int j = 0; j < imageRes.cols; j++){
						Vec3b v = imageRes.at<Vec3b>(i, j);
						if ((v[0] <= blue1 + 10) && (v[1] <= green1 + 10) && (v[2] <= red1 + 10) && (v[0] >= blue1 - 10) && (v[1] >= green1 - 10) && (v[2] >= red1 - 10)){
							pixelsP1.push_back(i);
							pixelsP1.push_back(j);
						}
						if ((v[0] <= blue2 + 10) && (v[1] <= green2 + 10) && (v[2] <= red2 + 10) && (v[0] >= blue2 - 10) && (v[1] >= green2 - 10) && (v[2] >= red2 - 10)){
							pixelsP2.push_back(i);
							pixelsP2.push_back(j);
						}

					}
				}
				
				double x1 = 0;
				double y1 = 0;
				for (int i = 0; i < pixelsP1.size(); i++){
					if (i % 2){
						x1 = x1 + (pixelsP1[i]);
					}
					else{
						y1 = y1 + (pixelsP1[i]);
					}
				}
				
				x1 = x1 / (pixelsP1.size() / 2);
				y1 = y1 / (pixelsP1.size() / 2);

				double x2 = 0;
				double y2 = 0;
				for (int i = 0; i < pixelsP2.size(); i++){
					if (i % 2){
						x2 = x2 + (pixelsP2[i]);
					}
					else{
						y2 = y2 + (pixelsP2[i]);
					}
				}
				Mat imgLine;

				x2 = x2 / (pixelsP2.size() / 2);
				y2 = y2 / (pixelsP2.size() / 2);
				int px1 = ceil(x1);
				int py1 = ceil(y1);
				int px2 = ceil(x2);
				int py2 = ceil(y2);

				if (px1 != lastX1 && py1 != lastY1){
					line(imgLine, Point(px1, py1), Point(lastX1, lastY1), Scalar(0, 0, 255), 2);
				}

				dessin = dessin + imgLine;
				ui.label_res->setPixmap(QPixmap::fromImage(QImage(dessin.data, dessin.cols, dessin.rows, dessin.step, QImage::Format_RGB888)));






			}
			cout << "something" << endl;
			if (waitKey(60) == 27) //
			{
				cout << "esc key is pressed by user" << endl;
				break;
			}
		
	}

	cap.release();
	return;
}

