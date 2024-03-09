# Contact-list

This C program implements a simple contact management system. Here are the functionalities it includes:

Add a Contact (addContact function):

Allows the user to add a new contact with a name and a number.
Dynamically allocates memory to store the new contact.
Increments the total count of contacts.
List all Contacts (listContact function):

Displays a list of all contacts along with their names, numbers, and completion status.
Iterates through the contact list and prints each contact's details.
Search for a Contact (searchContact function):

Searches for a contact by name.
Displays the contact details if found, including the name and number.
Indicates if the contact is not found.
Delete a Contact (deleteContact function):

Deletes a contact by name.
Shifts the remaining contacts to fill the gap left by the deleted contact.
Decrements the total count of contacts.
Notifies the user if the contact is not found.
Edit a Contact (editContact function):

Allows the user to edit the name and number of a contact by specifying the contact's name.
Prompts the user to enter the new name and number.
Updates the contact's details if found.
Notifies the user if the contact is not found.
Main Menu:

Displays a menu with options to add, list, search, edit, delete contacts, and exit.
Reads the user's choice and executes the corresponding functionality.
Continuously prompts the user for options until they choose to exit.
Overall, this program provides basic functionalities to manage a list of contacts, including adding, listing, searching, editing, and deleting contacts.