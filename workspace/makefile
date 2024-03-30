# Compiler
CC = arm-none-eabi-g++
# Compiler flags
CFLAGS = -mcpu=arm7tdmi -march=armv4t -mthumb -mlittle-endian -mfloat-abi=soft -munaligned-access -mtune=arm7tdmi -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g3
# Linker flags
LDFLAGS = -Xlinker --gc-sections --specs=rdimon.specs -Wl,-Map,"debug/ARM7TDI_Compile.map"
# Libraries
LIBS = -lgcc -lc -lm -lrdimon

# Source files
SRCS = src/main.cpp
# Object files
OBJS = $(addprefix debug/,$(notdir $(SRCS:.cpp=.o)))
# Output executable
TARGET = debug/ARM7TDI_Compile.elf
HEX = debug/ARM7TDI_Compile.hex

# Build rule
all: $(TARGET) $(HEX)

$(TARGET): $(OBJS) | debug
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(HEX): $(TARGET)
	arm-none-eabi-objcopy -O ihex $< $@
	
debug/%.o: src/%.cpp | debug
	$(CC) $(CFLAGS) -Iinc -Ianotherincludedir -c -o $@ $<

debug:
	mkdir debug

clean:
	rm -rf debug

clean-pwsh:
	powershell.exe -Command "Remove-Item -Recurse -Force debug"

.PHONY: all clean
