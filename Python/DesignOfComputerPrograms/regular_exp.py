'''
5 regular expression symbol
    ^
    $
    ''
    .
    *
    ?
'''

def search(pattern, text):
    'Return True if pattern appears anywhere in text.'
    if pattern.startswith('^'):
        return match(pattern[1:], text)
    else:
        return match(".*" + pattern, text)
    
def match(pattern, text):
    'Return True if pattern appears at the start of the text.'
    if pattern == '':
        return True
    
    elif pattern == '$':
        return (text == '')
    
    elif len(pattern)>1 and pattern[1] in '*?':
        p, op, pat = pattern[0], pattern[1], pattern[2:]
    
        if op == '*':
            return match_star(p, pat, text)
        
        elif op == '?':
            if match1(p, text) and match(pat, text[1:]):
                return True
            else:
                return match(pat, text)
    else:
        return match1(pattern[0], text) and match(pattern[1:], text[1:])
        
def match1(p, text):
    'Returns True if first character of text matches pattern character p.'
    if not text:
        return False
    if p == '.':
        return True
    if p == text[0]:
        return True
    return False

def match_star(p, pat, text):
    'Return True if any number of char p, followed by pattern, matches text.'
    if match(pat, text):
        return True
    if match1(p, text) and match_star(p, pat, text[1:]):
        return True
    return False


def test():
    assert search('', '')
    assert search('', 'aaa')
    assert search('.*', 'a')
    assert search('.?a*', 'a')
    print 'All test passed.'
    
test()