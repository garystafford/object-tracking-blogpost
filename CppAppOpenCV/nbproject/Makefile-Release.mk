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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/imageParams.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/testcvblobstill.o \
	${OBJECTDIR}/testcvblobvideo.o \
	${OBJECTDIR}/testfps.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/lib -L/usr/local/lib -L/usr/local/include/lib /usr/local/lib/libcvblob.so /usr/local/lib/libopencv_calib3d.so /usr/local/lib/libopencv_contrib.so /usr/local/lib/libopencv_core.so /usr/local/lib/libopencv_features2d.so /usr/local/lib/libopencv_flann.so /usr/local/lib/libopencv_gpu.so /usr/local/lib/libopencv_highgui.so /usr/local/lib/libopencv_imgproc.so /usr/local/lib/libopencv_legacy.so /usr/local/lib/libopencv_ml.so /usr/local/lib/libopencv_nonfree.so /usr/local/lib/libopencv_objdetect.so /usr/local/lib/libopencv_photo.so /usr/local/lib/libopencv_stitching.so /usr/local/lib/libopencv_ts.a /usr/local/lib/libopencv_video.so /usr/local/lib/libopencv_videostab.so /usr/local/lib/python2.7/dist-packages/cv2.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libcvblob.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_calib3d.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_contrib.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_features2d.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_flann.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_gpu.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_highgui.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_imgproc.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_legacy.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_ml.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_nonfree.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_objdetect.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_photo.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_stitching.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_ts.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_video.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/libopencv_videostab.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: /usr/local/lib/python2.7/dist-packages/cv2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppappopencv ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/imageParams.o: imageParams.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/imageParams.o imageParams.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/testcvblobstill.o: testcvblobstill.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testcvblobstill.o testcvblobstill.cpp

${OBJECTDIR}/testcvblobvideo.o: testcvblobvideo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testcvblobvideo.o testcvblobvideo.cpp

${OBJECTDIR}/testfps.o: testfps.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -s -I/usr/local/include/opencv -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/testfps.o testfps.cpp

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
