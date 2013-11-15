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
	${OBJECTDIR}/testcvblob.o \
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
LDLIBSOPTIONS=-L/usr/lib -L/usr/local/lib -L/usr/local/include/lib /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_ts.so /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so /usr/local/lib/libswresample.a /usr/local/lib/libswscale.a /usr/local/lib/libv4l1.so /usr/local/lib/libv4l2.so /usr/local/lib/libv4lconvert.so /usr/local/lib/libx264.so /usr/local/lib/libv4l/v4l1compat.so /usr/local/lib/libv4l/v4l2convert.so /usr/local/lib/python2.7/dist-packages/cv2.so ../../cvblob/lib/libcvblob.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_calib3d.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_contrib.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_features2d.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_gpu.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_highgui.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_imgproc.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_legacy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_ml.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_nonfree.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_objdetect.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_photo.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_stitching.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_ts.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_video.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_videostab.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libswresample.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libswscale.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libv4l1.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libv4l2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libv4lconvert.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libx264.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libv4l/v4l1compat.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libv4l/v4l2convert.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/python2.7/dist-packages/cv2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: ../../cvblob/lib/libcvblob.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/testcvblob.o: nbproject/Makefile-${CND_CONF}.mk testcvblob.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/testcvblob.o testcvblob.cpp

${OBJECTDIR}/testfps.o: nbproject/Makefile-${CND_CONF}.mk testfps.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -I/usr/local/include/opencv -MMD -MP -MF $@.d -o ${OBJECTDIR}/testfps.o testfps.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
