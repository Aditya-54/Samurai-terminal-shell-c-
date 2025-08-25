#include <bits/stdc++.h>
#include <windows.h>
#include <process.h>
using namespace std;


void launchNewTerminal();
void showHelp();
void showCommandNotFound(const string& command);
void printBanner();
void printSamuraiArt();
void printNinjaArt();


vector<string> samuraiQuotes = {
    "\"The way of the warrior is in death. This is not a morbid fixation, but a way of life.\"",
    "\"A samurai must remain calm at all times, even in the face of danger.\"",
    "\"The sword is the soul of the samurai.\"",
    "\"Honor is stronger than steel.\"",
    "\"Victory goes to the one who has no thought of himself.\"",
    "\"Fall down seven times, get up eight.\" - Japanese Proverb"
};

vector<string> ninjaQuotes = {
    "\"A ninja must see through deception.\"",
    "\"The best fighter is never angry.\" - Lao Tzu",
    "\"In the midst of chaos, there is also opportunity.\"",
    "\"Silent as shadow, swift as wind.\"",
    "\"The art of war is of vital importance to the state.\" - Sun Tzu"
};

vector<string> animeQuotes = {
    "\"Believe it!\" - Naruto",
    "\"I'll take a potato chip... AND EAT IT!\" - Death Note",
    "\"It's over 9000!\" - Dragon Ball Z",
    "\"I am going to be the Pirate King!\" - One Piece",
    "\"Plus Ultra!\" - My Hero Academia",
    "\"I'll become the world's greatest swordsman!\" - Zoro"
};

string getRandomQuote(const vector<string>& quotes) {
    return quotes[rand() % quotes.size()];
}

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printWithColor(const string& text, int color) {
    setConsoleColor(color);
    cout << text;
    setConsoleColor(7); // Reset to white
}

vector<string> parseInput(const string& input) {
    stringstream ss(input);
    string token;
    vector<string> tokens;
    while(ss >> token) tokens.push_back(token);
    return tokens;
}

