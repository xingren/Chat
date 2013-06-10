chat: Main.o ChatListItem.o ChatPerson.o ChatTabUI.o
	g++ -o chat Main.o ChatListItem.o ChatPerson.o `wx-config --cxxflags` `wx-config --libs`

Main.o: ./src/Main.cpp ./include/Main.h
	g++ -c src/Main.cpp `wx-config --cxxflags` `wx-config --libs`
ChatPerson.o: ./src/ChatPerson.cpp ./include/ChatPerson.h
	g++ -c src/ChatPerson.cpp `wx-config --cxxflags` `wx-config --libs`
ChatListItem.o: ./src/ChatListItem.cpp ./include/ChatListItem.h
	g++ -c src/ChatListItem.cpp `wx-config --cxxflags` `wx-config --libs`

ChatTabUI.o: ./src/ChatTabUI.cpp ./include/ChatTabUI.h
	g++ -c src/ChatTabUI.cpp `wx-config --cxxflags` `wx-config --libs`

clean:
	rm Main.o ChatListItem.o ChatPerson.o
