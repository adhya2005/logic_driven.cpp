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

Context(TestProgram) {
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(Test_1){
        std::string result = exec("echo '1\n2\n3\n4\n5' | ./temp");
        Assert::That(result, Equals("The min is: 1"));
    }
    Spec(Test_2){
        std::string result = exec("echo '5\n4\n3\n2\n1' | ./temp");
        Assert::That(result, Equals("The min is: 1"));
    }
    Spec(Test_3){
        std::string result = exec("echo '1\n2\n0\n3\n4' | ./temp");
        Assert::That(result, Equals("The min is: 0"));
    }
    Spec(Test_4){
        std::string result = exec("echo '7\n7\n7\n7\n7' | ./temp");
        Assert::That(result, Equals("The min is: 7"));
    }
    Spec(Test_5){
        std::string result = exec("echo '0\n-1\n-2\n-3\n-4' | ./temp");
        Assert::That(result, Equals("The min is: -4"));
    }
    Spec(Test_6){
        std::string result = exec("echo '-4\n-3\n-2\n-1\n-0' | ./temp");
        Assert::That(result, Equals("The min is: -4"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}