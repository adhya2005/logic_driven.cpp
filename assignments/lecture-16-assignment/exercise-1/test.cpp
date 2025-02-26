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
    static void SetUpContext(){
        exec("g++ main.cpp -o temp");
    }

    static void TearDownContext() {
        system("rm -rf temp");
    }

    Spec(password){
        std::string result = exec("echo 'password' | ./temp");
        Assert::That(result, Equals("p@$$w0rd"));
    }
    Spec(abc123){
        std::string result = exec("echo 'abc123' | ./temp");
        Assert::That(result, Equals("@b(123"));
    }
    Spec(acgos){
        std::string result = exec("echo 'acgos' | ./temp");
        Assert::That(result, Equals("@(90$"));
    }
    Spec(ACGOS){
        std::string result = exec("echo 'ACGOS' | ./temp");
        Assert::That(result, Equals("ACGOS"));
    }
    Spec(acgos_is_not_aword){
        std::string result = exec("echo 'acgos is not a word' | ./temp");
        Assert::That(result, Equals("@(90$ i$ n0t @ w0rd"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}