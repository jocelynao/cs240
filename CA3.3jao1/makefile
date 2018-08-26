
all:	FBLite

FBLite:	FBLUserLL.o FBLUser.o FBLUserNode.o FBLPostNode.o FBLPostLL.o FBLPostNode.o FBLPost.o FBLFeedLL.o FBLComment.o  FBLCommentsLL.o CA3.3.o
	g++ FBLUser.o FBLUserNode.o FBLUserLL.o FBLPostLL.o FBLPostNode.o FBLPost.o FBLFeedLL.o FBLComment.o FBLCommentsLL.o CA3.3.o -o FBLite

FBLCommentsLL.o: FBLCommentsLL.cpp
	g++ -c FBLCommentsLL.cpp

FBLComment.o: FBLComment.cpp
	g++ -c FBLComment.cpp

FBLFeedLL.o: FBLFeedLL.cpp
	g++ -c FBLFeedLL.cpp

FBLPost.o: FBLPost.cpp
	g++ -c FBLPost.cpp

FBLPostLL.o: FBLPostLL.cpp
	g++ -c FBLPostLL.cpp

FBLPostNode.o: FBLPostNode.cpp
	g++ -c FBLPostNode.cpp

FBLUserNode.o: FBLUserNode.cpp
	g++ -c FBLUserNode.cpp

FBLUserLL.o: FBLUserLL.cpp
	g++ -c FBLUserLL.cpp

FBLUser.o: FBLUser.cpp
	g++ -c FBLUser.cpp

CA3.3.o: CA3.3.cpp
	g++ -c CA3.3.cpp

clean:
	rm -f *.o FBLit
