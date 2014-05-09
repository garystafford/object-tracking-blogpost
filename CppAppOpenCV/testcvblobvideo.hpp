// -*- C++ -*-
/* 
 * File:        testcvblobvideo.hpp
 * Author:      Gary Stafford
 * Created:     February 3, 2013
 * Revised:     May 4, 2014
 */

#ifndef TESTCVBLOBVIDEO_HPP
#define	TESTCVBLOBVIDEO_HPP

int DetectBlobsNoVideo(int captureWidth, int captureHeight,
        double lowR, double lowG, double lowB,
        double highR, double highG, double highB);
int DetectBlobsShowVideo(int captureWidth, int captureHeight,
        double lowR, double lowG, double lowB,
        double highR, double highG, double highB);

#endif	/* TESTCVBLOBVIDEO_HPP */

