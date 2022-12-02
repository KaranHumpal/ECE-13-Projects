#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=Ascii.c BOARD.c CircularBuffer.c FieldOled.c Oled.c OledDriver.c Uart1.c AgentTest.c Agent.c Field.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o ${OBJECTDIR}/AgentTest.o ${OBJECTDIR}/Agent.o ${OBJECTDIR}/Field.o
POSSIBLE_DEPFILES=${OBJECTDIR}/Ascii.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/CircularBuffer.o.d ${OBJECTDIR}/FieldOled.o.d ${OBJECTDIR}/Oled.o.d ${OBJECTDIR}/OledDriver.o.d ${OBJECTDIR}/Uart1.o.d ${OBJECTDIR}/AgentTest.o.d ${OBJECTDIR}/Agent.o.d ${OBJECTDIR}/Field.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/Ascii.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/CircularBuffer.o ${OBJECTDIR}/FieldOled.o ${OBJECTDIR}/Oled.o ${OBJECTDIR}/OledDriver.o ${OBJECTDIR}/Uart1.o ${OBJECTDIR}/AgentTest.o ${OBJECTDIR}/Agent.o ${OBJECTDIR}/Field.o

# Source Files
SOURCEFILES=Ascii.c BOARD.c CircularBuffer.c FieldOled.c Oled.c OledDriver.c Uart1.c AgentTest.c Agent.c Field.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/flags/default/3a723efe68f6e2d39c2241eb33fe838ba2db2335 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Ascii.o.d 
	@${RM} ${OBJECTDIR}/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Ascii.o.d" -o ${OBJECTDIR}/Ascii.o Ascii.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/316831639b42595c2aedcd9a193bd1337efa7324 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/CircularBuffer.o: CircularBuffer.c  .generated_files/flags/default/ca167c5a3983ff636242ea81b17309cc883eea3f .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/CircularBuffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/CircularBuffer.o.d" -o ${OBJECTDIR}/CircularBuffer.o CircularBuffer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FieldOled.o: FieldOled.c  .generated_files/flags/default/35f1df80e9b05be7a446e254a6c4ff2b137db84c .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldOled.o.d 
	@${RM} ${OBJECTDIR}/FieldOled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/FieldOled.o.d" -o ${OBJECTDIR}/FieldOled.o FieldOled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/flags/default/5a44c021a29522da068435ca9d418f0b54167a10 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Oled.o.d 
	@${RM} ${OBJECTDIR}/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Oled.o.d" -o ${OBJECTDIR}/Oled.o Oled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/OledDriver.o: OledDriver.c  .generated_files/flags/default/48e74e16b1c57461315be0ca0cd799daae5e27c3 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/OledDriver.o.d" -o ${OBJECTDIR}/OledDriver.o OledDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Uart1.o: Uart1.c  .generated_files/flags/default/5600c627fd26f1ac90cc793a3100609937fdd823 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart1.o.d 
	@${RM} ${OBJECTDIR}/Uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Uart1.o.d" -o ${OBJECTDIR}/Uart1.o Uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/AgentTest.o: AgentTest.c  .generated_files/flags/default/cefa1fcf5e2a75c0c9d34e63796ed166b4131e41 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AgentTest.o.d 
	@${RM} ${OBJECTDIR}/AgentTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/AgentTest.o.d" -o ${OBJECTDIR}/AgentTest.o AgentTest.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Agent.o: Agent.c  .generated_files/flags/default/99cc157f8f2de85a36cd401c5c7565a481973098 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Agent.o.d 
	@${RM} ${OBJECTDIR}/Agent.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Agent.o.d" -o ${OBJECTDIR}/Agent.o Agent.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Field.o: Field.c  .generated_files/flags/default/bd73e0b2e9a7c651e0cc1e1ab7c491ea826f04cb .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Field.o.d 
	@${RM} ${OBJECTDIR}/Field.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Field.o.d" -o ${OBJECTDIR}/Field.o Field.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/Ascii.o: Ascii.c  .generated_files/flags/default/5ac8c58676028e0fbda661fdaf05af6b13ea016c .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Ascii.o.d 
	@${RM} ${OBJECTDIR}/Ascii.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Ascii.o.d" -o ${OBJECTDIR}/Ascii.o Ascii.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/f94fa154da8705b9cd531c5e69d546d626fbefac .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/CircularBuffer.o: CircularBuffer.c  .generated_files/flags/default/cd0d0a0eaa89aabc7bfe6a6b7e068e05dd165386 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/CircularBuffer.o.d 
	@${RM} ${OBJECTDIR}/CircularBuffer.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/CircularBuffer.o.d" -o ${OBJECTDIR}/CircularBuffer.o CircularBuffer.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/FieldOled.o: FieldOled.c  .generated_files/flags/default/bb3f2096fe60eac2daffa5365b4e5ffda29ec400 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/FieldOled.o.d 
	@${RM} ${OBJECTDIR}/FieldOled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/FieldOled.o.d" -o ${OBJECTDIR}/FieldOled.o FieldOled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Oled.o: Oled.c  .generated_files/flags/default/16fdee7c4317fab535a70e6c80799382429793ec .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Oled.o.d 
	@${RM} ${OBJECTDIR}/Oled.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Oled.o.d" -o ${OBJECTDIR}/Oled.o Oled.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/OledDriver.o: OledDriver.c  .generated_files/flags/default/b6ce10883a9e854836e26cef0232808178ef7ee .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/OledDriver.o.d 
	@${RM} ${OBJECTDIR}/OledDriver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/OledDriver.o.d" -o ${OBJECTDIR}/OledDriver.o OledDriver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Uart1.o: Uart1.c  .generated_files/flags/default/232385a2880a7f670c49f7102d214ebe86591db9 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Uart1.o.d 
	@${RM} ${OBJECTDIR}/Uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Uart1.o.d" -o ${OBJECTDIR}/Uart1.o Uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/AgentTest.o: AgentTest.c  .generated_files/flags/default/74acaefe4a6da875e1b8fe120c81402db6f81bc7 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/AgentTest.o.d 
	@${RM} ${OBJECTDIR}/AgentTest.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/AgentTest.o.d" -o ${OBJECTDIR}/AgentTest.o AgentTest.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Agent.o: Agent.c  .generated_files/flags/default/fa9c5192ba1cb35d8eb6a0b5455030f3a16281f5 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Agent.o.d 
	@${RM} ${OBJECTDIR}/Agent.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Agent.o.d" -o ${OBJECTDIR}/Agent.o Agent.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Field.o: Field.c  .generated_files/flags/default/3e766b811a31f1561347a89be3cea15b26bf1014 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Field.o.d 
	@${RM} ${OBJECTDIR}/Field.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -Wall -MP -MMD -MF "${OBJECTDIR}/Field.o.d" -o ${OBJECTDIR}/Field.o Field.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a Negotiation_correct.o Message_correct.o  
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a Negotiation_correct.o Message_correct.o      -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=5000,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  Lab9SupportLib.a Negotiation_correct.o Message_correct.o 
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    Lab9SupportLib.a Negotiation_correct.o Message_correct.o      -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=5000,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Lab9.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
