#exe file
EXE_FILE := program.exe

#list of cpp files
SRC_FILES := ./main.cpp
SRC_FILES += ./scanner.cpp   			

build_message:
	@echo "building..."
	@echo "program.exe is created"
clean_message:
	@echo "cleaning..."
run_message:
	@echo "running..."
	@echo "output.txt is created"
build:build_message
	@g++ $(SRC_FILES) -o $(EXE_FILE)
clean:clean_message
	@rm ./$(EXE_FILE)
run: build run_message
	@./$(EXE_FILE)
