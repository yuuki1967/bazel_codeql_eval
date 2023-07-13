#
## check test_qcc_project
Makefile
```
RTIFACT = main

#Build architecture/variant string, possible values: x86, armv7le, etc...
PLATFORM ?= aarch64le

#Build profile, possible values: release, debug, profile, coverage
BUILD_PROFILE ?= debug

CONFIG_NAME ?= $(PLATFORM)-$(BUILD_PROFILE)
OUTPUT_DIR = build/$(CONFIG_NAME)
TARGET = $(OUTPUT_DIR)/$(ARTIFACT)

#Compiler definitions

CC = qcc -Vgcc_nto$(PLATFORM) -nopipe
CXX = qcc -lang-c++ -Vgcc_nto$(PLATFORM) -nopipe
LD = $(CC)

#User defined include/preprocessor flags and libraries

#INCLUDES += -I/path/to/my/lib/include
#INCLUDES += -I../mylib/public

```

```
./configure
make
```

```
roject$ make
qcc -Vgcc_ntoaarch64le -nopipe -c -Wp,-MMD,build/aarch64le-debug/main.d,-MT,build/aarch64le-debug/main.o -o build/aarch64le-debug/main.o  -Wall -fmessage-length=0 -g -O0 -fno-builtin  main.c
main.c:3:10: fatal error: stdio.h: No such file or directory
 #include <stdio.h>
          ^~~~~~~~~
compilation terminated.
Makefile:56: recipe for target 'build/aarch64le-debug/main.o' failed
make: *** [build/aarch64le-debug/main.o] Error 1
```
