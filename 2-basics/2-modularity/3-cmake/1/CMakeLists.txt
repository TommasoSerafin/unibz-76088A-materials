cmake_minimum_required(VERSION 3.0.0)

project(2-modularity)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME}
	PRIVATE
	configuration.c main.c spi_bus.c temperature_sensor.c
	)
