#include "Zoo.h"

Zoo::Zoo()
{
    // Create some animals and add them to the zoo
    animals.push_back(new Lion("Simba", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Lion("Mufasa", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Monkey("Rafiki", Location(rand() % 20, rand() % 40)));
    animals.push_back(new Clownfish("Nemo", Location(rand() % 20, rand() % 40)));
}

Zoo::~Zoo()
{
    // Free memory for each ZooAnimal object in the animals vector
    for (ZooAnimal* animal : animals)
    {
        delete animal;
    }

    // Clear the vector to avoid dangling pointers
    animals.clear();
}

void Zoo::run()
{
    // Print the initial state of the zoo
    cout << "Welcome to the zoo!\n\n";
    printMap();
    printList();
    cout << "\n";
    while (true) {
        _valid_command = true;
        try
        {
            // Get the user's command
            string command, index, name;
            char type = 'M';
            int num;
            cout << "Enter command (type 'help' for a list of commands): ";
            getline(cin, command);

            // Parse the command and perform the appropriate action
            if (command == "stop") {
                cout << "Enter the index of the animal you want to stop:";
                cin >> index;
                num = stoi(index);
                stop(num);
            }
            else if (command == "move") {
                cout << "Enter the index of the animal you want to move:";
                cin >> index;
                num = stoi(index);
                move(num);
            }
            else if (command == "create") {
                cout << "Enter the first letter of the type of the animal you want to create:";
                cin >> type;
                cout << "Enter the name of the animal you want to create:";
                cin >> name;
                create(type, name);
            }
            else if (command == "del") {
                cout << "Enter the index of the animal you want to delete:";
                cin >> index;
                num = stoi(index);
                cout << num;
                del(num);
            }
            else if (command == "delAll") {
                cout << "Enter the first letter of the type of the animals you want to delete:";
                type = static_cast<char>(std::cin.get());
                delAll(type);
            }
            else if (command == "help") {
                // Print the help text
                cout << "commands:\n";
                cout << "stop-stop a specified animal from moving\n";
                cout << "move - start a specified animal moving again\n";
                cout << "create- create a new animal\n";
                cout << "del - delete a specified animal\n";
                cout << "delAll - delete all animals of a specified type\n";
                cout << "help - display this help text\n";
                cout << "exit - exit the program\n";
                cout << ". - advance to the next step\n";
                cout << "\n";
            }
            else if (command == "exit") {
                // Exit the program
                break;
            }
            else if (command == ".") {

            }
            else {
                // Invalid command
                cout << "Invalid command. Type 'help' for a list of commands.\n";
                _valid_command = false;
            }
            if (_valid_command)
            {
                stepAll();
                printMap();
                printList();
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }
}

void Zoo::stop(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
            animals[num]->stop();
    }
}

void Zoo::move(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
            animals[num]->move();
    }
}

void Zoo::create(char type, string name)
{
    if (type == 'L')
    {
        animals.push_back(new Lion(name, Location(rand() % 20, rand() % 40)));
    }
    else if (type == 'M')
    {
        animals.push_back(new Monkey(name, Location(rand() % 20, rand() % 40)));
    }
    else if (type == 'C')
    {
        animals.push_back(new Clownfish(name, Location(rand() % 20, rand() % 40)));
    }

}

void Zoo::del(int num)
{
    if (num >= 0 && num < animals.size())
    {
        if (animals[num])
        {
            delete animals[num];
            animals.erase(animals.begin() + num);
        }
    }
}

void Zoo::delAll(char type)
{
    for (int i = 0; i < animals.size(); i++)
    {
        if (animals[i]->getInitial() == type)
        {
            delete animals[i];
            animals.erase(animals.begin() + i);
            i--;
        }
    }
}

void Zoo::printMap()
{
    cout << "Map:\n";
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            bool found_animal = false;
            for (ZooAnimal* a : animals)
            {
                if (a->getLocation() == Location(i, j))
                {
                    cout << a->getInitial() << " ";
                    found_animal = true;
                    break;
                }
            }
            if (!found_animal)
            {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void Zoo::printList()
{
    cout << "\nList of animals:\n";
    for (int i = 0; i < animals.size(); i++)
    {
        std::cout << i << ".";
        animals[i]->printDetails();
    }
}

void Zoo::stepAll()
{
    for (int i = 0; i < animals.size(); i++)
    {
        animals[i]->step();
    }
}