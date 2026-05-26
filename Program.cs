using System;

// Namespace for the linked list browser project
namespace LinkedListBrowser
{
    // Node class represents each website in the linked list
    //by chris krawczyk
    class Node
    {
        // Stores website name
        public string Website;

        // Stores website URL
        public string Url;

        // Pointer to next node
        public Node Next;

        // Pointer to previous node
        public Node Prev;

        // Constructor to initialize website data
        public Node(string website, string url)
        {
            Website = website;
            Url = url;
            Next = null;
            Prev = null;
        }
    }

    // BrowserHistory class controls linked list operations
    class BrowserHistory
    {
        // Points to first node in list
        private Node head;

        // Points to last node in list
        private Node tail;

        // Keeps track of current website
        private Node current;

        // Adds a new website to the linked list
        public void AddWebsite(string website, string url)
        {
            // Create new node
            Node newNode = new Node(website, url);

            // If list is empty
            if (head == null)
            {
                // New node becomes head, tail, and current
                head = tail = current = newNode;
            }
            else
            {
                // Connect new node to end of list
                tail.Next = newNode;
                newNode.Prev = tail;

                // Move tail pointer to new node
                tail = newNode;
            }
        }

        // Displays all websites in the linked list
        public void DisplayList()
        {
            // Temporary pointer starts at head
            Node temp = head;

            Console.WriteLine("\nWebsite List:");

            // Traverse through list
            while (temp != null)
            {
                Console.WriteLine(temp.Website + " - " + temp.Url);

                // Move to next node
                temp = temp.Next;
            }
        }

        // Move forward in browser history
        public void GoForward()
        {
            // Check if list is empty
            if (current == null)
            {
                Console.WriteLine("No websites available.");
                return;
            }

            // Check if already at end of list
            if (current.Next == null)
            {
                Console.WriteLine("You are at the end of the list.");
            }
            else
            {
                // Move current pointer forward
                current = current.Next;

                Console.WriteLine("\nCurrent Website:");
                Console.WriteLine(current.Website + " - " + current.Url);
            }
        }

        // Move backward in browser history
        public void GoBackward()
        {
            // Check if list is empty
            if (current == null)
            {
                Console.WriteLine("No websites available.");
                return;
            }

            // Check if already at beginning
            if (current.Prev == null)
            {
                Console.WriteLine("You are at the beginning of the list.");
            }
            else
            {
                // Move current pointer backward
                current = current.Prev;

                Console.WriteLine("\nCurrent Website:");
                Console.WriteLine(current.Website + " - " + current.Url);
            }
        }

        // Search for a website by name
        public void FindWebsite(string name)
        {
            // Start at beginning of list
            Node temp = head;

            // Traverse through list
            while (temp != null)
            {
                // Compare website names ignoring capitalization
                if (temp.Website.ToLower() == name.ToLower())
                {
                    Console.WriteLine("\nFound:");
                    Console.WriteLine(temp.Website + " - " + temp.Url);
                    return;
                }

                // Move to next node
                temp = temp.Next;
            }

            // Website not found
            Console.WriteLine("Website not found.");
        }

        // Delete a website from the linked list
        public void DeleteWebsite(string name)
        {
            // Start at head node
            Node temp = head;

            // Traverse list
            while (temp != null)
            {
                // Check if website matches
                if (temp.Website.ToLower() == name.ToLower())
                {
                    // If deleting first node
                    if (temp == head)
                    {
                        head = temp.Next;

                        if (head != null)
                            head.Prev = null;
                    }

                    // If deleting last node
                    if (temp == tail)
                    {
                        tail = temp.Prev;

                        if (tail != null)
                            tail.Next = null;
                    }

                    // Connect previous node to next node
                    if (temp.Prev != null)
                        temp.Prev.Next = temp.Next;

                    // Connect next node to previous node
                    if (temp.Next != null)
                        temp.Next.Prev = temp.Prev;

                    Console.WriteLine(name + " deleted.");
                    return;
                }

                // Move to next node
                temp = temp.Next;
            }

            // Website not found
            Console.WriteLine("Website not found.");
        }
    }

    // Main program class
    class Program
    {
        // Program entry point
        static void Main(string[] args)
        {
            // Create browser history object
            BrowserHistory browser = new BrowserHistory();

            // Display my name and project title
            Console.WriteLine("Name: Christopher Krawczyk");
            Console.WriteLine("Linked List\n");

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
                Console.WriteLine("\n===== Browser Navigation Menu =====");
                Console.WriteLine("1. Display Website List");
                Console.WriteLine("2. Go Forward");
                Console.WriteLine("3. Go Backward");
                Console.WriteLine("4. Add Website");
                Console.WriteLine("5. Delete Website");
                Console.WriteLine("6. Find Website");
                Console.WriteLine("7. Exit");

                Console.Write("Enter choice: ");

                // Read user choice
                choice = Convert.ToInt32(Console.ReadLine());

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
                        Console.Write("Enter website name: ");
                        string website = Console.ReadLine();

                        Console.Write("Enter URL: ");
                        string url = Console.ReadLine();

                        browser.AddWebsite(website, url);

                        Console.WriteLine("Website added.");
                        break;

                    // Delete a website
                    case 5:
                        Console.Write("Enter website to delete: ");
                        string deleteSite = Console.ReadLine();

                        browser.DeleteWebsite(deleteSite);
                        break;

                    // Find a website
                    case 6:
                        Console.Write("Enter website to find: ");
                        string findSite = Console.ReadLine();

                        browser.FindWebsite(findSite);
                        break;

                    // Exit program
                    case 7:
                        Console.WriteLine("Exiting...");
                        break;

                    // Invalid menu option
                    default:
                        Console.WriteLine("Invalid choice.");
                        break;
                }

            } while (choice != 7); // Repeat until user exits
        }
    }
}