#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Password {
private:
    string site;
    string username;
    string password;

public:
    Password(const string& site, const string& username, const string& password)    // I used "const" here to ensure that the parameters are not changed.
       :site(site), username(username), password(password){}                        // This is called (Initialization List) to set initail values for the object's Password.
  
    string getSite() const { return site; }                                         // This is to read the values of objects.
    string getUsername() const { return username; }
    string getPassword() const { return password; }  
    
    void display() const { cout << "Site: " << site << endl;                        // display() use for display the details of object.
    }
};

class PasswordManager {
private:
    vector<Password> passwords;                    // I used " vector " here to provides a flexible, dynamic list of Password objects to store. Using vector, I can easily add, delete, or modify an unlimited number of passwords, making it suitable for managing a changing set of data efficiently.

public:
    void addPassword(const Password& password) {passwords.push_back(password);}     // This function for add a new Password to Passwords List.
    void viewPasswords()const{                                                      // This Function for view the List of Passwords.
        if(passwords.empty()){
            cout << "No passwords stored." << endl;}
        else{
            for(const auto &password : passwords){
                password.display();
            }
          }
        }
    void deletePassword(const string &site){                                        // This for remove the any Password that link with site that i want. 
        auto it = remove_if(passwords.begin(), passwords.end(),[&site](const Password &p){
            return p.getSite() == site;
        });

        if (it != passwords.end()){
            passwords.erase(it, passwords.end());
            cout << "Password for site " << site << " deleted." << endl;
        } else {
            cout << "No password found for site " << site << "." << endl;
        }
    }

    bool checkpasswordstrength(const string &password) const {                      // This to Check if the Password Strength or Not
        return password.length() >= 8 &&
               any_of(password.begin(), password.end(), ::isdigit)&&
               any_of(password.begin(), password.end(), ::isupper)&&
               any_of(password.begin(), password.end(), ::islower);
    }
};

int main(){
    PasswordManager manager;
    int choice;
    string site, username, password;

    do {
        cout << "\nPassword Manager\n";
        cout << "1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Delete Password\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                 cout << "Enter site : ";
                 cin >> site;
                 cout << "Enter username : ";
                 cin >> username;
                 cout << "Enter password : ";
                 cin >> password;

                 if (manager.checkpasswordstrength(password)){
                    manager.addPassword(Password(site, username, password));
                    cout << "Password added successfully\n";
                 } else {
                    cout << "Week Password!! It must at least 8 characters long, and include at least one uppercase letter, one lowercase letter, and one digit.\n";
                 }
                 break;

            case 2 :
                manager.viewPasswords();
                break;

            case 3 :
                cout << "Enter site to delete: ";
                cin >> site;
                manager.deletePassword(site);
                break;
            
            case 4 :
                cout << "Exiting Password Manager.\n";
                break;

            default:
                cout << "Invaild choice. Please try again.\n";
        }
   } while (choice != 4);

   return 0;

}