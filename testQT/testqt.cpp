
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
int h1, h2, s1, s2, v1, v2, lastX1,lastX2,lastY1,lastY2, r1, r2, g1, g2, b1, b2,r,g,b;
cv::Mat res;
cv::Mat res2;
bool drawing = false, gomme = false;


testQT::testQT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.b1, SIGNAL(clicked()), this, SLOT(testClick()));
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(visualisationC1()));
}

testQT::~testQT()
{


}

void testQT::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_R)
	{

		beginTraitement = true;
		drawing = true;
		gomme = false;
		Mat mask, hsv_image;
		//ui.label_res->settext("you pressed r");
		//std::cout << " you pressed r, and the captured image has been saved " << std::endl;
		//frame = frame2.clone();
		
		//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888)));
		
		Mat frameFiltered = frame2.clone();
		r1 = frameFiltered.at<Vec3b>(Point(300, 200)).val[0];
		r2 = frameFiltered.at<Vec3b>(Point(300, 200)).val[1];
		g1 = frameFiltered.at<Vec3b>(Point(300, 200)).val[2];
		g2 = frameFiltered.at<Vec3b>(Point(300, 200)).val[0];
		b1 = frameFiltered.at<Vec3b>(Point(300, 200)).val[1];
		b2 = frameFiltered.at<Vec3b>(Point(300, 200)).val[2];
		r = ceil((r1 + r2) / 2);
		g = ceil((g1 + g2) / 2);
		b = ceil((b1 + b2) / 2);


		//frameFiltered = filtreMedianNVG(frame2, 3);
		cvtColor(frameFiltered, gray, COLOR_BGR2HSV);
		intensity1 = gray.at<Vec3b>(Point(300, 200));
		intensity2 = gray.at<Vec3b>(Point(400, 200));

		circle(frameFiltered, Point(300, 50), 20, frameFiltered.at<Vec3b>(Point(300, 200)), -1);
		circle(frameFiltered, Point(400, 50), 20, frameFiltered.at<Vec3b>(Point(400, 200)), -1);
		//imshow("filtered", frameFiltered);

		//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frameFiltered.data, frameFiltered.cols, frameFiltered.rows, frameFiltered.step, QImage::Format_RGB888)));

		h1 = intensity1.val[0];
		s1 = intensity1.val[1];
		v1 = intensity1.val[2];
		h2 = intensity2.val[0];
		s2 = intensity2.val[1];
		v2 = intensity2.val[2];
		lastX1 = 300;
		lastX2 = 400;
		lastY1 = 200;
		lastY2 = 200;
		//string ka = std::to_string(blue1) + " " + std::to_string(green1) + " " + std::to_string(red1) + "   :::  " + std::to_string(blue2) + " " + std::to_string(green2) + " " + std::to_string(red2);
		//QString qstr = QString::fromStdString(ka);

	}

	else
		if (event->key() == Qt::Key_H)
		{

			beginTraitement = true;
			drawing = false;
			gomme = true;
		}
}


bool myInRange(int low,int  high, int x)
{
	return ((x - high)*(x - low) <= 0);
}


