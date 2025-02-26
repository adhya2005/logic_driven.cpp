#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <fstream>

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

Context(TextProgram){
    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(GenerateThreeOneToTen){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){8, 6, 7}' -DMIN='(int[]){5, 5, 5}' -DMAX='(int[]){9, 9, 9}'");
        std::string result = exec("echo 3 5 9 | ./temp");
        Assert::That(result, Equals("8\n6\n7"));
    }
    Spec(GenerateThreeOneToTen2){
        exec("g++ main.cpp -o temp -Itestlib -DSEQ='(int[]){901, 905, 904, 907}' -DMIN='(int[]){900, 900, 900, 900}' -DMAX='(int[]){910, 910, 910, 910}'");
        std::string result = exec("echo 4 900 910 | ./temp");
        Assert::That(result, Equals("901\n905\n904\n907"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}