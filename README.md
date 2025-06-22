🍽️ Restaurant Management System

A comprehensive console-based application for managing all aspects of a restaurant business, written in C++.

✨ Features

🍲 Menu Management
- Create multiple menu categories (e.g., Deserts, Main Course)
- Add/Remove/Update dishes with details (name, category, price, availability)
- View all dishes in a specific menu
- Track dish availability status

👥 Customer Management
- Add new customers with order details
- View/Update/Delete customer records
- Generate customer bills automatically
- Search for specific customers

👨‍🍳 Employee Management
- Add/Remove/Update employee records
- Assign orders to employees
- Track which employees serve which customers
- View all employee details

📊 Reporting
- Real-time sales tracking
- Customer count statistics
- Specific dish sales analysis
- Order tracking and management

🔐 Authentication
- Secure manager login system
- Role-based access control


💻 Installation

1. Prerequisites:
   - C++ compiler (g++ or equivalent)
   - Standard Library support

2. Compilation:
   g++ main.cpp -o restaurant_management -std=c++17

3. First-Time Setup:
   Create a manager.txt file with your credentials:
   admin
   password123
4. Run the compiled executable:
   ./restaurant_management


🚀 Main Menu Options:

1) Manager Activities (requires login)
   Manage menus and dishes
   View sales reports
   Analyze specific dish performance

2) Customer Panel
   Add new customers
   Manage customer orders
   View/Update customer details

3) Employee Panel
   Add/Remove employees
   Assign orders to staff
   View employee details

4) Exit Program
