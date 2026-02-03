Automobile Management System (C++)
A comprehensive command-line application designed to simulate the operations of an automobile dealership. This project was developed as part of my initial introduction to programming, focusing on Object-Oriented Programming (OOP) principles in C++.

🚀 Features
The system is divided into several modules to handle different aspects of vehicle transactions:

Secure Authentication: User registration and login system featuring basic password encryption (Shift Cipher).

Inventory Management: A pre-defined list of popular vehicles with real-time price tracking.

Buy & Sell: Users can purchase existing inventory or list their own vehicles for sale.

Rent & Lease: Logic for short-term renting and long-term leasing with dynamic pricing based on duration.

Finance & Payments: * Supports Cash, Card, and Cheque.

EMI Calculator: Automatically calculates down payments and monthly installments based on the user's CIBIL credit score.

Accessories Store: A dedicated shop for vehicle add-ons (LEDs, Cameras, etc.) with quantity-based cost calculation.

General Enquiry: Allows guest users to view inventory and accessories before logging in.

🛠️ Technical Concepts Used
This project implements several advanced C++ concepts:

Inheritance: Used to pass financial processing capabilities from the Finance class to the buy_sell, Rent_Lease, and Accessories classes.

Function Overloading: The Pay() method is overloaded to handle different parameters (Card numbers, Cheque details, or Credit scores).

Friend Classes: Rent_Lease is a friend of buy_sell to allow seamless access to vehicle inventory data.

Data Encapsulation: Logic and data are bundled within classes to maintain a clean structure.

Encryption: A simple character-shifting algorithm to demonstrate basic security concepts.

💻 How to Run
Clone the Repository:

Bash
git clone https://github.com/your-username/automobile-management-system.git
Compile the Code: Using a compiler like g++:

Bash
g++ main.cpp -o auto_system
Execute the Program:

Bash
./auto_system
