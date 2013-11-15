/* 
 * File:        main.cpp
 * Author:      Gary Stafford
 * Description: Program entry point
 * Created:     February 3, 2013
 */

#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>

#include "testfps.hpp"
#include "testcvblob.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int captureMethod = 0;
    int captureWidth = 0;
    int captureHeight = 0;

    if (argc == 4) { // user input parameters with call
        captureMethod = strtol(argv[1], NULL, 0);
        captureWidth = strtol(argv[2], NULL, 0);
        captureHeight = strtol(argv[3], NULL, 0);

    } else { // user did not input parameters with call
        cout << endl << "Demonstrations/Tests: " << endl;
        cout << endl << "(1) Test OpenCV - Show Webcam" << endl;
        cout << endl << "(2) Test OpenCV - No Webcam" << endl;
        cout << endl << "(3) Test cvBlob - Show Image" << endl;
        cout << endl << "(4) Test cvBlob - No Image" << endl;
        cout << endl << "(5) Test Blob Tracking - Show Webcam" << endl;
        cout << endl << "(6) Test Blob Tracking - No Webcam" << endl;
        cout << endl << "Input test # (1-6): ";
        cin >> captureMethod;

        // test 3 and 4 don't require width and height parameters
        if (captureMethod != 3 && captureMethod != 4) {
            cout << endl << "Input capture width (pixels): ";
            cin >> captureWidth;
            cout << endl << "Input capture height (pixels): ";
            cin >> captureHeight;
            cout << endl;

            if (!captureWidth > 0) {
                cout << endl << "Width value incorrect" << endl;
                return -1;
            }

            if (!captureHeight > 0) {
                cout << endl << "Height value incorrect" << endl;
                return -1;
            }
        }
    }

    switch (captureMethod) {
        case 1:
            TestFpsShowVideo(captureWidth, captureHeight);
        case 2:
            TestFpsNoVideo(captureWidth, captureHeight);
            break;
        case 3:
            DetectBlobsShowStillImage();
            break;
        case 4:
            DetectBlobsNoStillImage();
            break;
        case 5:
            DetectBlobsShowVideo(captureWidth, captureHeight);
            break;
        case 6:
            DetectBlobsNoVideo(captureWidth, captureHeight);
            break;
        default:
            break;
    }
    return 0;
}