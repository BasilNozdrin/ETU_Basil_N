# python 4.7.1
from wikipedia import *
from help_wiki_function import is_page_valid


def try_set_lang(language):
    if language in languages():
        set_lang(language)
        return True
    else:
        return False


def list_max_words(arg_WikipediaPage_list):
    max_summary_words_amount = 0
    max_summary_words_pagename = ''
    for a_page in arg_WikipediaPage_list:
        words_amount = len(a_page.summary.split())
        if words_amount >= max_summary_words_amount:
            max_summary_words_amount = words_amount
            max_summary_words_pagename = a_page.title
    return max_summary_words_amount, max_summary_words_pagename


def make_chain(wp_list):
    result_chain = [wp_list[0]]
    for i in range(len(wp_list)-1):
        if wp_list[i+1] in page(wp_list[i]).links:
            result_chain.append(wp_list[i+1])
        else:
            for intermediate in page(wp_list[i]).links:
                if is_page_valid(intermediate):
                    if wp_list[i+1] in page(intermediate).links:
                        result_chain.append(intermediate)
                        result_chain.append(wp_list[i+1])
                        break
    return result_chain


# if __name_ == "__main__":
user_input = input().split(', ')
lang = user_input[-1]
if try_set_lang(lang):
    wp_titles_list = user_input[:-1]
    WikipediaPage_list = list(map(page, wp_titles_list))
    max_words_amount, max_words_pagename = list_max_words(WikipediaPage_list)
    shortest_WikipediaPage_chain = make_chain(wp_titles_list)
    print(max_words_amount, max_words_pagename)
    print(shortest_WikipediaPage_chain)
else:
    print('no results')
