from parser import myparser
from parser import myparser_cpp

parser = myparser.MyParser()
parser.add_rules(open('syntax.md', 'r').readlines())

with open('mylang_syntax.hpp', 'w') as syntax_hpp:
    syntax_hpp.write(
        myparser_cpp.cplusplus_gen(
            'mylang',
            parser.xdump(myparser_cpp.cplusplus_dump),
            'parser/',
            'MYLANG_SYNTAX_HPP'
        )
    )
