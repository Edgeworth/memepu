from pygments.lexer import RegexLexer, bygroups
from pygments.token import *

import re

__all__=['MemelangLexer']

class MemelangLexer(RegexLexer):
    name = 'Memelang'
    aliases = ['memelang']
    filenames = ['*.meme']
    flags = re.MULTILINE | re.UNICODE

    tokens = {
        'root' : [
            (u'(//.*)', bygroups(Comment.Single)),
            (u'(fn)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Function)),
            (u'(intf)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(impl)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(struct)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(enum)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(var|i8|i16|i32|i64|u8|u16|u32|u64|f32|f64|bool|impl|intf|struct|enum|fn|asm)', bygroups(Keyword.Type)),
            (u'(static|auto|const)', bygroups(Keyword.Declaration)),
            (u'(ret|for|while|if|else|match)', bygroups(Keyword.Reserved)),
            (u'([a-zA-Z_]+[a-zA-Z0-9_]*)(\\s*)(\\()', bygroups(Name.Variable, Generic, Punctuation)),
            (u'(\\b\\d+u?)', bygroups(Number)),
            (u'(true|false)', bygroups(Keyword.Constant)),
            (u'(\\{)', bygroups(Punctuation), 'main__1'),
            (u'([:=<>\\-+*/%|!&.?~^])', bygroups(Operator)),
            (u'([(){}<>\\[\\]])', bygroups(Punctuation)),
            (u'([,:])', bygroups(Punctuation)),
            (u'([;])', bygroups(Punctuation)),
            (u'(\\\")', bygroups(String), 'main__2'),
            (u'(\\\')', bygroups(String), 'main__3'),
            (u'([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Generic)),
            (u'([^\\s\\n\\r])', bygroups(Generic.Error)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ],
        'main__1' : [
            (u'(//.*)', bygroups(Comment.Single)),
            (u'(fn)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Function)),
            (u'(intf)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(impl)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(struct)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(enum)(\\s+)([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Keyword.Type, Generic, Name.Class)),
            (u'(var|i8|i16|i32|i64|u8|u16|u32|u64|f32|f64|bool|impl|intf|struct|enum|fn|asm)', bygroups(Keyword.Type)),
            (u'(static|auto|const)', bygroups(Keyword.Declaration)),
            (u'(ret|for|while|if|else|match)', bygroups(Keyword.Reserved)),
            (u'([a-zA-Z_]+[a-zA-Z0-9_]*)(\\s*)(\\()', bygroups(Name.Variable, Generic, Punctuation)),
            (u'(\\b\\d+u?)', bygroups(Number)),
            (u'(true|false)', bygroups(Keyword.Constant)),
            (u'(\\{)', bygroups(Punctuation), 'main__1'),
            (u'([:=<>\\-+*/%|!&.?~^])', bygroups(Operator)),
            (u'([(){}<>\\[\\]])', bygroups(Punctuation)),
            (u'([,:])', bygroups(Punctuation)),
            (u'([;])', bygroups(Punctuation)),
            (u'(\\\")', bygroups(String), 'main__2'),
            (u'(\\\')', bygroups(String), 'main__3'),
            (u'([a-zA-Z_]+[a-zA-Z0-9_]*)', bygroups(Generic)),
            (u'([^\\s\\n\\r])', bygroups(Generic.Error)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ],
        'main__2' : [
            (u'(\\\\(?:\\\\|\'|\"|t|r|n))', bygroups(String.Escape)),
            (u'([^\"\\\\\\n\\r]+)', bygroups(String.Double)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ],
        'main__3' : [
            (u'(\\\\(?:\\\\|\'|\"|t|r|n))', bygroups(String.Escape)),
            (u'([^\'\\\\\\n\\r]+)', bygroups(String.Single)),
            ('(\n|\r|\r\n)', String),
            ('.', String),
        ]
    }
