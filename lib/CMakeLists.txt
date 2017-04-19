cmake_minimum_required(VERSION 3.4)
project(LibHotel)


#file(GLOB SOURCE_FILES src/*.cpp includes/*)
set(SOURCE_FILES
    include/Address.hpp
	include/Employee.hpp
	include/Hotel.hpp
    include/IHotel.hpp
	include/IHotelCLI.hpp
	include/Manager.hpp
	include/Person.hpp
	include/Date.hpp
	include/Bill.hpp
	include/Booking.hpp
	include/Floor.hpp
	include/Payment.hpp
	include/Room.hpp
	include/Cleaner.hpp
	include/Customer.hpp
	include/Equipment.hpp
	include/Receptionist.hpp
	include/TV.hpp
	include/Bed.hpp
	include/Sheets.hpp
	include/ExceptionCin.hpp
	src/Address.cpp
	src/Employee.cpp
	src/Hotel.cpp
	src/IHotelCLI.cpp
	src/Manager.cpp
	src/Person.cpp
	src/Date.cpp
	src/Bill.cpp
	src/Booking.cpp
	src/Floor.cpp
	src/Payment.cpp
	src/Room.cpp
	src/Cleaner.cpp
	src/Customer.cpp
	src/Equipment.cpp
	src/Receptionist.cpp
	src/TV.cpp
	src/Bed.cpp
	src/Sheets.cpp
	src/ExceptionCin.cpp
)


add_library(LibHotel ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(LibHotel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/master.cpp
        test/HotelTest.cpp
	test/AddressTest.cpp
	test/BedTest.cpp
	test/BillTest.cpp
	test/BookingTest.cpp
        )

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

target_link_libraries (Test
        LibHotel
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibHotelTest Test)

