#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <string>
#include "parser/parser.h"
#include "stream.h"
#include "file_stream.h"
#include "parser/variable_declaration_parser.h"
#include "parser/function_declaration_parser.h"
#include "parser/scope_parser.h"
#include "parser/block_parser.h"
#include "ast/abstract_syntax_tree.h"
#include "parser/type_parser.h"
#include "parser/if_then_else_parser.h"

int main()
{
    // std::string inputString = "//2 Your First C++ Program \n\n#include <iostream> \n\nint main() { \n\tstd::cout << \"Hello World!\"; \n\treturn 0; \n}";
    //std::string inputString = "((8+2))*(2*(2+2))+as*(3)) ";

    //std::vector<char> buffer;
    //buffer.reserve(inputString.size());
    //for (unsigned int i = 0; i < inputString.size(); i++)
    //{
    //    buffer.push_back(inputString[i]);
    //}
    //Stream<char> input(buffer);

    Stream<char>* i = new FileStream("D:\\test.ste");
    Parser<int>* p = new IntegerParser();
    
    auto result = p->parse(i);
    if (auto r = std::get_if<0>(&result.result))
    {
        // C++Program p = r->getData();
        // Analyzer an = Analyzer()
        // ScopeAnalyzer.analyze(block);
        // Block b = r->getData();
        std::cout << "Success" << std::endl;
    }
    else
    {
        std::cout << "Fuck" << std::endl;
    }
    return 0;
}