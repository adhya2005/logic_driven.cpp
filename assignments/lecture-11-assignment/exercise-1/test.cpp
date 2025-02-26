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

    Spec(FivePlusThreeIsEight){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=5 -DOP=1 -DRHS=3");
        std::string result = exec("echo 8 | ./temp");
        Assert::That(result, Equals("5 + 3 = That is the correct answer!"));
    }
    Spec(ThreePlusFiveIsFivePlusThree){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=3 -DOP=1 -DRHS=5");
        std::string result = exec("echo 8 | ./temp");
        Assert::That(result, Equals("5 + 3 = That is the correct answer!"));
    }
    Spec(FivePlusThreeIsNotNine){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=5 -DOP=1 -DRHS=3");
        std::string result = exec("echo 9 | ./temp");
        Assert::That(result, Equals("5 + 3 = That's incorrect. 5 + 3 = 8"));
    }
    Spec(FiveMinusThreeIsTwo){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=5 -DOP=2 -DRHS=3");
        std::string result = exec("echo 2 | ./temp");
        Assert::That(result, Equals("5 - 3 = That is the correct answer!"));
    }
    Spec(ThreeMinusFiveIsTreatedAsFiveMinusThree){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=3 -DOP=2 -DRHS=5");
        std::string result = exec("echo 2 | ./temp");
        Assert::That(result, Equals("5 - 3 = That is the correct answer!"));
    }
    Spec(FiveMinusThreeIsNotThree){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=5 -DOP=2 -DRHS=3");
        std::string result = exec("echo 3 | ./temp");
        Assert::That(result, Equals("5 - 3 = That's incorrect. 5 - 3 = 2"));
    }
    Spec(ThreeTimesTwoIsSix){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=3 -DOP=3 -DRHS=2");
        std::string result = exec("echo 6 | ./temp");
        Assert::That(result, Equals("3 * 2 = That is the correct answer!"));
    }
    Spec(ThreeTimesTwoIsNotOne){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=3 -DOP=3 -DRHS=2");
        std::string result = exec("echo 1 | ./temp");
        Assert::That(result, Equals("3 * 2 = That's incorrect. 3 * 2 = 6"));
    }
    Spec(TenDivTwoIsFive){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=10 -DOP=4 -DRHS=2");
        std::string result = exec("echo 5 | ./temp");
        Assert::That(result, Equals("10 / 2 = That is the correct answer!"));
    }
    Spec(TenDivTwoIsNotSeven){
        exec("g++ main.cpp -o temp -Itestlib -DLHS=10 -DOP=4 -DRHS=2");
        std::string result = exec("echo 7 | ./temp");
        Assert::That(result, Equals("10 / 2 = That's incorrect. 10 / 2 = 5"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}