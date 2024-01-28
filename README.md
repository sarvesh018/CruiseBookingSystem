# Cruise Booking System

This project is a cruise booking system implemented in C++ with Object-Oriented Programming (OOP) concepts. Users can select journey details and choose seat types for the cruise, including Economy, Business, and Deluxe. 
The system allows users to check booking status, cancel bookings, and handles situations where seats are not available by placing passengers on a waiting list.

## How to Run

To run the project on your local machine, follow these commands:

1. Compile the source code: g++ Main.cpp Passenger.cpp Cruise.cpp storeDetails.cpp Admin.cpp handleWaitingList.cpp -o run

2. Execute the compiled program: ./run

## Project Structure

The project is organized into multiple C++ files:

- `Main.cpp`: Main program file for user interaction.
- `Passenger.cpp`: Manages passenger-related functionalities.
- `Cruise.cpp`: Handles cruise-related details and functionalities.
- `storeDetails.cpp`: Manages storing details in separate text files.
- `Admin.cpp`: Implements administrative functionalities.
- `handleWaitingList.cpp`: Handles the waiting list when seats are not available.

## Data Storage

Passenger details are stored in a separate `.txt` file, which is updated when a booking is made or canceled. Similarly, cruise details are stored in their respective files.

Feel free to explore and contribute to the project!

