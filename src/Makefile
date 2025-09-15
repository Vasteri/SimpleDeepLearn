FLAGS=-Wall -Werror -Wextra
CPP_FILES=./DeepLearn/Model.cpp  \
	./DeepLearn/Functions/*.cpp  \
	./DeepLearn/Layers/*.cpp
ALL_FILES=main.cpp \
	./Matrix/*.*pp \
	./DeepLearn/*.*pp \
	./DeepLearn/Functions/*.*pp \
	./DeepLearn/Layers/*.*pp

all: rebuild

rebuild: clean build

debug: format check rebuild exec

build:
	g++ $(FLAGS) $(CPP_FILES)  \
	./main.cpp -o ../build/main

exec:
	../build/main

clean:
	rm -rf ../build/*

format:
	clang-format -i $(ALL_FILES)

check:
	cppcheck --enable=all --std=c++17 \
	--suppress=missingIncludeSystem --suppress=unusedFunction --suppress=checkersReport \
	main.cpp \
	$(CPP_FILES)


../build/test_mat.o:
	g++ -c ./Matrix/test_mat.cpp -o ../build/test_mat.o

matrix_test: clean ../build/test_mat.o
	g++ $(FLAGS) ../build/test_mat.o -o ../build/matrix_test
	../build/matrix_test