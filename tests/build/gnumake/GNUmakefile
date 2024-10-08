# This file was automatically generated by bakefile.
#
# Any manual changes will be lost if it is regenerated,
# modify the source .bkl file instead if possible.

# You may define standard make variables such as CFLAGS or
# CXXFLAGS to affect the build. For example, you could use:
#
#      make CXXFLAGS=-g
#
# to build with debug information. The full list of variables
# that can be used by this makefile is:
# AR, CC, CFLAGS, CPPFLAGS, CXX, CXXFLAGS, LD, LDFLAGS, MAKE, RANLIB.

# You may also specify config=Debug|Release
# or their corresponding lower case variants on make command line to select
# the corresponding default flags values.
ifeq ($(config),debug)
override config := Debug
endif
ifeq ($(config),release)
override config := Release
endif
ifeq ($(config),Debug)
override CPPFLAGS += -DDEBUG
override CFLAGS += -g -O0
override CXXFLAGS += -g -O0
override LDFLAGS += -g
else ifeq ($(config),Release)
override CPPFLAGS += -DNDEBUG
override CFLAGS += -O2
override CXXFLAGS += -O2
else ifneq (,$(config))
$(warning Unknown configuration "$(config)")
endif
#
# Additionally, this makefile is customizable with the following
# settings:
#
#      ISHIKO_CPP_BASEPLATFORM_ROOT   Path to the Ishiko/C++ BasePlatform installation
#      ISHIKO_CPP_ERRORS_ROOT         Path to the Ishiko/C++ Errors installation
#      ISHIKO_CPP_MEMORY_ROOT         Path to the Ishiko/C++ Memory installation
#      ISHIKO_CPP_BOOST_ROOT          Path to the Boost installation
#      ISHIKO_CPP_TEXT_ROOT           Path to the Ishiko/C++ Text installation
#      ISHIKO_CPP_CONFIGURATION_ROOT  Path to the Ishiko/C++ Configuration installation
#      ISHIKO_CPP_IO_ROOT             Path to the Ishiko/C++ IO installation
#      ISHIKO_CPP_FILESYSTEM_ROOT     Path to the Ishiko/C++ FileSystem installation
#      ISHIKO_CPP_TYPES_ROOT          Path to the Ishiko/C++ Types installation
#      ISHIKO_CPP_DIFF_ROOT           Path to the Ishiko/C++ Diff installation
#      ISHIKO_CPP_PROCESS_ROOT        Path to the Ishiko/C++ Process installation
#      ISHIKO_CPP_FMT_ROOT            Path to the fmt installation
#      ISHIKO_CPP_TIME_ROOT           Path to the Ishiko/C++ Time installation
#      ISHIKO_CPP_PUGIXML_ROOT        Path to the pugixml installation
#      ISHIKO_CPP_XML_ROOT            Path to the Ishiko/C++ XML installation
#      ISHIKO_CPP_TESTFRAMEWORK_ROOT  Path to the Ishiko/C++ TestFramework installation

# Use "make RANLIB=''" for platforms without ranlib.
RANLIB ?= ranlib

CC := cc
CXX := c++

# The directory for the build files, may be overridden on make command line.
builddir = .

ifneq ($(builddir),.)
_builddir := $(if $(findstring $(abspath $(builddir)),$(builddir)),,../../)$(builddir)/../gnumake/
_builddir_error := $(shell mkdir -p $(_builddir) 2>&1)
$(if $(_builddir_error),$(error Failed to create build directory: $(_builddir_error)))
endif

# ------------
# Configurable settings:
# 

# Path to the Ishiko/C++ BasePlatform installation
ISHIKO_CPP_BASEPLATFORM_ROOT ?= $(ISHIKO_CPP_ROOT)/base-platform
# Path to the Ishiko/C++ Errors installation
ISHIKO_CPP_ERRORS_ROOT ?= $(ISHIKO_CPP_ROOT)/errors
# Path to the Ishiko/C++ Memory installation
ISHIKO_CPP_MEMORY_ROOT ?= $(ISHIKO_CPP_ROOT)/memory
# Path to the Boost installation
ISHIKO_CPP_BOOST_ROOT ?= $(BOOST_ROOT)
# Path to the Ishiko/C++ Text installation
ISHIKO_CPP_TEXT_ROOT ?= $(ISHIKO_CPP_ROOT)/text
# Path to the Ishiko/C++ Configuration installation
ISHIKO_CPP_CONFIGURATION_ROOT ?= $(ISHIKO_CPP_ROOT)/configuration
# Path to the Ishiko/C++ IO installation
ISHIKO_CPP_IO_ROOT ?= $(ISHIKO_CPP_ROOT)/io
# Path to the Ishiko/C++ FileSystem installation
ISHIKO_CPP_FILESYSTEM_ROOT ?= $(ISHIKO_CPP_ROOT)/filesystem
# Path to the Ishiko/C++ Types installation
ISHIKO_CPP_TYPES_ROOT ?= $(ISHIKO_CPP_ROOT)/types
# Path to the Ishiko/C++ Diff installation
ISHIKO_CPP_DIFF_ROOT ?= $(ISHIKO_CPP_ROOT)/diff
# Path to the Ishiko/C++ Process installation
ISHIKO_CPP_PROCESS_ROOT ?= $(ISHIKO_CPP_ROOT)/process
# Path to the fmt installation
ISHIKO_CPP_FMT_ROOT ?= $(FMT_ROOT)
# Path to the Ishiko/C++ Time installation
ISHIKO_CPP_TIME_ROOT ?= $(ISHIKO_CPP_ROOT)/time
# Path to the pugixml installation
ISHIKO_CPP_PUGIXML_ROOT ?= $(PUGIXML_ROOT)
# Path to the Ishiko/C++ XML installation
ISHIKO_CPP_XML_ROOT ?= $(ISHIKO_CPP_ROOT)/xml
# Path to the Ishiko/C++ TestFramework installation
ISHIKO_CPP_TESTFRAMEWORK_ROOT ?= $(ISHIKO_CPP_ROOT)/test-framework

