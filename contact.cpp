#include <iostream>

#include <fstream>

#include <algorithm>

#include <vector>

#include <string>



using namespace std;



class Contact {

public:

    string name;

    string phone;

    string email;



    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}

};



class ContactManagement {

private:

    string file_name;

    vector<Contact> contacts;



public:

    ContactManagement(string filename) : file_name(filename) {

        loadContacts();

    }



    void loadContacts() {

        ifstream file(file_name);

       

        string name, phone, email;

        while (file >> name >> phone >> email) {

            contacts.push_back(Contact(name, phone, email));

        }



        file.close();

    }



    void saveContacts() {

        ofstream file(file_name);

       

        for (const auto& contact : contacts) {

            file << contact.name << " " << contact.phone << " " << contact.email << endl;

        }



        file.close();

    }



    void addContact(const Contact& contact) {

        contacts.push_back(contact);

        saveContacts();

        cout << "Contact added successfully." << endl;

    }



    void deleteContact(const string& name) {

        auto it = find_if(contacts.begin(), contacts.end(), [&name](const Contact& c) {

            return c.name == name;

        });



        if (it != contacts.end()) {

            contacts.erase(it);

            saveContacts();

            cout << "Contact deleted successfully." << endl;

        } else {

            cout << "Contact not found." << endl;

        }

    }



    void displayContacts() {

        if (contacts.empty()) {

            cout << "No contacts to display." << endl;

            return;

        }



        cout << "Contacts:" << endl;

        for (const auto& contact : contacts) {

            cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;

        }

    }

};



int main() {

    ContactManagement cm("contacts.txt");



    while (true) {

        cout << "\nContact Management System" << endl;

        cout << "1. Add Contact" << endl;

        cout << "2. Delete Contact" << endl;

        cout << "3. Display Contacts" << endl;

        cout << "4. Exit" << endl;



        int choice;

        cin >> choice;



        switch (choice) {

            case 1: {

                string name, phone, email;

                cout << "Enter name: ";

                cin >> name;

                cout << "Enter phone number: ";

                cin >> phone;

                cout << "Enter email address: ";

                cin >> email;

                Contact newContact(name, phone, email);

                cm.addContact(newContact);

                break;

            }

            case 2: {

                string name;

                cout << "Enter name of contact to delete: ";

                cin >> name;

                cm.deleteContact(name);

                break;

            }

            case 3:

                cm.displayContacts();

                break;

            case 4:

                cout << "Exiting program." << endl;

                return 0;

            default:

                cout << "Invalid choice. Please try again." << endl;

        }

    }



    return 0;

}