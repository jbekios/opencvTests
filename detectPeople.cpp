// This file is part of OpenCV project.
// It is subject to the license terms in the LICENSE file found in the top-level directory
// of this distribution and at http://opencv.org/license.html

#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

#include <iostream>
#include <iomanip>

#include "Detector.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    Detector detector;
    Mat imagen;
    imagen = imread("/home/jbekios/CODE/opencvTests/personas.png");
    //detector.toggleMode();
    cout << detector.modeName() << endl;

    vector<Rect> found = detector.detect(imagen);
    for (vector<Rect>::iterator i = found.begin(); i != found.end(); ++i)
    {
        Rect &r = *i;
        cout << r << endl;
        detector.adjustRect(r);
        rectangle(imagen, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
    }
    imshow("People detector", imagen);
    waitKey(0);

    return 0;
}