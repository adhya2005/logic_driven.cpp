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
        std::string result = exec("echo '750\n0' | ./temp");
        Assert::That(result, Equals("Full price shipping"));
    }
    Spec(Test_2){
        std::string result = exec("echo '900\n1' | ./temp");
        Assert::That(result, Equals("Discounted shipping"));
    }
    Spec(Test_3){
        std::string result = exec("echo '1000\n0' | ./temp");
        Assert::That(result, Equals("Free shipping"));
    }
    Spec(Test_4){
        std::string result = exec("echo '1000\n1' | ./temp");
        Assert::That(result, Equals("Free shipping"));
    }
    Spec(Test_5){
        std::string result = exec("echo '1200\n0' | ./temp");
        Assert::That(result, Equals("Free shipping"));
    }
    Spec(Test_6){
        std::string result = exec("echo '1500\n1' | ./temp");
        Assert::That(result, Equals("Free shipping"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}