bool handleCustomCommand(const vector<string>& args) {
    if(args.empty()) return false;
    
    if(args[0] == "exit" || args[0] == "seppuku") {
        printWithColor("\n🗾 ", 14);
        cout << "Sayonara, warrior! Your journey ends with honor!\n";
        printWithColor("さようなら (Goodbye) 🌸\n", 13);
        exit(0);
    }
    else if(args[0] == "help" || args[0] == "--help" || args[0] == "sensei") {
        showHelp();
        return true;
    }
    else if(args[0] == "greet" || args[0] == "konnichiwa") {
        if(args.size() < 2) {
            printWithColor("🏮 Usage: ", 14);
            cout << "greet <name> or konnichiwa <name>\n";
            printWithColor("Example: ", 11);
            cout << "konnichiwa Naruto-kun\n";
        }
        else {
            string name;
            for(int i = 1; i < args.size(); i++) {
                name += args[i];
                if(i != args.size() - 1) name += " ";
            }
            printWithColor("\n🌸 こんにちは ", 13);
            printWithColor(name, 14);
            printWithColor("-san! ", 13);
            cout << "Welcome to the dojo! 🥋\n";
            cout << getRandomQuote(animeQuotes) << "\n\n";
        }
        return true;
    }
    else if(args[0] == "reverse" || args[0] == "mirror" || args[0] == "kagami") {
        if(args.size() < 2) {
            printWithColor("🪞 Usage: ", 14);
            cout << "reverse <text> or kagami <text>\n";
            printWithColor("Example: ", 11);
            cout << "kagami \"Omae wa mou shindeiru\"\n";
        }
        else {
            string text;
            for(int i = 1; i < args.size(); i++) {
                text += args[i];
                if(i != args.size() - 1) text += " ";
            }
            reverse(text.begin(), text.end());
            printWithColor("\n⚔️  Mirror Technique Activated!\n", 12);
            printWithColor("🪞 Reversed: ", 14);
            printWithColor(text, 11);
            cout << "\n" << getRandomQuote(ninjaQuotes) << "\n\n";
        }
        return true;
    }
    else if(args[0] == "fact" || args[0] == "power" || args[0] == "chikara") {
        if(args.size() < 2) {
            printWithColor("⚡ Usage: ", 14);
            cout << "fact <n> or power <n> or chikara <n>\n";
            printWithColor("Example: ", 11);
            cout << "power 5\n";
        }
        else {
            try {
                int n = stoi(args[1]);
                if(n < 0) {
                    printWithColor("❌ ", 12);
                    cout << "Power level cannot be negative, baka!\n";
                } else if(n > 20) {
                    printWithColor("💥 ", 12);
                    cout << "Power level too high! Even Goku can't handle this! (max n=20)\n";
                } else {
                    long long f = 1;
                    for(int i = 1; i <= n; i++) f *= i;
                    printWithColor("\n⚡ POWER LEVEL CALCULATION ⚡\n", 14);
                    printWithColor("🔥 Power(" + to_string(n) + ") = ", 12);
                    printWithColor(to_string(f), 10);
                    cout << "\n" << getRandomQuote(samuraiQuotes) << "\n\n";
                }
            } catch(const exception& e) {
                printWithColor("❌ ", 12);
                cout << "Invalid power level format, Baka!\n";
            }
        }
        return true;
    }
    else if(args[0] == "new" || args[0] == "summon" || args[0] == "kage-bunshin") {
        printWithColor("\n🌀 SHADOW CLONE JUTSU! 🌀\n", 11);
        cout << "Summoning new terminal dojo...\n";
        launchNewTerminal();
        return true;
    }
    else if(args[0] == "debug" || args[0] == "sharingan") {
        printWithColor("\n👁️  SHARINGAN ACTIVATED! 👁️ \n", 12);
        char buffer[MAX_PATH];
        GetModuleFileNameA(NULL, buffer, MAX_PATH);
        printWithColor("🎯 Executable path: ", 14);
        cout << buffer << endl;
        printWithColor("🖥️  Console window: ", 14);
        cout << (GetConsoleWindow() != NULL ? "Active" : "Inactive") << endl;
        printWithColor("🆔 Process ID: ", 14);
        cout << GetCurrentProcessId() << endl;
        cout << "\n\"I can see everything now...\" - Sasuke\n\n";
        return true;
    }
    else if(args[0] == "clear" || args[0] == "cls" || args[0] == "cleanse") {
        system("cls");
        printBanner();
        return true;
    }
    else if(args[0] == "pwd" || args[0] == "location" || args[0] == "basho") {
        char buffer[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH, buffer);
        printWithColor("🗾 Current Location: ", 14);
        cout << buffer << endl;
        cout << "\"Know your battlefield.\" - Art of War\n\n";
        return true;
    }
    else if(args[0] == "quote" || args[0] == "wisdom" || args[0] == "meigen") {
        printWithColor("\n🌸 WISDOM OF THE SENSEI 🌸\n", 13);
        int choice = rand() % 3;
        if(choice == 0) {
            printWithColor("⚔️  Samurai Wisdom:\n", 12);
            cout << getRandomQuote(samuraiQuotes) << "\n\n";
        } else if(choice == 1) {
            printWithColor("🥷 Ninja Philosophy:\n", 8);
            cout << getRandomQuote(ninjaQuotes) << "\n\n";
        } else {
            printWithColor("📺 Anime Spirit:\n", 14);
            cout << getRandomQuote(animeQuotes) << "\n\n";
        }
        return true;
    }
    else if(args[0] == "art" || args[0] == "ascii") {
        int choice = rand() % 2;
        if(choice == 0) {
            printSamuraiArt();
        } else {
            printNinjaArt();
        }
        return true;
    }
    
    return false;
}

void printBanner() {
    printWithColor("================================================================\n", 11);
    printWithColor("                    [SAMURAI TERMINAL]                         \n", 14);
    printWithColor("                   Bushi no Terminal                          \n", 13);
    printWithColor("================================================================\n", 11);
    cout << "\n";
    printWithColor(">>> ", 13);
    cout << "Welcome to the Digital Dojo, warrior!\n";
    printWithColor("=== ", 12);
    cout << "Type 'sensei' for guidance or 'seppuku' to leave with honor\n";
    cout << getRandomQuote(samuraiQuotes) << "\n\n";
}

