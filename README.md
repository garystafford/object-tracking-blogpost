<p>
<a href='https://travis-ci.org/garystafford/object-tracking-blogpost'><img src='https://travis-ci.org/garystafford/object-tracking-blogpost.svg?branch=rev05_2014'></a>
</p>

##Object Tracking Project
Use C++ with OpenCV and cvBlob to perform image processing and object tracking, using a webcam. Originally, built to test Raspberry Pi performance.

#### GitHub Branches
##### Master 
Original code for my blog post, '[Object Tracking on the Raspberry Pi with C++, OpenCV, and cvBlob](http://wp.me/p1RD28-yW)'

##### rev05_2014 
Changes to original project branch:
* Refactored video blob tracking methods into a separate class.
* Refactored hard-coded color ranges. Now input parameters.
* All methods now accept common struct containing input parameters.
* New window displays low and high RGB color range color sample.
* Added support for Travis-CI. Project now building on each commit to GitHub.
* Project contains bash commands/script to install latest OpenCV, cvBlob, and all necessary dependencies on Ubuntu.
* Project contains bash commands/script to git clone, build, package, and run this project on Ubuntu.
* All installation and configuration tested with fresh Ubuntu image on VirtualBox VM 

#### Installation and Configuration
```bash
sudo apt-get update && sudo apt-get -y upgrade

# install openCV
cd ~/
sudo apt-get -y install git
# I had a problem with dependencies.sh finding libfaac-dev in multiverse repository.
# Multiverse repository is commented out by default in sources.list.
# Modify /etc/apt/sources.list. See: http://superuser.com/a/467775
sed -i '/precise multiverse/s/# //g' /etc/apt/sources.list
sed -i '/precise-updates multiverse/s/# //g' /etc/apt/sources.list
#sed -i '/precise-security multiverse/s/# //g' /etc/apt/sources.list
sudo apt-get update

git clone https://github.com/jayrambhia/Install-OpenCV
cd Install-OpenCV/Ubuntu
./opencv_latest.sh | tee ~/opencv_install.log

# install object-tracking-blogpostobject-tracking-blogpost  project
cd ~/
git clone https://github.com/garystafford/object-tracking-blogpost.git

#install cvBlob (uses script within object-tracking-blogpost project)
sh /object-tracking-blogpost/install_cvBlob.sh | tee ~/cvblob_install.log

# optional - fixed problem with app finding cvBlob library when started
echo 'export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH' | sudo tee -a ~/.bashrc
bash --login # or exit VM and log back in

# build project (compile object tracking application)
cd ~/object-tracking-blogpost/CppAppOpenCV
make -f nbproject/Makefile-Release.mk QMAKE= SUBPROJECTS= .build-conf

# run object tracking application
cd ~/object-tracking-blogpost/CppAppOpenCV/dist/Release/GNU-Linux-x86
./cppappopencv

# package object tracking application for distribution as .tar (incld. static images)
cd ~/object-tracking-blogpost/CppAppOpenCV
bash nbproject/Package-Release.bash

# use packaged object tracking application
cd ~/object-tracking-blogpost/CppAppOpenCV/dist/Release/GNU-Linux-x86/package/
tar -xvf cppappopencv.tar -C ~/

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
* Orange Pen
  * Low RGB: 25, 90, 56
  * High RGB: 255, 190, 120

#### Previews
<p>
![Preview 1](https://github.com/garystafford/object-tracking-blogpost/blob/rev05_2014/images/object_grab_1_preview.png?raw=true)
</p>
<p>
![Preview 2](https://github.com/garystafford/object-tracking-blogpost/blob/rev05_2014/images/object_grab_2_preview.png?raw=true)
</p>
<p>
![Preview 3](https://github.com/garystafford/object-tracking-blogpost/blob/rev05_2014/images/object_grab_4_preview.png?raw=true)
<a href='https://github.com/garystafford/object-tracking-blogpost/blob/rev05_2014/images/object_grab_4_preview.png?raw=true'><img src='https://github.com/garystafford/object-tracking-blogpost/blob/rev05_2014/images/object_grab_4.png?raw=true'></a>
</p>
 
