#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/testcvblobstill.o \
	${OBJECTDIR}/testcvblobvideo.o \
	${OBJECTDIR}/testfps.o


# C Compiler Flags
CFLAGS=-v

# CC Compiler Flags
CCFLAGS=-v
CXXFLAGS=-v

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -L/usr/local/lib -L/usr/local/include/lib /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so /usr/local/lib/libswresample.a /usr/local/lib/libswscale.a /usr/local/lib/libv4l1.so /usr/local/lib/libv4l2.so /usr/local/lib/libv4lconvert.so /usr/local/lib/libx264.so /usr/local/lib/libv4l/v4l1compat.so /usr/local/lib/libv4l/v4l2convert.so /usr/local/lib/python2.7/dist-packages/cv2.so ../../cvblob/lib/libcvblob.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_calib3d.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_contrib.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_core.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_features2d.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_gpu.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_highgui.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_imgproc.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_legacy.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_ml.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_nonfree.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_objdetect.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_photo.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_stitching.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_ts.a

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_video.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libopencv_videostab.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libswresample.a

${TESTDIR}/TestFiles/f1: /usr/local/lib/libswscale.a

${TESTDIR}/TestFiles/f1: /usr/local/lib/libv4l1.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libv4l2.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libv4lconvert.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libx264.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libv4l/v4l1compat.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/libv4l/v4l2convert.so

${TESTDIR}/TestFiles/f1: /usr/local/lib/python2.7/dist-packages/cv2.so

${TESTDIR}/TestFiles/f1: ../../cvblob/lib/libcvblob.so

${TESTDIR}/TestFiles/f1: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/testcvblobstill.o: nbproject/Makefile-${CND_CONF}.mk testcvblobstill.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testcvblobstill.o testcvblobstill.cpp

${OBJECTDIR}/testcvblobvideo.o: nbproject/Makefile-${CND_CONF}.mk testcvblobvideo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testcvblobvideo.o testcvblobvideo.cpp

${OBJECTDIR}/testfps.o: nbproject/Makefile-${CND_CONF}.mk testfps.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testfps.o testfps.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