void printSamuraiArt() {
    printWithColor("\n", 12);
    printWithColor("        [SAMURAI SPIRIT]\n", 12);
    printWithColor("              .='=.\n", 11);
    printWithColor("             /     \\   \n", 11);
    printWithColor("            | () () |  \n", 14);
    printWithColor("             \\  ^  /   \n", 11);
    printWithColor("              |||||     \n", 8);
    printWithColor("              |||||     \n", 8);
    printWithColor("        =================\n", 12);
    cout << "   \"The sword is the soul of the samurai\"\n\n";
}

void printNinjaArt() {
    printWithColor("\n", 8);
    printWithColor("        [SHADOW WARRIOR]\n", 8);
    printWithColor("              /\\_/\\  \n", 15);
    printWithColor("             ( o.o ) \n", 15);
    printWithColor("              > ^ <  \n", 15);
    printWithColor("             /|   |\\ \n", 8);
    printWithColor("            / |   | \\\n", 8);
    printWithColor("        =================\n", 11);
    cout << "   \"Silent as shadow, swift as wind\"\n\n";
}

void showHelp() {
    printWithColor("\n╔══════════════════════════════════════════════════════════════╗\n", 11);
    printWithColor("║                    🏮 DOJO TRAINING MANUAL 🏮                ║\n", 14);
    printWithColor("╚══════════════════════════════════════════════════════════════╝\n", 11);
    
    printWithColor("\n🌸 BASIC TECHNIQUES:\n", 13);
    cout << "  sensei, --help     - Show this training manual\n";
    cout << "  konnichiwa <name>  - Greet a fellow warrior\n";
    cout << "  kagami <text>      - Mirror technique (reverse text)\n";
    cout << "  chikara <n>        - Calculate power level (factorial)\n";
    cout << "  kage-bunshin       - Shadow clone jutsu (new terminal)\n";
    cout << "  cleanse            - Purify the dojo (clear screen)\n";
    cout << "  basho              - Show current location\n";
    cout << "  meigen             - Get wisdom from sensei\n";
    cout << "  ascii              - Display warrior art\n";
    cout << "  sharingan          - Debug vision (system info)\n";
    cout << "  seppuku            - Leave with honor (exit)\n\n";
    
    printWithColor("⚔️  SYSTEM JUTSU:\n", 12);
    cout << "  Any Windows command (dir, ping, etc.)\n\n";
    
    printWithColor("🎌 EXAMPLES:\n", 14);
    cout << "  konnichiwa Naruto-kun\n";
    cout << "  kagami \"Omae wa mou shindeiru\"\n";
    cout << "  chikara 7\n";
    cout << "  dir\n";
    cout << "  ping google.com\n\n";
    
    printWithColor("🌟 ", 14);
    cout << getRandomQuote(animeQuotes) << "\n\n";
}

void showCommandNotFound(const string& command) {
    printWithColor("❌ ", 12);
    printWithColor("\"" + command + "\" ", 11);
    cout << "is not a recognized jutsu!\n";
    printWithColor("🏮 ", 14);
    cout << "Consult your sensei with 'sensei' for available techniques.\n";
    cout << "\"Even the greatest warriors must learn.\" - Ancient Proverb\n\n";
}

void executeSystemCommand(const vector<string>& args) {
    printWithColor("⚡ Executing system jutsu: ", 11);
    string command;
    for(const auto& arg : args) {
        command += arg + " ";
    }
    cout << command << "\n";
    
    int result = system(command.c_str());
    if(result == -1) {
        printWithColor("💥 ", 12);
        cout << "System jutsu failed! The technique was too powerful!\n";
    }
    cout << "\n";
}

