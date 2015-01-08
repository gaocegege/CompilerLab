MyLang - Syntax Definition
===

File
---

**root**:

    <> <program> <>
    // allow spaces before and after
    // ignore tail

Main Structure
---

program:

    program <proto> <main body> <end program>

function:

    function <proto> <main body> <end function>

class:

    class <argument tuple> <main body> end class

end program:

    end program <id>
    end

end function:

    end function <id>
    end

Block
---

main body:

    <public block> <private block> <code block>

public block:

    <definition list>

private block:

    is <definition list>
    <>

code block:

    begin <statement list>
    <>

Proto
---

proto:

    <id> <argument tuple>

argument tuple:

    ( <argument list> )
    <>

argument list:

    <argument> , <argument list>
    <argument>
    <>

argument:

    type <id>
    in <id>
    out <id>
    var <id>
    <id>

Definition
---

definition list:

    <definition> <definition list>
    <>

definition:

    <field definition>
    <function> ;
    ;

field definition:

    type <field name> <expression>
    expr <field name> <expression>
    var <field name> <expression>
    static <field name> <expression>
    fast <field name> <expression>
    <field name> <expression>

field name:

    extends
    refers
    receive
    return
    <id> imports
    <id> is
    // receive: id="__input", supported in program only
    // return: id="__result", supported in function only

Statement
---

statement list:

    <statement> <statement list>
    <>

statement:

    <expression> ;
    <jump> ;
    <structure>
    <repeat> ;
    ;

Jump Statement
---

jump:

    <receive>
    <restart>
    <return>
    // TODO:
    // <continue>
    // <break>
    // <label>
    // <goto>

receive:

    receive <expression>

restart:

    restart

return:

    return <expression>
    return

Code Structure
---

structure:

    <if structure>
    <for structure>
    <foreach structure>
    <while structure>

if structure:

    if <expression> then <statement list> <condition chain> end if

for structure:

    for <id> in <expression> <to step> <expression> do <statement list> end for

foreach structure:

    foreach <id> in <expression> do <statement list> end foreach

while structure:

    while <expression> do <statement list> end while

condition chain:

    elif <expression> then <statement list> <condition chain>
    else <statement list>
    <>

to step:

    to
    downto

repeat:

    repeat <statement list> until <expression>
    // special structure

Expression
---

expression list:

    <expression> , <expression list>
    <expression>
    <>

expression:

    <assign expression>

assign expression:

    <relative expression> <assign operation>

assign operation:

    <assignment> <assign expression>
    <>

relative expression:

    <additive expression> <relative operation>

relative operation:

    <relation> <additive expression> <relative operation>
    <>
    // left-asso
    // <relation> <relative expression>
    // <>

additive expression:

    <multiplicative expression> <additive operation>

additive operation:

    <addition> <multiplicative expression> <additive operation>
    <>
    // left-asso
    // <addition> <additive expression>
    // <>

multiplicative expression:

    <unary expression> <multiplicative operation>

multiplicative operation:

    <multiplication> <unary expression> <multiplicative operation>
    <>
    // left-asso
    // <multiplication> <multiplicative expression>
    // <>

unary expression:

    <unary operator> <unary expression>
    <call expression>

call expression:

    <access expression> <call operation>

call operation:

    <call expression>
    of <call expression>
    <>

access expression:

    <value> <access operation>

access operation:

    . <value> <access operation>
    <>
    // left-asso
    // . <access expression>
    // <>

Operator
---

assignment:

    :=
    +=
    -=
    *=
    /=

relation:

    <comparison>
    in

addition:

    <addsub>
    or
    xor

multiplication:

    <muldivmod>
    div
    mod
    and
    shl
    shr
    rol
    ror

unary operator:

    <addsub>
    not

*comparison*:

    ==|<=|=<|>=|=>|!=|<|>

*addsub*:

    \+|-

*muldivmod*:

    \*|\/|%

Value
---

value:

    <id>
    <real>
    <integer>
    <byte>
    <string>
    <tuple>
    <list>
    <class>
    // expr boolean yes := -1
    //              no := 0
    // class: allow inline class

*real*:

    [0-9]*\.[0-9]+([Ee][\+-]?[0-9]+)?

*integer*:

    [0-9]+

*byte*:

    '([^"'\\]|\\[Xx][0-9A-Fa-f][0-9A-Fa-f]|\\[^Xx])'

*string*:

    "([^"'\\]|\\[Xx][0-9A-Fa-f][0-9A-Fa-f]|\\[^Xx])*"

tuple:

    ( <expression list> )

list:

    [ <expression list> ]

Special
---

**space**:

    <ignored>

**keyword**:

    <reserved id>
    <sign>

*id*:

    [A-Za-z_][A-Za-z0-9_]*

*reserved id*:

    [A-Za-z_][A-Za-z0-9_]*

*sign*:

    [\(\)\[\],.;]|[\:\+\-\*\/]\=

*ignored*:

    (\/\/.*|[ \t\r\n])*
    // including comments
