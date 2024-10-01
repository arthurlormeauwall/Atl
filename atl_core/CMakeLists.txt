cmake_minimum_required(VERSION 3.25.1)

project(atl_core)

set(SOURCE_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(CONTROLLER_FOLDER "${SOURCE_FOLDER}/controller")
set(MODEL_FOLDER "${SOURCE_FOLDER}/model")
set(OUT_FOLDER "${SOURCE_FOLDER}/out")
set(SERVICE_FOLDER "${SOURCE_FOLDER}/service")
set(TESTBUILDER_FOLDER "${SOURCE_FOLDER}/testBuilder")

add_library(${PROJECT_NAME} STATIC
    ${SOURCE_FOLDER}/atl_includes.h
    ${SOURCE_FOLDER}/template.h

    ${CONTROLLER_FOLDER}/AtlController.cpp
    ${CONTROLLER_FOLDER}/AtlController.h

    ${MODEL_FOLDER}/ChildrenResult.h
    ${MODEL_FOLDER}/Model.h
    ${MODEL_FOLDER}/Result.h
    ${MODEL_FOLDER}/StackMap.h
    ${MODEL_FOLDER}/TestData.h

    ${OUT_FOLDER}/consoleOutput/ConsoleOutputWriter.cpp
    ${OUT_FOLDER}/consoleOutput/ConsoleOutputWriter.h
    ${OUT_FOLDER}/consoleOutput/ConsolePresenter.cpp
    ${OUT_FOLDER}/consoleOutput/ConsolePresenter.h
    ${OUT_FOLDER}/consoleOutput/ConsoleResultStringWriter.cpp
    ${OUT_FOLDER}/consoleOutput/ConsoleResultStringWriter.h
    ${OUT_FOLDER}/consoleOutput/style/color/ConsoleColorHelpers.cpp
    ${OUT_FOLDER}/consoleOutput/style/color/ConsoleColorHelpers.h
    ${OUT_FOLDER}/consoleOutput/style/color/AinsiConsoleColor.h

    ${OUT_FOLDER}/output/OutputWriter.h

    ${OUT_FOLDER}/views/Views.cpp
    ${OUT_FOLDER}/views/Views.h
    ${OUT_FOLDER}/views/AllTestView.h
    ${OUT_FOLDER}/views/CommonViews.h
    ${OUT_FOLDER}/views/ModuleView.h
    ${OUT_FOLDER}/views/ResultView.h
    ${OUT_FOLDER}/views/TestClassView.h
    ${OUT_FOLDER}/views/UnitTestView.h

    ${SERVICE_FOLDER}/AtlService.cpp
    ${SERVICE_FOLDER}/AtlService.h
    ${SERVICE_FOLDER}/TestRunner.cpp
    ${SERVICE_FOLDER}/TestRunner.h
    ${SERVICE_FOLDER}/assertion/IsEqualTo.h
    ${SERVICE_FOLDER}/assertion/ToStringTemplate.h

    ${TESTBUILDER_FOLDER}/TestClassBuilder.cpp
    ${TESTBUILDER_FOLDER}/TestClassBuilder.h
    ${TESTBUILDER_FOLDER}/AllTestBuilder.h
    ${TESTBUILDER_FOLDER}/ModuleBuilder.h
    ${TESTBUILDER_FOLDER}/TestBuilder.h
    ${TESTBUILDER_FOLDER}/TestTreeBuilder.h
    ${TESTBUILDER_FOLDER}/TestTreeBuilder.cpp
    ${TESTBUILDER_FOLDER}/UnitTestBuilder.h
)

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${SOURCE_FOLDER}
)

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_11
)