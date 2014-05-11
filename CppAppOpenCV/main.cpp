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
#include "imageParams.h"

using namespace std;

int main(int argc, char* argv[]) {
    imageParams inputParams;

    if (argc == 4) { // user input parameters with call
        inputParams.captureMethod = strtol(argv[1], NULL, 0);
        inputParams.captureWidth = strtol(argv[2], NULL, 0);
        inputParams.captureHeight = strtol(argv[3], NULL, 0);
        inputParams.lowR = strtol(argv[4], NULL, 0);
        inputParams.lowG = strtol(argv[5], NULL, 0);
        inputParams.lowB = strtol(argv[6], NULL, 0);
        inputParams.highR = strtol(argv[7], NULL, 0);
        inputParams.highG = strtol(argv[8], NULL, 0);
        inputParams.highB = strtol(argv[9], NULL, 0);

    } else { // user did not input parameters with call
        cout << endl << "Demonstrations/Tests: " << endl;
        cout << endl << "(1) Test OpenCV - Show Webcam" << endl;
        cout << endl << "(2) Test OpenCV - No Webcam" << endl;
        cout << endl << "(3) Test cvBlob - Show Image" << endl;
        cout << endl << "(4) Test cvBlob - No Image" << endl;
        cout << endl << "(5) Test Blob Tracking - Show Webcam" << endl;
        cout << endl << "(6) Test Blob Tracking - No Webcam" << endl;
        cout << endl << "Input test # (1-6): ";
        cin >> inputParams.captureMethod;

        if (inputParams.captureMethod < 1 || inputParams.captureMethod > 6) {
            cout << endl << "Test # incorrect" << endl;
            return -1;
        }

        // test 3 and 4 don't require width and height parameters
        if (inputParams.captureMethod != 3 && inputParams.captureMethod != 4) {
            cout << endl << "Input capture width (1 - 1920 pixels): ";
            cin >> inputParams.captureWidth;
            cout << endl << "Input capture height (1 - 1920 pixels): ";
            cin >> inputParams.captureHeight;
            cout << endl;

            if (inputParams.captureWidth < 0 || inputParams.captureWidth > 1920) {
                cout << endl << "Width value incorrect" << endl;
                return -1;
            }

            if (inputParams.captureHeight < 0 || inputParams.captureHeight > 1920) {
                cout << endl << "Height value incorrect" << endl;
                return -1;
            }
        }

        // test 3 and 4 don't require width and height parameters
        if (inputParams.captureMethod != 1 && inputParams.captureMethod != 2) {
            cout << endl << "Input color range low R (0 - 255): ";
            cin >> inputParams.lowR;
            cout << endl << "Input color range low G (0 - 255): ";
            cin >> inputParams.lowG;
            cout << endl << "Input color range low B (0 - 255): ";
            cin >> inputParams.lowB;
            cout << endl << "Input color range high R (0 - 255): ";
            cin >> inputParams.highR;
            cout << endl << "Input color range high G (0 - 255): ";
            cin >> inputParams.highG;
            cout << endl << "Input color range high B (0 - 255): ";
            cin >> inputParams.highB;
            cout << endl;

            if (inputParams.lowR < 0 || inputParams.lowR > 255) {
                cout << endl << "Low red color value incorrect" << endl;
                return -1;
            }

            if (inputParams.lowG < 0 || inputParams.lowG > 255) {
                cout << endl << "Low green color value incorrect" << endl;
                return -1;
            }

            if (inputParams.lowB < 0 || inputParams.lowB > 255) {
                cout << endl << "Low blue color value incorrect" << endl;
                return -1;
            }

            if (inputParams.highR < 0 || inputParams.highR > 255) {
                cout << endl << "High red color value incorrect" << endl;
                return -1;
            }

            if (inputParams.highG < 0 || inputParams.highG > 255) {
                cout << endl << "High green color value incorrect" << endl;
                return -1;
            }

            if (inputParams.highB < 0 || inputParams.highB > 255) {
                cout << endl << "High blue color value incorrect" << endl;
                return -1;
            }
        }
    }

    switch (inputParams.captureMethod) {
        case 1:
            TestFpsShowVideo(inputParams);
        case 2:
            TestFpsNoVideo(inputParams);
            break;
        case 3:
            DetectBlobsShowStillImage(inputParams);
            break;
        case 4:
            DetectBlobsNoStillImage(inputParams);
            break;
        case 5:
            DetectBlobsShowVideo(inputParams);
            break;
        case 6:
            DetectBlobsNoVideo(inputParams);
            break;
        default:
            break;
    }
    return 0;
}