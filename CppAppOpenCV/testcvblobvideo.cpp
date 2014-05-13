/* 
 * File:        testcvblobvideo.cpp
 * Author:      Gary Stafford
 * Description: Track blobs using OpenCV and cvBlob
 * Created:     February 3, 2013
 * Revised:     May 4, 2014
 */

#include <cv.h>
#include <highgui.h>
#include <cvblob.h>

#include "testcvblobvideo.hpp"
#include "imageParams.h"

using namespace cvb;
using namespace std;

const int webcamID = 1;

// Test 5: Blob Tracking (w/ webcam feed)

int DetectBlobsNoVideo(struct imageParams params) {
    /// Variables /////////////////////////////////////////////////////////
    CvCapture *capture;
    CvSize imgSize;

    IplImage *image, *frame, *segmentated, *labelImg;
    int picWidth, picHeight;

    CvTracks tracks;
    CvBlobs blobs;
    CvBlob* blob;

    unsigned int result = 0;

    bool quit = false;
    ///////////////////////////////////////////////////////////////////////

    capture = cvCaptureFromCAM(webcamID);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, params.captureWidth);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, params.captureHeight);
    cvGrabFrame(capture);
    image = cvRetrieveFrame(capture);

    if (image == NULL) {
        return -1;
    }

    imgSize = cvGetSize(image);
    cout << endl << "Width (pixels): " << image->width;
    cout << endl << "Height (pixels): " << image->height << endl << endl;

    frame = cvCreateImage(imgSize, image->depth, image->nChannels);

    while (!quit && cvGrabFrame(capture)) {
        image = cvRetrieveFrame(capture);

        cvConvertScale(image, frame, 1, 0);

        segmentated = cvCreateImage(imgSize, 8, 1);

        cvInRangeS(image, CV_RGB(params.lowR, params.lowG, params.lowB),
                CV_RGB(params.highR, params.highG, params.highB), segmentated);

        //Can experiment either or both
        cvSmooth(segmentated, segmentated, CV_MEDIAN, 7, 7);
        cvSmooth(segmentated, segmentated, CV_GAUSSIAN, 9, 9);

        labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);

        result = cvLabel(segmentated, labelImg, blobs);
        cvFilterByArea(blobs, 500, 1000000);
        cvRenderBlobs(labelImg, blobs, frame, frame, 0x000f, 1.);
        cvUpdateTracks(blobs, tracks, 200., 5);
        cvRenderTracks(tracks, frame, frame, 0x000f, NULL);

        picWidth = frame->width;
        picHeight = frame->height;

        if (cvGreaterBlob(blobs)) {
            blob = blobs[cvGreaterBlob(blobs)];

            cout << "Blobs found: " << blobs.size() << endl;
            cout << "Pixels labeled: " << result << endl;
            cout << "center-x: " << blob->centroid.x
                    << "   center-y: " << blob->centroid.y
                    << endl;
            cout << "offset-x: " << ((picWidth / 2)-(blob->centroid.x))
                    << "   offset-y: " << (picHeight / 2)-(blob->centroid.y)
                    << endl;
            cout << "\n";
        }

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

    cvDestroyAllWindows();

    cvReleaseCapture(&capture);

    return 0;
}

// Test 6: Blob Tracking (w/o webcam feed)

