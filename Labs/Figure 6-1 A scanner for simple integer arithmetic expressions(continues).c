#include <ctype.h>
#include <stdio.h>

/* the tokens as an enumerated type */
typedef enum {TT_PLUS, TT_TIMES, TT_LPAREN, TT_RPAREN, TT_EOL, TT_NUMBER, TT_ERROR} TokenType;

int numVal;     /* computed numeric value of a NUMBER token */
int currChar;   /* current character */

TokenType getToken(){
    while (currChar == ' ')     /* skip blanks */
        currChar = getChar();
    if (isdigit(currChar)){
        numVal = 0;
        while (isdigit(currChar)){
            /* compute numeric value */
            numVal = 10 * numVal + currChar - '0';
            /* 考虑到数字的位数， 每次循环都会将'numVal'乘以10 */
            currChar = getchar();
        }
        return TT_NUMBER;
    }
    else{
        switch (currChar){
            case '(': return TT_LPAREN; break;
            case ')': return TT_RPAREN; break;
            case '+': return TT_PLUS; break;
            case '*': return TT_TIMES; break;
            case '\n': return TT_EOL; break;
            default: return TT_ERROR; break;
        }
    }
}

main(){
    TokenType token;
    currChar = getchar();
    do{
        token = getToken();
        switch (token){
            case TT_PLUS: printf("TT_PLUS\n"); break;
            case TT_TIMES: printf("TT_TIMES\n"); break;
            case TT_LPAREN: printf("TT_LPAREN\n"); break;
            case TT_RPAREN: printf("TT_RPAREN\n"); break;
            case TT_EOL: printf("TT_EOL\n");break;
            case TT_NUMBER: printf("TT_NUMBER: %d\n", numVal); break;
            case TT_ERROR: printf("TT_ERROR: %c\n", currChar); break;
        }
    } while (token != TT_EOL);
    return 0;
}

/*
这段C代码是一个简单的词法分析器（Lexer），
它的主要用途是对输入的字符序列（比如一段文本或代码）进行扫描，
并将它们分解成一系列称为“token”的有意义的元素。在编译器的前端阶段，
词法分析是一个重要步骤，它为语法分析（Parsing）阶段准备数据。
*/

/*
TT_PLUS: 代表加号（+）符号。
TT_TIMES: 代表乘号（*）符号。
TT_LPAREN: 代表左括号（(）。
TT_RPAREN: 代表右括号（)）。
TT_EOL: 代表行结束符，这里使用换行符（\n）表示输入结束。
TT_NUMBER: 代表一个数字，该数字可以是多位数。
TT_ERROR: 代表一个无法识别的字符。
*/

/*
程序的流程如下：

main函数首先从标准输入读取一个字符到currChar变量中。
main函数进入一个循环，在循环中调用getToken函数来获取下一个token。
getToken函数首先跳过所有的空格字符，然后根据currChar的值确定下一个token的类型。
如果currChar是一个数字，getToken会继续读取直到非数字字符出现，并计算这一系列数字字符代表的数值，然后返回TT_NUMBER。
如果currChar是一个特殊字符（如+、*、(、)或\n），getToken会返回相应的token类型。对于其他任何字符，getToken会返回TT_ERROR。
main函数根据getToken返回的token类型打印相应的信息。对于数字token，它还会打印出该数字的值。
如果遇到行结束符（TT_EOL），循环结束。
*/