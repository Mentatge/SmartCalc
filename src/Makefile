CC = gcc -Wall -Werror -Wextra -g -std=c11
SRC= $(wildcard s21_*.c)
OBJ= $(patsubst %.c, %.o, ${SRC})
LFLAGS= -lcheck -lpthread 
GCF= -ftest-coverage -fprofile-arcs --coverage
VAL= valgrind --tool=memcheck --leak-check=yes
QT_PROJECT_NAME = Calculator
QT_PROJECT_FOLDER = $(QT_PROJECT_NAME)
QT_PRO = $(QT_PROJECT_NAME).pro
QT_MAKEFILE = $(QT_PROJECT_NAME)_Makefile
QT_BUILD_FOLDER = build
QT_APP_FOLDER = ../App
DIST_FOLDER_NAME = SmartCalc-1.0
OS_NAME = $(shell uname -s)


ifeq ($(shell uname -s), Linux)
	LFLAGS += -lrt -lsubunit -lm
endif

all: install test gcov_report

install: generate_make
	echo "Building application..."
	cd ./$(QT_BUILD_FOLDER) && make -sf $(QT_MAKEFILE)
	echo "Application builded."
	echo  "Moving application to folder \"$(QT_APP_FOLDER)\"..." -n
	mkdir -p ./$(QT_APP_FOLDER)
ifeq ($(OS_NAME), Linux) 
	mv build/$(QT_PROJECT_NAME) ../App 
endif 
ifeq ($(OS_NAME), Darwin)
	mv build/$(QT_PROJECT_NAME).app ../App
endif
	echo " Done."
	echo -n "Deleting build folder..."
	rm -rf $(QT_BUILD_FOLDER)
	echo " Done."
	echo "Installation complete!"

generate_make:
	qmake $(QT_PROJECT_FOLDER)/$(QT_PRO)  -o ./$(QT_BUILD_FOLDER)/$(QT_MAKEFILE)
	rm -rf .qmake.stash

uninstall:
	echo -n "Uninstalling application..."
	rm -rf $(QT_APP_FOLDER)
	echo " Done"

TAR_DIR = SmartCalc_v1.0_v1.0_Archive

rebuild: clean s21_calc.a


clean:
	rm -rf *.o && rm -rf *.gcno
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.dSYM
	rm -rf *.info && rm -rf *.gcov
	rm -rf ./test && rm -rf ./gcov_report
	rm -rf ./report/
	rm -rf test_output/
	rm -rf build/

s21_calc.o:
	$(CC) -c ${SRC} 

s21_calc.a: s21_calc.o
	ar rcs s21_calc.a ${OBJ} 
	ranlib s21_calc.a
	rm *.o


test: unit_tests.c s21_calc.a

	$(CC) -o test $^ ${LFLAGS} 
	./test

gcov_report: test
	$(CC) $(GCF) unit_tests.c $(SRC)  $(LFLAGS) -o gcov_report
	./gcov_report
	lcov -t "test" -o gcov_report.info -c -d .
	genhtml -o test_output gcov_report.info
	open ./test_output/index.html\

style:
	cp ../materials/linters/.clang-format ./
	clang-format -style=Google -i *.c
	rm -f .clang-format