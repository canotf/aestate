JSON_ERROR = 'CACode-Json'
SYNTAX_ERROR = 'CACode-Syntax'
ATTR_ERROR = 'CACode-Attr'
LOG_OPERA_NAME = 'CACode-Database-Operation'
WARN = 'WARN'
INFO = 'INFO'
DB_TASK = 'DATABASE OPERATION'
PARSE_ERROR = 'CACode-Parse'


def CACode_SQLERROR(msg):
    return '%s:%s' % ('CACode-Sql', msg)
