MODDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
TARGET = mod

SRCS = src/dummy.c src/stophittingyourself.c src/hook_dopoing_switchofffist.s 
CPPFLAGS = -DBUILD=0
LDSYMS = -T$(MODDIR)../../symbols/funcs-u.txt -T$(MODDIR)../../symbols/addrs-u.txt 
USE_FUNCTION_SECTIONS ?= true
DISABLE_FUNCTION_REORDER ?= false
USE_PSYQ ?= false
OVERLAYSECTION ?= .srcdummyc .srcstophittingyourselfc .srchook_dopoing_switchofffists 
OVR_START_ADDR = 0x8016ca80
OVERLAYSCRIPT = overlay.ld
BUILDDIR = $(MODDIR)output/
SRCINCLUDEDIR = $(MODDIR)src/
GAMEINCLUDEDIR = $(MODDIR)../../include/
EXTRA_CC_FLAGS = -Os -g
OPT_CC_FLAGS = -fshort-enums
OPT_LD_FLAGS = 
PCHS = $(GAMEINCLUDEDIR)
TRIMBIN_OFFSET = $(MODDIR)debug/offset.txt

include ../../../common.mk