# ------------

all: $(_builddir)IshikoMemoryTests

$(_builddir)IshikoMemoryTests: $(_builddir)IshikoMemoryTests_BigEndianWordTests.o $(_builddir)IshikoMemoryTests_ByteBufferPoolTests.o $(_builddir)IshikoMemoryTests_ByteBufferTests.o $(_builddir)IshikoMemoryTests_FixedByteBufferTests.o $(_builddir)IshikoMemoryTests_main.o $(_builddir)IshikoMemoryTests_WordTests.o
	$(CXX) -o $@ $(LDFLAGS) $(_builddir)IshikoMemoryTests_BigEndianWordTests.o $(_builddir)IshikoMemoryTests_ByteBufferPoolTests.o $(_builddir)IshikoMemoryTests_ByteBufferTests.o $(_builddir)IshikoMemoryTests_FixedByteBufferTests.o $(_builddir)IshikoMemoryTests_main.o $(_builddir)IshikoMemoryTests_WordTests.o -L$(ISHIKO_CPP_BASEPLATFORM_ROOT)/lib -L$(ISHIKO_CPP_ERRORS_ROOT)/lib -L$(ISHIKO_CPP_MEMORY_ROOT)/lib -L$(ISHIKO_CPP_BOOST_ROOT)/lib -L$(ISHIKO_CPP_TEXT_ROOT)/lib -L$(ISHIKO_CPP_CONFIGURATION_ROOT)/lib -L$(ISHIKO_CPP_IO_ROOT)/lib -L$(ISHIKO_CPP_FILESYSTEM_ROOT)/lib -L$(ISHIKO_CPP_TYPES_ROOT)/lib -L$(ISHIKO_CPP_DIFF_ROOT)/lib -L$(ISHIKO_CPP_XML_ROOT)/lib -L$(ISHIKO_CPP_PROCESS_ROOT)/lib -L$(ISHIKO_CPP_FMT_ROOT)/lib -L$(ISHIKO_CPP_TIME_ROOT)/lib -L$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/lib -lIshikoTestFrameworkCore -lIshikoConfiguration -lIshikoXML -lIshikoFileSystem -lIshikoIO -lIshikoProcess -lIshikoTime -lIshikoText -lIshikoMemory -lIshikoErrors -lIshikoBasePlatform -lfmt -lboost_filesystem -pthread

$(_builddir)IshikoMemoryTests_BigEndianWordTests.o: ../../src/BigEndianWordTests.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/BigEndianWordTests.cpp

$(_builddir)IshikoMemoryTests_ByteBufferPoolTests.o: ../../src/ByteBufferPoolTests.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/ByteBufferPoolTests.cpp

$(_builddir)IshikoMemoryTests_ByteBufferTests.o: ../../src/ByteBufferTests.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/ByteBufferTests.cpp

$(_builddir)IshikoMemoryTests_FixedByteBufferTests.o: ../../src/FixedByteBufferTests.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/FixedByteBufferTests.cpp

$(_builddir)IshikoMemoryTests_main.o: ../../src/main.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/main.cpp

$(_builddir)IshikoMemoryTests_WordTests.o: ../../src/WordTests.cpp
	$(CXX) -c -o $@ $(CPPFLAGS) $(CXXFLAGS) -MD -MP -pthread -DPUGIXML_HEADER_ONLY -I$(ISHIKO_CPP_BASEPLATFORM_ROOT)/include -I$(ISHIKO_CPP_ERRORS_ROOT)/include -I$(ISHIKO_CPP_MEMORY_ROOT)/include -I$(ISHIKO_CPP_BOOST_ROOT)/include -I$(ISHIKO_CPP_TEXT_ROOT)/include -I$(ISHIKO_CPP_CONFIGURATION_ROOT)/include -I$(ISHIKO_CPP_IO_ROOT)/include -I$(ISHIKO_CPP_FILESYSTEM_ROOT)/include -I$(ISHIKO_CPP_TYPES_ROOT)/include -I$(ISHIKO_CPP_DIFF_ROOT)/include -I$(ISHIKO_CPP_PUGIXML_ROOT)/src -I$(ISHIKO_CPP_XML_ROOT)/include -I$(ISHIKO_CPP_PROCESS_ROOT)/include -I$(ISHIKO_CPP_FMT_ROOT)/include -I$(ISHIKO_CPP_TIME_ROOT)/include -I$(ISHIKO_CPP_TESTFRAMEWORK_ROOT)/include -std=c++11 ../../src/WordTests.cpp

clean:
	rm -f $(_builddir)*.o
	rm -f $(_builddir)*.d
	rm -f $(_builddir)IshikoMemoryTests

.PHONY: all clean

# Dependencies tracking:
-include $(_builddir)*.d
