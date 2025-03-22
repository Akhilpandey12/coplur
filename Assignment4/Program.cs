using System;
using System.Collections.Generic;

class OnlineFoodOrderingSystem
{
    static List<FoodItem> menu = new List<FoodItem>();
    static Dictionary<int, List<FoodItem>> orders = new Dictionary<int, List<FoodItem>>();
    static Queue<int> pendingDeliveries = new Queue<int>();
    static Stack<int> deliveredOrders = new Stack<int>();
    static HashSet<string> foodCategories = new HashSet<string>();
    static int orderIDCounter = 1;

    static void Main()
    {
        bool exit = false;
        while (!exit)
        {
            Console.WriteLine("\n1. Add Food Item");
            Console.WriteLine("2. Show Menu");
            Console.WriteLine("3. Place Order");
            Console.WriteLine("4. Deliver Order");
            Console.WriteLine("5. Show Pending Deliveries");
            Console.WriteLine("6. Show Delivered Orders");
            Console.WriteLine("7. Show Food Categories");
            Console.WriteLine("8. Exit");
            Console.Write("Choose an option: ");
            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    AddFoodItem();
                    break;
                case 2:
                    ShowMenu();
                    break;
                case 3:
                    PlaceOrder();
                    break;
                case 4:
                    DeliverOrder();
                    break;
                case 5:
                    ShowPendingDeliveries();
                    break;
                case 6:
                    ShowDeliveredOrders();
                    break;
                case 7:
                    ShowFoodCategories();
                    break;
                case 8:
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Invalid choice!");
                    break;
            }
        }
    }

    static void AddFoodItem()
    {
        Console.Write("Enter food name: ");
        string name = Console.ReadLine();
        Console.Write("Enter food price: ");
        decimal price = decimal.Parse(Console.ReadLine());
        Console.Write("Enter food category: ");
        string category = Console.ReadLine();

        menu.Add(new FoodItem(name, price, category));
        foodCategories.Add(category);
        Console.WriteLine("Food item added!");
    }

    static void ShowMenu()
    {
        Console.WriteLine("\nMenu:");
        foreach (var item in menu)
        {
            Console.WriteLine($"{item.Name} - {item.Price:C} ({item.Category})");
        }
    }

    static void PlaceOrder()
    {
        Console.WriteLine("\nPlacing Order:");
        List<FoodItem> orderItems = new List<FoodItem>();

        while (true)
        {
            Console.Write("Enter food name to add to order (or 'done' to finish): ");
            string name = Console.ReadLine();
            if (name.ToLower() == "done") break;

            FoodItem food = menu.Find(f => f.Name.Equals(name, StringComparison.OrdinalIgnoreCase));
            if (food != null)
            {
                orderItems.Add(food);
            }
            else
            {
                Console.WriteLine("Food item not found!");
            }
        }

        if (orderItems.Count > 0)
        {
            orders.Add(orderIDCounter, orderItems);
            pendingDeliveries.Enqueue(orderIDCounter);
            Console.WriteLine($"Order placed! Order ID: {orderIDCounter}");
            orderIDCounter++;
        }
    }

    static void DeliverOrder()
    {
        if (pendingDeliveries.Count > 0)
        {
            int orderID = pendingDeliveries.Dequeue();
            deliveredOrders.Push(orderID);
            Console.WriteLine($"Order {orderID} delivered!");
        }
        else
        {
            Console.WriteLine("No pending deliveries!");
        }
    }

    static void ShowPendingDeliveries()
    {
        Console.WriteLine("\nPending Deliveries:");
        foreach (var orderID in pendingDeliveries)
        {
            Console.WriteLine($"Order ID: {orderID}");
        }
    }

    static void ShowDeliveredOrders()
    {
        Console.WriteLine("\nDelivered Orders:");
        foreach (var orderID in deliveredOrders)
        {
            Console.WriteLine($"Order ID: {orderID}");
        }
    }

    static void ShowFoodCategories()
    {
        Console.WriteLine("\nFood Categories:");
        foreach (var category in foodCategories)
        {
            Console.WriteLine(category);
        }
    }
}

class FoodItem
{
    public string Name { get; }
    public decimal Price { get; }
    public string Category { get; }

    public FoodItem(string name, decimal price, string category)
    {
        Name = name;
        Price = price;
        Category = category;
    }
}