quiz: index.o layout.o math_quiz.o
	g++ index.o layout.o math_quiz.o -o quiz
	mv quiz ./build/

index.o: index.cpp
	g++ -c index.cpp

layout.o: layout.cpp
	g++ -c layout.cpp

math_quiz.o: math_quiz.cpp
	g++ -c math_quiz.cpp

clean:
	rm *.o ./build/quiz


