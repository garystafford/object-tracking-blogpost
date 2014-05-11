<p>
<a href='https://travis-ci.org/garystafford/object-tracking-blogpost'><img src='https://travis-ci.org/garystafford/object-tracking-blogpost.svg?branch=rev05_2014'></a>
</p>

##Object Tracking Project
Use C++ with OpenCV and cvBlob to perform image processing and object tracking, using a webcam. Originally, built to test Raspberry Pi performance.

#### GitHub Branches
##### Master 
Original code for my blog post, '[Object Tracking on the Raspberry Pi with C++, OpenCV, and cvBlob](http://wp.me/p1RD28-yW)'

##### rev05_2014 
Revised code for future blog post:
* Refactored video blob methods into a separate class.
* Removed hard-coded color ranges. Now input paramaters.
* All methods now accept struct as input parameter.
* New window displays low and high RGB color range.
* Added support for Travis-CI. Project now building on each commit to GitHub.
* Project contains code and directions to install latest OpenCV, cvBlob, and all neccessary dependencies on Ubuntu. Travis is using this code to prep for project builds.
* Project contains directions on how to git clone, build, and run project on Ubuntu.

#### Installation and Configuration
```
################################################################
#
# installs latest OpenCV, cvBlob, all dependencies on Ubuntu
# git clones, builds, and runs project on Ubuntu
# tested with fresh Ubuntu image on VirtualBox VM
#
################################################################

sudo apt-get update && sudo apt-get -y upgrade

# install OpenCV
cd ~/
sudo apt-get -y install git
git clone https://github.com/jayrambhia/Install-OpenCV
cd Install-OpenCV/Ubuntu
./opencv_latest.sh | tee ~/opencv_install.log

# install project
cd ~/
git clone https://github.com/garystafford/object-tracking-blogpost.git

#install cvBlob (uses script from project)
cd ~/object-tracking-blogpost
sh install_cvBlob.sh | tee ~/cvblob_install.log

# build project (compile app)
cd ~/object-tracking-blogpost/CppAppOpenCV
make -f nbproject/Makefile-Release.mk QMAKE= SUBPROJECTS= .build-conf

# optional - fixed problem with app finding cvBlob library when started
echo 'LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH' | sudo tee -a ~/.bashrc

# run app
cd ~/object-tracking-blogpost/CppAppOpenCV/dist/Release/GNU-Linux-x86
./cppappopencv

# package app for distribution as .tar (incld. static images)
cd ~/object-tracking-blogpost/CppAppOpenCV
bash nbproject/Package-Release.bash
# package located here: ~/object-tracking-blogpost/CppAppOpenCV/dist/Release/GNU-Linux-x86/package/cppappopencv.tar
```
#### Color Range Examples
These are the values shown in the blog post and YouTube video
* Red balls
  * Low RGB: 155, 0, 0
  * High RGB: 255, 130, 130 
* Blue paper
  * Low RGB: 49, 69, 100
  * High RGB: 134, 163, 216 
* Green paper
  * Low RGB: 45, 92, 76
  * High RGB: 70, 155, 124 
 
