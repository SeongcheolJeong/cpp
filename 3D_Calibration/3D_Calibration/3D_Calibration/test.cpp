#ifdef _DEBUG
#pragma comment(lib, "opencv_world341d.lib")
#else
#pragma comment(lib, "opencv_world341.lib")
#endif

#include <opencv2\imgcodecs.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\calib3d.hpp>
#include <vector>
#include <iostream>


using namespace cv;
using namespace std;

int main()
{
	vector<vector<Point3d>> object_points;
	vector<vector<Point2d>> image_points;

	Size image_sz = Size(10, 10);

	Mat camera_matrix = (Mat_<double>(3, 3) << 1, 0, 0, 0, 1, 0, 0, 0, 1);
	cout<<camera_matrix;
	Mat dist_coeff;
	vector<Mat> rvecs;
	vector<Mat> tvecs;



	object_points = { { {-1, -1, 0}, {-1, 1, 0}, {1, -1, 0}, {1, 1, 0} }, { { 0, -1, 0 },{ 0, 1, 0 },{ 2, -1, 0 },{ 2, 1, 0 } } };  //x, y, z
	image_points = { { { -1, -1},{ -1, 1},{ 1, -1},{ 1, 1} },{ { 0, -1},{ 0, 1},{ 2, -1},{ 2, 1} } };  //x, y, z


	calibrateCamera(object_points, image_points, image_sz, camera_matrix, dist_coeff, rvecs, tvecs);
	


	getchar();

	return 0;
}