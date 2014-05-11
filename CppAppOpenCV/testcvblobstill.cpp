/* 
 * File:        testcvblobstill.cpp
 * Author:      Gary Stafford
 * Description: Track blobs using OpenCV and cvBlob
 * Created:     February 3, 2013
 * Revised:     May 4, 2014
 */

#include <cv.h>
#include <highgui.h>
#include <cvblob.h>

#include "testcvblobstill.hpp"
#include "imageParams.h"

using namespace cvb;
using namespace std;

// Test 3: OpenCV and cvBlob (w/ webcam feed)

int DetectBlobsNoStillImage(struct imageParams params) {
    /// Variables /////////////////////////////////////////////////////////
    CvSize imgSize;
    IplImage *image, *segmentated, *labelImg;
    CvBlobs blobs;

    unsigned int result = 0;
    ///////////////////////////////////////////////////////////////////////

    image = cvLoadImage("colored_balls.jpg");

    if (image == NULL) {
        cout << endl << "No image found?";
        return -1;
    }

    imgSize = cvGetSize(image);
    cout << endl << "Width (pixels): " << image->width;
    cout << endl << "Height (pixels): " << image->height;
    cout << endl << "Channels: " << image->nChannels;
    cout << endl << "Bit Depth: " << image->depth;
    cout << endl << "Image Data Size (kB): "
            << image->imageSize / 1024 << endl << endl;

    segmentated = cvCreateImage(imgSize, 8, 1);

    //cvInRangeS(image, CV_RGB(155, 0, 0), CV_RGB(255, 130, 130), segmentated);
    cvInRangeS(image, CV_RGB(params.lowR, params.lowG, params.lowB),
            CV_RGB(params.highR, params.highG, params.highB), segmentated);

    labelImg = cvCreateImage(cvGetSize(image), IPL_DEPTH_LABEL, 1);

    result = cvLabel(segmentated, labelImg, blobs);

    cvFilterByArea(blobs, 500, 1000000);

    cout << endl << "Blob Count: " << blobs.size();
    cout << endl << "Pixels Labeled: " << result << endl << endl;

    cvReleaseBlobs(blobs);

    cvReleaseImage(&labelImg);
    cvReleaseImage(&segmentated);
    cvReleaseImage(&image);

    return 0;
}

// Test 4: OpenCV and cvBlob (w/o webcam feed)

int DetectBlobsShowStillImage(struct imageParams params) {
    /// Variables /////////////////////////////////////////////////////////
    CvSize imgSize;
    IplImage *image, *frame, *segmentated, *labelImg, *colorRange;
    CvBlobs blobs;

    unsigned int result = 0;
    bool quit = false;
    ///////////////////////////////////////////////////////////////////////

    cvNamedWindow("Processed Image", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Processed Image", 750, 100);
    cvNamedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Original Image", 100, 100);
    cvNamedWindow("Color Range", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Color Range", 100, 600);

    image = cvLoadImage("colored_balls.jpg");

    if (image == NULL) {
        cout << endl << "No image found?";
        return -1;
    }

    imgSize = cvGetSize(image);
    cout << endl << "Width (pixels): " << image->width;
    cout << endl << "Height (pixels): " << image->height;
    cout << endl << "Channels: " << image->nChannels;
    cout << endl << "Bit Depth: " << image->depth;
    cout << endl << "Image Data Size (kB): "
            << image->imageSize / 1024 << endl << endl;

    frame = cvCreateImage(imgSize, image->depth, image->nChannels);

    cvConvertScale(image, frame, 1, 0);

    segmentated = cvCreateImage(imgSize, 8, 1);

    cvInRangeS(image, CV_RGB(params.lowR, params.lowG, params.lowB),
            CV_RGB(params.highR, params.highG, params.highB), segmentated);
    cvSmooth(segmentated, segmentated, CV_MEDIAN, 7, 7);

    labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);

    result = cvLabel(segmentated, labelImg, blobs);
    cvFilterByArea(blobs, 500, 1000000);
    cvRenderBlobs(labelImg, blobs, frame, frame,
            CV_BLOB_RENDER_BOUNDING_BOX | CV_BLOB_RENDER_TO_STD, 1.);

    cvShowImage("Original Image", frame);
    cvShowImage("Processed Image", segmentated);
    
    // Show color range values in separate window
    colorRange = cvCreateImage(cvSize(200,100),8,3);  
    cvZero(colorRange);  
    cvRectangle(colorRange, cvPoint(0,0), cvPoint(100, 100), 
            CV_RGB(params.lowR, params.lowG, params.lowB), CV_FILLED);  
    cvRectangle(colorRange, cvPoint(100,0), cvPoint(200, 100), 
            CV_RGB(params.highR, params.highG, params.highB), CV_FILLED);  
    cvShowImage("Color Range", colorRange);
    
    while (!quit) {
        char k = cvWaitKey(10)&0xff;
        switch (k) {
            case 27:
            case 'q':
            case 'Q':
                quit = true;
                break;
        }
    }
    cvReleaseBlobs(blobs);

    cvReleaseImage(&labelImg);
    cvReleaseImage(&segmentated);
    cvReleaseImage(&frame);
    cvReleaseImage(&image);
    cvReleaseImage(&colorRange);

    cvDestroyAllWindows();

    return 0;
}