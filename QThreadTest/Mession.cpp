#include "Mession.h"
/*
Mession::Mession(QObject *parent)
	: QObject(parent)
{
}
*/
Mession::Mession()
{
}
Mession::~Mession()
{
}

void Mession::templateMatch(QImage  srcImg, QImage templateImg)
{
	QImage  outputImg;
	QImage  outputDrawRectangleImg;
	using namespace cv;
	ConvertMatQImage cvt;
	
	Mat tmp;
	Mat src;
	Mat result;
	Mat rectResult; //原图中包含的矩形

	//类型转换
	cvt.qImageToMat(&srcImg, &src);
	cvt.qImageToMat(&templateImg, &tmp);
	//cvt.qImageToMat(outputImg, &result);
	//src.copyTo(rectResult);	//原图复制
	cvt.qImageToMat(&srcImg, &rectResult);
	namedWindow("src", WINDOW_AUTOSIZE);
	imshow("src", src);
	namedWindow("template", WINDOW_AUTOSIZE);
	imshow("template", tmp);

	Point minLoc;
	double minVal;
	//模板匹配
	matchTemplate(src, tmp, result, TM_SQDIFF_NORMED);
	namedWindow("result", WINDOW_AUTOSIZE);
	imshow("result", result);
	//std::cout << result.size() << std::endl;

	minMaxLoc(result, &minVal, 0, &minLoc, 0);

	Point result_rect = minLoc;
	Size result_size = tmp.size();

	rectangle(rectResult, Rect(minLoc, tmp.size()), Scalar(0, 100, 255), 1, 8, 0);
	namedWindow("resultDraw", WINDOW_AUTOSIZE);
	imshow("result", rectResult);
	//*outputImg = cvt.matToQImage(&result);
	//*outputDrawRectangleImg = cvt.matToQImage(&rectResult);
	emit sendResult(outputImg, outputDrawRectangleImg);
}
