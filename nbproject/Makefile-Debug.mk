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
	${OBJECTDIR}/_ext/515780377/1menuBubble.o \
	${OBJECTDIR}/_ext/515780377/2menuInsertion.o \
	${OBJECTDIR}/_ext/515780377/3menuMerge.o \
	${OBJECTDIR}/_ext/515780377/4menuQuick.o \
	${OBJECTDIR}/_ext/515780377/5menuHeap.o \
	${OBJECTDIR}/_ext/515780377/questao4.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/questao1.o \
	${OBJECTDIR}/questao2.o \
	${OBJECTDIR}/questao3.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trab1_cal

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trab1_cal: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trab1_cal ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/515780377/1menuBubble.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/1menuBubble.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/1menuBubble.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/1menuBubble.c

${OBJECTDIR}/_ext/515780377/2menuInsertion.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/2menuInsertion.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/2menuInsertion.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/2menuInsertion.c

${OBJECTDIR}/_ext/515780377/3menuMerge.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/3menuMerge.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/3menuMerge.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/3menuMerge.c

${OBJECTDIR}/_ext/515780377/4menuQuick.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/4menuQuick.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/4menuQuick.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/4menuQuick.c

${OBJECTDIR}/_ext/515780377/5menuHeap.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/5menuHeap.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/5menuHeap.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/5menuHeap.c

${OBJECTDIR}/_ext/515780377/questao4.o: nbproject/Makefile-${CND_CONF}.mk /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/questao4.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/515780377
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/515780377/questao4.o /home/daniel/Dropbox/UDESC/7_sem/CAL/Trab1_CAL/Q4/questao4.c

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/questao1.o: nbproject/Makefile-${CND_CONF}.mk questao1.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/questao1.o questao1.c

${OBJECTDIR}/questao2.o: nbproject/Makefile-${CND_CONF}.mk questao2.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/questao2.o questao2.c

${OBJECTDIR}/questao3.o: nbproject/Makefile-${CND_CONF}.mk questao3.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/questao3.o questao3.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/trab1_cal

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