void testQT::testClick()  {
	int iter = 0;

	Mat roi = imread("C:\\Users\\USER\\Documents\\Master2\\Vision\\pencil.jpg");
	Mat roi2 = imread("C:\\Users\\USER\\Documents\\Master2\\Vision\\eraser.jpg");

	VideoCapture cap;
	//dessin = Mat::zeros(ka.size(), CV_8UC3);
	Mat dessin = imread("C:\\Users\\USER\\Documents\\Master2\\Vision\\image_blanche.jpg");
	cv::resize(dessin, dessin, cv::Size(541, 471));    
	//ui.label_res->setPixmap(QPixmap::fromImage(QImage(dessin.data, dessin.cols, dessin.rows, dessin.step, QImage::Format_RGB888)));
	cercle1 = Point(300, 200);
	cercle2 = Point(400, 200);
	
	//Mat imgLines = Mat::zeros(dessin.size(), CV_8UC3);
	if(!cap.open(0)) return;

	//Mat imgTmp;
	//cap.read(imgTmp);
	
	//Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);


	while (1){
		//Mat dessin = frame;
		
		cap >> frame2;
		Mat img = frame2.clone();
		
		bool bSuccess = cap.read(frame2); // lire une nouvelle frame depuis la vidéo

		if (!bSuccess) //le cas d'un échec 
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		
		Mat temp = frame2.clone();
		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				temp.at<Vec3b>(i, j) = frame2.at<Vec3b>(i, img.cols-j-1);
			}
		}
		frame2 = temp.clone();
		img = temp.clone();
		for (int i = 0; i < img.rows; ++i)
		{
			for (int j = 0; j < img.cols; ++j)
			{
				Vec3b v = frame2.at<Vec3b>(i, j);
				img.at<Vec3b>(i, j) = Vec3b(v[2], v[1], v[0]);
				frame2.at<Vec3b>(i, j) = Vec3b(v[2], v[1], v[0]);
			}
		}
		circle(frame2, Point(300, 200), 7, Scalar(0, 200, 500), 2, 3);
		circle(frame2, Point(400, 200), 7, Scalar(0, 200, 500), 2, 3);
		//frame2 = img.clone();


		cv::resize(frame2, frame2, cv::Size(591, 481)); 
		if (beginTraitement == false){
			ui.camera->setPixmap(QPixmap::fromImage(QImage(frame2.data, frame2.cols, frame2.rows, frame2.step, QImage::Format_RGB888)));
		}
		//frame = frame2.clone();
		//Début Traitement 
		if (beginTraitement == true){
			//cout << "Commencement ..." << endl;
			//ui.label_res->setPixmap(QPixmap::fromImage(QImage(frame2.data, frame2.cols, frame2.rows, frame2.step, QImage::Format_RGB888)));
			Mat dessintmp = dessin.clone();

			iter++;
			
				//ui.label_res->setText("kakouuche");
				Mat imgHSV;
				//cvtColor(img, img, COLOR_RGB2HSV);
				//cvtColor(img, img, COLOR_RGB2BGR);
				cvtColor(img, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
				//cvtColor(img, img, COLOR_BGR2RGB);
				Scalar s;
				Mat imageRes = imgHSV.clone();
				
				//Vec3b v1 = imageRes.at<Vec3b>(300, 200);
				//Mat imgThresholded;
				//imageRes = filtreMedianNVG(imageRes, 3);

				vector<int> pixelsP2;
				vector<int> pixelsP1;
				//-10<h<+10
				//s*0.6<s<255
				//20<v<255
			
				int iP1 = 0;
				int iP2 = 0;
				res = Mat(imageRes.rows, imageRes.cols, CV_8UC1);
				res2 = Mat(imageRes.rows, imageRes.cols, CV_8UC1);

				for (int i = 0; i < imageRes.rows; i++){
					for (int j = 0; j < imageRes.cols; j++){
						res.at<uchar>(i, j) = 0;
						res2.at<uchar>(i, j) = 0;
						Vec3b v = imageRes.at<Vec3b>(i, j);
						if ((v[0] <= h1 + 8) && (v[1] <= 255) && (v[2] <= 255) && (v[0] >= h1 - 8) && (v[1] >= s1*0.6) && (v[2] >= 20)){
							res.at<uchar>(i, j) = 255;
							//pixelsP1.push_back(i);
							//pixelsP1.push_back(j);
						}
						else
						if ((v[0] <= h2 + 8) && (v[1] <= 255) && (v[2] <= 255) && (v[0] >= h2 - 8) && (v[1] >= s2*0.6) && (v[2] >= 20)){
							//pixelsP2.push_back(i);
							//pixelsP2.push_back(j);
							res2.at<uchar>(i, j) = 255;
						}
							
					}
				}
				//imshow("src", img);
				//cv::resize(res, res, Size(280, 180));
				//cv::resize(res2, res2, Size(280, 180));
				//imshow("gray", res);
				//imshow("gray2", res2);
				erode(res, res, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				erode(res2, res2, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				dilate(res, res, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				dilate(res2, res2, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));

				/*erode(res, res, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				erode(res2, res2, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				dilate(res, res, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));
				dilate(res2, res2, getStructuringElement(MORPH_ELLIPSE, Size(3, 3)));*/
				imshow("grayErode", res);
				imshow("grayErode2", res2);
				for (int i = 0; i < res.rows; i++){
					for (int j = 0; j < res.cols; j++){
						uchar v = res.at<uchar>(i, j);
						if (v){
							pixelsP1.push_back(i);
							pixelsP1.push_back(j);
						}
					}
				}
				for (int i = 0; i < res2.rows; i++){
					for (int j = 0; j < res2.cols; j++){
						uchar v = res2.at<uchar>(i, j);
						if (v){
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

				double x = x1 - x2;
				double y = y1 - y2;
				double distance = pow(x, 2) + pow(y, 2);
				distance = sqrt(distance);




				//cout << "Distance = " << distance << "\n" << endl;


				if (distance <= 70.0){

						//Rect WhereRec(0, 0, roi.cols, roi.rows);
					//dessin = imread("C:\\Users\\USER\\Documents\\Master2\\Vision\\image_blanche.jpg");
					if (drawing == true){
						//cout << "Dessiner .. " << endl;
						roi.copyTo(dessintmp(Rect(px1, py1, roi.cols, roi.rows)));

						line(dessin, Point(px1, py1), Point(lastX1, lastY1), Scalar(0,0,0), 2); //Dessiner la tragéctoire en bleu 
						//line(img, Point(px1, py1), Point(px2, py2), Scalar(255, 0, 0), 2); //Dessiner la distance en bleu 
						ui.label_res->setPixmap(QPixmap::fromImage(QImage(dessintmp.data, dessintmp.cols, dessintmp.rows, dessintmp.step, QImage::Format_RGB888)));
					}
						if (gomme == true){
							cout << "bidayaaat al mim7aaat " << endl;
							roi2.copyTo(dessintmp(Rect(px1, py1, roi2.cols, roi2.rows)));
							line(dessin, Point(px1, py1), Point(lastX1, lastY1), Scalar(255, 255, 255), 2);
							ui.label_res->setPixmap(QPixmap::fromImage(QImage(dessintmp.data, dessintmp.cols, dessintmp.rows, dessintmp.step, QImage::Format_RGB888)));

						}

				}
				lastX1 = px1; lastX2 = px2;
				lastY1 = py1; lastY2 = py2;
				//if (px1 > 0 && px2 > 0 && px1 < 521 && px2 < 521 && py1 > 0 && py2 > 0 && py1 < 471 && py2 < 471){
					
					//roi.copyTo(dessintmp(Rect(px2, py2, roi.cols, roi.rows)));

					//Rect WhereRec(px1, py1, roi.cols, roi.rows);
					//roi.copyTo(dessintmp(WhereRec));
					//Rect blanc(px1, py1, 0, 0);
					//dessin(roi).setTo(blanc));
					
					//line(dessin, Point(px2, py2), Point(lastX2, lastY2), Scalar(r2, g2, b2), 2); //Dessiner la tragéctoire en bleu
					
				//}
				//else{
					//line(dessin, Point(px1, py1), Point(px2, py2), Scalar(255, 0, 0), 2);		//Dessiner la distance en rouge

				//}

					
				//img = img + imgLines;
				cv::resize(img, img, cv::Size(591, 481));
				ui.camera->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));





			}
			
			//cout << "something" << endl;
			if (waitKey(60) == 27) //
			{
				cout << "esc key is pressed by user" << endl;
				break;
			}
		
	}

	cap.release();
	return;
}

