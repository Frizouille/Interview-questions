//
//  main.cpp
//  Normalize_hist
//
//  Created by Abigail Aldridge on 8/18/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>


#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv2/core/core.hpp"

using namespace std;
using namespace cv;


void normalize_gray (IplImage* img)
{
    double min, max, alpha, beta;
    
    assert (img->depth == IPL_DEPTH_8U);
    assert (img->nChannels == 1);
    
    cvMinMaxLoc (img, &min, &max, NULL, NULL, NULL);
    
    alpha = 255.0 / (max - min);
    beta  = -min * alpha;
    cvScale (img, img, alpha, beta);
}

void showHistogram(IplImage* image){
    
    
    int histSize = 256;             // number of bins
    Mat img = cvarrToMat(image);
    vector<Mat> bgr_planes(3);       // array for storing the histograms
    
    split( img, bgr_planes );
    
    /// Set the ranges ( for B,G,R) )
    float range[] = { 0, 256 } ;
    const float* histRange = { range };

    bool uniform = true; bool accumulate = false;
    
    Mat b_hist, g_hist, r_hist;
    
    /// Compute the histograms:
    calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
    calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

    // Draw the histograms for B, G and R
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound( (double) hist_w/histSize );
    
    Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

    /// Normalize the result to [ 0, histImage.rows ]
    normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
    normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

    /// Draw for each channel
    for( int i = 1; i < histSize; i++ )
    {
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
             Scalar( 255, 0, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
             Scalar( 0, 255, 0), 2, 8, 0  );
        line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
             Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
             Scalar( 0, 0, 255), 2, 8, 0  );
    }

    /// Display
    namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE );
    imshow("calcHist Demo", histImage );
    
    waitKey(0);

}


int main(int argc, const char * argv[]) {
    
    IplImage* img = NULL;
    const char* src_path = NULL;
    const char* window_title = "Normlize";

    
    if (argc < 2)
    {
        fprintf (stderr, "usage: %s IMAGE [SAVE_PATH]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    src_path = argv[1];
    
    
    if (!(img = cvLoadImage (src_path, CV_LOAD_IMAGE_GRAYSCALE)))
    {
        fprintf (stderr, "couldn't open image file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    

    showHistogram(img);
    
    normalize_gray(img);
    
    showHistogram(img);
    
    cvNamedWindow (window_title, CV_WINDOW_AUTOSIZE);
    cvShowImage   (window_title, img);
    cvWaitKey (0);
    cvDestroyAllWindows ();
    
    
    cvReleaseImage(&img);
    return EXIT_SUCCESS;
}
