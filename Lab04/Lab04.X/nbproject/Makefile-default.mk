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
FINAL_IMAGE=${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
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
SOURCEFILES_QUOTED_IF_SPACED=rpn_test.c BOARD.c stack_test.c rpn.c stack.c Lab04_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/rpn_test.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/stack_test.o ${OBJECTDIR}/rpn.o ${OBJECTDIR}/stack.o ${OBJECTDIR}/Lab04_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/rpn_test.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/stack_test.o.d ${OBJECTDIR}/rpn.o.d ${OBJECTDIR}/stack.o.d ${OBJECTDIR}/Lab04_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/rpn_test.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/stack_test.o ${OBJECTDIR}/rpn.o ${OBJECTDIR}/stack.o ${OBJECTDIR}/Lab04_main.o

# Source Files
SOURCEFILES=rpn_test.c BOARD.c stack_test.c rpn.c stack.c Lab04_main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX370F512H
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
${OBJECTDIR}/rpn_test.o: rpn_test.c  .generated_files/flags/default/c2e712a1ab60682745e700927476a33a3c6f9515 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rpn_test.o.d 
	@${RM} ${OBJECTDIR}/rpn_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rpn_test.o.d" -o ${OBJECTDIR}/rpn_test.o rpn_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/6f2d373a6433fda5cacc67bbe9f48f30575e13d .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/stack_test.o: stack_test.c  .generated_files/flags/default/58d04755ba7fe952975ff539fe9259faa1f1cb4f .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stack_test.o.d 
	@${RM} ${OBJECTDIR}/stack_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/stack_test.o.d" -o ${OBJECTDIR}/stack_test.o stack_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/rpn.o: rpn.c  .generated_files/flags/default/b0effa3d1abd46f48b5d287eddaa2b284123dd7 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rpn.o.d 
	@${RM} ${OBJECTDIR}/rpn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rpn.o.d" -o ${OBJECTDIR}/rpn.o rpn.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/stack.o: stack.c  .generated_files/flags/default/433ce5d892b1d99fb85679ea5ae54ad7299aed95 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stack.o.d 
	@${RM} ${OBJECTDIR}/stack.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/stack.o.d" -o ${OBJECTDIR}/stack.o stack.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Lab04_main.o: Lab04_main.c  .generated_files/flags/default/f160bb1187aa78818f9148992efa7b2ab9fd58 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Lab04_main.o.d 
	@${RM} ${OBJECTDIR}/Lab04_main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_SIMULATOR=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Lab04_main.o.d" -o ${OBJECTDIR}/Lab04_main.o Lab04_main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
else
${OBJECTDIR}/rpn_test.o: rpn_test.c  .generated_files/flags/default/29315060c83539dd4d949d53ea22b834baae1c6a .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rpn_test.o.d 
	@${RM} ${OBJECTDIR}/rpn_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rpn_test.o.d" -o ${OBJECTDIR}/rpn_test.o rpn_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/BOARD.o: BOARD.c  .generated_files/flags/default/85fea89bba4ccd7401a3ee7ffb50c884960b5228 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/stack_test.o: stack_test.c  .generated_files/flags/default/2eaca9af49da7334ade06eea5cd488e1272f5bf9 .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stack_test.o.d 
	@${RM} ${OBJECTDIR}/stack_test.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/stack_test.o.d" -o ${OBJECTDIR}/stack_test.o stack_test.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/rpn.o: rpn.c  .generated_files/flags/default/6e67ab84f5cbe24b4738041b6fb31ffd2c869d0d .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/rpn.o.d 
	@${RM} ${OBJECTDIR}/rpn.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/rpn.o.d" -o ${OBJECTDIR}/rpn.o rpn.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/stack.o: stack.c  .generated_files/flags/default/276516d015070608868e86fcfba0ffe87b23d3ff .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/stack.o.d 
	@${RM} ${OBJECTDIR}/stack.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/stack.o.d" -o ${OBJECTDIR}/stack.o stack.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
${OBJECTDIR}/Lab04_main.o: Lab04_main.c  .generated_files/flags/default/b1c6bdc6d5e3a19414bb52ab3536dc7f076abdcc .generated_files/flags/default/15078ce8f5a6ad03035624f12995f439edad8cad
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Lab04_main.o.d 
	@${RM} ${OBJECTDIR}/Lab04_main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -fno-common -MP -MMD -MF "${OBJECTDIR}/Lab04_main.o.d" -o ${OBJECTDIR}/Lab04_main.o Lab04_main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}"  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_SIMULATOR=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)      -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_SIMULATOR=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	
else
${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}"
	${MP_CC_DIR}/xc32-bin2hex ${DISTDIR}/Lab04.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
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
