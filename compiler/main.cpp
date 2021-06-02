#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <string>
#include "parser/parser.h"
#include "parser/tree_parser.h"
#include "parser/string_parser.h"
#include "parser/term_parser.h"
#include "parser/scope_parser.h"
#include "parser/symbol_parser.h"
#include "parser/arithmetic_operator_parser.h"
#include "parser/space_parser.h"
#include "parser/binary_expression_parser.h"
#include "parser/assignment_parser.h"
#include "stream.h"
#include "file_stream.h"

int main()
{
    // std::string inputString = "//2 Your First C++ Program \n\n#include <iostream> \n\nint main() { \n\tstd::cout << \"Hello World!\"; \n\treturn 0; \n}";
    std::string inputString = "((8+2))*(2*(2+2))+as*(3)) ";

    //std::vector<char> buffer;
    //buffer.reserve(inputString.size());
    //for (unsigned int i = 0; i < inputString.size(); i++)
    //{
    //    buffer.push_back(inputString[i]);
    //}
    //Stream<char> input(buffer);

    Stream<char>* i = new FileStream("D:\\test.ste");

    auto a = new TermParser<int, std::string>(new IntegerParser(), new SymbolParser());
    auto result = a->parse(i);
    try {
        auto b = std::get<0>(result);
        std::cout << "Success" << std::endl;
        //std::cout << result << std::endl;
        std::cout << i;
    }
    catch (const std::bad_variant_access&) {
        std::cout << "Fuck" << std::endl;
    }
    return 0;
}