/* 
 * File:        main.cpp
 * Author:      Gary Stafford
 * Description: Program entry point
 * Created:     February 3, 2013
 * Revised:     May 4, 2014
 */

#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <iostream>

#include "testfps.hpp"
#include "testcvblobstill.hpp"
#include "testcvblobvideo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    int captureMethod = 0;
    int captureWidth = 0;
    int captureHeight = 0;
    double lowR = 0;
    double lowG = 0;
    double lowB = 0;
    double highR = 0;
    double highG = 0;
    double highB = 0;

    if (argc == 4) { // user input parameters with call
        captureMethod = strtol(argv[1], NULL, 0);
        captureWidth = strtol(argv[2], NULL, 0);
        captureHeight = strtol(argv[3], NULL, 0);
        lowR = strtol(argv[4], NULL, 0);
        lowG = strtol(argv[5], NULL, 0);
        lowB = strtol(argv[6], NULL, 0);
        highR = strtol(argv[7], NULL, 0);
        highG = strtol(argv[8], NULL, 0);
        highB = strtol(argv[9], NULL, 0);

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

        if (captureMethod < 1 || captureMethod > 6) {
            cout << endl << "Test # incorrect" << endl;
            return -1;
        }

        // test 3 and 4 don't require width and height parameters
        if (captureMethod != 3 && captureMethod != 4) {
            cout << endl << "Input capture width (1 - 1920 pixels): ";
            cin >> captureWidth;
            cout << endl << "Input capture height (1 - 1920 pixels): ";
            cin >> captureHeight;
            cout << endl;

            if (captureWidth < 0 || captureWidth > 1920) {
                cout << endl << "Width value incorrect" << endl;
                return -1;
            }

            if (captureHeight < 0 || captureHeight > 1920) {
                cout << endl << "Height value incorrect" << endl;
                return -1;
            }
        }

        // test 3 and 4 don't require width and height parameters
        if (captureMethod != 1 && captureMethod != 2) {
            cout << endl << "Input color range low R (0 - 255): ";
            cin >> lowR;
            cout << endl << "Input color range low G (0 - 255): ";
            cin >> lowG;
            cout << endl << "Input color range low B (0 - 255): ";
            cin >> lowB;
            cout << endl << "Input color range high R (0 - 255): ";
            cin >> highR;
            cout << endl << "Input color range high G (0 - 255): ";
            cin >> highG;
            cout << endl << "Input color range high B (0 - 255): ";
            cin >> highB;
            cout << endl;

            if (lowR < 0 || lowR > 255) {
                cout << endl << "Low red color value incorrect" << endl;
                return -1;
            }

            if (lowG < 0 || lowG > 255) {
                cout << endl << "Low green color value incorrect" << endl;
                return -1;
            }

            if (lowB < 0 || lowB > 255) {
                cout << endl << "Low blue color value incorrect" << endl;
                return -1;
            }

            if (highR < 0 || highR > 255) {
                cout << endl << "High red color value incorrect" << endl;
                return -1;
            }

            if (highG < 0 || highG > 255) {
                cout << endl << "High green color value incorrect" << endl;
                return -1;
            }

            if (highB < 0 || highB > 255) {
                cout << endl << "High blue color value incorrect" << endl;
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
            DetectBlobsShowStillImage(lowR, lowG, lowB, highR, highG, highB);
            break;
        case 4:
            DetectBlobsNoStillImage(lowR, lowG, lowB, highR, highG, highB);
            break;
        case 5:
            DetectBlobsShowVideo(captureWidth, captureHeight,
                    lowR, lowG, lowB, highR, highG, highB);
            break;
        case 6:
            DetectBlobsNoVideo(captureWidth, captureHeight,
                    lowR, lowG, lowB, highR, highG, highB);
            break;
        default:
            break;
    }
    return 0;
}