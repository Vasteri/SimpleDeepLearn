FLAGS=-Wall -Werror -Wextra

all: rebuild

rebuild: clean build

build:
	g++ $(FLAGS) ./DeepLearn/Model.cpp  \
	./DeepLearn/Functions/*.cpp         \
	./DeepLearn/Layers/*.cpp  			\
	./main.cpp -o ../build/main

exec:
	../build/main

clean:
	rm -rf ../build/*

format:
	clang-format -i main.cpp \
	./Matrix/*.*pp \
	./DeepLearn/*.*pp \
	./DeepLearn/Functions/*.*pp \
	./DeepLearn/Layers/*.*pp

check:
	cppcheck --enable=all --std=c++17 \
	main.cpp \
	./Matrix/*.cpp \
	./DeepLearn/*.cpp \
	./DeepLearn/Functions/*.cpp \
	./DeepLearn/Layers/*.cpp

../build/test_mat.o:
	g++ -c ./Matrix/test_mat.cpp -o ../build/test_mat.o

matrix_test: clean ../build/test_mat.o
	g++ $(FLAGS) ../build/test_mat.o -o ../build/matrix_test
	../build/matrix_test