//
//  main.cpp
//  Superposition_2_image
//
//  Created by Abigail Aldridge on 8/18/15.
//  Copyright (c) 2015 Abigail Aldridge. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>



void superpose (IplImage* img1, IplImage* img2, IplImage* dst)
{
    cvAddWeighted (img1, 0.5, img2, 0.5, 0.0, dst);

//    uchar *p_dst, *p_1, *p_2, *line;
//    assert (img1->depth == IPL_DEPTH_8U && img1->nChannels == 1 && img2->depth == IPL_DEPTH_8U && img2->nChannels == 1);
//    assert (img1->width == img2->width);
//    assert (img1->height == img2->height);
//    
//    for (y = 0; y < dst->height; ++y)
//    {
//        for (x = 0; x < dst->width; ++x)
//        {
//            p_1 = cvPtr2D (img1, y, x, NULL);
//            p_2 = cvPtr2D (img2, y, x, NULL);
//            p_dst  = cvPtr2D (dst , y, x, NULL);
//            
//            *p_dst  = *p_1 / 2 + *p_2 / 2;
//        }
//    }
}

void fix_origin (IplImage* img)
{
    if (img->origin == IPL_ORIGIN_BL)
    {
        cvConvertImage(img, img, CV_CVTIMG_FLIP);
        img->origin = IPL_ORIGIN_TL;
    }
}

/**
 * Ce programme prend deux arguments dont un optionnel:
 * IMAGE:     l'image à inverser
 * SAVE_PATH: (optionnel) l'image dans laquelle sauvegarder le résultat
 */
int main (int argc, char* argv[])
{
    IplImage* img1 = NULL;
    IplImage* img2 = NULL;
    IplImage* dst = NULL;
    const char* img1_path = NULL;
    const char* img2_path = NULL;
    const char* window_title = "Supperpose";
    
    if (argc < 3)
    {
        fprintf (stderr, "usage: %s IMG1 IMG2\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    img1_path = argv[1];
    img2_path = argv[2];
    
    
    if (!(img1 = cvLoadImage (img1_path, CV_LOAD_IMAGE_GRAYSCALE)))
    {
        fprintf (stderr, "couldn't open image file: %s\n", img1_path);
        return EXIT_FAILURE;
    }
    
    if (!(img2 = cvLoadImage (img2_path, CV_LOAD_IMAGE_GRAYSCALE)))
    {
        fprintf (stderr, "couldn't open image file: %s\n", img2_path);
        return EXIT_FAILURE;
    }
    
    fix_origin(img1);
    fix_origin(img2);
    
    dst = cvCreateImage (cvGetSize (img1), IPL_DEPTH_8U, 1);
    
    superpose(img1, img2, dst);
    
    cvNamedWindow (window_title, CV_WINDOW_AUTOSIZE);
    cvShowImage   (window_title, dst);
    cvWaitKey (0);
    cvDestroyAllWindows ();
    
    cvReleaseImage(&img1);
    cvReleaseImage(&img2);
    cvReleaseImage(&dst);
    
    return EXIT_SUCCESS;
}
