CC = g++
CFLAGS = -Wall -g 
BASIC_DIR = PAT_Basic_Level_Practise
ADVANCED_DIR = PAT_Advanced_Level_Practise
BASIC_SRCS = $(wildcard $(BASIC_DIR)/*.cpp)
ADVANCED_SRCS = $(wildcard $(ADVANCED_DIR)/*.cpp)
OBJS = $(patsubst %.cpp, $(BASIC_DIR)/%, $(notdir $(BASIC_SRCS))) \
	$(patsubst %.cpp, $(ADVANCED_DIR)/%, $(notdir $(ADVANCED_SRCS)))

.PHONY: all clean
all: $(OBJS)
%:%.cpp
	$(CC) $(CFLAGS) -o $@ $<
clean:
	rm -f $(OBJS)