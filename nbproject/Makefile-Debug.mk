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
CND_PLATFORM=Cygwin_4.x-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/joueur.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/plateau.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
LDLIBSOPTIONS=../googletest/dist/Debug/Cygwin_4.x-Windows/libgoogletest.a

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medev-tp-go.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medev-tp-go.exe: ../googletest/dist/Debug/Cygwin_4.x-Windows/libgoogletest.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medev-tp-go.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medev-tp-go ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/joueur.o: joueur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/joueur.o joueur.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/plateau.o: plateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/plateau.o plateau.cpp

# Subprojects
.build-subprojects:
	cd ../googletest && ${MAKE}  -f Makefile CONF=Debug

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/TestDimitri.o ${TESTDIR}/TestGuillaume.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/TestDimitri.o: TestDimitri.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/TestDimitri.o TestDimitri.cpp


${TESTDIR}/TestGuillaume.o: TestGuillaume.cpp 
	${MKDIR} -p ${TESTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/TestGuillaume.o TestGuillaume.cpp


${OBJECTDIR}/joueur_nomain.o: ${OBJECTDIR}/joueur.o joueur.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/joueur.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/joueur_nomain.o joueur.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/joueur.o ${OBJECTDIR}/joueur_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/plateau_nomain.o: ${OBJECTDIR}/plateau.o plateau.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/plateau.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -I../../gtest-1.7.0 -I../../gtest-1.7.0/include -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/plateau_nomain.o plateau.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/plateau.o ${OBJECTDIR}/plateau_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/medev-tp-go.exe

# Subprojects
.clean-subprojects:
	cd ../googletest && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
