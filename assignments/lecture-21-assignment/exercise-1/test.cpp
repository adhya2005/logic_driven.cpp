#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

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

void replace_pattern(std::string&output, const std::string& pattern){
    while (output.find(pattern) != std::string::npos){
        output = output.replace(output.find(pattern), pattern.length(), "");
    }
}

struct OutputParser{
    std::string output;

    void replace_pattern(const std::string& pattern){
        while (output.find(pattern) != std::string::npos){
            output = output.replace(output.find(pattern), pattern.length(), "");
        }
    }

    OutputParser(std::string output){
        this->output = output;

        replace_pattern("[H[2J");
        replace_pattern(" ");
        replace_pattern("\n");
        replace_pattern("\t");
        replace_pattern("\r");
        replace_pattern("\v");
        replace_pattern("\f");

    }
};

Context(TextProgram){
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(StopOn13){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){4, 3, 5, 1}' -DMAX='(int[]){6, 6, 6, 6}' -DMIN='(int[]){1, 1, 1, 1}'");
        std::string actual = exec("printf 'Y\nN\n' | ./temp");
        std::string actual_min = OutputParser(actual).output;

        std::string expected = exec("cat testlib/expected1.txt");
        std::string expected_min = OutputParser(expected).output;
        
        Assert::That(expected_min, Equals(actual_min));
    }

    Spec(RollDouble6){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){6, 6}' -DMAX='(int[]){6, 6}' -DMIN='(int[]){1, 1}'");
        std::string actual = exec("printf 'Y\nN\n' | ./temp");
        std::string actual_min = OutputParser(actual).output;

        std::string expected = exec("cat testlib/expected2.txt");
        std::string expected_min = OutputParser(expected).output;
        

        Assert::That(expected_min, Equals(actual_min));
    }

};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}