void launchNewTerminal() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    string exePath = string(buffer);
    string exeDir = exePath.substr(0, exePath.find_last_of("\\"));
    string batchPath = exeDir + "\\launch.bat";
    
    // Check if launch.bat exists
    ifstream batchFile(batchPath);
    if(batchFile.good()) {
        batchFile.close();
        printWithColor("🌀 ", 11);
        cout << "Using shadow clone scroll...\n";
        string batchCmd = "\"" + batchPath + "\"";
        int result = system(batchCmd.c_str());
        if(result == 0) return;
    }
    
    printWithColor("🥷 ", 8);
    cout << "Summoning new dojo in Command Prompt...\n";
    
    // Method 1: CMD (most reliable for paths with spaces)
    string cmdCmd = "start \"Samurai Terminal\" cmd /k \"\"" + exePath + "\" --new-window\"";
    int result1 = system(cmdCmd.c_str());
    
    if(result1 != 0) {
        printWithColor("⚡ ", 14);
        cout << "Trying PowerShell jutsu...\n";
        string powershellCmd = "start powershell -ArgumentList \"-Command\", \"& \\\"" + exePath + "\\\" --new-window; pause\"";
        int result2 = system(powershellCmd.c_str());
        
        if(result2 != 0) {
            printWithColor("🌟 ", 14);
            cout << "Attempting Windows Terminal technique...\n";
            string wtCmd = "wt.exe cmd /k \"\"" + exePath + "\" --new-window\"";
            int result3 = system(wtCmd.c_str());
            
            if(result3 != 0) {
                printWithColor("📜 ", 13);
                cout << "Creating shadow clone scroll...\n";
                
                ofstream batch(batchPath);
                if(batch.is_open()) {
                    batch << "@echo off\n";
                    batch << "start \"Samurai Terminal\" cmd /k \"%~dp0mycli.exe --new-window\"\n";
                    batch.close();
                    printWithColor("✅ ", 10);
                    cout << "Shadow clone scroll created! Activating...\n";
                    system(("\"" + batchPath + "\"").c_str());
                } else {
                    printWithColor("🆘 ", 12);
                    cout << "Manual shadow clone technique required:\n";
                    cout << "1. Open a new terminal window\n";
                    cout << "2. Execute: \"" << exePath << "\" --new-window\n";
                    system("pause");
                }
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Set console to UTF-8 for proper emoji/Japanese display
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    // Alternative: Use system command if above doesn't work
    // system("chcp 65001 >nul");
    
    // Seed random for quotes
    srand(time(NULL));
    
    // Check if we have the special flag indicating we're already in a new window
    bool alreadyInNewWindow = false;
    if(argc > 1 && string(argv[1]) == "--new-window") {
        alreadyInNewWindow = true;
    }
    
    // If not already in new window, launch one
    if(!alreadyInNewWindow) {
        printWithColor("🌀 ", 11);
        cout << "Summoning the Digital Dojo...\n";
        launchNewTerminal();
        return 0;
    }
    
    // Main shell loop (only runs in the new window)
    system("cls");
    printBanner();
    
    string input;
    while(true) {
        printWithColor("[samurai", 12);
        printWithColor("@dojo", 11);
        printWithColor("]$ ", 14);
        getline(cin, input);
        
        if(input.empty()) continue;
        
        printWithColor("[⚔️  Executing]: ", 8);
        cout << input << "\n";
        vector<string> args = parseInput(input);
        
        if(!handleCustomCommand(args)) {
            // Check if it's a known Windows command or show error
            string cmd = args[0];
            transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
            
            // Common Windows commands that should work
            vector<string> commonCommands = {
                "dir", "cd", "copy", "del", "type", "echo", "ping", "ipconfig",
                "tasklist", "taskkill", "whoami", "hostname", "systeminfo",
                "netstat", "tree", "findstr", "attrib", "xcopy", "robocopy"
            };
            
            bool isCommonCommand = find(commonCommands.begin(), commonCommands.end(), cmd) != commonCommands.end();
            
            if(isCommonCommand) {
                executeSystemCommand(args);
            } else {
                // Try to execute anyway, but show help if it fails
                int oldErrorMode = SetErrorMode(SEM_FAILCRITICALERRORS);
                int result = system((args[0] + " >nul 2>nul").c_str());
                SetErrorMode(oldErrorMode);
                
                if(result != 0) {
                    showCommandNotFound(args[0]);
                } else {
                    executeSystemCommand(args);
                }
            }
        }
    }
    
    return 0;
}