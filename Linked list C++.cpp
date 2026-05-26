#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Node class represents each website in the linked list
// by Chris Krawczyk
class Node
{
public:
    // Stores website name
    string website;

    // Stores website URL
    string url;

    // Pointer to next node
    Node* next;

    // Pointer to previous node
    Node* prev;

    // Constructor to initialize website data
    Node(string w, string u)
    {
        website = w;
        url = u;
        next = nullptr;
        prev = nullptr;
    }
};

// BrowserHistory class controls linked list operations
class BrowserHistory
{
private:
    // Points to first node in list
    Node* head;

    // Points to last node in list
    Node* tail;

    // Keeps track of current website
    Node* current;

public:
    // Constructor
    BrowserHistory()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    // Adds a new website to the linked list
    void AddWebsite(string website, string url)
    {
        // Create new node
        Node* newNode = new Node(website, url);

        // If list is empty
        if (head == nullptr)
        {
            // New node becomes head, tail, and current
            head = tail = current = newNode;
        }
        else
        {
            // Connect new node to end of list
            tail->next = newNode;
            newNode->prev = tail;

            // Move tail pointer to new node
            tail = newNode;
        }
    }

    // Displays all websites in the linked list
    void DisplayList()
    {
        // Temporary pointer starts at head
        Node* temp = head;

        cout << "\nWebsite List:\n";

        // Traverse through list
        while (temp != nullptr)
        {
            cout << temp->website
                << " - "
                << temp->url
                << endl;

            // Move to next node
            temp = temp->next;
        }
    }

    // Move forward in browser history
    void GoForward()
    {
        // Check if list is empty
        if (current == nullptr)
        {
            cout << "No websites available.\n";
            return;
        }

        // Check if already at end of list
        if (current->next == nullptr)
        {
            cout << "You are at the end of the list.\n";
        }
        else
        {
            // Move current pointer forward
            current = current->next;

            cout << "\nCurrent Website:\n";
            cout << current->website
                << " - "
                << current->url
                << endl;
        }
    }

    // Move backward in browser history
    void GoBackward()
    {
        // Check if list is empty
        if (current == nullptr)
        {
            cout << "No websites available.\n";
            return;
        }

        // Check if already at beginning
        if (current->prev == nullptr)
        {
            cout << "You are at the beginning of the list.\n";
        }
        else
        {
            // Move current pointer backward
            current = current->prev;

            cout << "\nCurrent Website:\n";
            cout << current->website
                << " - "
                << current->url
                << endl;
        }
    }

    // Convert string to lowercase
    string ToLower(string text)
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        return text;
    }

    // Search for a website by name
    void FindWebsite(string name)
    {
        // Start at beginning of list
        Node* temp = head;

        // Traverse through list
        while (temp != nullptr)
        {
            // Compare website names ignoring capitalization
            if (ToLower(temp->website) == ToLower(name))
            {
                cout << "\nFound:\n";
                cout << temp->website
                    << " - "
                    << temp->url
                    << endl;
                return;
            }

            // Move to next node
            temp = temp->next;
        }

        // Website not found
        cout << "Website not found.\n";
    }

    // Delete a website from the linked list
    void DeleteWebsite(string name)
    {
        // Start at head node
        Node* temp = head;

        // Traverse list
        while (temp != nullptr)
        {
            // Check if website matches
            if (ToLower(temp->website) == ToLower(name))
            {
                // If deleting first node
                if (temp == head)
                {
                    head = temp->next;

                    if (head != nullptr)
                    {
                        head->prev = nullptr;
                    }
                }

                // If deleting last node
                if (temp == tail)
                {
                    tail = temp->prev;

                    if (tail != nullptr)
                    {
                        tail->next = nullptr;
                    }
                }

                // Connect previous node to next node
                if (temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }

                // Connect next node to previous node
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }

                // Update current pointer if needed
                if (current == temp)
                {
                    current = head;
                }

                cout << name << " deleted.\n";

                // Free memory
                delete temp;

                return;
            }

            // Move to next node
            temp = temp->next;
        }

        // Website not found
        cout << "Website not found.\n";
    }

    // Destructor to free memory
    ~BrowserHistory()
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// Main program class
int main()
{
    // Create browser history object
    BrowserHistory browser;

    // Display my name and project title
    cout << "Name: Christopher Krawczyk\n";
    cout << "Linked List\n";

    // Add 20 websites to linked list
    browser.AddWebsite("Google", "https://www.google.com");
    browser.AddWebsite("YouTube", "https://www.youtube.com");
    browser.AddWebsite("Amazon", "https://www.amazon.com");
    browser.AddWebsite("Wikipedia", "https://www.wikipedia.org");
    browser.AddWebsite("Reddit", "https://www.reddit.com");
    browser.AddWebsite("Netflix", "https://www.netflix.com");
    browser.AddWebsite("GitHub", "https://www.github.com");
    browser.AddWebsite("Stack Overflow", "https://stackoverflow.com");
    browser.AddWebsite("LinkedIn", "https://www.linkedin.com");
    browser.AddWebsite("Yahoo", "https://www.yahoo.com");
    browser.AddWebsite("Bing", "https://www.bing.com");
    browser.AddWebsite("ESPN", "https://www.espn.com");
    browser.AddWebsite("CNN", "https://www.cnn.com");
    browser.AddWebsite("Twitch", "https://www.twitch.tv");
    browser.AddWebsite("Disney", "https://www.disney.com");
    browser.AddWebsite("Spotify", "https://www.spotify.com");
    browser.AddWebsite("Apple", "https://www.apple.com");
    browser.AddWebsite("Microsoft", "https://www.microsoft.com");
    browser.AddWebsite("Facebook", "https://www.facebook.com");
    browser.AddWebsite("Instagram", "https://www.instagram.com");

    // Variable to store menu choice
    int choice;

    // Menu loop
    do
    {
        // Display menu
        cout << "\n===== Browser Navigation Menu =====\n";
        cout << "1. Display Website List\n";
        cout << "2. Go Forward\n";
        cout << "3. Go Backward\n";
        cout << "4. Add Website\n";
        cout << "5. Delete Website\n";
        cout << "6. Find Website\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";

        // Read user choice
        cin >> choice;

        // Clear input buffer
        cin.ignore();

        // Process menu choice
        switch (choice)
        {
            // Display all websites
        case 1:
            browser.DisplayList();
            break;

            // Move forward
        case 2:
            browser.GoForward();
            break;

            // Move backward
        case 3:
            browser.GoBackward();
            break;

            // Add a new website
        case 4:
        {
            string website;
            string url;

            cout << "Enter website name: ";
            getline(cin, website);

            cout << "Enter URL: ";
            getline(cin, url);

            browser.AddWebsite(website, url);

            cout << "Website added.\n";
            break;
        }

        // Delete a website
        case 5:
        {
            string deleteSite;

            cout << "Enter website to delete: ";
            getline(cin, deleteSite);

            browser.DeleteWebsite(deleteSite);
            break;
        }

        // Find a website
        case 6:
        {
            string findSite;

            cout << "Enter website to find: ";
            getline(cin, findSite);

            browser.FindWebsite(findSite);
            break;
        }

        // Exit program
        case 7:
            cout << "Exiting...\n";
            break;

            // Invalid menu option
        default:
            cout << "Invalid choice.\n";
            break;
        }

    } while (choice != 7); // Repeat until user exits

    return 0;
}