CC = g++ 
wxflags = `wx-config --cxxflags`
wxlibs = `wx-config --libs`

source_path = ./src
sources := $(wildcard $(source_path)/*.cpp) 
objects := $(sources: .cpp=.o) 
executable := chat

all:$(sources) $(executable)

$(executable) : $(objects)
		$(CC) $(wxflags) $^ -o $@ $(wxlibs)
.cpp.o:
		$(CC) $< -o $@ 
% : %.cpp
		$(CC) $(wxflags)  $^ -o $@ $(wxlibs) 
.PHONY:clean
clean: 
		rm *.o $(executable)


