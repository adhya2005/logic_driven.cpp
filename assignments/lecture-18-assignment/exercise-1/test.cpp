#include <igloo/igloo.h>
#include <iostream>
#include <fstream>
#include "ucm_utils.h"

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

struct OutputParser{
    std::vector<std::string> result;

    OutputParser(std::string output){
        std::stringstream ss(output);
        std::string line;
        while (getline(ss, line)){
            // line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1);
            if (line != ""){
                result.push_back(line);
            }
        }
    }
};

Context(TextProgram){
    static void TearDownContext() {
        system("rm -rf temp test.txt");
    }

    Spec(TestRufus){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        printCard("Rufus", "Bobcat", "rbobcat@ucmerced.edu", 18);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        std::string raw = exec("cat test.txt");
        std::vector<std::string> actual = OutputParser(raw).result;

        std::vector<std::string> expected = {
            "Rufus Bobcat",
            "18 years old.",
            "rbobcat@ucmerced.edu",
        };

        Assert::That(actual, EqualsContainer(expected));
    }

    Spec(TestBob){
        std::ofstream fw;
        fw.open("test.txt");
        std::streambuf *oldbuf = std::cout.rdbuf();
        std::cout.rdbuf(fw.rdbuf()); 

        printCard("Bob", "Builder", "bbuilder@gmail.com", 37);
        std::cout.flush();

        std::cout.rdbuf(oldbuf);

        std::string raw = exec("cat test.txt");
        std::vector<std::string> actual = OutputParser(raw).result;

        std::vector<std::string> expected = {
            "Bob Builder",
            "37 years old.",
            "bbuilder@gmail.com",
        };

        Assert::That(actual, EqualsContainer(expected));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}

