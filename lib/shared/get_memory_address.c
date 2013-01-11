void get_memory_address(zval* arg, char* out)
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
    int i;
    for(i = 0; i <= 100; i++)
    {
        out[i] = r[i];
    }
}