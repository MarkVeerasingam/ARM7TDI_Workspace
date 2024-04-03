# Compiler
CC = arm-none-eabi-g++
# Compiler flags
CFLAGS = -mcpu=arm7tdmi -march=armv4t -mthumb -mlittle-endian -mfloat-abi=soft -mtune=arm7tdmi -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -g3 -Iinc -Ianotherincludedir -Iinc/bios -Iinc/applications -Iinc/applications/Dialog -Iinc/drivers
# Linker flags
LDFLAGS = -Xlinker --gc-sections --specs=rdimon.specs -Wl,-Map,"debug/ARM7TDI_Compile.map"
# Libraries
LIBS = -lgcc -lc -lm -lrdimon

# Source files
SRCS = $(wildcard src/applications/*.cpp) \
       $(wildcard src/bios/*.cpp) \
	   $(wildcard src/drivers/*.cpp) \

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
	
debug/%.o: src/applications/%.cpp | debug
	$(CC) $(CFLAGS) -c -o $@ $<

debug/%.o: src/bios/%.cpp | debug
	$(CC) $(CFLAGS) -c -o $@ $<

debug/%.o: src/drivers/%.cpp | debug
	$(CC) $(CFLAGS) -c -o $@ $<

debug:
	mkdir debug

clean:
	rm -rf debug

clean-pwsh:
	powershell.exe -Command "Remove-Item -Recurse -Force debug"

.PHONY: all clean
