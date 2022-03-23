cmake_minimum_required(VERSION 3.0.0)

project(2-modularity)

# Define a variable called TARGET_NAME with value ${PROJECT_NAME}
# PROJECT_NAME is a predefined variable of CMake that contains: the name of the
# project given to the project command.
# So in this case it should be 2-modularity
set(TARGET_NAME ${PROJECT_NAME})

# Create an executable target, whose name will be ${TARGET_NAME}
add_executable(${TARGET_NAME})
target_sources(${TARGET_NAME}
	PRIVATE
	main.c
	spi_bus/spi_bus.c
	temperature_sensor/temperature_sensor.c
	configuration/common.c
	)
target_include_directories(${TARGET_NAME}
	PRIVATE
	spi_bus
	temperature_sensor
	configuration
	)

if ("${CONFIGURATION_FAKE_IMPL}" STREQUAL "default")
	target_sources(${TARGET_NAME}
		PRIVATE
		configuration/fake_default.c
		)
elseif("${CONFIGURATION_FAKE_IMPL}" STREQUAL "file")
	target_sources(${TARGET_NAME}
		PRIVATE
		configuration/fake_file.c
		)
elseif("${CONFIGURATION_FAKE_IMPL}" STREQUAL "user_input")
	target_sources(${TARGET_NAME}
		PRIVATE
		configuration/fake_user_input.c
		)
else()
	message(FATAL_ERROR "Unsupported value \"${CONFIGURATION_FAKE_IMPL}\" for CONFIGURATION_FAKE_IMPL")
endif()
