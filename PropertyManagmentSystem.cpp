#include <iostream>
#include <fstream>
#include <string>
#include <vector> // For dynamic property storage
#include <cstdlib> // For exit()

using namespace std;

class Person {
protected:
    string name;
    int contact;
    string id;
public:
    void setname(string name) { this->name = name; }
    void setid(string id) { this->id = id; }
    void setcontact(int contact) { this->contact = contact; }
    string getname() const { return name; }
    string getid() const { return id; }
    int getcontact() const { return contact; }
};

class Manager : public Person {
private:
    string password;
public:
    Manager() { this->password = "admin"; }
    void setpassword(string pass) { this->password = pass; }
    string getpassword() const { return password; }
};

class Agent : public Person {
public:
    Agent() { ; }
    Agent(string name, string id, int contact) {
        this->name = name;
        this->contact = contact;
        this->id = id;
    }
};

class Property {
private:
    float sellingPrice;
    // postalcode easier than whole address
    int postalCode;
    float size;
    string type;
    int rooms;
    Agent agent;

public:
    void setSellingPrice(float x) { this->sellingPrice = x; }
    void setPostalCode(int x) { this->postalCode = x; }
    void setsize(float x) { this->size = x; }
    void setType(string x) { this->type = x; }
    void setrooms(int x) { this->rooms = x; }
    void setAgent(const Agent& x) { this->agent = x; }
    float getsellingPrice() const { return sellingPrice; }
    int getPostalCode() const { return postalCode; }
    float getsize() const { return size; }
    string getType() const { return type; }
    int getrooms() const { return rooms; }
    const Agent& getagent() const { return agent; }
    Property() { ; }
    Property(float sp, int pcode, float size, string type, int rooms, const Agent& A) :
        sellingPrice(sp), postalCode(pcode), size(size), type(type), rooms(rooms), agent(A) {}
};

// Function to remove a property
void removeProperty(vector<Property>& properties) {
    int postal_code;
    cout << "Enter postal code of property you want to remove:";
    cin >> postal_code;
    for (auto& prop : properties) {
        if (prop.getPostalCode() == postal_code) {
            // Remove property by setting its details to default or empty values
            prop = Property();
            cout << "Property removed successfully." << endl;
            return;
        }
    }
    cout << "Property with given postal code not found." << endl;
}

// Function to display all properties
void displayProperties(const vector<Property>& properties) {
    for (const auto& prop : properties) {
        cout << "Postal code: " << prop.getPostalCode() << endl;
        cout << "Type of property: " << prop.getType() << endl;
        cout << "Number of rooms in property: " << prop.getrooms() << endl;
        cout << "Size of property: " << prop.getsize() << endl;
        cout << "Price of property: " << prop.getsellingPrice() << endl;
        cout << "Agent assigned to property: " << prop.getagent().getname() << endl;
    }
}

// Function to add a new property
void addProperty(vector<Property>& properties) {
    string type, name, id;
    int postal_code, contact, num;
    float size, price;

    cout << "Enter data for the property:" << endl;
    cout << "\nType of property:";
    cin >> type;
    cout << "\nPostal code of location of property:";
    cin >> postal_code;
    cout << "\nSize of property:";
    cin >> size;
    cout << "\nSelling price of property:";
    cin >> price;
    cout << "\nTotal rooms in property:";
    cin >> num;
    cout << "\nEnter agent name:";
    cin >> name;
    cout << "\nEnter agent id:";
    cin >> id;
    cout << "\nEnter agent contact:";
    cin >> contact;
    Agent agent(name, id, contact);
    properties.emplace_back(Property(price, postal_code, size, type, num, agent));
}

int main() {
    int choice;
    Manager manager;
    vector<Property> properties;

    cout << "Welcome to the Property Database Program.\nSign in as \n1)Manager\n2)Agent" << endl;
    cin >> choice;
    if (choice == 1) {
        string name, password;
        cout << "Enter manager name:";
        cin >> name;
        manager.setname(name);
        cout << "Enter manager password:";
        cin >> password;
        manager.setpassword(password);
    }
    
    while (true) {
        cout << "Menu" << endl;
        cout << "(1) Add new property" << endl;
        cout << "(2) Remove property " << endl;
        cout << "(3) Display information" << endl;
        cout << "(4) Quit" << endl;
        cout << "Enter choice:";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addProperty(properties);
                break;
            case 2:
                removeProperty(properties);
                break;
            case 3:
                displayProperties(properties);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Input" << endl;
                break;
        }
    }
    return 0;
}