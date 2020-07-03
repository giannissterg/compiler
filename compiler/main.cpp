#include <iostream>
#include <tuple>
#include <vector>
#include <utility>
#include <string>
#include "parser/parser.h"
#include "parser/digit_parser.h"
#include "parser/or_parser.h"
#include "parser/one_of_parser.h"
#include "parser/optional_parser.h"
#include "parser/integer_parser.h"
#include "parser/character_parser.h"
#include "parser/integer_parser.h"
#include "parser/chain_parser.h"
#include "parser/expression_parser.h"
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
#

int main()
{
    // std::string inputString = "//2 Your First C++ Program \n\n#include <iostream> \n\nint main() { \n\tstd::cout << \"Hello World!\"; \n\treturn 0; \n}";
    //std::string inputString = "(8+2)*(2*(2+2))+as*3 ";
    std::string inputString = "int a3 = 2 ";

    std::vector<char> buffer;
    buffer.reserve(inputString.size());
    for (unsigned int i = 0; i < inputString.size(); i++)
    {
        buffer.push_back(inputString[i]);
    }
    Stream<char> input(buffer);

    //auto a = new TermParser<int, std::string>(new IntegerParser(), new SymbolParser());
    auto a = AssignmentParser("=");
    auto result = a.parse(input);
    try {
        std::cout << "Success" << std::endl;
        //std::cout << result << std::endl;
        std::cout << input;
    }
    catch (const std::bad_variant_access&) {
        std::cout << "Fuck" << std::endl;
    }
    return 0;
}