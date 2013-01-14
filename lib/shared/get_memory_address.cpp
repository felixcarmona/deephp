std::string get_memory_address(zval* arg)
{
    char r[100];
    switch (arg->type) {
        case IS_BOOL:
        case IS_LONG:
            sprintf(r, "%p", (void *)&arg->value.lval);
            break;
        case IS_DOUBLE:
            sprintf(r, "%p", (void *)&arg->value.dval);
            break;
        case IS_STRING:
            sprintf(r, "%p", (void *)arg->value.str.val);
            break;
        case IS_ARRAY:
        case IS_OBJECT:
        case IS_RESOURCE:
        case IS_NULL:
        default:
            sprintf(r, "%p", (void *)arg);
            break;
    }
    return r; // returned as std::string
}