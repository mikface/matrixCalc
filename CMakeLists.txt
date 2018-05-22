cmake_minimum_required(VERSION 3.7)
project(MatrixCalc)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp src/App.cpp src/calc/Help.cpp src/config/StateEnum.h src/calc/InputHandler.cpp src/calc/InputHandler.h src/matrix/Matrix.cpp src/matrix/Matrix.h src/matrix/IdentityMatrix.cpp src/matrix/IdentityMatrix.h src/matrix/DenseMatrix.cpp src/matrix/DenseMatrix.h src/matrix/SparseMatrix.cpp src/matrix/SparseMatrix.h src/operation/Operation.cpp src/operation/Operation.h src/operation/BinaryOperation.cpp src/operation/BinaryOperation.h src/calc/Calculator.cpp src/calc/Calculator.h src/config/CommandEnum.h src/command/Command.cpp src/command/Command.h)
add_executable(MatrixCalc ${SOURCE_FILES})