int DetectBlobsShowVideo(struct imageParams params) {
    /// Variables /////////////////////////////////////////////////////////
    CvCapture *capture;
    CvSize imgSize;

    IplImage *image, *frame, *segmentated, *labelImg, *colorRange;
    CvPoint pt1, pt2, pt3, pt4, pt5, pt6;
    CvScalar red, green, blue;
    int picWidth, picHeight, thickness;

    CvTracks tracks;
    CvBlobs blobs;
    CvBlob* blob;

    unsigned int result = 0;

    bool quit = false;
    ///////////////////////////////////////////////////////////////////////

    cvNamedWindow("Processed Video Frames", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Processed Video Frames", 600, 100);
    cvNamedWindow("Webcam Preview", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Webcam Preview", 100, 100);
    cvNamedWindow("Color Range", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("Color Range", 100, 600);

    capture = cvCaptureFromCAM(webcamID);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, params.captureWidth);
    cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, params.captureHeight);
    cvGrabFrame(capture);
    image = cvRetrieveFrame(capture);

    if (image == NULL) {
        return -1;
    }

    imgSize = cvGetSize(image);
    cout << endl << "Width (pixels): " << image->width;
    cout << endl << "Height (pixels): " << image->height << endl << endl;

    frame = cvCreateImage(imgSize, image->depth, image->nChannels);

    while (!quit && cvGrabFrame(capture)) {
        image = cvRetrieveFrame(capture);
        cvFlip(image, image, 1);

        cvConvertScale(image, frame, 1, 0);

        segmentated = cvCreateImage(imgSize, 8, 1);

        cvInRangeS(image, CV_RGB(params.lowR, params.lowG, params.lowB),
                CV_RGB(params.highR, params.highG, params.highB), segmentated);

        //Can experiment either or both
        cvSmooth(segmentated, segmentated, CV_MEDIAN, 7, 7);
        cvSmooth(segmentated, segmentated, CV_GAUSSIAN, 9, 9);

        labelImg = cvCreateImage(cvGetSize(frame), IPL_DEPTH_LABEL, 1);

        result = cvLabel(segmentated, labelImg, blobs);
        cvFilterByArea(blobs, 500, 1000000);
        cvRenderBlobs(labelImg, blobs, frame, frame, CV_BLOB_RENDER_COLOR, 0.5);
        cvUpdateTracks(blobs, tracks, 200., 5);
        cvRenderTracks(tracks, frame, frame, CV_TRACK_RENDER_BOUNDING_BOX, NULL);

        red = CV_RGB(250, 0, 0);
        green = CV_RGB(0, 250, 0);
        blue = CV_RGB(0, 0, 250);

        thickness = 1;
        picWidth = frame->width;
        picHeight = frame->height;

        pt1 = cvPoint(picWidth / 2, 0);
        pt2 = cvPoint(picWidth / 2, picHeight);
        cvLine(frame, pt1, pt2, red, thickness);

        pt3 = cvPoint(0, picHeight / 2);
        pt4 = cvPoint(picWidth, picHeight / 2);
        cvLine(frame, pt3, pt4, red, thickness);

        cvShowImage("Webcam Preview", frame);
        cvShowImage("Processed Video Frames", segmentated);

        // Show color range values in separate window
        colorRange = cvCreateImage(cvSize(200, 100), 8, 3);
        cvZero(colorRange);
        cvRectangle(colorRange, cvPoint(0, 0), cvPoint(100, 100),
                CV_RGB(params.lowR, params.lowG, params.lowB), CV_FILLED);
        cvRectangle(colorRange, cvPoint(100, 0), cvPoint(200, 100),
                CV_RGB(params.highR, params.highG, params.highB), CV_FILLED);
        cvShowImage("Color Range", colorRange);

        if (cvGreaterBlob(blobs)) {
            blob = blobs[cvGreaterBlob(blobs)];
            pt5 = cvPoint(picWidth / 2, picHeight / 2);
            pt6 = cvPoint(blob->centroid.x, blob->centroid.y);
            cvLine(frame, pt5, pt6, green, thickness);
            cvCircle(frame, pt6, 3, green, 2, CV_FILLED, 0);

            cvShowImage("Webcam Preview", frame);
            cvShowImage("Processed Video Frames", segmentated);

            cout << "Blobs found: " << blobs.size() << endl;
            cout << "Pixels labeled: " << result << endl;
            cout << "center-x: " << blob->centroid.x
                    << "   center-y: " << blob->centroid.y
                    << endl;
            cout << "offset-x: " << ((picWidth / 2)-(blob->centroid.x))
                    << "   offset-y: " << (picHeight / 2)-(blob->centroid.y)
                    << endl;
            cout << "\n";
        }

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

    cvReleaseCapture(&capture);

    return 0;
}
