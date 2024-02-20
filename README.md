# Grocery Store Mangement With Binary File Handling
A large grocery store company is revamping their business and moving from manual to automated  processes and management. The company has branches all over Pakistan and wants you to develop  an object-oriented software to improve customers shopping experience (in person and virtually). 
# Features
# 1. Registration 
Registration details are stored in three separate files namely admin, manager & customer. These files have User details. Note: carefully analyze and select the attributes that need to be stored in  these files. 
• Customer registration 
o A new customer can register into the system by providing a valid 13-digit  CNIC. 
o Password must be 9 characters long and use of a minimum of one uppercase  letter and one numeric digit is must. 
o Customer should be asked to re-enter the password and check for any typing  mistake. 
o Customer’s account cannot be repeated. If it already exists, then appropriate  messages should be displayed to notify the user. 
o Customer’s gender, phone number, address and other personal information  should also be stored. 
• Manager registration 
o A new manager can only be registered by the admin and store should be  assigned to that manager by the admin based on location. 
# 2. Login  
• Admin  
o Admin can login to the system with predefined username and password. o Display proper error messages if wrong credentials are entered. 
• Manager  
o Manager can login to the system with predefined username and password. o Display proper error messages if wrong credentials are entered. 
• Customer 
o Customer can login to the system with predefined username and password. o Display proper error messages if wrong credentials are entered. 
# 3. Home screen & sub menus 
• Different home screens should be displayed to every kind of user after they have logged into  the system. Proper menus are to be displayed.
# 4. Manage stores and users 
This module is only available to admins of the systems 
The admin manages the records of all stores open in the country. Additionally, the store managers  cannot register with the system themselves; they must be added to the system by an admin. The  admin can also remove spam customers and prevent them from creating new accounts 
# 5. Manage product catalog 
This module is only available to admins of the systems 
The company deals with multiple categories of products including, food, personal hygiene and  household cleaning. For your simplicity you can assume that a product is only available from a single  company. Also, prices of every product are to be specified when adding each product. 
 These products can be further divided into subcategories 
• Food 
o Perishable Goods 
▪ Meat 
• Chicken 
• Beef 
• Mutton 
• Fish 
▪ Dairy 
• Milk 
• Eggs 
• Yogurt 
• Cheese 
▪ Fruit 
• Apple 
• Banana 
• Mango 
• Orange 
• Watermelon 
▪ Vegetable 
• Tomato 
• Onion 
• Cucumber 
• Potatoes 
o Non-Perishable Goods 
▪ Snacks 
• Chocolates 
• Chips 
• Biscuits 
▪ Spices
▪ Grains 
• Lentils 
• Wheat 
• Flour 
• Rice 
▪ Cereal 
• Personal Hygiene 
o Shampoo 
o Soap 
o Hand Sanitizer 
• Household Cleaning 
o Detergent 
o Dish Soap 
o Washroom Cleaner 
Product catalog is not “Inventory”. Product catalog is just all the possible categories of products a  store can carry, and an Inventory contains lists of all the items in the store. Create separate Classes  for both Product Catalog and Inventory. 
Product Catalog should also be saved into a separate file and should be populated from the file  each time the program starts. 
Make sure all products are measured in correct units, e.g., fruits, vegetables, grains and meat are  measured in kilograms, eggs are measured in dozens. 
The system admins can add, remove and update products in the product catalog. All changes must  reflect in the Product Catalog file. 
# 6. Inventory management 
This module is only available to store managers 
The company has stores all over Pakistan, each store has its own inventory managed through this  system. It consists of the following sub modules: 
Add, Remove and Update Inventory Items: 
The manager of a store can add, delete and update items along with its quantity only in the inventory  of their store. If the stock ends the status of the item should be “Not Available”. 
All the items in the inventory should be saved in a separate file, each time the program starts, data  from the file should be populated into the inventory of the respective store. All changes made in the  inventory should be saved into the file in real-time during program execution. For example, the  company has stores in Islamabad, Lahore and Karachi, there would be separate file for inventory of  each store. To avoid confusion, you can create a separate directory as “Inventory Management” and  save inventory details of each store in that directory. 
Search and View inventory items: 
A store manager can view and search products in the inventory of any other store. For example, the  company has stores in Islamabad, Lahore and Karachi. The manager of the Islamabad store can add, 
delete and update items in Islamabad store’s inventory but the same manager can also view and  search for a product in Lahore and Karachi stores inventory. 
# 7. Online Shopping 
This module is only available for customers  
Add to Cart 
Checkout and Payment 
Feedback 
# 8. Payment 
After checkout, customer is asked to pay. You have to implement payment gateways for example,  COD (Cash on Delivery), Debit or Credit card, Easypaisa, Jazz cash or any other way you can think  of.  
If the user asks for Cash on delivery, the system should charge 50 rupees extra if the customer is  not in the same city as the store or 30 rupees if in the same city. 
