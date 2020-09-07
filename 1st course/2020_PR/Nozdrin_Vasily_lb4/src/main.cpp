#include <iostream>
#include <cstring>

#include "customstack.h"

int main()
{
    CustomStack *stack = new CustomStack(1);


    stack->push("a");

    return 0;
//
//    char c;
//    bool readingTag = false;
//    bool isClosing = false;
//    char *tag = new char[30];
//    int tagLen = 0;
//    do
//    {
//        c = getc(stdin);
//        if (readingTag)
//        {
//            if (c == '/')
//            {
//                isClosing = true;
//                continue;
//            }
//            if (c == '>')
//            {
//                readingTag = false;
//                if (!strcmp(tag, "br") || !strcmp(tag, "hr"))
//                {
//                    tag[0] = '\0';
//                    tagLen = 0;
//                    isClosing = false;
//                    continue;
//                }
//
//                if (!isClosing)
//                {
//                    stack.push(tag);
//                } else {
//                    if (strcmp(stack.top(), tag))
//                    {
//                        printf("wrong\n");
//                        return 0;
//                    } else {
//                        stack.pop();
//                    }
//                }
//
//                tag[0] = '\0';
//                tagLen = 0;
//                isClosing = false;
//                continue;
//            }
//
//            tag[tagLen++] = c;
//            tag[tagLen] = '\0';
//        }
//        if (c == '<')
//            readingTag = true;
//    } while ( c != EOF && c != '\n');
//
//    if (stack.empty())
//        printf("correct\n");
//    else
//        printf("wrong\n");

    return 0;
}
